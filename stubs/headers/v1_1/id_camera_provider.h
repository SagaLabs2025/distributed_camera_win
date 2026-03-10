#ifndef ID_CAMERA_PROVIDER_H
#define ID_CAMERA_PROVIDER_H

#include <string>
#include <cstdint>
#include <memory>
#include <vector>
#include "refbase.h"
#include "id_camera_provider_callback.h"
#include "id_camera_hdf_callback.h"
#include "dcamera_types.h"

namespace OHOS {
namespace HDI {
namespace DistributedCamera {
namespace V1_1 {

// HdiBase 基类 Mock
class HdiBase {
public:
    virtual ~HdiBase() = default;
};

// 分布式相机提供者接口 Mock
class IDCameraProvider : public HdiBase {
public:
    virtual ~IDCameraProvider() = default;
    
    // 引用计数方法（用于 sptr 兼容性）
    virtual void IncStrongRef(const void* objectId) {
        (void)objectId;
    }
    
    virtual void DecStrongRef(const void* objectId) {
        (void)objectId;
    }
    
    // 静态工厂方法 - 获取 IDCameraProvider 实例
    static sptr<IDCameraProvider> Get(const std::string& serviceName) {
        (void)serviceName;
        // Mock: 返回 nullptr，表示 HDF 服务不可用
        return nullptr;
    }
    
    // 使能分布式相机设备
    virtual int32_t EnableDCameraDevice(
        const DHBase& dhBase,
        const std::string& parameters,
        const sptr<IDCameraProviderCallback>& callback) {
        (void)dhBase;
        (void)parameters;
        (void)callback;
        return 0; // 成功
    }
    
    // 禁用分布式相机设备
    virtual int32_t DisableDCameraDevice(const DHBase& dhBase) {
        (void)dhBase;
        return 0; // 成功
    }
    
    // 打开相机设备
    virtual int32_t OpenDCameraDevice(const DHBase& dhBase) {
        (void)dhBase;
        return 0; // 成功
    }
    
    // 关闭相机设备
    virtual int32_t CloseDCameraDevice(const DHBase& dhBase) {
        (void)dhBase;
        return 0; // 成功
    }
    
    // Acquire a frame buffer
    virtual int32_t AcquireBuffer(const DHBase& dhBase, int streamId, DCameraBuffer& buffer) {
        (void)dhBase;
        (void)streamId;
        (void)buffer;
        return 0; // 成功
    }
    
    // 释放缓冲区
    virtual int32_t ShutterBuffer(const DHBase& dhBase, int streamId, const DCameraBuffer& buffer) {
        (void)dhBase;
        (void)streamId;
        (void)buffer;
        return 0; // 成功
    }
    
    // 通知事件
    virtual int32_t Notify(const DHBase& dhBase, const DCameraHDFEvent& event) {
        (void)dhBase;
        (void)event;
        return 0; // 成功
    }
    
    // 设置结果回调
    virtual int32_t OnSettingsResult(const DHBase& dhBase, const DCameraSettings& settings) {
        (void)dhBase;
        (void)settings;
        return 0; // 成功
    }
    
    // 注册相机 HDF 监听器
    virtual int32_t RegisterCameraHdfListener(const std::string& serviceName, const sptr<IDCameraHdfCallback>& callback) {
        (void)serviceName;
        (void)callback;
        return 0; // 成功
    }
    
    // 注销相机 HDF 监听器
    virtual int32_t UnRegisterCameraHdfListener(const std::string& serviceName) {
        (void)serviceName;
        return 0; // 成功
    }
};

} // V1_1
} // DistributedCamera
} // HDI
} // OHOS

#endif // ID_CAMERA_PROVIDER_H
