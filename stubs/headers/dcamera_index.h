#ifndef STUBS_DCAMERA_INDEX_H
#define STUBS_DCAMERA_INDEX_H
#include <string>

namespace OHOS {
namespace DistributedHardware {

class DCameraIndex {
public:
    DCameraIndex() = default;
    explicit DCameraIndex(std::string devId, std::string dhId) : devId_(devId), dhId_(dhId) {}
    ~DCameraIndex() = default;

    bool operator == (const DCameraIndex& index) const
    {
        return this->devId_ == index.devId_ && this->dhId_ == index.dhId_;
    }

    bool operator < (const DCameraIndex& index) const
    {
        return (this->devId_ + this->dhId_) < (index.devId_ + index.dhId_);
    }

    std::string devId_;
    std::string dhId_;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_INDEX_H
