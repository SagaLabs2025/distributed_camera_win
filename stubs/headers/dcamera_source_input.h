/*
 * DCameraSourceInput Stub for macOS Mock
 *
 * OpenHarmony 分布式相机源输入的 macOS 兼容层
 *
 * 重要原则：使用源码中的定义，不重复定义
 */

#ifndef STUBS_DCAMERA_SOURCE_INPUT_H
#define STUBS_DCAMERA_SOURCE_INPUT_H

#include <string>
#include <memory>
#include <cstdint>
#include <vector>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

// 前向声明
class DCameraSourceDev;

/**
 * @brief 分布式相机源输入接口
 * 匹配源码中的构造函数签名
 */
class DCameraSourceInput {
public:
    // Constructor 匹配源码签名（接受值以支持 std::make_shared）
    DCameraSourceInput(std::string devId, std::string dhId, std::shared_ptr<DCameraSourceDev> camDev)
    {
        (void)devId;
        (void)dhId;
        (void)camDev;
    }

    virtual ~DCameraSourceInput() = default;

    virtual int32_t Init()
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

    virtual int32_t StartCapture(const std::vector<std::string>& captureInfos)
    {
        (void)captureInfos;
        return 0;  // Mock: 总是成功
    }

    virtual int32_t StopCapture()
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
