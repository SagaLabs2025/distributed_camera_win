/*
 * TimeStatistician - OpenHarmony - macOS Stub
 *
 * 时间统计类
 */

#ifndef STUBS_TIME_STATISTICIAN_H
#define STUBS_TIME_STATISTICIAN_H

#include "ifeedable_data.h"
#include <memory>

namespace OHOS {
namespace DistributedHardware {

class TimeStatistician {
public:
    virtual ~TimeStatistician() = default;
    virtual void CalProcessTime(const std::shared_ptr<IFeedableData>& data);
    void CalAverFeedInterval(const int64_t feedTime);
    void CalAverTimeStampInterval(const int64_t timeStamp);

public:
    int64_t GetAverFeedInterval();
    int64_t GetAverTimeStampInterval();
    int64_t GetFeedInterval();
    int64_t GetTimeStampInterval();

public:
    uint32_t feedIndex_ = 0;
    int64_t averFeedInterval_ = 0;
    int64_t lastFeedTime_ = 0;
    int64_t feedTime_ = 0;
    int64_t feedIntervalSum_ = 0;
    int64_t feedInterval_ = 0;

    uint32_t timeStampIndex_ = 0;
    int64_t averTimeStampInterval_ = 0;
    int64_t lastTimeStamp_ = 0;
    int64_t timeStamp_ = 0;
    int64_t timeStampIntervalSum_ = 0;
    int64_t timeStampInterval_ = 0;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_TIME_STATISTICIAN_H
