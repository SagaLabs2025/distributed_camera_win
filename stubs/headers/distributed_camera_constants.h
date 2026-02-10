/*
 * Distributed Camera Constants - OpenHarmony Distributed Camera - macOS Mock
 *
 * 分布式相机常量定义
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_CONSTANTS_H
#define STUBS_DISTRIBUTED_CAMERA_CONSTANTS_H

#include <stdint.h>

namespace OHOS {
namespace DistributedHardware {

// HDF 分布式相机服务名称
constexpr const char* HDF_DCAMERA_EXT_SERVICE = "distributed_camera_service";

// 相机能力常量
constexpr int32_t DCAMERA_MAX_WIDTH = 4096;
constexpr int32_t DCAMERA_MAX_HEIGHT = 3072;

// 通道类型
constexpr int32_t SNAPSHOT_CHANNEL = 0;
constexpr int32_t CONTINUOUS_CHANNEL = 1;

// 状态常量
constexpr int32_t CAMERA_STATE_OK = 0;
constexpr int32_t CAMERA_STATE_ERROR = -1;

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DISTRIBUTED_CAMERA_CONSTANTS_H
