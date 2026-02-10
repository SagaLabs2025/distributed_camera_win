/*
 * IFeedableData - OpenHarmony - macOS Stub
 *
 * 可供平滑处理的数据接口
 */

#ifndef STUBS_IFEEDABLE_DATA_H
#define STUBS_IFEEDABLE_DATA_H

#include <cstdint>
#include <memory>

namespace OHOS {
namespace DistributedHardware {

class IFeedableData {
public:
    virtual ~IFeedableData() = default;
    virtual int64_t GetTimeStamp() = 0;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_IFEEDABLE_DATA_H
