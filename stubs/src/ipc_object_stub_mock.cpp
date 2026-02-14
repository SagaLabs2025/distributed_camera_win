/*
 * IPC Object Stub Mock Implementation for macOS
 *
 * OpenHarmony IPCObjectStub 类的 macOS Mock 空实现
 * 提供所有虚函数的空实现以解决链接问题
 */

#include "ipc_object_stub.h"
#include "message_parcel.h"
#include "message_option.h"
#include "iremote_object.h"

namespace OHOS {

// IPCObjectStub 虚函数的空实现

int IPCObjectStub::SendRequest(uint32_t code, MessageParcel& data, 
                                MessageParcel& reply, MessageOption& option)
{
    (void)code;
    (void)data;
    (void)reply;
    (void)option;
    return 0;  // Mock: 总是成功
}

int IPCObjectStub::OnRemoteDump(uint32_t code, MessageParcel& data,
                                 MessageParcel& reply, MessageOption& option)
{
    (void)code;
    (void)data;
    (void)reply;
    (void)option;
    return 0;  // Mock: 总是成功
}

int IPCObjectStub::ProcessProto(uint32_t code, MessageParcel& data,
                                 MessageParcel& reply, MessageOption& option)
{
    (void)code;
    (void)data;
    (void)reply;
    (void)option;
    return 0;  // Mock: 总是成功
}

void IPCObjectStub::OnLastStrongRef(const void* objectId)
{
    (void)objectId;
    // Mock: 空实现
}

int IPCObjectStub::OnRemoteRequest(uint32_t code, MessageParcel& data,
                                    MessageParcel& reply, MessageOption& option)
{
    (void)code;
    (void)data;
    (void)reply;
    (void)option;
    return 0;  // Mock: 总是成功
}

void IPCObjectStub::OnFirstStrongRef(const void* objectId)
{
    (void)objectId;
    // Mock: 空实现
}

bool IPCObjectStub::AddDeathRecipient(const sptr<IRemoteObject::DeathRecipient>& recipient)
{
    (void)recipient;
    return true;  // Mock: 总是成功
}

int IPCObjectStub::GetObjectRefCount()
{
    return 1;  // Mock: 返回固定值
}

bool IPCObjectStub::RemoveDeathRecipient(const sptr<IRemoteObject::DeathRecipient>& recipient)
{
    (void)recipient;
    return true;  // Mock: 总是成功
}

int IPCObjectStub::Dump(int fd, const std::vector<std::u16string>& args)
{
    (void)fd;
    (void)args;
    return 0;  // Mock: 总是成功
}

int IPCObjectStub::GetAndSaveDBinderData(int cmd, uint32_t handle)
{
    (void)cmd;
    (void)handle;
    return 0;  // Mock: 总是成功
}

int IPCObjectStub::DBinderClearServiceState(uint32_t code, MessageParcel& data,
                                             MessageParcel& reply, MessageOption& option)
{
    (void)code;
    (void)data;
    (void)reply;
    (void)option;
    return 0;  // Mock: 总是成功
}

int IPCObjectStub::GetObjectType() const
{
    return 0;  // Mock: 返回默认类型
}

// 析构函数
IPCObjectStub::~IPCObjectStub()
{
    // Mock: 空实现
}

} // namespace OHOS
