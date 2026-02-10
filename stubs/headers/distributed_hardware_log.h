/*
 * Distributed Camera Log - OpenHarmony - macOS Stub
 *
 * 分布式硬件日志头文件
 * 此文件只定义日志相关的函数和宏，不包含常量定义
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_LOG_H
#define STUBS_DISTRIBUTED_CAMERA_LOG_H

#include <cstdio>
#include <cstdarg>
#include "distributed_camera_constants.h"

namespace OHOS {
namespace DistributedHardware {

// 使用 distributed_camera_constants.h 中定义的类型

// 日志级别定义（使用 constants.h 中的定义，避免重复）
// typedef enum {
//     DH_LOG_DEBUG,
//     DH_LOG_INFO,
//     DH_LOG_WARN,
//     DH_LOG_ERROR,
// } DHLogLevel;

// 日志函数实现
inline void DHLog(DHLogLevel logLevel, const char *fmt, ...) {
    (void)logLevel;
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    printf("\n");
    va_end(args);
}

// 日志宏
#define DHLOGD(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#define DHLOGI(fmt, ...) printf("[INFO] " fmt "\n", ##__VA_ARGS__)
#define DHLOGW(fmt, ...) printf("[WARN] " fmt "\n", ##__VA_ARGS__)
#define DHLOGE(fmt, ...) printf("[ERROR] " fmt "\n", ##__VA_ARGS__)

// 错误码定义（使用 constants.h 中的定义）
// constexpr int32_t DCAMERA_OK = 0;
// constexpr int32_t DCAMERA_ERROR = -1;
// constexpr int32_t DCAMERA_ERROR_INVALID_PARAM = -2;
// constexpr int32_t DCAMERA_ERROR_NULL_PTR = -3;

// 错误检查宏
#define CHECK_NULL_RETURN(cond, ret, ...)       \
    do {                                        \
        if ((cond)) {                           \
            return (ret);                       \
        }                                       \
    } while (0)

#define CHECK_NULL_FREE_RETURN(ptr, ret, root, ...) \
    do { \
        if ((ptr) == nullptr) { \
            if ((root) != nullptr) { \
                cJSON_Delete(root); \
            } \
            return (ret); \
        } \
    } while (0)

#define CHECK_AND_RETURN_RET_LOG(cond, ret, fmt, ...)   \
    do {                                                \
        if ((cond)) {                                   \
            DHLOGE(fmt, ##__VA_ARGS__);                 \
            return (ret);                               \
        }                                               \
    } while (0)

#define CHECK_AND_LOG(cond, fmt, ...)          \
    do {                                       \
        if ((cond)) {                          \
            DHLOGE(fmt, ##__VA_ARGS__);        \
            return;                            \
        }                                      \
    } while (0)

// 保持兼容性的别名定义（仅用于兼容源码引用）
// 这些宏现在在 distributed_camera_constants.h 中定义

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DISTRIBUTED_CAMERA_LOG_H
