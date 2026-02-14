/*
 * SystemAbilityManagerClient Mock Implementation for macOS
 *
 * OpenHarmony SystemAbilityManagerClient 的 macOS Mock 空实现
 */

namespace OHOS {

// 前向声明
class ISystemAbilityManager;

class SystemAbilityManagerClient {
public:
    static SystemAbilityManagerClient& GetInstance();
    ISystemAbilityManager* GetSystemAbilityManager();
};

// 实现
SystemAbilityManagerClient& SystemAbilityManagerClient::GetInstance()
{
    static SystemAbilityManagerClient instance;
    return instance;
}

ISystemAbilityManager* SystemAbilityManagerClient::GetSystemAbilityManager()
{
    return nullptr;  // Mock: 返回空指针
}

} // namespace OHOS
