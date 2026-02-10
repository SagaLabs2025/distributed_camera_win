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

// 日志标签定义
constexpr int32_t DH_LOG_TAG = 0xD004101;

// 日志级别定义
typedef enum {
    DH_LOG_DEBUG = 0,
    DH_LOG_INFO = 1,
    DH_LOG_WARN = 2,
    DH_LOG_ERROR = 3,
} DHLogLevel;

// 基础错误码
constexpr int32_t DCAMERA_OK = 0;
constexpr int32_t DCAMERA_ERROR = -1;
constexpr int32_t DCAMERA_ERROR_INVALID_PARAM = -2;
constexpr int32_t DCAMERA_ERROR_NULL_PTR = -3;
constexpr int32_t DCAMERA_ERROR_NOT_READY = -4;
constexpr int32_t DCAMERA_ERROR_TIMEOUT = -5;
constexpr int32_t DCAMERA_ERROR_NO_MEMORY = -6;
constexpr int32_t DCAMERA_ERROR_BUSY = -7;
constexpr int32_t DCAMERA_ERROR_NOT_FOUND = -8;
constexpr int32_t DCAMERA_ERROR_ALREADY_EXISTS = -9;
constexpr int32_t DCAMERA_ERROR_PERMISSION_DENIED = -10;

// HDF 错误码基础
constexpr int32_t ERR_DH_CAMERA_BASE = 0x05C20000;
constexpr int32_t DCAMERA_BAD_VALUE = ERR_DH_CAMERA_BASE + 2;  // 957473662
constexpr int32_t DCAMERA_BAD_TYPE = ERR_DH_CAMERA_BASE + 3;

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
