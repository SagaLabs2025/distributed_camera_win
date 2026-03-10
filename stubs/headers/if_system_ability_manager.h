#ifndef STUBS_IF_SYSTEM_ABILITY_MANAGER_H
#define STUBS_IF_SYSTEM_ABILITY_MANAGER_H

#include <cstdint>
#include <string>

#include "iremote_broker.h"
#include "isystem_ability_load_callback.h"

namespace OHOS {

class ISystemAbilityManager : public IRemoteBroker {
public:
    virtual ~ISystemAbilityManager() override = default;

    virtual sptr<IRemoteObject> GetSystemAbility(int32_t systemAbilityId) = 0;
    virtual sptr<IRemoteObject> CheckSystemAbility(int32_t systemAbilityId) = 0;
    virtual sptr<IRemoteObject> CheckSystemAbility(int32_t systemAbilityId, const std::string& deviceId) = 0;

    virtual int32_t LoadSystemAbility(int32_t systemAbilityId, const sptr<ISystemAbilityLoadCallback>& callback) = 0;
    virtual int32_t UnloadSystemAbility(int32_t systemAbilityId) = 0;

    DECLARE_INTERFACE_DESCRIPTOR(u"OHOS.ISystemAbilityManager");
};

} // namespace OHOS

#endif // STUBS_IF_SYSTEM_ABILITY_MANAGER_H

