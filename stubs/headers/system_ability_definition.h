/*
 * SystemAbilityDefinition Stub for macOS Mock
 *
 * OpenHarmony 系统能力定义的 macOS 兼容层
 */

#ifndef STUBS_SYSTEM_ABILITY_DEFINITION_H
#define STUBS_SYSTEM_ABILITY_DEFINITION_H

#include <cstdint>
#include <string>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

// SA ID 常量现在在 system_ability_manager_unified.h 中定义
// 避免重定义

/**
 * @brief 系统能力定义模板
 */
template<int32_t SaId, const char* Name>
class SystemAbility {
public:
    static constexpr int32_t SA_ID = SaId;
    static const char* GetName() { return Name; }
};

// 分布式硬件框架 SA ID
constexpr int32_t DISTRIBUTED_HARDWARE_SA_ID = 4801;

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_SYSTEM_ABILITY_DEFINITION_H
