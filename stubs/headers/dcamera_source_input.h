/*
 * DCamera Source Input - OpenHarmony Distributed Camera - macOS Mock
 *
 * 分布式相机源输入的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_SOURCE_INPUT_H
#define STUBS_DCAMERA_SOURCE_INPUT_H

#include <memory>
#include <string>

namespace OHOS {
namespace DistributedHardware {

// DCameraSourceInput - 相机源输入
class DCameraSourceInput {
public:
    DCameraSourceInput() = default;
    virtual ~DCameraSourceInput() = default;

    int32_t Initialize() {
        return 0;  // Mock: 返回成功
    }

    int32_t Release() {
        return 0;  // Mock: 返回成功
    }

    int32_t Start() {
        return 0;  // Mock: 返回成功
    }

    int32_t Stop() {
        return 0;  // Mock: 返回成功
    }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_SOURCE_INPUT_H
