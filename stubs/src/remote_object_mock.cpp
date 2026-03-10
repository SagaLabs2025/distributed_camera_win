/*
 * RemoteObjectMock Implementation for macOS
 *
 * RemoteObjectMock 的实现，支持 SDK 和 Service 在同一进程内的直接调用
 */

#include "remote_object_mock.h"
#include "iremote_stub.h"
#include "message_parcel.h"
#include "message_option.h"
#include "service_registry.h"
#include "distributed_hardware_log.h"

namespace OHOS {
namespace DistributedHardware {

/**
 * @brief RemoteObjectMock 构造函数（通过 SA ID）
 * @param saId System Ability ID
 */
RemoteObjectMock::RemoteObjectMock(int32_t saId)
    : IRemoteObject(u""), saId_(saId), targetService_(nullptr)
{
    DHLOGD("RemoteObjectMock created with SA ID: %d", saId);
}

/**
 * @brief RemoteObjectMock 构造函数（直接持有 Service 对象）
 * @param service Service 对象的智能指针
 */
RemoteObjectMock::RemoteObjectMock(const sptr<IRemoteObject>& service)
    : IRemoteObject(u""), saId_(-1), targetService_(service)
{
    DHLOGD("RemoteObjectMock created with direct service reference");
}

/**
 * @brief 发送 IPC 请求（Mock 实现）
 * 
 * 在 Mock 模式下，此方法不会真正发送 IPC 请求，而是：
 * 1. 从 ServiceRegistry 获取目标 Service 对象（如果未直接持有）
 * 2. 直接调用 Service 的 SendRequest 方法（对于 Stub，会调用 OnRemoteRequest）
 * 3. 返回调用结果
 * 
 * 这样实现了进程内的直接函数调用，避免了真实的 IPC 开销。
 */
int RemoteObjectMock::SendRequest(uint32_t code, MessageParcel& data, 
                                  MessageParcel& reply, MessageOption& option)
{
    DHLOGD("RemoteObjectMock::SendRequest called with code: %u", code);
    
    // 1. 获取目标 Service 对象
    sptr<IRemoteObject> service = targetService_;
    
    if (service == nullptr && saId_ >= 0) {
        // 从 ServiceRegistry 获取
        service = ServiceRegistry::GetInstance().GetService(saId_);
        if (service == nullptr) {
            DHLOGE("Service not found for SA ID: %d", saId_);
            return -1;  // ERR_DEAD_OBJECT
        }
        DHLOGD("Service found in registry for SA ID: %d", saId_);
    }
    
    if (service == nullptr) {
        DHLOGE("Target service is null");
        return -1;  // ERR_DEAD_OBJECT
    }
    
    // 2. 直接调用 Service 的 SendRequest（对于 Stub，会调用 OnRemoteRequest）
    // 注意：OpenHarmony 的 IRemoteStub 模板类会在 SendRequest 中调用 OnRemoteRequest
    DHLOGD("Calling SendRequest on service object");
    int result = service->SendRequest(code, data, reply, option);
    
    DHLOGD("SendRequest returned: %d", result);
    return result;
}

/**
 * @brief 设置目标 Service 对象
 * @param service Service 对象的智能指针
 */
void RemoteObjectMock::SetTargetService(const sptr<IRemoteObject>& service)
{
    targetService_ = service;
    DHLOGD("Target service set");
}

/**
 * @brief 获取目标 Service 对象
 * @return Service 对象的智能指针
 */
sptr<IRemoteObject> RemoteObjectMock::GetTargetService() const
{
    return targetService_;
}

} // namespace DistributedHardware
} // namespace OHOS
