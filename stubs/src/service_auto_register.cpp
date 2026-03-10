/*
 * Service Auto-Registration Implementation for macOS
 *
 * 自动注册 Source 和 Sink Service 到 ServiceRegistry
 * 
 * 功能：
 * - 在动态库加载时自动创建并注册 Service Mock 对象
 * - Source Service 注册为 SA ID 4803
 * - Sink Service 注册为 SA ID 4804
 * - 确保 Service 在 SDK 初始化之前就已准备好
 * 
 * 注意：
 * - 由于 DistributedCameraSourceService 和 DistributedCameraSinkService
 *   在 CMakeLists.txt 中被注释掉（依赖太多 camera framework），
 *   我们创建最小化的 Mock Service 对象来满足 SDK 的查找需求
 */

#include "service_registry.h"
#include "distributed_hardware_log.h"
#include "dcamera_ipc_interface_code.h"
#include "distributed_camera_errno.h"
#include "idcamera_sink_callback.h"
#include "idcamera_source_callback.h"
#include "iremote_stub.h"
#include "iremote_object.h"
#include "refbase.h"
#include "message_parcel.h"
#include "message_option.h"

#include <mutex>
#include <cstdlib>

#if defined(DCAMERA_BUILD_SOURCE_LIB)
#include "distributed_camera_source_service.h"
#include "idcamera_source_callback.h"
#include "distributed_camera_errno.h"
#endif

namespace OHOS {
namespace DistributedHardware {

#if defined(DCAMERA_BUILD_SOURCE_LIB)
class DistributedCameraSourceServiceEx final : public DistributedCameraSourceService {
public:
    DistributedCameraSourceServiceEx(int32_t saId, bool runOnCreate) : DistributedCameraSourceService(saId, runOnCreate) {}
    using DistributedCameraSourceService::OnStart;
    using DistributedCameraSourceService::OnStop;

    int32_t InitSource(const std::string& params, const sptr<IDCameraSourceCallback>& callback) override
    {
        {
            std::lock_guard<std::mutex> lock(cbMutex_);
            callback_ = callback;
        }
        return DistributedCameraSourceService::InitSource(params, callback);
    }

    int32_t RegisterDistributedHardware(const std::string& devId, const std::string& dhId,
        const std::string& reqId, const EnableParam& param) override
    {
        int32_t ret = DistributedCameraSourceService::RegisterDistributedHardware(devId, dhId, reqId, param);

        sptr<IDCameraSourceCallback> cb;
        {
            std::lock_guard<std::mutex> lock(cbMutex_);
            cb = callback_;
        }
        if (cb != nullptr && ret == DCAMERA_OK) {
            std::string data = std::string("mock_register_ok");
            (void)cb->OnNotifyRegResult(devId, dhId, reqId, ret, data);
        }
        return ret;
    }

    int32_t UnregisterDistributedHardware(const std::string& devId, const std::string& dhId,
        const std::string& reqId) override
    {
        int32_t ret = DistributedCameraSourceService::UnregisterDistributedHardware(devId, dhId, reqId);

        sptr<IDCameraSourceCallback> cb;
        {
            std::lock_guard<std::mutex> lock(cbMutex_);
            cb = callback_;
        }
        if (cb != nullptr && ret == DCAMERA_OK) {
            std::string data = std::string("mock_unregister_ok");
            (void)cb->OnNotifyUnregResult(devId, dhId, reqId, ret, data);
        }
        return ret;
    }

private:
    std::mutex cbMutex_;
    sptr<IDCameraSourceCallback> callback_ { nullptr };
};
#endif

/**
 * @brief 最小化的 Source Service Mock（IRemoteObject）
 *
 * 目标：
 * - 让 SDK Proxy 能通过 SendRequest 走到“服务端”
 * - 写回 reply 中的 int32 返回码，保持调用语义
 * - 保存 InitSource 传入的 callback remote object，并在 Register/Unregister 时回调
 */
class MinimalSourceServiceMock : public IRemoteObject {
public:
    MinimalSourceServiceMock() : IRemoteObject(u"distributed_camera_source") {
        DHLOGI("MinimalSourceServiceMock created");
    }

    virtual ~MinimalSourceServiceMock() {
        DHLOGI("MinimalSourceServiceMock destroyed");
    }

    int32_t GetObjectRefCount() override
    {
        return 1;
    }

    bool AddDeathRecipient(const sptr<DeathRecipient>& recipient) override
    {
        (void)recipient;
        return true;
    }

    bool RemoveDeathRecipient(const sptr<DeathRecipient>& recipient) override
    {
        (void)recipient;
        return true;
    }

    int Dump(int fd, const std::vector<std::u16string>& args) override
    {
        (void)fd;
        (void)args;
        return 0;
    }

    int32_t SendRequest(uint32_t code, MessageParcel& data, 
                       MessageParcel& reply, MessageOption& option) override {
        (void)option;
        DHLOGD("MinimalSourceServiceMock::SendRequest code: %u", code);

        // Consume interface token (kept for compatibility checks inside proxy/stub code).
        (void)data.ReadInterfaceToken();

        switch (static_cast<IDCameraSourceInterfaceCode>(code)) {
            case IDCameraSourceInterfaceCode::INIT_SOURCE: {
                const std::string params = data.ReadString();
                const sptr<IRemoteObject> callbackObj = data.ReadRemoteObject();
                {
                    std::lock_guard<std::mutex> lock(mutex_);
                    initParams_ = params;
                    callbackRemote_ = callbackObj;
                }
                reply.WriteInt32(DCAMERA_OK);
                return DCAMERA_OK;
            }
            case IDCameraSourceInterfaceCode::RELEASE_SOURCE: {
                {
                    std::lock_guard<std::mutex> lock(mutex_);
                    callbackRemote_ = nullptr;
                    initParams_.clear();
                }
                reply.WriteInt32(DCAMERA_OK);
                return DCAMERA_OK;
            }
            case IDCameraSourceInterfaceCode::REGISTER_DISTRIBUTED_HARDWARE: {
                const std::string devId = data.ReadString();
                const std::string dhId = data.ReadString();
                const std::string reqId = data.ReadString();
                const std::string sinkVersion = data.ReadString();
                const std::string sinkAttrs = data.ReadString();
                (void)sinkVersion;
                (void)sinkAttrs;

                reply.WriteInt32(DCAMERA_OK);

                sptr<IRemoteObject> cb;
                {
                    std::lock_guard<std::mutex> lock(mutex_);
                    cb = callbackRemote_;
                }
                if (cb != nullptr) {
                    MessageParcel cbData;
                    MessageParcel cbReply;
                    MessageOption cbOption;
                    cbData.WriteInterfaceToken(IDCameraSourceCallback::GetDescriptor());
                    cbData.WriteString(devId);
                    cbData.WriteString(dhId);
                    cbData.WriteString(reqId);
                    cbData.WriteInt32(DCAMERA_OK);
                    cbData.WriteString(std::string("mock_register_ok"));
                    (void)cb->SendRequest(IDCameraSourceCallback::NOTIFY_REG_RESULT, cbData, cbReply, cbOption);
                }
                return DCAMERA_OK;
            }
            case IDCameraSourceInterfaceCode::UNREGISTER_DISTRIBUTED_HARDWARE: {
                const std::string devId = data.ReadString();
                const std::string dhId = data.ReadString();
                const std::string reqId = data.ReadString();

                reply.WriteInt32(DCAMERA_OK);

                sptr<IRemoteObject> cb;
                {
                    std::lock_guard<std::mutex> lock(mutex_);
                    cb = callbackRemote_;
                }
                if (cb != nullptr) {
                    MessageParcel cbData;
                    MessageParcel cbReply;
                    MessageOption cbOption;
                    cbData.WriteInterfaceToken(IDCameraSourceCallback::GetDescriptor());
                    cbData.WriteString(devId);
                    cbData.WriteString(dhId);
                    cbData.WriteString(reqId);
                    cbData.WriteInt32(DCAMERA_OK);
                    cbData.WriteString(std::string("mock_unregister_ok"));
                    (void)cb->SendRequest(IDCameraSourceCallback::NOTIFY_UNREG_RESULT, cbData, cbReply, cbOption);
                }
                return DCAMERA_OK;
            }
            case IDCameraSourceInterfaceCode::CAMERA_NOTIFY: {
                // devId/dhId/events
                (void)data.ReadString();
                (void)data.ReadString();
                (void)data.ReadString();
                reply.WriteInt32(DCAMERA_OK);
                return DCAMERA_OK;
            }
            case IDCameraSourceInterfaceCode::UPDATE_WORKMODE: {
                (void)data.ReadString();
                (void)data.ReadString();
                (void)data.ReadFileDescriptor();
                (void)data.ReadInt32();
                (void)data.ReadUint32();
                (void)data.ReadInt32();
                reply.WriteInt32(DCAMERA_OK);
                return DCAMERA_OK;
            }
            default:
                reply.WriteInt32(DCAMERA_NOT_FOUND);
                return DCAMERA_NOT_FOUND;
        }
    }

private:
    std::mutex mutex_;
    std::string initParams_;
    sptr<IRemoteObject> callbackRemote_;
};

/**
 * @brief 最小化的 Sink Service Mock
 *
 * 当前仅保证 SDK 侧调用不崩溃并返回成功码；如需更完整语义，可逐步增强。
 */
class MinimalSinkServiceMock : public IRemoteObject {
public:
    MinimalSinkServiceMock() : IRemoteObject(u"distributed_camera_sink") {
        DHLOGI("MinimalSinkServiceMock created");
    }

    virtual ~MinimalSinkServiceMock() {
        DHLOGI("MinimalSinkServiceMock destroyed");
    }

    int32_t GetObjectRefCount() override
    {
        return 1;
    }

    bool AddDeathRecipient(const sptr<DeathRecipient>& recipient) override
    {
        (void)recipient;
        return true;
    }

    bool RemoveDeathRecipient(const sptr<DeathRecipient>& recipient) override
    {
        (void)recipient;
        return true;
    }

    int Dump(int fd, const std::vector<std::u16string>& args) override
    {
        (void)fd;
        (void)args;
        return 0;
    }

    int32_t SendRequest(uint32_t code, MessageParcel& data, 
                       MessageParcel& reply, MessageOption& option) override {
        (void)option;
        DHLOGD("MinimalSinkServiceMock::SendRequest code: %u", code);
        (void)data.ReadInterfaceToken();

        switch (static_cast<IDCameraSinkInterfaceCode>(code)) {
            case IDCameraSinkInterfaceCode::INIT_SINK: {
                const std::string params = data.ReadString();
                const sptr<IRemoteObject> callbackObj = data.ReadRemoteObject();
                {
                    std::lock_guard<std::mutex> lock(mutex_);
                    initParams_ = params;
                    callbackRemote_ = callbackObj;
                }
                reply.WriteInt32(DCAMERA_OK);
                return DCAMERA_OK;
            }
            case IDCameraSinkInterfaceCode::RELEASE_SINK: {
                {
                    std::lock_guard<std::mutex> lock(mutex_);
                    callbackRemote_ = nullptr;
                    initParams_.clear();
                }
                reply.WriteInt32(DCAMERA_OK);
                return DCAMERA_OK;
            }
            default:
                // For current tests we only require a successful reply.
                reply.WriteInt32(DCAMERA_OK);
                return DCAMERA_OK;
        }
    }

private:
    std::mutex mutex_;
    std::string initParams_;
    sptr<IRemoteObject> callbackRemote_;
};

/**
 * @brief Service 自动注册类
 * 
 * 使用全局静态对象实现自动注册：
 * - 构造函数在动态库加载时执行，注册 Service
 * - 析构函数在动态库卸载时执行，清理资源
 */
class ServiceAutoRegister {
public:
    ServiceAutoRegister();
    ~ServiceAutoRegister();

private:
    // 保存 Service 对象的引用，防止被过早释放
    sptr<IRemoteObject> sourceService_;
    sptr<IRemoteObject> sinkService_;

#if defined(DCAMERA_BUILD_SOURCE_LIB)
    sptr<DistributedCameraSourceServiceEx> realSourceService_;
    bool useRealSourceService_ { false };
#endif
};

/**
 * @brief 构造函数 - 注册 Service
 * 
 * 在动态库加载时自动执行：
 * 1. 创建 MinimalSourceServiceMock 实例
 * 2. 创建 MinimalSinkServiceMock 实例
 * 3. 注册到 ServiceRegistry
 */
ServiceAutoRegister::ServiceAutoRegister()
    : sourceService_(nullptr), sinkService_(nullptr)
{
    DHLOGI("ServiceAutoRegister: Starting service registration...");

    try {
#if defined(DCAMERA_BUILD_SOURCE_LIB)
        // If requested, register the real Source Service implementation (so service-side key logs are visible).
        // Default to real service; allow forcing minimal mode for tests.
        // - DCAMERA_SOURCE_SERVICE_MODE=minimal -> force minimal mock
        // - DCAMERA_SOURCE_SERVICE_MODE=real    -> force real service
        // - (unset) -> default real service
        const char* mode = std::getenv("DCAMERA_SOURCE_SERVICE_MODE");
        if (mode != nullptr && std::string(mode) == "minimal") {
            useRealSourceService_ = false;
        } else {
            useRealSourceService_ = true;
        }
        if (useRealSourceService_) {
            DHLOGI("ServiceAutoRegister: Using real DistributedCameraSourceService (default; override with "
                   "DCAMERA_SOURCE_SERVICE_MODE=minimal)");
            realSourceService_ = new DistributedCameraSourceServiceEx(4803, true);
            if (realSourceService_ != nullptr) {
                realSourceService_->OnStart();
                sourceService_ = realSourceService_->AsObject();
            }
        } else {
            DHLOGI("ServiceAutoRegister: Using MinimalSourceServiceMock (env DCAMERA_SOURCE_SERVICE_MODE=minimal)");
        }
#endif

        // Default/mock path (or fallback if real service isn't enabled).
        if (sourceService_ == nullptr) {
            sourceService_ = new MinimalSourceServiceMock();
        }
        if (sourceService_ != nullptr) {
            bool ret = ServiceRegistry::GetInstance().RegisterService(4803, sourceService_);
            if (ret) {
                DHLOGI("ServiceAutoRegister: Source Service (SA 4803) registered successfully");
            } else {
                DHLOGE("ServiceAutoRegister: Failed to register Source Service (SA 4803)");
            }
        } else {
            DHLOGE("ServiceAutoRegister: Failed to create Source Service");
        }

        // 创建 Sink Service Mock
        sinkService_ = new MinimalSinkServiceMock();
        if (sinkService_ != nullptr) {
            bool ret = ServiceRegistry::GetInstance().RegisterService(4804, sinkService_);
            if (ret) {
                DHLOGI("ServiceAutoRegister: Sink Service (SA 4804) registered successfully");
            } else {
                DHLOGE("ServiceAutoRegister: Failed to register Sink Service (SA 4804)");
            }
        } else {
            DHLOGE("ServiceAutoRegister: Failed to create Sink Service Mock");
        }

        DHLOGI("ServiceAutoRegister: Service registration completed");
    } catch (const std::exception& e) {
        DHLOGE("ServiceAutoRegister: Exception during registration: %s", e.what());
    } catch (...) {
        DHLOGE("ServiceAutoRegister: Unknown exception during registration");
    }
}

/**
 * @brief 析构函数 - 清理资源
 * 
 * 在动态库卸载时自动执行：
 * 1. 从 ServiceRegistry 注销 Service
 * 2. 释放 Service 对象
 */
ServiceAutoRegister::~ServiceAutoRegister()
{
    DHLOGI("ServiceAutoRegister: Starting service cleanup...");

    try {
        // 注销 Source Service
        if (sourceService_ != nullptr) {
            ServiceRegistry::GetInstance().UnregisterService(4803);
#if defined(DCAMERA_BUILD_SOURCE_LIB)
            if (useRealSourceService_ && realSourceService_ != nullptr) {
                realSourceService_->OnStop();
                realSourceService_ = nullptr;
            }
#endif
            sourceService_ = nullptr;
            DHLOGI("ServiceAutoRegister: Source Service (SA 4803) unregistered");
        }

        // 注销 Sink Service
        if (sinkService_ != nullptr) {
            ServiceRegistry::GetInstance().UnregisterService(4804);
            sinkService_ = nullptr;
            DHLOGI("ServiceAutoRegister: Sink Service (SA 4804) unregistered");
        }

        DHLOGI("ServiceAutoRegister: Service cleanup completed");
    } catch (const std::exception& e) {
        DHLOGE("ServiceAutoRegister: Exception during cleanup: %s", e.what());
    } catch (...) {
        DHLOGE("ServiceAutoRegister: Unknown exception during cleanup");
    }
}

// 全局静态对象 - 在动态库加载时自动执行构造函数
// 这是实现自动注册的关键：
// - 对于 libdcamera_source.dylib，会在库加载时注册 Source Service
// - 对于 libdcamera_sink.dylib，会在库加载时注册 Sink Service
static ServiceAutoRegister g_serviceAutoRegister;

} // namespace DistributedHardware
} // namespace OHOS
