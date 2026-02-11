/*
 * DCamera TimeStatistician - OpenHarmony Stub 实现
 */

#include "dcamera_time_statistician.h"
#include "distributed_hardware_log.h"

namespace OHOS {
namespace DistributedHardware {

void DCameraTimeStatistician::CalProcessTime(const std::shared_ptr<IFeedableData>& data)
{
    (void)data;
    DHLOGD("CalProcessTime - stub implementation");
}

int64_t DCameraTimeStatistician::GetRecvTime()
{
    DHLOGD("GetRecvTime - stub implementation");
    return 0;
}

int64_t DCameraTimeStatistician::GetAverRecv2FeedTime()
{
    DHLOGD("GetAverRecv2FeedTime - stub implementation");
    return 0;
}

void DCameraTimeStatistician::CalAverFeedInterval(const int64_t feedTime)
{
    (void)feedTime;
    DHLOGD("CalAverFeedInterval - stub implementation");
}

void DCameraTimeStatistician::CalAverTimeStampInterval(const int64_t timeStamp)
{
    (void)timeStamp;
    DHLOGD("CalAverTimeStampInterval - stub implementation");
}

} // namespace DistributedHardware
} // namespace OHOS
