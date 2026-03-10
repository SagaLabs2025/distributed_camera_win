/*
 * IRemoteObject Mock Implementation for macOS
 *
 * OpenHarmony IRemoteObject 基类的 macOS Mock 实现
 * 支持 SDK 和 Service 在同一进程内的直接调用
 */

#include "iremote_object.h"
#include "iremote_broker.h"
#include "message_parcel.h"
#include "message_option.h"
#include "parcel.h"
#include "refbase.h"
#include "service_registry.h"
#include "distributed_hardware_log.h"

namespace OHOS {

namespace DistributedHardware {

// RefBase 虚函数的空实现
void RefBase::OnFirstStrongRef(const void* objectId)
{
    (void)objectId;
    // Mock: 空实现
}

void RefBase::OnLastStrongRef(const void* objectId)
{
    (void)objectId;
    // Mock: 空实现
}

void RefBase::OnLastWeakRef(const void* objectId)
{
    (void)objectId;
    // Mock: 空实现
}

bool RefBase::OnAttemptPromoted(const void* objectId)
{
    (void)objectId;
    return true;  // Mock: 总是成功
}

void RefBase::RefPtrCallback()
{
    // Mock: 空实现
}

void RefBase::IncStrongRef(const void* objectId)
{
    (void)objectId;
    // Mock: 空实现
}

void RefBase::DecStrongRef(const void* objectId)
{
    (void)objectId;
    // Mock: 空实现
}

RefBase::RefBase()
{
    // Mock: 空实现
}

RefBase::~RefBase()
{
    // Mock: 空实现
}

// IRemoteObject 构造函数
IRemoteObject::IRemoteObject(std::u16string descriptor)
{
    (void)descriptor;
    // Mock: 空实现
}

// IRemoteStub 构造函数
IRemoteStub::IRemoteStub(std::u16string descriptor)
    : IRemoteObject(descriptor)
{
    // Mock: 空实现
}

// IRemoteStub::SendRequest 实现（Stub 端不应该调用 SendRequest）
int IRemoteStub::SendRequest(uint32_t code, MessageParcel& data, 
                             MessageParcel& reply, MessageOption& option)
{
    (void)code;
    (void)data;
    (void)reply;
    (void)option;
    // Stub 端不应该调用 SendRequest
    return -1;
}

// IRemoteObject 虚函数的空实现
sptr<IRemoteBroker> IRemoteObject::AsInterface()
{
    return nullptr;  // Mock: 返回空指针
}

std::u16string IRemoteObject::GetInterfaceDescriptor()
{
    return std::u16string();  // Mock: 返回空字符串
}

int IRemoteObject::GetObjectRefCount()
{
    return 1;  // Mock: 返回默认引用计数
}

int IRemoteObject::Dump(int fd, const std::vector<std::u16string>& args)
{
    (void)fd;
    (void)args;
    return 0;  // Mock: 总是成功
}

bool IRemoteObject::AddDeathRecipient(const sptr<DeathRecipient>& recipient)
{
    (void)recipient;
    return true;  // Mock: 总是成功
}

bool IRemoteObject::RemoveDeathRecipient(const sptr<DeathRecipient>& recipient)
{
    (void)recipient;
    return true;  // Mock: 总是成功
}

bool IRemoteObject::IsProxyObject() const
{
    return false;  // Mock: 不是代理对象
}

bool IRemoteObject::CheckObjectLegality() const
{
    return true;  // Mock: 对象合法
}

bool IRemoteObject::IsObjectDead() const
{
    return false;  // Mock: 对象未死亡
}

bool IRemoteObject::Marshalling(Parcel& parcel) const
{
    (void)parcel;
    return true;  // Mock: 总是成功
}

// IRemoteObject::DeathRecipient 虚函数的空实现
void IRemoteObject::DeathRecipient::OnRemoteDied(const wptr<IRemoteObject>& object)
{
    (void)object;
    // Mock: 空实现
}

// Parcelable 构造函数
Parcelable::Parcelable()
{
    // Mock: 空实现
}

// ============================================================================
// RemoteObjectMock 实现
// ============================================================================

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
 * 2. 将 Service 对象转换为 IRemoteStub
 * 3. 直接调用 Service 的 OnRemoteRequest 方法
 * 4. 返回调用结果
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
        service = DistributedHardware::ServiceRegistry::GetInstance().GetService(saId_);
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
    
    // 2. 尝试转换为 IRemoteStub
    IRemoteStub* stub = dynamic_cast<IRemoteStub*>(service.GetRefPtr());
    if (stub == nullptr) {
        DHLOGE("Failed to cast service to IRemoteStub");
        return -1;  // ERR_INVALID_OPERATION
    }
    
    // 3. 直接调用 OnRemoteRequest（进程内直接调用）
    DHLOGD("Calling OnRemoteRequest on service stub");
    int result = stub->OnRemoteRequest(code, data, reply, option);
    
    DHLOGD("OnRemoteRequest returned: %d", result);
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
