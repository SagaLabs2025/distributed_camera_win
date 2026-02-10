/*
 * Distributed Camera Error Codes - OpenHarmony Distributed Camera - macOS Mock
 *
 * 分布式相机错误码定义
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_ERRNO_H
#define STUBS_DISTRIBUTED_CAMERA_ERRNO_H

#include <int32.h>

namespace OHOS {
namespace DistributedHardware {

// 错误码定义
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
