/*
 * DCamera FeedingSmoother - OpenHarmony Stub 实现
 * 完全空实现，避免复杂依赖
 */

#include "dcamera_feeding_smoother.h"
#include "distributed_hardware_log.h"

namespace OHOS {
namespace DistributedHardware {

void DCameraFeedingSmoother::PrepareSmooth()
{
    DHLOGD("PrepareSmooth - empty stub");
}

void DCameraFeedingSmoother::InitBaseline(const int64_t timeStampBaseline, const int64_t clockBaseline)
{
    (void)timeStampBaseline;
    (void)clockBaseline;
    DHLOGD("InitBaseline - empty stub");
}

void DCameraFeedingSmoother::InitTimeStatistician()
{
    dCameraStatistician_ = std::make_shared<DCameraTimeStatistician>();
    DHLOGD("InitTimeStatistician - empty stub");
}

} // namespace DistributedHardware
} // namespace OHOS
