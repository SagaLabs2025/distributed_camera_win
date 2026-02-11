/*
 * SystemAbilityManager 统一 Stub
 *
 * OpenHarmony 系统能力管理器的 macOS 兼容层
 */

#ifndef STUBS_SYSTEM_ABILITY_MANAGER_UNIFIED_H
#define STUBS_SYSTEM_ABILITY_MANAGER_UNIFIED_H

#include <cstdint>
#include <string>
#include <memory>

#ifdef __cplusplus
namespace OHOS {

// 前向声明
template<typename T> class sptr;
class IRemoteObject;

/**
 * @brief 系统能力状态枚举
 */
enum SaState {
    SA_NOT_REGISTERED,
    SA_REGISTERED,
};

/**
 * @brief 系统能力管理器接口
 */
class ISystemAbilityManager {
public:
    virtual ~ISystemAbilityManager() = default;

    // 纯虚函数，由 MockSystemAbilityManager 实现
    virtual int32_t CheckSystemAbility(int32_t saId) = 0;
    virtual int32_t AddSystemAbility(int32_t saId, void* ability) = 0;
    virtual int32_t RemoveSystemAbility(int32_t saId) = 0;
    virtual int32_t UnloadSystemAbility(int32_t saId) = 0;
    virtual SaState GetSystemAbilityState(int32_t saId) = 0;

    // 带 deviceId 的版本（返回 sptr）
    virtual sptr<IRemoteObject> CheckSystemAbility(int32_t saId, const std::string& deviceId)
    {
        (void)saId; (void)deviceId;
        return nullptr;  // Mock 默认实现
    }
};

/**
 * @brief Mock 的 SystemAbilityManager
 * 在测试环境中直接返回成功，不进行真实的系统调用
 */
class MockSystemAbilityManager : public ISystemAbilityManager {
public:
    MockSystemAbilityManager() = default;
    ~MockSystemAbilityManager() override = default;

    int32_t CheckSystemAbility(int32_t saId) override
    {
        (void)saId;
        return 0;  // Mock: SA 总是存在
    }

    // 带 deviceId 参数的版本（返回 sptr）
    sptr<IRemoteObject> CheckSystemAbility(int32_t saId, const std::string& deviceId) override
    {
        (void)saId; (void)deviceId;
        return nullptr;  // Mock: 返回空指针
    }

    int32_t AddSystemAbility(int32_t saId, void* ability) override
    {
        (void)saId;
        (void)ability;
        return 0;  // Mock: 总是添加成功
    }

    int32_t RemoveSystemAbility(int32_t saId) override
    {
        (void)saId;
        return 0;  // Mock: 总是移除成功
    }

    int32_t UnloadSystemAbility(int32_t saId) override
    {
        (void)saId;
        return 0;  // Mock: 总是卸载成功
    }

    SaState GetSystemAbilityState(int32_t saId) override
    {
        (void)saId;
        return SA_REGISTERED;  // Mock: 总是已注册
    }
};

/**
 * @brief SystemAbilityManagerClient 类
 * 测试环境中的单例客户端
 */
class SystemAbilityManagerClient {
public:
    /**
     * @brief 获取单例实例（返回引用，兼容 . 调用方式）
     * @return 客户端实例引用
     */
    static SystemAbilityManagerClient& GetInstance()
    {
        static SystemAbilityManagerClient instance;
        return instance;
    }

    /**
     * @brief 获取单例指针（兼容 -> 调用方式）
     * @return 客户端实例指针
     */
    static SystemAbilityManagerClient* GetInstancePtr()
    {
        return &GetInstance();
    }

    /**
     * @brief 获取系统能力管理器
     * @return Mock 的系统能力管理器指针
     */
    ISystemAbilityManager* GetSystemAbilityManager()
    {
        // 返回单例的 Mock 管理器
        static MockSystemAbilityManager mockManager;
        return &mockManager;
    }

private:
    SystemAbilityManagerClient() = default;
    ~SystemAbilityManagerClient() = default;
};

// 导出到 DistributedHardware 命名空间（用于源码访问）
namespace DistributedHardware {
    // 分布式相机 SA ID 常量定义
    constexpr int32_t DISTRIBUTED_HARDWARE_CAMERA_SOURCE_SA_ID = 4803;
    constexpr int32_t DISTRIBUTED_HARDWARE_CAMERA_SINK_SA_ID = 4804;

    // 导出 SystemAbilityManagerClient
    using OHOS::SystemAbilityManagerClient;
}

} // namespace OHOS

// 全局命名空间别名 - 方便各命名空间使用
using OHOS::ISystemAbilityManager;
using OHOS::SaState;

#endif // __cplusplus

#endif // STUBS_SYSTEM_ABILITY_MANAGER_UNIFIED_H
