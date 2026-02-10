/*
 * FeedingSmootherListener - OpenHarmony - macOS Stub
 *
 * 平滑处理器监听器
 */

#ifndef STUBS_FEEDING_SMOOTHER_LISTENER_H
#define STUBS_FEEDING_SMOOTHER_LISTENER_H

#include <memory>
#include "ifeedable_data.h"

namespace OHOS {
namespace DistributedHardware {

// IFeedableDataProducer - 数据生产者接口
class IFeedableDataProducer {
public:
    virtual ~IFeedableDataProducer() = default;
    virtual void OnSmoothFinished(const std::shared_ptr<IFeedableData>& data) = 0;
};

// 平滑处理器监听器
class FeedingSmootherListener {
public:
    virtual ~FeedingSmootherListener() = default;
    virtual int32_t OnSmoothFinished(const std::shared_ptr<IFeedableData>& data) = 0;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_FEEDING_SMOOTHER_LISTENER_H
