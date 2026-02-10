/*
 * DCamera HDF Types - macOS Mock
 *
 * OpenHarmony 分布式相机 HDF 类型定义
 */

#ifndef STUBS_V1_1_DCAMERA_TYPES_H
#define STUBS_V1_1_DCAMERA_TYPES_H

#include <cstdint>
#include <string>
#include <vector>
#include <memory>

namespace OHOS {
namespace HDI {
namespace DistributedCamera {
namespace V1_1 {

// 前向声明，避免循环依赖
// DCameraSettings 在 DistributedHardware 命名空间中
namespace DistributedHardware {
    class DCameraSettings;
}

// 数据流类型
enum DCStreamType {
    DC_STREAM_TYPE_SNAPSHOT = 0,
    DC_STREAM_TYPE_CONTINUOUS = 1,
    DC_STREAM_TYPE_VIDEO = 2,
};

// 兼容性常量：用于源码中使用的整型常量
// 注意：这些是为了兼容性而添加的别名
constexpr int32_t SNAPSHOT_STREAM = static_cast<int32_t>(DC_STREAM_TYPE_SNAPSHOT);
constexpr int32_t CONTINUOUS_FRAME = static_cast<int32_t>(DC_STREAM_TYPE_CONTINUOUS);

// 相机状态
enum DCameraState {
    CAMERA_STATE_CLOSED = 0,
    CAMERA_STATE_OPENED = 1,
    CAMERA_STATE_CONFIGURED = 2,
    CAMERA_STREAMING = 3,
};

// 分辨率
struct DCResolution {
    int32_t width;
    int32_t height;

    DCResolution() : width(0), height(0) {}
    DCResolution(int32_t w, int32_t h) : width(w), height(h) {}
};

// 编码类型
enum DCEncodingType {
    ENCODING_TYPE_H264 = 0,
    ENCODING_TYPE_H265 = 1,
    ENCODING_TYPE_JPEG = 2,
};

// 类型别名：OpenHarmony 源码中使用 DCEncodeType
using DCEncodeType = DCEncodingType;

// DCStreamInfo - 流信息结构
struct DCStreamInfo {
    int32_t streamId_;
    int32_t width_;
    int32_t height_;
    int32_t dataspace_;
    int32_t encodeType_;
    DCStreamType streamType_;

    DCStreamInfo()
        : streamId_(0), width_(0), height_(0),
          dataspace_(0), encodeType_(0),
          streamType_(static_cast<DCStreamType>(0)) {}
};

// DCCaptureInfo - 捕获信息结构
struct DCCaptureInfo {
    int32_t captureId_;
    int32_t streamId_;
    int32_t width_;
    int32_t height_;
    int32_t dataspace_;
    int32_t encodeType_;
    DCStreamType streamType_;

    DCCaptureInfo()
        : captureId_(0), streamId_(0), width_(0), height_(0),
          dataspace_(0), encodeType_(0),
          streamType_(static_cast<DCStreamType>(0)) {}
};

} // namespace V1_1
} // namespace DistributedCamera
} // namespace HDI
} // namespace OHOS

#endif // STUBS_V1_1_DCAMERA_TYPES_H
