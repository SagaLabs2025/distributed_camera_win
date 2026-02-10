/*
 * DCamera Source Controller - OpenHarmony Distributed Camera - macOS Mock
 *
 * 分布式相机源控制器的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_SOURCE_CONTROLLER_H
#define STUBS_DCAMERA_SOURCE_CONTROLLER_H

#include <memory>
#include <string>

namespace OHOS {
namespace DistributedHardware {

// DCameraSourceController - 相机源控制器
class DCameraSourceController {
public:
    DCameraSourceController() = default;
    virtual ~DCameraSourceController() = default;

    int32_t Initialize() {
        return 0;  // Mock: 返回成功
    }

    int32_t Release() {
        return 0;  // Mock: 返回成功
    }

    int32_t StartCapture() {
        return 0;  // Mock: 返回成功
    }

    int32_t StopCapture() {
        return 0;  // Mock: 返回成功
    }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_SOURCE_CONTROLLER_H
