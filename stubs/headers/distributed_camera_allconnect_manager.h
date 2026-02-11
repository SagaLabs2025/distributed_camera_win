/*
 * DistributedCameraAllConnectManager Stub for macOS Mock
 *
 * OpenHarmony 分布式相机连接管理器的 macOS 兼容层
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_ALLCONNECT_MANAGER_H
#define STUBS_DISTRIBUTED_CAMERA_ALLCONNECT_MANAGER_H

#include <string>
#include <memory>
#include <cstdint>
#include <functional>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

// 服务状态常量
constexpr int32_t SCM_IDLE = 0;
constexpr int32_t SCM_PREPARE = 1;
constexpr int32_t SCM_START = 2;
constexpr int32_t SCM_STOP = 3;

// 服务状态枚举
enum DCameraSrvState {
    DCAMERA_SRV_STATE_NOT_START = 0,
    DCAMERA_SRV_STATE_RUNNING = 1,
    DCAMERA_SRV_STATE_STOPPING = 2,
};

// 类型别名
using DCameraServiceState = int32_t;

// 生命周期回调类型
using LifecycleCallback = std::function<void(const std::string&, const std::string&)>;

/**
 * @brief 分布式相机所有连接管理器（Mock）
 */
class DCameraAllConnectManager {
public:
    static DCameraAllConnectManager& GetInstance()
    {
        static DCameraAllConnectManager instance;
        return instance;
    }

    // 初始化状态检查
    bool IsInited()
    {
        return true;  // Mock: 总是已初始化
    }

    // 初始化管理器
    int32_t InitDCameraAllConnectManager()
    {
        return 0;  // Mock: 总是成功
    }

    // 反初始化管理器
    int32_t UnInitDCameraAllConnectManager()
    {
        return 0;  // Mock: 总是成功
    }

    // 注册生命周期回调
    int32_t RegisterLifecycleCallback(const LifecycleCallback& callback)
    {
        (void)callback;
        return 0;  // Mock: 总是成功
    }

    // 注销生命周期回调
    int32_t UnRegisterLifecycleCallback()
    {
        return 0;  // Mock: 总是成功
    }

    // 资源请求相关方法
    int32_t BuildResourceRequest(const std::string& devId, const std::string& dhId)
    {
        (void)devId; (void)dhId;
        return 0;  // Mock: 总是成功
    }

    int32_t BuildResourceRequest()
    {
        return 0;  // Mock: 总是成功
    }

    int32_t ApplyAdvancedResource(const std::string& devId, const std::string& dhId)
    {
        (void)devId; (void)dhId;
        return 0;  // Mock: 总是成功
    }

    // 服务状态发布
    int32_t PublishServiceState(const std::string& devId, const std::string& dhId, int32_t state)
    {
        (void)devId; (void)dhId; (void)state;
        return 0;  // Mock: 总是成功
    }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_DISTRIBUTED_CAMERA_ALLCONNECT_MANAGER_H
