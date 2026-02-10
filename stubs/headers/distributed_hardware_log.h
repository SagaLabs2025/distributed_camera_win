/*
 * Distributed Camera Log - OpenHarmony - macOS Stub
 *
 * 分布式硬件日志的 macOS 空实现
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_LOG_H
#define STUBS_DISTRIBUTED_CAMERA_LOG_H

#include <cstdio>
#include <cstdarg>
#include "distributed_camera_constants.h"

namespace OHOS {
namespace DistributedHardware {

// 使用 distributed_camera_constants.h 中定义的日志级别
// 这里不重复定义 DHLogLevel 以避免冲突

// 日志函数实现
inline void DHLog(DHLogLevel logLevel, const char *fmt, ...) {
    (void)logLevel;
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    printf("\n");
    va_end(args);
}

// 日志宏（使用 distributed_camera_constants.h 中定义的日志级别）
#define DHLOGD(fmt, ...) DHLog(DH_LOG_DEBUG, fmt, ##__VA_ARGS__)
#define DHLOGI(fmt, ...) DHLog(DH_LOG_INFO, fmt, ##__VA_ARGS__)
#define DHLOGW(fmt, ...) DHLog(DH_LOG_WARN, fmt, ##__VA_ARGS__)
#define DHLOGE(fmt, ...) DHLog(DH_LOG_ERROR, fmt, ##__VA_ARGS__)

// 兼容性别名（保持与源码一致）
#define distributed_hardware_log distributed_hardware_log

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DISTRIBUTED_CAMERA_LOG_H
