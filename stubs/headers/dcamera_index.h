/*
 * DCameraIndex - OpenHarmony Distributed Camera - macOS Mock
 *
 * 分布式相机索引的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_INDEX_H
#define STUBS_DCAMERA_INDEX_H

#include <string>

namespace OHOS {
namespace DistributedHardware {

// DCameraIndex - 相机索引
struct DCameraIndex {
    std::string devId_;
    std::string dhId_;

    DCameraIndex() = default;
    ~DCameraIndex() = default;

    bool operator<(const DCameraIndex& other) const {
        if (devId_ != other.devId_) {
            return devId_ < other.devId_;
        }
        return dhId_ < other.dhId_;
    }

    bool operator==(const DCameraIndex& other) const {
        return devId_ == other.devId_ && dhId_ == other.dhId_;
    }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_INDEX_H
