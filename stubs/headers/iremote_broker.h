/*
 * IRemoteBroker - OpenHarmony IPC - macOS Mock
 *
 * IPC 远程代理接口的 macOS 空实现
 */

#ifndef STUBS_IREMOTE_BROKER_H
#define STUBS_IREMOTE_BROKER_H

#include <string>

// IRemoteBroker - 远程代理基类（在 OHOS 顶层命名空间）
namespace OHOS {
class IRemoteBroker {
public:
    virtual ~IRemoteBroker() = default;
};

// 接口描述符宏
#define DECLARE_INTERFACE_DESCRIPTOR(descriptor)

} // namespace OHOS

#endif // STUBS_IREMOTE_BROKER_H
