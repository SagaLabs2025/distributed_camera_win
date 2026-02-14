/*
 * SystemAbilityManagerClient Mock Implementation for macOS
 *
 * OpenHarmony SystemAbilityManagerClient 类的 macOS Mock 空实现
 */

#include "system_ability_manager_client.h"
#include "system_ability_manager_unified.h"

namespace OHOS {

// SystemAbilityManagerClient 单例实现
SystemAbilityManagerClient& SystemAbilityManagerClient::GetInstance()
{
    static SystemAbilityManagerClient instance;
    return instance;
}

// SystemAbilityManagerClient 方法的空实现
sptr<ISystemAbilityManager> SystemAbilityManagerClient::GetSystemAbilityManager()
{
    return nullptr;  // Mock: 返回空指针
}

} // namespace OHOS
