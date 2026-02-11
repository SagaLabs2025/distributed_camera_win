/*
 * SystemAbilityManager Interface Stub for macOS Mock
 *
 * OpenHarmony 系统能力管理器接口的 macOS 兼容层
 */

#ifndef STUBS_IF_SYSTEM_ABILITY_MANAGER_H
#define STUBS_IF_SYSTEM_ABILITY_MANAGER_H

#include <cstdint>
#include <string>
#include <memory>

#ifdef __cplusplus
namespace OHOS {

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
};

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IF_SYSTEM_ABILITY_MANAGER_H

