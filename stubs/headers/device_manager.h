/*
 * DeviceManager Stub for macOS Mock
 *
 * OpenHarmony 设备管理器的 macOS 兼容层
 */

#ifndef STUBS_DEVICE_MANAGER_H
#define STUBS_DEVICE_MANAGER_H

#include <string>
#include <vector>
#include <functional>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

// 前向声明
class DMCallback;
class DmDeviceInfo;

/**
 * @brief 设备状态枚举
 */
enum class DeviceState {
    DEVICE_ONLINE = 0,
    DEVICE_OFFLINE = 1,
    DEVICE_NOT_READY = 2,
};

/**
 * @brief 设备初始化回调接口
 */
class DmInitCallback {
public:
    virtual ~DmInitCallback() = default;

    /**
     * @brief 远程死亡回调
     */
    virtual void OnRemoteDied()
    {
        // Mock: 空实现
    }
};

/**
 * @brief 设备管理器回调接口
 */
class DMCallback {
public:
    virtual ~DMCallback() = default;

    /**
     * @brief 设备上线回调
     */
    virtual void OnDeviceOnline(const std::string& deviceId)
    {
        (void)deviceId;
    }

    /**
     * @brief 设备离线回调
     */
    virtual void OnDeviceOffline(const std::string& deviceId)
    {
        (void)deviceId;
    }
};

/**
 * @brief 设备信息结构
 */
struct DmDeviceInfo {
    std::string deviceId;
    std::string deviceName;
    DeviceState state;
};

/**
 * @brief 设备管理器类（Mock）
 */
class DeviceManager {
public:
    static DeviceManager* GetInstance()
    {
        static DeviceManager instance;
        return &instance;
    }

    /**
     * @brief 初始化设备管理器
     */
    int32_t Init()
    {
        return 0;  // Mock: 总是成功
    }

    /**
     * @brief 注册设备回调
     */
    int32_t RegisterDevStateCallback(const std::string& packageName, DMCallback* callback)
    {
        (void)packageName; (void)callback;
        return 0;  // Mock: 总是成功
    }

    /**
     * @brief 注销设备回调
     */
    int32_t UnregisterDevStateCallback(const std::string& packageName)
    {
        (void)packageName;
        return 0;  // Mock: 总是成功
    }

    /**
     * @brief 获取设备列表
     */
    std::vector<DmDeviceInfo> GetDeviceList()
    {
        return {};  // Mock: 返回空列表
    }

private:
    DeviceManager() = default;
    ~DeviceManager() = default;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_DEVICE_MANAGER_H
