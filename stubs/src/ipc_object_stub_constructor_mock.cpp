/*
 * IPCObjectStub Constructor Mock Implementation for macOS
 *
 * OpenHarmony IPCObjectStub 构造函数的 macOS Mock 空实现
 */

#include "ipc_object_stub.h"

namespace OHOS {

// IPCObjectStub 构造函数
IPCObjectStub::IPCObjectStub(std::u16string descriptor, bool serialInvokeFlag)
    : IRemoteObject(std::move(descriptor)), serialInvokeFlag_(serialInvokeFlag)
{
}

} // namespace OHOS
