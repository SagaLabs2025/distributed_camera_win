/*
 * DCameraAllConnectManager Stub for macOS Mock
 *
 * OpenHarmony 分布式相机全连接管理器的 macOS 兼容层
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_ALLCONNECT_MANAGER_H
#define STUBS_DISTRIBUTED_CAMERA_ALLCONNECT_MANAGER_H

#include <stdint.h>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

/**
 * @brief 分布式相机全连接管理器类
 */
class DCameraAllConnectManager {
public:
    /**
     * @brief 获取单例实例
     * @return 管理器实例引用
     */
    static DCameraAllConnectManager& GetInstance()
    {
        static DCameraAllConnectManager instance;
        return instance;
    }

    /**
     * @brief 检查是否已初始化
     * @return true/false
     */
    static bool IsInited()
    {
        return false;  // Mock: 未初始化
    }

    /**
     * @brief 初始化分布式相机全连接管理器
     * @return 成功返回 0
     */
    int32_t InitDCameraAllConnectManager()
    {
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 注册生命周期回调
     * @return 成功返回 0
     */
    int32_t RegisterLifecycleCallback()
    {
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 注销生命周期回调
     * @return 成功返回 0
     */
    int32_t UnRegisterLifecycleCallback()
    {
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 反初始化分布式相机全连接管理器
     * @return 成功返回 0
     */
    int32_t UnInitDCameraAllConnectManager()
    {
        return 0;  // Mock: 总是返回成功
    }

private:
    DCameraAllConnectManager() = default;
    ~DCameraAllConnectManager() = default;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_DISTRIBUTED_CAMERA_ALLCONNECT_MANAGER_H
