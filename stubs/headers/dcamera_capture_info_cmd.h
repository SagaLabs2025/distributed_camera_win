/*
 * DCamera Capture Info Command - OpenHarmony Distributed Camera - macOS Mock
 *
 * 相机捕获信息命令的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_CAPTURE_INFO_CMD_H
#define STUBS_DCAMERA_CAPTURE_INFO_CMD_H

#include <string>
#include <vector>

namespace OHOS {
namespace DistributedHardware {

// DCameraCaptureInfo - 相机捕获信息
struct DCameraCaptureInfo {
    int32_t captureId_;
    std::string streamId_;

    DCameraCaptureInfo() : captureId_(0) {}
    ~DCameraCaptureInfo() = default;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_CAPTURE_INFO_CMD_H
