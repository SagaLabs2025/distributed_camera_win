/*
 * MessageParcel Mock Implementation for macOS
 *
 * OpenHarmony MessageParcel 类的 macOS Mock 空实现
 */

#include "message_parcel.h"
#include "iremote_object.h"
#include "parcel.h"

namespace OHOS {

// Parcel 基类的空实现
Parcel::Parcel()
{
    // Mock: 空实现
}

Parcel::~Parcel()
{
    // Mock: 空实现
}

bool Parcel::WriteInt32(int32_t value)
{
    (void)value;
    return true;  // Mock: 总是成功
}

int32_t Parcel::ReadInt32()
{
    return 0;  // Mock: 返回0
}

uint32_t Parcel::ReadUint32()
{
    return 0;  // Mock: 返回0
}

bool Parcel::ReadBool()
{
    return false;  // Mock: 返回false
}

bool Parcel::WriteString(const std::string& value)
{
    (void)value;
    return true;  // Mock: 总是成功
}

const std::string Parcel::ReadString()
{
    return std::string();  // Mock: 返回空字符串
}

// MessageParcel 构造函数和析构函数
MessageParcel::MessageParcel()
{
    // Mock: 空实现
}

MessageParcel::~MessageParcel()
{
    // Mock: 空实现
}

// MessageParcel 方法的空实现
sptr<IRemoteObject> MessageParcel::ReadRemoteObject()
{
    return nullptr;  // Mock: 返回空指针
}

int MessageParcel::ReadFileDescriptor()
{
    return -1;  // Mock: 返回无效文件描述符
}

std::u16string MessageParcel::ReadInterfaceToken()
{
    return std::u16string();  // Mock: 返回空字符串
}

bool MessageParcel::WriteInterfaceToken(std::u16string token)
{
    (void)token;
    return true;  // Mock: 总是成功
}

// MessageOption 构造函数
MessageOption::MessageOption(int flags, int waitTime)
{
    (void)flags;
    (void)waitTime;
    // Mock: 空实现
}

} // namespace OHOS
