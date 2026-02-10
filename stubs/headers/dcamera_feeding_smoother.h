/*
 * DCamera FeedingSmoother - OpenHarmony - macOS Stub
 *
 * 相机平滑处理器
 */

#ifndef STUBS_DCAMERA_FEEDING_SMOOTHER_H
#define STUBS_DCAMERA_FEEDING_SMOOTHER_H

#include "ifeeding_smoother.h"
#include "time_statistician.h"

namespace OHOS {
namespace DistributedHardware {

// 别名
typedef TimeStatistician DCameraTimeStatistician;

// DCamera 平滑处理器
class DCameraFeedingSmoother : public IFeedingSmoother {
public:
    virtual ~DCameraFeedingSmoother() = default;
    virtual void PrepareSmooth() = 0;
    virtual void InitBaseline(const int64_t timeStampBaseline, const int64_t clockBaseline) = 0;
    virtual void InitTimeStatistician() = 0;
    virtual int32_t NotifySmoothFinished(const std::shared_ptr<IFeedableData>& data) = 0;

private:
    constexpr static uint8_t DYNAMIC_BALANCE_THRE = 3;
    constexpr static int32_t SMOOTH_BUFFER_TIME_US = 20000;
    constexpr static uint32_t AVER_INTERVAL_DIFF_THRE_US = 2000;
    constexpr static uint32_t FEED_ONCE_DIFF_THRE_US = 10000;
    std::shared_ptr<DCameraTimeStatistician> dCameraStatistician_ = nullptr;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_FEEDING_SMOOTHER_H
