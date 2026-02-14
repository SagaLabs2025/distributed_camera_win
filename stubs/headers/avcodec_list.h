/*
 * AVCodec List Stub for macOS Mock
 *
 * OpenHarmony AVCodec List 的 macOS 兼容层
 */

#ifndef STUBS_AVCODEC_LIST_H
#define STUBS_AVCODEC_LIST_H

#include <string>
#include <vector>

namespace OHOS {
namespace Media {

class AVCodecList {
public:
    static std::vector<std::string> GetCodecNameList()
    {
        return std::vector<std::string>();  // Mock: 返回空列表
    }
};

} // namespace Media
} // namespace OHOS

#endif // STUBS_AVCODEC_LIST_H
