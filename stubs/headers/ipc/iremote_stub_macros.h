/*
 * IPC Stub Macros for macOS Mock
 *
 * OpenHarmony IPC Stub 宏定义的 macOS 兼容层
 */

#ifndef STUBS_IREMOTE_STUB_MACROS_H
#define STUBS_IREMOTE_STUB_MACROS_H

#include <string>
#include "ipc_types.h"

#ifdef __cplusplus

// Mock 宏定义 - 避免使用 UTF-16 字符串字面量
// 在测试环境中使用普通字符串，然后转换

#undef DECLARE_INTERFACE_DESCRIPTOR
#define DECLARE_INTERFACE_DESCRIPTOR(Descriptor) \
    static std::string GetDescriptor() { \
        return std::string(Descriptor); \
    }

// 用于接口的简化宏
#define IPC_INTERFACE_PROXY
#define IPC_INTERFACE_STUB

#endif // __cplusplus

#endif // STUBS_IREMOTE_STUB_MACROS_H
