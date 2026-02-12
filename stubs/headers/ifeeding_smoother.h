/*
 * IFeedingSmoother Interface Stub for macOS Mock
 *
 * OpenHarmony 数据平滑处理器接口的 macOS 兼容层
 */

#ifndef STUBS_IFEEDING_SMOOTHER_H
#define STUBS_IFEEDING_SMOOTHER_H

#include <vector>
#include <cstdint>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

class IFeedingSmoother {
public:
    virtual ~IFeedingSmoother() = default;
    virtual void Init() = 0;
    virtual void FeedInputData(const std::vector<std::vector<int32_t>>& datas) = 0;
    virtual void Reset() = 0;
};

} // namespace DistributedHardware
} // namespace OHOS
#endif

#endif // STUBS_IFEEDING_SMOOTHER_H
