/*
 * DCamera HDF Constants Stub for macOS Mock
 *
 * OpenHarmony 分布式相机 HDF 常量的 macOS 兼容层
 */

#ifndef STUBS_DCAMERA_HDF_CONSTANTS_H
#define STUBS_DCAMERA_HDF_CONSTANTS_H

#include <cstdint>

#ifdef __cplusplus

// HDF 服务名称
#define HDF_DCAMERA_EXT_SERVICE "camera_service"
#define HDF_DCAMERA_SOURCE_SERVICE "distributed_camera_source"

// 版本标志
#define SEPARATE_SINK_VERSION 1

// 服务状态管理常量
#define SCM_IDLE 0
#define SCM_PREPARE 1
#define SCM_START 2
#define SCM_STOP 3

// 会话标志
#define CONTINUE_SESSION_FLAG "dataContinue"
#define SNAP_SHOT_SESSION_FLAG "dataSnapshot"

#endif // __cplusplus

#endif // STUBS_DCAMERA_HDF_CONSTANTS_H
