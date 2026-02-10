/*
 * Distributed Camera Log - OpenHarmony - macOS Stub
 *
 * 分布式硬件日志的 macOS 空实现
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_LOG_H
#define STUBS_DISTRIBUTED_CAMERA_LOG_H

#include <cstdio>
#include <cstdarg>

namespace OHOS {
namespace DistributedHardware {

// 日志级别定义
typedef enum {
    DH_LOG_DEBUG = 0,
    DH_LOG_INFO = 1,
    DH_LOG_WARN = 2,
    DH_LOG_ERROR = 3,
} DHLogLevel;

// 错误码定义（简化版，只定义基本错误码）
constexpr int32_t DCAMERA_OK = 0;
constexpr int32_t DCAMERA_ERROR = -1;
constexpr int32_t DCAMERA_ERROR_INVALID_PARAM = -2;
constexpr int32_t DCAMERA_ERROR_NULL_PTR = -3;

// 相机特定错误码
constexpr int32_t DCAMERA_ERR_CAMERA_NOT_FOUND = -100;
constexpr int32_t DCAMERA_ERR_CAMERA_OPEN_FAILED = -101;
constexpr int32_t DCAMERA_ERR_CAMERA_CLOSE_FAILED = -102;
constexpr int32_t DCAMERA_ERR_CAMERA_CONFIG_FAILED = -103;
constexpr int32_t DCAMERA_ERR_CAMERA_CAPTURE_FAILED = -104;

// 通道错误码
constexpr int32_t DCAMERA_ERR_CHANNEL_NOT_FOUND = -200;
constexpr int32_t DCAMERA_ERR_CHANNEL_OPEN_FAILED = -201;
constexpr int32_t DCAMERA_ERR_CHANNEL_CLOSE_FAILED = -202;
constexpr int32_t DCAMERA_ERR_CHANNEL_SEND_FAILED = -203;
constexpr int32_t DCAMERA_ERR_CHANNEL_RECV_FAILED = -204;

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
