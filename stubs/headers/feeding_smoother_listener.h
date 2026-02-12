/*
 * FeedingSmootherListener Interface Stub for macOS Mock
 *
 * OpenHarmony 数据平滑监听器接口的 macOS 兼容层
 */

#ifndef STUBS_FEEDING_SMOOTHER_LISTENER_H
#define STUBS_FEEDING_SMOOTHER_LISTENER_H

#include <cstdint>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

class FeedingSmootherListener {
public:
    virtual ~FeedingSmootherListener() = default;
    virtual void OnSmoothFinished() = 0;
    virtual void OnSmoothInputData(const std::vector<int32_t>& data) = 0;
};

} // namespace DistributedHardware
} // namespace OHOS
#endif

#endif // STUBS_FEEDING_SMOOTHER_LISTENER_H
