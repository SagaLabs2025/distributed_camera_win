#ifndef STUBS_AVCODEC_INFO_H
#define STUBS_AVCODEC_INFO_H

#include <string>

namespace OHOS {
namespace MediaAVCodec {

struct CapabilityData {
    std::string mimeType;
};

enum class AVCodecCategory {
    AVCODEC_HARDWARE = 0,
};

struct CodecMimeType {
    static constexpr const char* VIDEO_AVC = "video/avc";
    static constexpr const char* VIDEO_HEVC = "video/hevc";
};

} // namespace MediaAVCodec
} // namespace OHOS

#endif // STUBS_AVCODEC_INFO_H

