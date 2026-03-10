/*
 * DCameraSinkOutput Mock Implementation for macOS
 *
 * OpenHarmony DCameraSinkOutput 的 macOS Mock 空实现
 */

#include <string>
#include <vector>
#include <memory>
#include "v1_1/dcamera_types.h"

namespace OHOS {
namespace DistributedHardware {

// 前向声明
class DataBuffer;

class DCameraSinkOutput {
public:
    void OnSessionError(OHOS::HDI::DistributedCamera::V1_1::DCStreamType streamType,
                        int eventType,
                        int eventReason,
                        const std::string& detail);
    void OnSessionState(OHOS::HDI::DistributedCamera::V1_1::DCStreamType streamType, int state);
    void OnDataReceived(OHOS::HDI::DistributedCamera::V1_1::DCStreamType streamType,
                        std::vector<std::shared_ptr<DataBuffer>>& buffers);
    void OnPhotoResult(std::shared_ptr<DataBuffer>& buffer);
    void OnVideoResult(std::shared_ptr<DataBuffer>& buffer);
};

// 实现
void DCameraSinkOutput::OnSessionError(OHOS::HDI::DistributedCamera::V1_1::DCStreamType streamType,
                                       int eventType,
                                       int eventReason,
                                       const std::string& detail)
{
    (void)streamType;
    (void)eventType;
    (void)eventReason;
    (void)detail;
    // Mock: 空实现
}

void DCameraSinkOutput::OnSessionState(OHOS::HDI::DistributedCamera::V1_1::DCStreamType streamType, int state)
{
    (void)streamType;
    (void)state;
    // Mock: 空实现
}

void DCameraSinkOutput::OnDataReceived(OHOS::HDI::DistributedCamera::V1_1::DCStreamType streamType,
                                       std::vector<std::shared_ptr<DataBuffer>>& buffers)
{
    (void)streamType;
    (void)buffers;
    // Mock: 空实现
}

void DCameraSinkOutput::OnPhotoResult(std::shared_ptr<DataBuffer>& buffer)
{
    (void)buffer;
    // Mock: 空实现
}

void DCameraSinkOutput::OnVideoResult(std::shared_ptr<DataBuffer>& buffer)
{
    (void)buffer;
    // Mock: 空实现
}

} // namespace DistributedHardware
} // namespace OHOS
