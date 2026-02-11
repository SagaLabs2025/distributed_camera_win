/*
 * FFRT Inner Event Stub for macOS Mock
 *
 * OpenHarmony FFRT 内核事件的 macOS 兼容层
 * 
 * 重要原则：使用源码中的定义，不重复定义或简化
 */

#ifndef STUBS_FFRT_INNER_H
#define STUBS_FFRT_INNER_H

#include <cstdint>
#include <string>

#ifdef __cplusplus
namespace OHOS {
namespace AppExecFwk {

// 直接使用源码中的字符串常量定义（const std::string 类型）
const std::string REGISTER_SERVICE_NOTIFY = "regSvcNotify";
const std::string UNREGISTER_SERVICE_NOTIFY = "unregSvcNotify";
const std::string SINK_START_EVENT = "sinkStartEvent";
const std::string SOURCE_START_EVENT = "srcStartEvent";

} // namespace AppExecFwk
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_FFRT_INNER_H
