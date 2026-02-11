/*
 * IDistributedCameraSink Interface Stub for macOS Mock
 *
 * OpenHarmony 分布式相机 Sink 接口的 macOS 兼容层
 */

#ifndef STUBS_IDISTRIBUTED_CAMERA_SINK_H
#define STUBS_IDISTRIBUTED_CAMERA_SINK_H

#include <string>
#include <vector>
#include "ipc/iremote_broker.h"
#include "ipc/iremote_object.h"

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

/**
 * @brief 分布式相机 Sink 参数结构
 */
struct SinkParam {
    std::string devId;
    std::string dhId;
};

/**
 * @brief 分布式相机 Sink 接口
 * 继承 IRemoteBroker 以获得引用计数和 AsObject() 方法
 */
class IDistributedCameraSink : public virtual IRemoteBroker {
public:
    virtual ~IDistributedCameraSink() = default;

    /**
     * @brief 获取接口描述符
     * @return 描述符
     */
    std::u16string GetDescriptor() override
    {
        return u"IDistributedCameraSink";
    }

    /**
     * @brief 初始化 Sink
     * @param params 参数
     * @return 成功返回 0
     */
    virtual int32_t InitSink(const std::string& params)
    {
        (void)params;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 释放 Sink
     * @return 成功返回 0
     */
    virtual int32_t ReleaseSink()
    {
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 注册分布式硬件
     */
    virtual int32_t RegisterDistributedHardware(const std::string& devId,
                                                   const std::string& dhId,
                                                   const std::string& reqId,
                                                   const SinkParam& param)
    {
        (void)devId; (void)dhId; (void)reqId; (void)param;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 注销分布式硬件
     */
    virtual int32_t UnregisterDistributedHardware(const std::string& devId,
                                                     const std::string& dhId,
                                                     const std::string& reqId)
    {
        (void)devId; (void)dhId; (void)reqId;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 获取远程对象（IRemoteBroker 实现）
     * @return 远程对象原始指针
     */
    IRemoteObject* AsObject() override
    {
        return nullptr;  // Mock: 返回空指针
    }

    /**
     * @brief 获取常量远程对象
     * @return 常量远程对象原始指针
     */
    const IRemoteObject* AsObject() const override
    {
        return nullptr;  // Mock: 返回空指针
    }

    /**
     * @brief 增加强引用计数（sptr 兼容）
     */
    void IncStrongRef(const void* objectId) override
    {
        (void)objectId;
    }

    /**
     * @brief 减少强引用计数（sptr 兼容）
     */
    void DecStrongRef(const void* objectId) override
    {
        (void)objectId;
    }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IDISTRIBUTED_CAMERA_SINK_H
