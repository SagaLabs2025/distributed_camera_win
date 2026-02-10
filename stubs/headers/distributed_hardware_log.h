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

// 日志函数实现（直接定义在这里）
inline void DHLog(int32_t logLevel, const char *fmt, ...) {
    (void)logLevel;
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    printf("\n");
    va_end(args);
}

// 日志宏
#define DHLOGD(fmt, ...) DHLog(DH_LOG_DEBUG, fmt, ##__VA_ARGS__)
#define DHLOGI(fmt, ...) DHLog(DH_LOG_INFO, fmt, ##__VA_ARGS__)
#define DHLOGW(fmt, ...) DHLog(DH_LOG_WARN, fmt, ##__VA_ARGS__)
#define DHLOGE(fmt, ...) DHLog(DH_LOG_ERROR, fmt, ##__VA_ARGS__)

// 错误检查宏
#define CHECK_NULL_RETURN(cond, ret) \
    do { \
        if ((cond)) { \
            return (ret); \
        } \
    } while (0)

#define CHECK_NULL_FREE_RETURN(ptr, ret, root) \
    do { \
        if ((ptr) == nullptr) { \
            if ((root) != nullptr) { \
                cJSON_Delete(root); \
            } \
            return (ret); \
        } \
    } while (0)

#define CHECK_AND_RETURN_RET_LOG(cond, ret, fmt) \
    do { \
        if ((cond)) { \
            DHLOGE(fmt, ##__VA_ARGS__); \
            return (ret); \
        } \
    } while (0)

#define CHECK_AND_LOG(cond, fmt) \
    do { \
        if ((cond)) { \
            DHLOGE(fmt, ##__VA_ARGS__); \
            return; \
        } \
    } while (0)

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DISTRIBUTED_CAMERA_LOG_H
