/*
 * DCamera Sink Output Result Callback - OpenHarmony - macOS Stub
 *
 * Sink 输出结果回调（仅接口定义，实现在源文件中）
 */

#ifndef STUBS_DCAMERA_SINK_OUTPUT_RESULT_CALLBACK_H
#define STUBS_DCAMERA_SINK_OUTPUT_RESULT_CALLBACK_H

#include <memory>
#include "data_buffer.h"
#include "icamera_sink_output.h"

namespace OHOS {
namespace DistributedHardware {

class DCameraSinkOutputResultCallback {
public:
    explicit DCameraSinkOutputResultCallback(std::shared_ptr<DCameraSinkOutput>& output);
    virtual ~DCameraSinkOutputResultCallback() = default;

    virtual void OnPhotoResult(std::shared_ptr<DataBuffer>& buffer) = 0;
    virtual void OnVideoResult(std::shared_ptr<DataBuffer>& buffer) = 0;

private:
    std::weak_ptr<DCameraSinkOutput> output_;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_SINK_OUTPUT_RESULT_CALLBACK_H
