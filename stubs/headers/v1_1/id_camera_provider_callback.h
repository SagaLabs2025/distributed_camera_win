/*
 * IDCameraProviderCallback HDF Stub for macOS Mock
 *
 * OpenHarmony 分布式相机 HDF 回调接口的 macOS 兼容层
 */

#ifndef STUBS_V1_1_ID_CAMERA_PROVIDER_CALLBACK_H
#define STUBS_V1_1_ID_CAMERA_PROVIDER_CALLBACK_H

#include "dcamera_types.h"
#include <vector>

#ifdef __cplusplus
namespace OHOS {
namespace HDI {
namespace DistributedCamera {
namespace V1_1 {

/**
 * @brief 分布式相机 SA 服务的回调接口
 * 调用者需要实现这些回调
 */
class IDCameraProviderCallback {
public:
    virtual ~IDCameraProviderCallback() = default;

    // 引用计数方法（用于 sptr 兼容性）
    virtual void IncStrongRef(const void* objectId)
    {
        (void)objectId;
    }

    virtual void DecStrongRef(const void* objectId)
    {
        (void)objectId;
    }

    /**
     * @brief 在源设备和目标设备之间创建传输通道
     * 打开并初始化分布式相机会话
     * @param dhBase 分布式硬件设备基础信息
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t OpenSession(const DHBase& dhBase)
    {
        (void)dhBase;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 关闭分布式相机会话，销毁源设备和目标设备之间的传输通道
     * @param dhBase 分布式硬件设备基础信息
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t CloseSession(const DHBase& dhBase)
    {
        (void)dhBase;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 配置流
     * @param dhBase 分布式硬件设备基础信息
     * @param streamInfos 流信息列表
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t ConfigureStreams(const DHBase& dhBase,
                                     const std::vector<DCStreamInfo>& streamInfos)
    {
        (void)dhBase;
        (void)streamInfos;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 释放流
     * @param dhBase 分布式硬件设备基础信息
     * @param streamIds 要释放的流 ID 列表
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t ReleaseStreams(const DHBase& dhBase,
                                   const std::vector<int>& streamIds)
    {
        (void)dhBase;
        (void)streamIds;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 开始捕获图像
     * 该函数必须在 ConfigureStreams 之后调用
     * 有两种图像捕获模式：连续捕获和单次捕获
     * @param dhBase 分布式硬件设备基础信息
     * @param captureInfos 捕获请求配置信息
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t StartCapture(const DHBase& dhBase,
                                 const std::vector<DCCaptureInfo>& captureInfos)
    {
        (void)dhBase;
        (void)captureInfos;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 停止捕获图像
     * @param dhBase 分布式硬件设备基础信息
     * @param streamIds 要停止捕获的流 ID 列表
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t StopCapture(const DHBase& dhBase,
                                const std::vector<int>& streamIds)
    {
        (void)dhBase;
        (void)streamIds;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 更新分布式相机设备控制参数
     * @param dhBase 分布式硬件设备基础信息
     * @param settings 相机参数，包括传感器帧率和 3A 参数
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t UpdateSettings(const DHBase& dhBase,
                                   const std::vector<DCameraSettings>& settings)
    {
        (void)dhBase;
        (void)settings;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 通知分布式相机 SA 事件
     * @param dhBase 分布式硬件设备基础信息
     * @param event 通知事件类型（如对焦事件、音量事件等）
     * @return 成功返回 0，失败返回负值
     */
    virtual int32_t NotifyEvent(const DHBase& dhBase, const DCameraHDFEvent& event)
    {
        (void)dhBase;
        (void)event;
        return 0;  // Mock: 总是返回成功
    }
};

} // namespace V1_1
} // namespace DistributedCamera
} // namespace HDI
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_V1_1_ID_CAMERA_PROVIDER_CALLBACK_H

