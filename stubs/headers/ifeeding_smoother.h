/*
 * IFeedingSmoother - OpenHarmony - macOS Stub
 *
 * 平滑处理器接口
 */

#ifndef STUBS_IFEEDING_SMOOTHER_H
#define STUBS_IFEEDING_SMOOTHER_H

#include <memory>
#include "ifeedable_data.h"
#include "smoother_constants.h"

namespace OHOS {
namespace DistributedHardware {

// 平滑处理器监听器
class FeedingSmootherListener {
public:
    virtual ~FeedingSmootherListener() = default;
    virtual int32_t OnSmoothFinished(const std::shared_ptr<IFeedableData>& data) = 0;
};

// 平滑处理器接口
class IFeedingSmoother {
public:
    virtual ~IFeedingSmoother() = default;
    
    virtual void PushData(const std::shared_ptr<IFeedableData>& data) = 0;
    virtual int32_t StartSmooth() = 0;
    virtual void StopSmooth() = 0;
    virtual void SetListener(std::shared_ptr<FeedingSmootherListener>& listener) = 0;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_IFEEDING_SMOOTHER_H
