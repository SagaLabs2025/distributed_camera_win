#ifndef STUBS_SYSTEM_ABILITY_LOAD_CALLBACK_STUB_H
#define STUBS_SYSTEM_ABILITY_LOAD_CALLBACK_STUB_H

#include "iremote_stub.h"
#include "isystem_ability_load_callback.h"
#include "ipc_types.h"

namespace OHOS {

class SystemAbilityLoadCallbackStub : public IRemoteStub<ISystemAbilityLoadCallback> {
public:
    int32_t OnRemoteRequest(uint32_t code, MessageParcel& data, MessageParcel& reply, MessageOption& option) override
    {
        (void)reply;
        (void)option;
        // In this in-process mock, callbacks are typically invoked directly; keep a minimal dispatcher for safety.
        switch (code) {
            case ON_LOAD_SYSTEM_ABILITY_SUCCESS: {
                int32_t systemAbilityId = data.ReadInt32();
                sptr<IRemoteObject> remoteObject = data.ReadRemoteObject();
                OnLoadSystemAbilitySuccess(systemAbilityId, remoteObject);
                return ERR_NONE;
            }
            case ON_LOAD_SYSTEM_ABILITY_FAIL: {
                int32_t systemAbilityId = data.ReadInt32();
                OnLoadSystemAbilityFail(systemAbilityId);
                return ERR_NONE;
            }
            case ON_LOAD_SYSTEM_ABILITY_COMPLETE_FOR_REMOTE: {
                std::string deviceId = data.ReadString();
                int32_t systemAbilityId = data.ReadInt32();
                bool ok = data.ReadBool();
                sptr<IRemoteObject> remoteObject = ok ? data.ReadRemoteObject() : nullptr;
                OnLoadSACompleteForRemote(deviceId, systemAbilityId, remoteObject);
                return ERR_NONE;
            }
            default:
                return ERR_INVALID_DATA;
        }
    }
};

} // namespace OHOS

#endif // STUBS_SYSTEM_ABILITY_LOAD_CALLBACK_STUB_H

