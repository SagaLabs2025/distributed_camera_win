/*
 * DCameraSourceInput Stub for macOS Mock
 *
 * OpenHarmony 分布式相机源输入的 macOS 兼容层
 */

#ifndef STUBS_DCAMERA_SOURCE_INPUT_H
#define STUBS_DCAMERA_SOURCE_INPUT_H

#include <string>
#include <memory>
#include <cstdint>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

/**
 * @brief 分布式相机源输入接口
 */
class DCameraSourceInput {
public:
    // Constructor taking devId, dhId, and cameraSourceDev
    DCameraSourceInput(const std::string& devId, const std::string& dhId,
                      const std::shared_ptr<void>& cameraSourceDev)
    {
        (void)devId;
        (void)dhId;
        (void)cameraSourceDev;
    }

    virtual ~DCameraSourceInput() = default;

    virtual int32_t Initialize()
    {
        return 0;  // Mock: 总是成功
    }

    virtual int32_t Start()
    {
        return 0;  // Mock: 总是成功
    }

    virtual int32_t Stop()
    {
        return 0;  // Mock: 总是成功
    }

    virtual int32_t Release()
    {
        return 0;  // Mock: 总是成功
    }
};

/**
 * @brief 相机输入配置
 */
struct DCameraInputConfig {
    int32_t width;
    int32_t height;
    int32_t frameRate;
    int32_t encodingType;

    DCameraInputConfig()
        : width(1920), height(1080), frameRate(30), encodingType(0)
    {}
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_DCAMERA_SOURCE_INPUT_H
