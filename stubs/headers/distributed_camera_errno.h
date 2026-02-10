/*
 * Distributed Camera Error Codes - OpenHarmony - macOS Stub
 *
 * 分布式相机错误码定义
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_ERRNO_H
#define STUBS_DISTRIBUTED_CAMERA_ERRNO_H

#include <cstdint>

namespace OHOS {
namespace DistributedHardware {

// 日志级别定义
typedef enum {
    DH_LOG_DEBUG,
    DH_LOG_INFO,
    DH_LOG_WARN,
    DH_LOG_ERROR,
} DHLogLevel;

// 日志函数（简化版，避免与distributed_hardware_log.h冲突）
inline void DHLog(DHLogLevel logLevel, const char *fmt, ...) {
    (void)logLevel;
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    printf("\n");
    va_end(args);
}

// 日志宏（简化版）
#define DHLOGD(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#define DHLOGI(fmt, ...) printf("[INFO] " fmt "\n", ##__VA_ARGS__)
#define DHLOGW(fmt, ...) printf("[WARN] " fmt "\n", ##__VA_ARGS__)
#define DHLOGE(fmt, ...) printf("[ERROR] " fmt "\n", ##__VA_ARGS__)

// 错误码定义（使用distributed_hardware_log.h中的定义）
// 这里不重复定义 DCAMERA_OK, DCAMERA_ERROR 等
// 以避免与 distributed_hardware_log.h 冲突

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

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DISTRIBUTED_CAMERA_ERRNO_H
