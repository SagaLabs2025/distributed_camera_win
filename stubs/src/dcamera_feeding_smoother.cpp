/*
 * DCamera FeedingSmoother - OpenHarmony Stub 实现
 */

#include "dcamera_feeding_smoother.h"
#include "ifeeding_smoother.h"
#include "distributed_hardware_log.h"

namespace OHOS {
namespace DistributedHardware {

void DCameraFeedingSmoother::PrepareSmooth()
{
    DHLOGD("PrepareSmooth - stub implementation");
}

void DCameraFeedingSmoother::InitBaseline(const int64_t timeStampBaseline, const int64_t clockBaseline)
{
    (void)timeStampBaseline;
    (void)clockBaseline;
    DHLOGD("InitBaseline - stub implementation");
}

void DCameraFeedingSmoother::InitTimeStatistician()
{
    statistician_ = std::make_shared<DCameraTimeStatistician>();
    DHLOGD("InitTimeStatistician - stub implementation");
}

} // namespace DistributedHardware
} // namespace OHOS
