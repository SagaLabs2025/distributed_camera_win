/*
 * SystemAbilityManagerClient Mock for macOS Mock
 *
 * OpenHarmony 系统能力管理器客户端的 macOS 兼容层
 *
 * Mock 策略：返回单例的 MockSystemAbilityManager，避免真正的 SA Manager 调用
 */

#ifndef STUBS_SYSTEM_ABILITY_MANAGER_CLIENT_H
#define STUBS_SYSTEM_ABILITY_MANAGER_CLIENT_H

#include "if_system_ability_manager.h"
#include "iremote_object.h"
#include <memory>

#ifdef __cplusplus
namespace OHOS {
namespace {

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

    // 新增：带 deviceId 参数的版本（用于分布式 SA）
    sptr<IRemoteObject> CheckSystemAbility(int32_t saId, const std::string& deviceId)
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
     * @brief 获取单例实例（返回引用，与 OpenHarmony 原生 API 一致）
     * @return 客户端实例引用
     */
    static SystemAbilityManagerClient& GetInstance()
    {
        static SystemAbilityManagerClient instance;
        return instance;
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

} // namespace
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_SYSTEM_ABILITY_MANAGER_CLIENT_H
