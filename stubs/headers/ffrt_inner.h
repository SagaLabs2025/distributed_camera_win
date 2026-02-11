/*
 * FFRT Inner Event Stub for macOS Mock
 *
 * OpenHarmony FFRT 内核事件的 macOS 兼容层
 * 
 * 重要原则：使用源码中的定义，不重复定义
 */

#ifndef STUBS_FFRT_INNER_H
#define STUBS_FFRT_INNER_H

#include <cstdint>
#include <string>

// 使用源码中的常量定义（如果可用）
#ifdef USE_SOURCE_DEFINITIONS
#include "dcamera_source_state.h"
#endif

#ifdef __cplusplus
namespace OHOS {
namespace AppExecFwk {

// 使用源码中的事件类型定义
#ifdef USE_SOURCE_DEFINITIONS
typedef DCameraSourceState DCameraEventType;
#else
// 简化的枚举定义（临时，待源码定义可用时替换）
enum DCameraEventType {
    EVENT_START = 0,
    EVENT_COMPLETE = 1,
    EVENT_ERROR = 2,
};
#endif

// 使用源码中的事件通知定义
#ifdef USE_SOURCE_DEFINITIONS
const std::string REGISTER_SERVICE_NOTIFY = "regSvcNotify";
const std::string UNREGISTER_SERVICE_NOTIFY = "unregSvcNotify";
const std::string SINK_START_EVENT = "sinkStartEvent";
const std::string SOURCE_START_EVENT = "sourceStartEvent";
#else
// 简化的字符串定义（临时，待源码定义可用时替换）
constexpr auto REGISTER_SERVICE_NOTIFY = "regSvcNotify";
constexpr auto UNREGISTER_SERVICE_NOTIFY = "unregSvcNotify";
constexpr auto SINK_START_EVENT = "sinkStartEvent";
constexpr auto SOURCE_START_EVENT = "sourceStartEvent";
#endif

} // namespace AppExecFwk
} // namespace OHOS

#endif // STUBS_FFRT_INNER_H
