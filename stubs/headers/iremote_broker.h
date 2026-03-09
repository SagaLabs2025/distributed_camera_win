#ifndef STUBS_IREMOTE_BROKER_H
#define STUBS_IREMOTE_BROKER_H

#include <atomic>
#include <functional>
#include <mutex>
#include <string>
#include <type_traits>
#include <utility>

#include "iremote_object.h"

namespace OHOS {

class IRemoteBroker : public virtual RefBase {
public:
    IRemoteBroker() = default;
    virtual ~IRemoteBroker() override = default;
    virtual sptr<IRemoteObject> AsObject() = 0;
};

class BrokerDelegatorBase {
public:
    BrokerDelegatorBase() = default;
    virtual ~BrokerDelegatorBase() = default;
    std::atomic<bool> isSoUnloaded { false };
    std::u16string descriptor_;
};

#define DECLARE_INTERFACE_DESCRIPTOR(DESCRIPTOR)                  \
    static constexpr const char16_t* metaDescriptor_ = DESCRIPTOR; \
    static inline const std::u16string GetDescriptor()            \
    {                                                             \
        return metaDescriptor_;                                   \
    }

class BrokerRegistration {
public:
    using Constructor = std::function<sptr<IRemoteBroker>(const sptr<IRemoteObject>& object)>;

    static BrokerRegistration& Get();
    bool Register(const std::u16string& descriptor, const Constructor& constructor, const BrokerDelegatorBase* delegator);
    void Unregister(const std::u16string& descriptor);
    sptr<IRemoteBroker> NewInstance(const std::u16string& descriptor, const sptr<IRemoteObject>& object);

protected:
    BrokerRegistration() = default;
    ~BrokerRegistration();
};

template <typename T>
class BrokerDelegator : public BrokerDelegatorBase {
public:
    BrokerDelegator()
    {
        descriptor_ = T::GetDescriptor();
        (void)BrokerRegistration::Get().Register(
            descriptor_,
            [](const sptr<IRemoteObject>& object) -> sptr<IRemoteBroker> {
                return sptr<IRemoteBroker>(new T(object));
            },
            this);
    }

    ~BrokerDelegator() override
    {
        isSoUnloaded.store(true);
    }
};

template <typename INTERFACE>
inline sptr<INTERFACE> iface_cast(const sptr<IRemoteObject>& object)
{
    if (object == nullptr) {
        return sptr<INTERFACE>(nullptr);
    }

    if (auto* casted = dynamic_cast<INTERFACE*>(object.GetRefPtr()); casted != nullptr) {
        return sptr<INTERFACE>(casted);
    }

    sptr<IRemoteBroker> broker = BrokerRegistration::Get().NewInstance(INTERFACE::GetDescriptor(), object);
    if (broker == nullptr) {
        return sptr<INTERFACE>(nullptr);
    }

    auto* casted = dynamic_cast<INTERFACE*>(broker.GetRefPtr());
    if (casted == nullptr) {
        return sptr<INTERFACE>(nullptr);
    }
    return sptr<INTERFACE>(casted);
}

} // namespace OHOS

#endif // STUBS_IREMOTE_BROKER_H
