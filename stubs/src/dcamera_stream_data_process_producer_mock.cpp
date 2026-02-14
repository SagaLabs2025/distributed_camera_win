/*
 * DCameraStreamDataProcessProducer Mock Implementation for macOS
 *
 * OpenHarmony DCameraStreamDataProcessProducer 的 macOS Mock 空实现
 */

#include <string>
#include <memory>
#include "data_buffer.h"
#include "dcamera_hdf_constants.h"

namespace OHOS {
namespace DistributedHardware {

// 前向声明
struct WorkModeParam;

class DCameraStreamDataProcessProducer {
public:
    DCameraStreamDataProcessProducer(const std::string& devId, const std::string& dhId, 
                                     int streamId, int streamType)
    {
        (void)devId;
        (void)dhId;
        (void)streamId;
        (void)streamType;
    }
    
    virtual ~DCameraStreamDataProcessProducer() = default;
    
    int32_t Start()
    {
        return 0;  // Mock: 总是成功
    }
    
    int32_t Stop()
    {
        return 0;  // Mock: 总是成功
    }
    
    int32_t FeedStream(const std::shared_ptr<DataBuffer>& buffer)
    {
        (void)buffer;
        return 0;  // Mock: 总是成功
    }
    
    int32_t UpdateProducerWorkMode(const WorkModeParam& param)
    {
        (void)param;
        return 0;  // Mock: 总是成功
    }
};

} // namespace DistributedHardware
} // namespace OHOS
