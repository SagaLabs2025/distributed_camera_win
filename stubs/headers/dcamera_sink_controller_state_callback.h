/*
 * DCamera Sink Controller State Callback - OpenHarmony - macOS Stub
 *
 * Sink 控制器状态回调（仅接口定义，实现在源文件中）
 */

#ifndef STUBS_DCAMERA_SINK_CONTROLLER_STATE_CALLBACK_H
#define STUBS_DCAMERA_SINK_CONTROLLER_STATE_CALLBACK_H

#include <memory>
#include "icamera_operator.h"
#include "dcamera_sink_controller.h"

namespace OHOS {
namespace DistributedHardware {

class DCameraSinkControllerStateCallback : public StateCallback {
public:
    explicit DCameraSinkControllerStateCallback(std::shared_ptr<DCameraSinkController>& controller);
    ~DCameraSinkControllerStateCallback() override = default;

    void OnStateChanged(std::shared_ptr<DCameraEvent>& event) override;
    void OnMetadataResult(std::vector<std::shared_ptr<DCameraSettings>>& settings) override;

private:
    std::weak_ptr<DCameraSinkController> controller_;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_SINK_CONTROLLER_STATE_CALLBACK_H
