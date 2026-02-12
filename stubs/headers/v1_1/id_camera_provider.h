/*
 * IDCameraProvider HDF Stub for macOS Mock
 *
 * OpenHarmony 分布式相机 HDF 提供者接口的 macOS 兼容层
 */

#ifndef STUBS_V1_1_ID_CAMERA_PROVIDER_H
#define STUBS_V1_1_ID_CAMERA_PROVIDER_H

#include "dcamera_types.h"
#include "id_camera_provider_callback.h"
#include "id_camera_hdf_callback.h"
#include <vector>
#include <memory>

#ifdef __cplusplus
namespace OHOS {
namespace HDI {
namespace DistributedCamera {
namespace V1_1 {

/**
 * @brief 分布式相机 HDF 提供者接口
 * 在分布式相机 SA 服务和分布式相机 HDF 服务之间传输接口调用
 * 为上层提供硬件驱动接口 (HDI)
 */
class IDCameraProvider {
public:
    virtual ~IDCameraProvider() = default;

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
     * @brief 获取 IDCameraProvider 实例
     * @param serviceName HDF 服务名称
     * @return 返回 IDCameraProvider 实例指针
     */
    static IDCameraProvider* Get(const std::string& serviceName)
    {
        (void)serviceName;
        static IDCameraProvider instance;
        return &instance;  // Mock: 返回单例
    }

    /**
     * @brief 获取 IDCameraProvider 实例（无参数版本）
     * @return 返回 IDCameraProvider 实例指针
     */
    static IDCameraProvider* Get()
    {
        static IDCameraProvider instance;
        return &instance;  // Mock: 返回单例
    }

    /**
     * @brief 启用分布式相机设备并设置回调
     * @param dhBase 分布式硬件设备基础信息
     * @param abilityInfo 要启用的分布式相机设备的静态能力信息
     * @param callbackObj 要设置的回调对象
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t EnableDCameraDevice(const DHBase& dhBase,
                                        const std::string& abilityInfo,
                                        sptr<IDCameraProviderCallback> callbackObj)
    {
        (void)dhBase;
        (void)abilityInfo;
        (void)callbackObj;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 禁用分布式相机设备
     * @param dhBase 分布式硬件设备基础信息
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t DisableDCameraDevice(const DHBase& dhBase)
    {
        (void)dhBase;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 从附加到 streamId 的过程句柄获取帧缓冲区
     * @param dhBase 分布式硬件设备基础信息
     * @param streamId 流 ID
     * @param buffer 输出：帧缓冲区
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t AcquireBuffer(const DHBase& dhBase,
                                  int32_t streamId,
                                  DCameraBuffer& buffer)
    {
        (void)dhBase;
        (void)streamId;
        (void)buffer;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 当帧缓冲区已填充时通知分布式相机 HDF 服务
     * @param dhBase 分布式硬件设备基础信息
     * @param streamId 流 ID
     * @param buffer 输出帧缓冲区
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t ShutterBuffer(const DHBase& dhBase,
                                  int32_t streamId,
                                  const DCameraBuffer& buffer)
    {
        (void)dhBase;
        (void)streamId;
        (void)buffer;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 报告与分布式相机设备相关的元数据
     * @param dhBase 分布式硬件设备基础信息
     * @param result 报告的元数据
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t OnSettingsResult(const DHBase& dhBase,
                                     const DCameraSettings& result)
    {
        (void)dhBase;
        (void)result;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 通知从分布式相机 SA 服务到分布式相机 HDF 服务的某些事件
     * @param dhBase 分布式硬件设备基础信息
     * @param event 详细事件内容
     * @return 成功返回 NO_ERROR，否则返回 DCamRetCode 中的错误码
     */
    virtual int32_t Notify(const DHBase& dhBase, const DCameraHDFEvent& event)
    {
        (void)dhBase;
        (void)event;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 注册分布式相机 HDF 驱动监听器
     * @param serviceName 服务名称
     * @param callbackObj 分布式相机 HDF 监听器回调
     * @return 成功返回 0，失败返回负值
     */
    virtual int32_t RegisterCameraHdfListener(const std::string& serviceName,
                                              std::shared_ptr<IDCameraHdfCallback> callbackObj)
    {
        (void)serviceName;
        (void)callbackObj;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 注销分布式相机 HDF 驱动监听器
     * @param serviceName 服务名称
     * @return 成功返回 0，失败返回负值
     */
    virtual int32_t UnRegisterCameraHdfListener(const std::string& serviceName)
    {
        (void)serviceName;
        return 0;  // Mock: 总是返回成功
    }
};

} // namespace V1_1
} // namespace DistributedCamera
} // namespace HDI
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_V1_1_ID_CAMERA_PROVIDER_H
