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

// 分布式相机 SA ID 定义
constexpr int32_t DISTRIBUTED_HARDWARE_CAMERA_SOURCE_SA_ID = 4803;
constexpr int32_t DISTRIBUTED_HARDWARE_CAMERA_SINK_SA_ID = 4804;

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
