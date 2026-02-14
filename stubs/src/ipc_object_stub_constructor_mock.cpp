/*
 * IPCObjectStub Constructor Mock Implementation for macOS
 *
 * OpenHarmony IPCObjectStub 构造函数的 macOS Mock 空实现
 */

#include "ipc_object_stub.h"

namespace OHOS {

// IPCObjectStub 构造函数
IPCObjectStub::IPCObjectStub(std::u16string descriptor, bool serialInvokeFlag)
    : IRemoteObject()
{
    (void)descriptor;
    (void)serialInvokeFlag;
    // Mock: 空实现
}

} // namespace OHOS
