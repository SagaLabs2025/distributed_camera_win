/*
 * IPC Broker Macros for macOS Mock
 *
 * Mock 宏定义，替代 OpenHarmony 原生宏
 */

#ifndef STUBS_IREMOTE_BROKER_MACROS_H
#define STUBS_IREMOTE_BROKER_MACROS_H

#include <string>
#include <cstring>
#include "ipc_types.h"

#ifdef __cplusplus

namespace OHOS {

// 重新定义 DECLARE_INTERFACE_DESCRIPTOR 宏，处理 UTF-16 字符串字面量
// 返回 std::u16string 而不是 std::string
#ifdef DECLARE_INTERFACE_DESCRIPTOR
#undef DECLARE_INTERFACE_DESCRIPTOR
#endif

#define DECLARE_INTERFACE_DESCRIPTOR(Descriptor) \
    virtual std::u16string GetDescriptor() override { \
        return Descriptor; \
    }

// BrokerDelegator 模板 - 用于代理注册
template<typename T>
class BrokerDelegator {
public:
    BrokerDelegator() = default;
    ~BrokerDelegator() = default;
};

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IREMOTE_BROKER_MACROS_H
