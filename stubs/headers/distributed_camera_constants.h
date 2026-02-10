/*
 * Distributed Camera Constants - OpenHarmony - macOS Stub
 *
 * 分布式相机常量定义（简化版）
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_CONSTANTS_H
#define STUBS_DISTRIBUTED_CAMERA_CONSTANTS_H

#include <cstdint>
#include <string>

namespace OHOS {
namespace DistributedHardware {

// 日志标签定义
constexpr int32_t DH_LOG_TAG = 0xD004101;

// 相机服务状态
typedef enum {
    DCAMERA_SRV_STATE_NOT_START,
    DCAMERA_SRV_STATE_RUNNING
} DCameraServiceState;

// 授权状态
typedef enum {
    DCAMERA_AUTHORIZATION_DEFAULT = 0,
    DCAMERA_AUTHORIZATION_AGREE = 1,
    DCAMERA_AUTHORIZATION_REJECT = 2,
    DCAMERA_AUTHORIZATION_TIMEOUT = 3,
} AuthorizationState;

// 事件类型
typedef enum {
    DCAMERA_MESSAGE = 0,
    DCAMERA_OPERATION = 1,
    DCAMERA_SINK_STOP = 2,
    DCAMERE_GETFULLCAP = 3,
} DCameraEventType;

// 相机事件结果
typedef enum {
    DCAMERA_EVENT_CHANNEL_DISCONNECTED = 0,
    DCAMERA_EVENT_CHANNEL_CONNECTED = 1,
    DCAMERA_EVENT_CAMERA_SUCCESS = 2,
    DCAMERA_EVENT_SINK_STOP = 3,
    DCAMERA_EVENT_CAMERA_ERROR = -1,
    DCAMERA_EVENT_OPEN_CHANNEL_ERROR = -2,
    DCAMERA_EVENT_CLOSE_CHANNEL_ERROR = -3,
    DCAMERA_EVENT_CONFIG_STREAMS_ERROR = -4,
    DCAMERA_EVENT_RELEASE_STREAMS_ERROR = -5,
    DCAMERA_EVENT_START_CAPTURE_ERROR = -6,
    DCAMERA_EVENT_STOP_CAPTURE_ERROR = -7,
    DCAMERA_EVENT_UPDATE_SETTINGS_ERROR = -8,
    DCAMERA_EVENT_DEVICE_ERROR = -9,
    DCAMERA_EVENT_DEVICE_PREEMPT = -10,
    DCAMERA_EVENT_DEVICE_IN_USE = -11,
    DCAMERA_EVENT_NO_PERMISSION = -12,
} DCameraEventResult;

// 相机格式
typedef enum {
    OHOS_CAMERA_FORMAT_INVALID = 0,
    OHOS_CAMERA_FORMAT_RGBA_8888,
    OHOS_CAMERA_FORMAT_YCBCR_420_888,
    OHOS_CAMERA_FORMAT_YCRCB_420_SP,
    OHOS_CAMERA_FORMAT_YCBCR_420_SP,
    OHOS_CAMERA_FORMAT_JPEG,
    OHOS_CAMERA_FORMAT_YCBCB_P010,
} DCameraFormat;

// 相机位置
const std::string CAMERA_POSITION_BACK = "BACK";
const std::string CAMERA_POSITION_FRONT = "FRONT";
const std::string CAMERA_POSITION_UNSPECIFIED = "UNSPECIFIED";

// 相机模式
const std::string CAMERA_FORMAT_PREVIEW = "Preview";
const std::string CAMERA_FORMAT_VIDEO = "Video";
const std::string CAMERA_FORMAT_PHOTO = "Photo";

// 相机能力
const uint32_t DCAMERA_MAX_NUM = 1;
const uint32_t DCAMERA_PRODUCER_ONE_MINUTE_MS = 1000;
const uint32_t DCAMERA_PRODUCER_FPS_DEFAULT = 30;
const uint32_t DCAMERA_MAX_RECV_DATA_LEN = 104857600;
const uint16_t DCAMERA_MAX_RECV_EXT_LEN = 65535;

// 相机服务 ID
const uint32_t DISTRIBUTED_HARDWARE_CAMERA_SOURCE_SA_ID = 4803;
const uint32_t DISTRIBUTED_HARDWARE_CAMERA_SINK_SA_ID = 4804;

// 相机包名
const std::string DCAMERA_PKG_NAME = "ohos.dhardware.dcamera";
const std::string CAMERA_PROTOCOL_VERSION_KEY = "ProtocolVer";
const std::string CAMERA_PROTOCOL_VERSION_VALUE = "1.0";

// 基础错误码（简化版，避免与distributed_hardware_log.h冲突）
constexpr int32_t DCAMERA_OK = 0;
constexpr int32_t DCAMERA_ERROR = -1;
constexpr int32_t DCAMERA_ERROR_INVALID_PARAM = -2;
constexpr int32_t DCAMERA_ERROR_NULL_PTR = -3;

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DISTRIBUTED_CAMERA_CONSTANTS_H
