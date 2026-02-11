/*
 * IFeedingSmoother - OpenHarmony Stub 实现
 */

#include "ifeeding_smoother.h"
#include "distributed_hardware_log.h"

namespace OHOS {
namespace DistributedHardware {

void IFeedingSmoother::PushData(const std::shared_ptr<IFeedableData>& data)
{
    (void)data;
    DHLOGD("PushData - stub implementation");
}

int32_t IFeedingSmoother::StartSmooth()
{
    DHLOGD("StartSmooth - stub implementation");
    return 0;
}

void IFeedingSmoother::StopSmooth()
{
    DHLOGD("StopSmooth - stub implementation");
}

void IFeedingSmoother::SetListener(std::shared_ptr<FeedingSmootherListener>& listener)
{
    (void)listener;
    DHLOGD("SetListener - stub implementation");
}

} // namespace DistributedHardware
} // namespace OHOS
