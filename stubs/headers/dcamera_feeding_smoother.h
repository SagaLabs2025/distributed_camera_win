/*
 * DCamera FeedingSmoother - OpenHarmony 简化版 Stub
 *
 * 相机平滑处理器 - 避免复杂依赖
 */

#ifndef STUBS_DCAMERA_FEEDING_SMOOTHER_H
#define STUBS_DCAMERA_FEEDING_SMOOTHER_H

#include <memory>
#include "ifeeding_smoother.h"

namespace OHOS {
namespace DistributedHardware {

// 别名
typedef TimeStatistician DCameraTimeStatistician;

// 简化版 DCamera 平滑处理器
class DCameraFeedingSmoother : public IFeedingSmoother {
public:
    DCameraFeedingSmoother() = default;
    virtual ~DCameraFeedingSmoother() override = default;
    
    virtual void PrepareSmooth() override {
        // 简化版：无操作
    }
    
    virtual void InitBaseline(const int64_t timeStampBaseline, const int64_t clockBaseline) override {
        // 简化版：无操作
        (void)timeStampBaseline;
        (void)clockBaseline;
    }
    
    virtual void InitTimeStatistician() override {
        // 简化版：创建空统计器
        dCameraStatistician_ = std::make_shared<DCameraTimeStatistician>();
    }
    
    virtual int32_t NotifySmoothFinished(const std::shared_ptr<IFeedableData>& data) override {
        // 简化版：直接返回成功
        (void)data;
        return 0;
    }
    
private:
    std::shared_ptr<DCameraTimeStatistician> dCameraStatistician_ = nullptr;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_FEEDING_SMOOTHER_H
