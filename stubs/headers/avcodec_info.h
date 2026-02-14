/*
 * AVCodec Info Stub for macOS Mock
 *
 * OpenHarmony AVCodec Info 的 macOS 兼容层
 */

#ifndef STUBS_AVCODEC_INFO_H
#define STUBS_AVCODEC_INFO_H

#include <string>
#include <vector>
#include <map>

namespace OHOS {
namespace Media {

enum class CodecMimeType {
    VIDEO_H264,
    VIDEO_H265,
    VIDEO_MPEG4,
    AUDIO_AAC,
    AUDIO_FLAC,
};

struct CapabilityData {
    std::string mimeType;
    int32_t maxWidth = 0;
    int32_t maxHeight = 0;
    int32_t maxFrameRate = 0;
};

class AVCodecInfo {
public:
    static std::vector<CapabilityData> GetCapability(const std::string& mime, bool isEncoder)
    {
        (void)mime;
        (void)isEncoder;
        return std::vector<CapabilityData>();  // Mock: 返回空列表
    }
};

} // namespace Media
} // namespace OHOS

#endif // STUBS_AVCODEC_INFO_H
