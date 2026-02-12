/*
 * IDataProcessPipeline HDF Stub for macOS Mock
 *
 * OpenHarmony 数据处理管道接口的 macOS 兼容层
 */

#ifndef STUBS_IDATA_PROCESS_PIPELINE_H
#define STUBS_IDATA_PROCESS_PIPELINE_H

#include <cstdint>
#include <string>
#include <vector>
#include <memory>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

// Forward declarations
class DataBuffer;
class DataProcessListener;
struct PropertyCarrier;

namespace Camera {
class CameraMetadata;
}

struct VideoConfigParams {
    int32_t width;
    int32_t height;
    int32_t frameRate;
};

enum PipelineType {
    PIPELINE_TYPE_VIDEO = 0,
    PIPELINE_TYPE_AUDIO = 1,
};

class IDataProcessPipeline {
public:
    virtual ~IDataProcessPipeline() = default;

    virtual int32_t CreateDataProcessPipeline(PipelineType pipelineType,
                                           const VideoConfigParams& sourceConfig,
                                           const VideoConfigParams& targetConfig,
                                           const std::shared_ptr<DataProcessListener>& listener) = 0;
    virtual int32_t ProcessData(std::vector<std::shared_ptr<DataBuffer>>& dataBuffers) = 0;
    virtual void DestroyDataProcessPipeline() = 0;
    virtual int32_t GetProperty(const std::string& propertyName, PropertyCarrier& propertyCarrier) = 0;
    virtual int32_t UpdateSettings(const std::shared_ptr<Camera::CameraMetadata> settings) = 0;
};

} // namespace DistributedHardware
} // namespace OHOS
#endif

#endif // STUBS_IDATA_PROCESS_PIPELINE_H
