/*
 * DCameraTypes - OpenHarmony Distributed Camera - macOS Stub
 *
 * 相机类型定义的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_TYPES_H
#define STUBS_DCAMERA_TYPES_H

#include <string>
#include <vector>

namespace OHOS {
namespace HDI {
namespace DistributedCamera {
namespace V1_1 {

/**
 * @brief Enumerates distributed camera metadata updating types.
 */
enum DCSettingsType {
    UPDATE_METADATA = 0,
    ENABLE_METADATA = 1,
    DISABLE_METADATA = 2,
    METADATA_RESULT = 3,
    SET_FLASH_LIGHT = 4,
    FPS_RANGE = 5,
    UPDATE_FRAME_METADATA = 6,
};

/**
 * @brief Enumerates return values of HDIs.
 */
enum DCamRetCode {
    SUCCESS = 0,
    CAMERA_BUSY = 1,
    INVALID_ARGUMENT = 2,
    METHOD_NOT_SUPPORTED = 3,
    CAMERA_OFFLINE = 4,
    EXCEED_MAX_NUMBER = 5,
    DEVICE_NOT_INIT = 6,
    FAILED = 7,
};

/**
 * @brief Enumerates encoding types of stream data.
 */
enum DCEncodeType {
    ENCODE_TYPE_NULL = 0,
    ENCODE_TYPE_H264 = 1,
    ENCODE_TYPE_H265 = 2,
    ENCODE_TYPE_JPEG = 3,
    ENCODE_TYPE_MPEG4_ES = 4,
};

/**
 * @brief Enumerates distributed camera inner stream types.
 */
enum DCStreamType {
    CONTINUOUS_FRAME = 0,
    SNAPSHOT_FRAME = 1,
};

/**
 * @brief Distributed hardware device base info.
 */
struct DHBase {
    std::string deviceId_;
    std::string dhId_;
};

/**
 * @brief The control settings of distributed camera device.
 */
struct DCameraSettings {
    int type_;
    std::string value_;
};

/**
 * @brief Defines inner stream information of distributed camera,
 * which is used to pass configuration parameters during stream creation.
 */
struct DCStreamInfo {
    int streamId_;
    int width_;
    int height_;
    int stride_;
    int format_;
    int dataspace_;
    int encodeType_;
    int type_;
    int mode_;
};

/**
 * @brief Defines information about an inner capture request of distributed camera.
 */
struct DCCaptureInfo {
    int streamIds_[10];
    int width_;
    int height_;
    int stride_;
    int format_;
    int dataspace_;
    int isCapture_;
    int encodeType_;
    int type_;
    DCameraSettings captureSettings_[10];
};

} // namespace V1_1
} // namespace DistributedCamera
} // namespace HDI
} // namespace OHOS

#endif // STUBS_DCAMERA_TYPES_H
