/*
 * DCameraSinkController Stub Implementation for macOS
 *
 * 这是 dcamera_sink_controller.cpp 的 stub 实现，用于替代真实的实现
 */

#include "dcamera_sink_controller.h"
#include <memory>
#include <vector>
#include <string>

namespace OHOS {
namespace DistributedHardware {

DCameraSinkController::DCameraSinkController(std::shared_ptr<ICameraSinkAccessControl>& accessControl,
                                             const sptr<IDCameraSinkCallback>& callback)
{
    (void)accessControl;
    (void)callback;
    // Mock: 空实现
}

DCameraSinkController::~DCameraSinkController()
{
    // Mock: 空实现
}

int32_t DCameraSinkController::Init(std::vector<DCameraIndex>& indexs)
{
    (void)indexs;
    return 0;  // Mock: 成功
}

int32_t DCameraSinkController::UnInit()
{
    return 0;  // Mock: 成功
}

int32_t DCameraSinkController::StartCapture(std::vector<std::shared_ptr<DCameraCaptureInfo>>& captureInfos, int mode)
{
    (void)captureInfos;
    (void)mode;
    return 0;  // Mock: 成功
}

int32_t DCameraSinkController::StopCapture()
{
    return 0;  // Mock: 成功
}

int32_t DCameraSinkController::CloseChannel()
{
    return 0;  // Mock: 成功
}

int32_t DCameraSinkController::DCameraNotify(std::shared_ptr<DCameraEvent>& events)
{
    (void)events;
    return 0;  // Mock: 成功
}

int32_t DCameraSinkController::GetCameraInfo(std::shared_ptr<DCameraInfo>& camInfo)
{
    (void)camInfo;
    return 0;  // Mock: 成功
}

int32_t DCameraSinkController::UpdateSettings(std::vector<std::shared_ptr<HDI::DistributedCamera::V1_1::DCameraSettings>>& settings)
{
    (void)settings;
    return 0;  // Mock: 成功
}

int32_t DCameraSinkController::StopDistributedHardware(const std::string& dhId)
{
    (void)dhId;
    return 0;  // Mock: 成功
}

int32_t DCameraSinkController::PauseDistributedHardware(const std::string& networkId)
{
    (void)networkId;
    return 0;  // Mock: 成功
}

int32_t DCameraSinkController::ResumeDistributedHardware(const std::string& networkId)
{
    (void)networkId;
    return 0;  // Mock: 成功
}

void DCameraSinkController::OnStateChanged(std::shared_ptr<DCameraEvent>& event)
{
    (void)event;
    // Mock: 空实现
}

void DCameraSinkController::OnSessionState(int state, std::string detail)
{
    (void)state;
    (void)detail;
    // Mock: 空实现
}

void DCameraSinkController::OnSessionError(int eventType, int eventReason, std::string detail)
{
    (void)eventType;
    (void)eventReason;
    (void)detail;
    // Mock: 空实现
}

void DCameraSinkController::OnDataReceived(std::vector<std::shared_ptr<DataBuffer>>& buffers)
{
    (void)buffers;
    // Mock: 空实现
}

void DCameraSinkController::OnMetadataResult(std::vector<std::shared_ptr<DCameraSettings>>& settings)
{
    (void)settings;
    // Mock: 空实现
}

} // namespace DistributedHardware
} // namespace OHOS

int32_t OHOS::DistributedHardware::DCameraSinkController::ChannelNeg(std::shared_ptr<DCameraChannelInfo>& info)
{
    (void)info;
    return 0;  // Mock: 成功
}

void OHOS::DistributedHardware::DCameraSinkController::SetTokenId(uint64_t tokenId)
{
    (void)tokenId;
    // Mock: 空实现
}

int32_t OHOS::DistributedHardware::DCameraSinkController::OpenChannel(std::shared_ptr<DCameraOpenInfo>& openInfo)
{
    (void)openInfo;
    return 0;  // Mock: 成功
}
