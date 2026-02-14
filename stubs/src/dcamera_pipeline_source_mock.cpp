/*
 * DCameraPipelineSource Mock Implementation for macOS
 *
 * OpenHarmony DCameraPipelineSource 类的 macOS Mock 空实现
 */

#include "dcamera_pipeline_source.h"

namespace OHOS {
namespace DistributedHardware {

// DCameraPipelineSource 析构函数
DCameraPipelineSource::~DCameraPipelineSource()
{
    // Mock: 空实现
}

// DCameraPipelineSource 虚函数的空实现
int32_t DCameraPipelineSource::CreateDataProcessPipeline(PipelineType piplineType,
    const VideoConfigParams& sourceConfig, const VideoConfigParams& targetConfig,
    const std::shared_ptr<DataProcessListener>& listener)
{
    (void)piplineType;
    (void)sourceConfig;
    (void)targetConfig;
    (void)listener;
    return 0;  // Mock: 总是成功
}

int32_t DCameraPipelineSource::ProcessData(std::vector<std::shared_ptr<DataBuffer>>& dataBuffers)
{
    (void)dataBuffers;
    return 0;  // Mock: 总是成功
}

void DCameraPipelineSource::DestroyDataProcessPipeline()
{
    // Mock: 空实现
}

void DCameraPipelineSource::OnError(DataProcessErrorType errorType)
{
    (void)errorType;
    // Mock: 空实现
}

void DCameraPipelineSource::OnProcessedVideoBuffer(const std::shared_ptr<DataBuffer>& videoResult)
{
    (void)videoResult;
    // Mock: 空实现
}

int32_t DCameraPipelineSource::GetProperty(const std::string& propertyName, PropertyCarrier& propertyCarrier)
{
    (void)propertyName;
    (void)propertyCarrier;
    return 0;  // Mock: 总是成功
}

int32_t DCameraPipelineSource::UpdateSettings(const std::shared_ptr<Camera::CameraMetadata> settings)
{
    (void)settings;
    return 0;  // Mock: 总是成功
}

} // namespace DistributedHardware
} // namespace OHOS
