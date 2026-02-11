/*
 * DistributedCameraConstants Stub for macOS Mock
 *
 * OpenHarmony 分布式相机常量的 macOS 兼容层
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_CONSTANTS_H
#define STUBS_DISTRIBUTED_CAMERA_CONSTANTS_H

#include <cstdint>
#include <string>
#include <functional>

#ifdef __cplusplus
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

// 服务状态常量
constexpr int32_t DCAMERA_SRV_STATE_NOT_START = 0;
constexpr int32_t DCAMERA_SRV_STATE_RUNNING = 1;
constexpr int32_t DCAMERA_SRV_STATE_STOPPING = 2;

// 类型别名（使用 int32_t）
using DCameraSourceState = int32_t;
using DCameraServiceState = int32_t;

// 生命周期回调类型
using LifecycleCallback = std::function<void(const std::string&, const std::string&)>;

// 事件类型枚举
enum DCameraEventType {
    DCAMERA_EVENT_OPEN_CHANNEL_ERROR = 100,
    DCAMERA_EVENT_CLOSE_CHANNEL_ERROR,
    DCAMERA_EVENT_CONFIG_STREAMS_ERROR,
    DCAMERA_EVENT_RELEASE_STREAMS_ERROR,
    DCAMERA_EVENT_START_CAPTURE_ERROR,
    DCAMERA_EVENT_STOP_CAPTURE_ERROR,
    DCAMERA_EVENT_UPDATE_SETTINGS_ERROR,
};

// 事件结果常量
enum DCameraEventResult {
    DCAMERA_EVENT_SUCCESS = 0,
    DCAMERA_EVENT_FAILED = 1,
};

// 消息类型常量
constexpr int32_t DCAMERA_OPERATION = 0;
constexpr int32_t DCAMERA_MESSAGE = 1;

// 通道事件常量
enum DCameraChannelEvent {
    DCAMERA_EVENT_CHANNEL_CONNECTED = 200,
    DCAMERA_EVENT_CHANNEL_DISCONNECTED,
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_DISTRIBUTED_CAMERA_CONSTANTS_H
