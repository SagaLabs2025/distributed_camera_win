/*
 * DistributedCameraConstants Stub for macOS Mock
 *
 * OpenHarmony 分布式相机常量的 macOS 兼容层
 * 
 * 重要：本文件不定义类型，直接使用源代码中的类型定义
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_CONSTANTS_H
#define STUBS_DISTRIBUTED_CAMERA_CONSTANTS_H

#include <cstdint>
#include <string>
#include <functional>

// 源码中的状态机定义（直接使用）
#ifdef __cplusplus
// 包含源码定义，优先于 stub 中的定义
#include "dcamera_source_state.h"

namespace OHOS {
namespace DistributedHardware {

// HDF 服务名称
#define HDF_DCAMERA_EXT_SERVICE "camera_service"
#define HDF_DCAMERA_SOURCE_SERVICE "distributed_camera_source"

// 版本标志
#define SEPARATE_SINK_VERSION 1

// 会话标志
#define CONTINUE_SESSION_FLAG "dataContinue"
#define SNAP_SHOT_SESSION_FLAG "dataSnapshot"

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_DISTRIBUTED_CAMERA_CONSTANTS_H
