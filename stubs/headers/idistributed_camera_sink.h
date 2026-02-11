/*
 * IDistributedCameraSink Interface Stub for macOS Mock
 *
 * OpenHarmony 分布式相机 Sink 接口的 macOS 兼容层
 */

#ifndef STUBS_IDISTRIBUTED_CAMERA_SINK_H
#define STUBS_IDISTRIBUTED_CAMERA_SINK_H

#include <string>
#include <vector>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

/**
 * @brief 分布式相机 Sink 参数结构
 */
struct SinkParam {
    std::string devId;
    std::string dhId;
};

/**
 * @brief 分布式相机 Sink 接口
 */
class IDistributedCameraSink {
public:
    virtual ~IDistributedCameraSink() = default;

    /**
     * @brief 初始化 Sink
     * @param params 参数
     * @return 成功返回 0
     */
    virtual int32_t InitSink(const std::string& params)
    {
        (void)params;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 释放 Sink
     * @return 成功返回 0
     */
    virtual int32_t ReleaseSink()
    {
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 注册分布式硬件
     */
    virtual int32_t RegisterDistributedHardware(const std::string& devId,
                                                   const std::string& dhId,
                                                   const std::string& reqId,
                                                   const SinkParam& param)
    {
        (void)devId; (void)dhId; (void)reqId; (void)param;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 注销分布式硬件
     */
    virtual int32_t UnregisterDistributedHardware(const std::string& devId,
                                                     const std::string& dhId,
                                                     const std::string& reqId)
    {
        (void)devId; (void)dhId; (void)reqId;
        return 0;  // Mock: 总是返回成功
    }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IDISTRIBUTED_CAMERA_SINK_H
