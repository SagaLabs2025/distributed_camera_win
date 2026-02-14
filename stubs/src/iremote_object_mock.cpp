/*
 * IRemoteObject Mock Implementation for macOS
 *
 * OpenHarmony IRemoteObject 基类的 macOS Mock 空实现
 */

#include "iremote_object.h"
#include "iremote_broker.h"
#include "message_parcel.h"
#include "message_option.h"
#include "parcel.h"
#include "refbase.h"

namespace OHOS {

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

} // namespace OHOS
