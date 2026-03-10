#ifndef STUBS_ISERVICE_REGISTRY_H
#define STUBS_ISERVICE_REGISTRY_H

#include <mutex>
#include <string>

#include "if_system_ability_manager.h"
#include "ipc_types.h"
#include "service_registry.h"

namespace OHOS {

// Minimal SystemAbilityManager implementation backed by the in-process ServiceRegistry.
class MockSystemAbilityManager : public ISystemAbilityManager {
public:
    sptr<IRemoteObject> AsObject() override
    {
        return nullptr;
    }

    sptr<IRemoteObject> GetSystemAbility(int32_t systemAbilityId) override
    {
        return DistributedHardware::ServiceRegistry::GetInstance().GetService(systemAbilityId);
    }

    sptr<IRemoteObject> CheckSystemAbility(int32_t systemAbilityId) override
    {
        return DistributedHardware::ServiceRegistry::GetInstance().GetService(systemAbilityId);
    }

    sptr<IRemoteObject> CheckSystemAbility(int32_t systemAbilityId, const std::string& deviceId) override
    {
        (void)deviceId;
        return DistributedHardware::ServiceRegistry::GetInstance().GetService(systemAbilityId);
    }

    int32_t LoadSystemAbility(int32_t systemAbilityId, const sptr<ISystemAbilityLoadCallback>& callback) override
    {
        auto object = DistributedHardware::ServiceRegistry::GetInstance().GetService(systemAbilityId);
        if (callback != nullptr) {
            if (object != nullptr) {
                callback->OnLoadSystemAbilitySuccess(systemAbilityId, object);
            } else {
                callback->OnLoadSystemAbilityFail(systemAbilityId);
            }
        }
        return ERR_OK;
    }

    int32_t UnloadSystemAbility(int32_t systemAbilityId) override
    {
        (void)systemAbilityId;
        return ERR_OK;
    }
};

class SystemAbilityManagerClient {
public:
    static SystemAbilityManagerClient& GetInstance()
    {
        static SystemAbilityManagerClient instance;
        return instance;
    }

    sptr<ISystemAbilityManager> GetSystemAbilityManager()
    {
        static sptr<ISystemAbilityManager> manager = sptr<ISystemAbilityManager>(new MockSystemAbilityManager());
        return manager;
    }

    void DestroySystemAbilityManagerObject() {}

private:
    SystemAbilityManagerClient() = default;
    ~SystemAbilityManagerClient() = default;
};

} // namespace OHOS

#endif // STUBS_ISERVICE_REGISTRY_H

