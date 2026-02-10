/*
 * ICameraProvider - macOS Mock Implementation
 *
 * OpenHarmony HDF v1.1 相机提供者接口的 macOS 实现
 */

#ifndef STUBS_V1_1_ID_CAMERA_PROVIDER_H
#define STUBS_V1_1_ID_CAMERA_PROVIDER_H

#include <string>
#include <vector>
#include <memory>
#include "dcamera_types.h"
#include "dcamera_hdf_types.h"

namespace OHOS {
namespace HDI {
namespace DistributedCamera {
namespace V1_1 {

// ICameraProviderCallback - 相机提供者回调接口
class ICameraProviderCallback {
public:
    virtual ~ICameraProviderCallback() = default;

    // 相机设备状态变化回调
    virtual void OnCameraDeviceStatusChange(const std::string& deviceId, int32_t status) {
        (void)deviceId;
        (void)status;
    }
};

// 前向声明
class MockCameraProvider;

// ICameraProvider - 相机提供者接口
class ICameraProvider {
public:
    virtual ~ICameraProvider() = default;

    // 静态方法：获取服务实例
    static std::shared_ptr<ICameraProvider> Get(const std::string& serviceName);

    // 设置回调
    virtual int32_t SetCallback(const std::shared_ptr<ICameraProviderCallback>& callback) {
        (void)callback;
        return 0;  // Mock: 返回成功
    }

    // 启用相机设备 - 更新签名以匹配 OpenHarmony 源码调用
    virtual int32_t EnableDCameraDevice(const DHBase& dhBase, const DCameraAbility& ability,
                                        const std::shared_ptr<ICameraProviderCallback>& callback) {
        (void)dhBase;
        (void)ability;
        (void)callback;
        return 0;  // Mock: 返回成功
    }

    // 禁用相机设备
    virtual int32_t DisableDCameraDevice(const std::string& dhId) {
        (void)dhId;
        return 0;  // Mock: 返回成功
    }

    // 获取相机设备列表
    virtual int32_t GetCameraDeviceList(std::vector<std::string>& deviceIds) {
        deviceIds.clear();
        deviceIds.push_back("camera0");
        return 0;  // Mock: 返回成功
    }

    // 获取相机设备能力
    virtual int32_t GetCameraAbility(const std::string& deviceId, DCameraAbility& ability) {
        (void)deviceId;
        // Mock: 返回默认能力
        ability = DCameraAbility();
        return 0;
    }

    // 打开相机设备
    virtual int32_t OpenCamera(const std::string& deviceId, void** cameraDevice) {
        (void)deviceId;
        *cameraDevice = nullptr;
        return 0;  // Mock: 返回成功
    }

    // 关闭相机设备
    virtual int32_t CloseCamera(void* cameraDevice) {
        (void)cameraDevice;
        return 0;  // Mock: 返回成功
    }
};

// Mock 实现类
class MockCameraProvider : public ICameraProvider {
public:
    MockCameraProvider() = default;
    ~MockCameraProvider() override = default;
};

// 在类定义之后实现 Get 方法
inline std::shared_ptr<ICameraProvider> ICameraProvider::Get(const std::string& serviceName) {
    (void)serviceName;
    static auto instance = std::make_shared<MockCameraProvider>();
    return instance;
}

} // namespace V1_1
} // namespace DistributedCamera
} // namespace HDI
} // namespace OHOS

// 为兼容 OpenHarmony 源码，在 DistributedHardware 命名空间中引入类型别名
namespace OHOS {
namespace DistributedHardware {
    using IDCameraProvider = OHOS::HDI::DistributedCamera::V1_1::ICameraProvider;
}
}

#endif // STUBS_V1_1_ID_CAMERA_PROVIDER_H
