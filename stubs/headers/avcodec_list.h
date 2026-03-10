#ifndef STUBS_AVCODEC_LIST_H
#define STUBS_AVCODEC_LIST_H

#include <memory>
#include <string>

#include "avcodec_info.h"

namespace OHOS {
namespace MediaAVCodec {

class AVCodecList {
public:
    CapabilityData* GetCapability(const std::string& /*mime*/, bool /*isEncoder*/, AVCodecCategory /*category*/)
    {
        return nullptr;
    }
};

class AVCodecListFactory {
public:
    static std::shared_ptr<AVCodecList> CreateAVCodecList()
    {
        return nullptr;
    }
};

} // namespace MediaAVCodec
} // namespace OHOS

#endif // STUBS_AVCODEC_LIST_H

