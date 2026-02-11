/*
 * IDCameraHdfCallback HDF Stub for macOS Mock
 *
 * OpenHarmony 分布式相机 HDF 回调接口的 macOS 兼容层
 */

#ifndef STUBS_V1_1_ID_CAMERA_HDF_CALLBACK_H
#define STUBS_V1_1_ID_CAMERA_HDF_CALLBACK_H

#include "dcamera_types.h"

#ifdef __cplusplus
namespace OHOS {
namespace HDI {
namespace DistributedCamera {
namespace V1_1 {

/**
 * @brief 分布式相机 SA 服务的 HDF 回调接口
 * 调用者需要实现这些回调
 */
class IDCameraHdfCallback {
public:
    virtual ~IDCameraHdfCallback() = default;

    /**
     * @brief 通知分布式相机 HDF 事件
     * @param devId 分布式音频设备的设备 ID
     * @param event 通知事件类型（如对焦事件、音量事件等）
     * @return 成功返回 0，失败返回负值
     */
    virtual int32_t NotifyEvent(int32_t devId, const DCameraHDFEvent& event)
    {
        (void)devId;
        (void)event;
        return 0;  // Mock: 总是返回成功
    }
};

} // namespace V1_1
} // namespace DistributedCamera
} // namespace HDI
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_V1_1_ID_CAMERA_HDF_CALLBACK_H
