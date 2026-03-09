/*
 * BrokerRegistration Implementation for macOS
 *
 * OpenHarmony BrokerRegistration 方法的 macOS Mock 实现
 */

#include "iremote_broker.h"

#include <mutex>
#include <unordered_map>

namespace OHOS {

namespace {
struct Entry {
    BrokerRegistration::Constructor constructor;
    const BrokerDelegatorBase* delegator { nullptr };
};

class RegistryState {
public:
    std::mutex mutex;
    std::unordered_map<std::u16string, Entry> entries;
};

RegistryState& GetRegistryState()
{
    // Intentionally leaked to avoid static destruction order issues when dylibs unload.
    static RegistryState* state = new RegistryState();
    return *state;
}
} // namespace

BrokerRegistration& BrokerRegistration::Get()
{
    static BrokerRegistration instance;
    return instance;
}

BrokerRegistration::~BrokerRegistration()
{
}

bool BrokerRegistration::Register(const std::u16string& descriptor,
                                   const Constructor& constructor,
                                   const BrokerDelegatorBase* delegator)
{
    auto& state = GetRegistryState();
    std::lock_guard<std::mutex> lock(state.mutex);
    state.entries[descriptor] = Entry { constructor, delegator };
    return true;
}

void BrokerRegistration::Unregister(const std::u16string& descriptor)
{
    auto& state = GetRegistryState();
    std::lock_guard<std::mutex> lock(state.mutex);
    state.entries.erase(descriptor);
}

sptr<IRemoteBroker> BrokerRegistration::NewInstance(const std::u16string& descriptor,
                                                      const sptr<IRemoteObject>& object)
{
    BrokerRegistration::Constructor ctor;
    {
        auto& state = GetRegistryState();
        std::lock_guard<std::mutex> lock(state.mutex);
        auto it = state.entries.find(descriptor);
        if (it == state.entries.end()) {
            return nullptr;
        }
        ctor = it->second.constructor;
    }

    if (!ctor) {
        return nullptr;
    }
    return ctor(object);
}

} // namespace OHOS
