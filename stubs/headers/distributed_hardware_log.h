/*
 * Distributed Hardware Log Stub for macOS
 *
 * 目标：
 * - 在测试工程里尽量复用 OpenHarmony distributed camera 源码仓的日志宏风格：
 *   DHLOG* 会在日志中携带 tag / function / file / line，并使用 `%{public}` 扩展格式。
 *
 * 说明：
 * - 这里优先包含源码仓 `common/include/utils/distributed_hardware_log.h`；
 * - `%{public}` / `%{private}` 的格式替换由 `stubs/src/hilog_mock.cpp::OH_LOG_Print` 负责。
 */

#ifndef DCAMERA_TEST_DISTRIBUTED_HARDWARE_LOG_STUB_H
#define DCAMERA_TEST_DISTRIBUTED_HARDWARE_LOG_STUB_H

#include "cJSON_compat.h"

#if __has_include("utils/distributed_hardware_log.h")
#include "utils/distributed_hardware_log.h"
#else
// Fallback: minimal DHLOG macros (no file/func), but keep buildable.
#include "hilog/log.h"

#ifndef DH_LOG_TAG
#define DH_LOG_TAG "DHFWK"
#endif

namespace OHOS {
namespace DistributedHardware {
#undef LOG_TAG
#define LOG_TAG "DCAMERA"

#define DHLOGD(fmt, ...) HILOG_DEBUG(LOG_CORE, "[%{public}s][%{public}s]:" fmt, DH_LOG_TAG, __FUNCTION__, ##__VA_ARGS__)
#define DHLOGI(fmt, ...) HILOG_INFO(LOG_CORE, "[%{public}s][%{public}s]:" fmt, DH_LOG_TAG, __FUNCTION__, ##__VA_ARGS__)
#define DHLOGW(fmt, ...) HILOG_WARN(LOG_CORE, "[%{public}s][%{public}s]:" fmt, DH_LOG_TAG, __FUNCTION__, ##__VA_ARGS__)
#define DHLOGE(fmt, ...) HILOG_ERROR(LOG_CORE, "[%{public}s][%{public}s]:" fmt, DH_LOG_TAG, __FUNCTION__, ##__VA_ARGS__)
} // namespace DistributedHardware
} // namespace OHOS
#endif

#endif // DCAMERA_TEST_DISTRIBUTED_HARDWARE_LOG_STUB_H
