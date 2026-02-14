/*
 * DCameraSinkOutput Stub Implementation for macOS
 *
 * 这是 dcamera_sink_output.cpp 的 stub 实现，用于替代真实的实现
 */

#include "dcamera_sink_output.h"
#include "dcamera_sink_output_result_callback.h"
#include "icamera_sink_access_control.h"
#include "idcamera_sink_callback.h"
#include "data_buffer.h"
#include "v1_1/dcamera_types.h"
#include <memory>
#include <vector>

namespace OHOS {
namespace DistributedHardware {

DCameraSinkOutput::DCameraSinkOutput(const std::string& dhId,
                                     std::shared_ptr<ICameraOperator>& cameraOperator)
{
    (void)dhId;
    (void)cameraOperator;
    // Mock: 空实现
}

DCameraSinkOutput::~DCameraSinkOutput()
{
    // Mock: 空实现
}

int32_t DCameraSinkOutput::Init()
{
    return 0;  // Mock: 成功
}

int32_t DCameraSinkOutput::UnInit()
{
    return 0;  // Mock: 成功
}

int32_t DCameraSinkOutput::StartCapture(std::vector<std::shared_ptr<DCameraCaptureInfo>>& captureInfos)
{
    (void)captureInfos;
    return 0;  // Mock: 成功
}

int32_t DCameraSinkOutput::StopCapture()
{
    return 0;  // Mock: 成功
}

void DCameraSinkOutput::OnSessionState(HDI::DistributedCamera::V1_1::DCStreamType streamType, int state)
{
    (void)streamType;
    (void)state;
    // Mock: 空实现
}

void DCameraSinkOutput::OnSessionError(HDI::DistributedCamera::V1_1::DCStreamType streamType,
                                       int eventType,
                                       int eventReason,
                                       std::string detail)
{
    (void)streamType;
    (void)eventType;
    (void)eventReason;
    (void)detail;
    // Mock: 空实现
}

void DCameraSinkOutput::OnDataReceived(HDI::DistributedCamera::V1_1::DCStreamType streamType,
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

int32_t OHOS::DistributedHardware::DCameraSinkOutput::GetProperty(const std::string& propertyName, PropertyCarrier& propertyCarrier)
{
    (void)propertyName;
    (void)propertyCarrier;
    return 0;  // Mock: 成功
}

int32_t OHOS::DistributedHardware::DCameraSinkOutput::OpenChannel(std::shared_ptr<DCameraChannelInfo>& info)
{
    (void)info;
    return 0;  // Mock: 成功
}

int32_t OHOS::DistributedHardware::DCameraSinkOutput::CloseChannel()
{
    return 0;  // Mock: 成功
}
