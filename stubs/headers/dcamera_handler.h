/*
 * DCameraHandler Stub for macOS Mock
 *
 * OpenHarmony 分布式相机处理器的 macOS 兼容层
 */

#ifndef STUBS_DCAMERA_HANDLER_H
#define STUBS_DCAMERA_HANDLER_H

#include <string>
#include <vector>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

/**
 * @brief 分布式相机处理器类
 */
class DCameraHandler {
public:
    DCameraHandler() = default;
    ~DCameraHandler() = default;

    // Mock 方法 - 总是返回成功
    int32_t Init()
    {
        return 0;
    }

    int32_t Release()
    {
        return 0;
    }

    int32_t Start()
    {
        return 0;
    }

    int32_t Stop()
    {
        return 0;
    }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_DCAMERA_HANDLER_H
