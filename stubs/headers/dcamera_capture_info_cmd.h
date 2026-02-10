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

// DCameraSettings - 相机设置
struct DCameraSettings {
    int32_t settingId_;
    std::string value_;

    DCameraSettings() : settingId_(0) {}
    ~DCameraSettings() = default;
};

// DCameraCaptureInfo - 相机捕获信息
struct DCameraCaptureInfo {
    int32_t width_;
    int32_t height_;
    int32_t format_;
    int32_t dataspace_;
    bool isCapture_;
    int32_t encodeType_;
    int32_t streamType_;
    std::vector<std::shared_ptr<DCameraSettings>> captureSettings_;

    DCameraCaptureInfo() 
        : width_(0), height_(0), format_(0), dataspace_(0), 
          isCapture_(false), encodeType_(0), streamType_(0) {}
    ~DCameraCaptureInfo() = default;
};

// DCameraCaptureInfoCmd - 相机捕获信息命令
class DCameraCaptureInfoCmd {
public:
    std::string type_;
    std::string dhId_;
    std::string command_;
    std::vector<std::shared_ptr<DCameraCaptureInfo>> value_;
    int32_t sceneMode_;
    int32_t userId_;
    uint64_t tokenId_;
    std::string accountId_;

public:
    int32_t Marshal(std::string& jsonStr);
    int32_t Unmarshal(const std::string& jsonStr);

    DCameraCaptureInfoCmd() 
        : sceneMode_(0), userId_(0), tokenId_(0) {}
    ~DCameraCaptureInfoCmd() = default;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_CAPTURE_INFO_CMD_H
