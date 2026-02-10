/*
 * HiTrace Meter - OpenHarmony Trace - macOS Mock
 *
 * 性能追踪的 macOS 空实现
 */

#ifndef STUBS_HITRACE_METER_H
#define STUBS_HITRACE_METER_H

#include <cstdint>

namespace OHOS {
namespace HiviewDFX {
namespace HiTrace {

// 追踪标签定义
constexpr uint64_t HITRACE_TAG_DISTRIBUTED_CAMERA = 1 << 10;

} // namespace HiTrace
} // namespace HiviewDFX
} // namespace OHOS

// 追踪宏（空实现）
#define HITRACE_METER_NAME(label, value) do {} while(0)
#define START_TRACE_SYNC(name) do {} while(0)
#define FINISH_TRACE_SYNC(name) do {} while(0)

#endif // STUBS_HITRACE_METER_H
