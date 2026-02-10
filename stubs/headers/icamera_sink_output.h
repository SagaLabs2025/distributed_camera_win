/*
 * DCamera Sink Output - OpenHarmony - macOS Stub
 *
 * 分布式相机 Sink 输出接口（简化版）
 */

#ifndef STUBS_ICAMERA_SINK_OUTPUT_H
#define STUBS_ICAMERA_SINK_OUTPUT_H

#include <cstdint>
#include <memory>
#include <vector>
#include "data_buffer.h"
#include "distributed_camera_errno.h"

namespace OHOS {
namespace DistributedHardware {

// Sink 输出接口
class DCameraSinkOutput {
public:
    DCameraSinkOutput() = default;
    virtual ~DCameraSinkOutput() = default;

    virtual void OnPhotoResult(std::shared_ptr<DataBuffer>& buffer) = 0;
    virtual void OnVideoResult(std::shared_ptr<DataBuffer>& buffer) = 0;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_ICAMERA_SINK_OUTPUT_H
