/*
 * DCameraStreamDataProcessProducer Mock Implementation for macOS
 *
 * OpenHarmony DCameraStreamDataProcessProducer 的 macOS Mock 空实现
 */

#include <string>
#include <memory>
#include "v1_1/dcamera_types.h"

// 前向声明
namespace OHOS {
namespace DistributedHardware {
class DataBuffer;
struct WorkModeParam;
}
}

namespace OHOS {
namespace DistributedHardware {

class DCameraStreamDataProcessProducer {
public:
    // Constructor with references
    DCameraStreamDataProcessProducer(const std::string& devId, const std::string& dhId, 
                                     int streamId, OHOS::HDI::DistributedCamera::V1_1::DCStreamType streamType);
    
    // Constructor with values (for std::make_shared)
    DCameraStreamDataProcessProducer(std::string devId, std::string dhId, 
                                     int streamId, OHOS::HDI::DistributedCamera::V1_1::DCStreamType streamType);
    
    virtual ~DCameraStreamDataProcessProducer();
    
    int32_t Start();
    int32_t Stop();
    int32_t FeedStream(const std::shared_ptr<DataBuffer>& buffer);
    int32_t UpdateProducerWorkMode(const WorkModeParam& param);
};

// 实现
DCameraStreamDataProcessProducer::DCameraStreamDataProcessProducer(
    const std::string& devId, const std::string& dhId, 
    int streamId, OHOS::HDI::DistributedCamera::V1_1::DCStreamType streamType)
{
    (void)devId;
    (void)dhId;
    (void)streamId;
    (void)streamType;
}

DCameraStreamDataProcessProducer::DCameraStreamDataProcessProducer(
    std::string devId, std::string dhId, 
    int streamId, OHOS::HDI::DistributedCamera::V1_1::DCStreamType streamType)
{
    (void)devId;
    (void)dhId;
    (void)streamId;
    (void)streamType;
}

DCameraStreamDataProcessProducer::~DCameraStreamDataProcessProducer() = default;

int32_t DCameraStreamDataProcessProducer::Start()
{
    return 0;  // Mock: 总是成功
}

int32_t DCameraStreamDataProcessProducer::Stop()
{
    return 0;  // Mock: 总是成功
}

int32_t DCameraStreamDataProcessProducer::FeedStream(const std::shared_ptr<DataBuffer>& buffer)
{
    (void)buffer;
    return 0;  // Mock: 总是成功
}

int32_t DCameraStreamDataProcessProducer::UpdateProducerWorkMode(const WorkModeParam& param)
{
    (void)param;
    return 0;  // Mock: 总是成功
}

} // namespace DistributedHardware
} // namespace OHOS
