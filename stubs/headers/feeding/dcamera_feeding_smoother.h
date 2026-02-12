/*
 * DCamera Feeding Smoother Stub for macOS Mock
 *
 * OpenHarmony 分布式相机数据平滑处理器的 macOS 兼容层
 */

#ifndef STUBS_DCAMERA_FEEDING_SMOOTHER_H
#define STUBS_DCAMERA_FEEDING_SMOOTHER_H

#include <cstdint>
#include <vector>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

struct NodeBasicInfo {
    int32_t id;
    int32_t value;
};

class DCameraFeedingSmoother {
public:
    virtual ~DCameraFeedingSmoother() = default;
    virtual void Init() = 0;
    virtual void FeedInputData(const std::vector<std::vector<int32_t>>& datas) = 0;
    virtual void Reset() = 0;
};

} // namespace DistributedHardware
} // namespace OHOS
#endif

#endif // STUBS_DCAMERA_FEEDING_SMOOTHER_H
