/*
 * DCameraStreamDataProcessProducer Stub for macOS Mock
 *
 * OpenHarmony 数据流处理生产者接口的 macOS 兼容层
 */

#ifndef STUBS_DCAMERA_STREAM_DATA_PROCESS_PRODUCER_H
#define STUBS_DCAMERA_STREAM_DATA_PROCESS_PRODUCER_H

#include <cstdint>
#include <vector>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

class DCameraStreamDataProcessProducer {
public:
    virtual ~DCameraStreamDataProcessProducer() = default;
    virtual void CreateProducer(const std::shared_ptr<class IFeedingSmoother>& smoother) = 0;
    virtual void ReleaseProducer() = 0;
};

} // namespace DistributedHardware
} // namespace OHOS
#endif

#endif // STUBS_DCAMERA_STREAM_DATA_PROCESS_PRODUCER_H
