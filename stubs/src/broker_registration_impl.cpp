/*
 * BrokerRegistration Implementation for macOS
 *
 * OpenHarmony BrokerRegistration 方法的 macOS Mock 实现
 */

#include "iremote_broker.h"
#include "iremote_object.h"

namespace OHOS {

BrokerRegistration& BrokerRegistration::Get()
{
    static BrokerRegistration instance;
    return instance;
}

bool BrokerRegistration::Register(const std::u16string& descriptor,
                                   const Constructor& constructor,
                                   const BrokerDelegatorBase* delegator)
{
    (void)descriptor;
    (void)constructor;
    (void)delegator;
    return true;  // Mock: 总是成功
}

void BrokerRegistration::Unregister(const std::u16string& descriptor)
{
    (void)descriptor;
    // Mock: 空实现
}

sptr<IRemoteBroker> BrokerRegistration::NewInstance(const std::u16string& descriptor,
                                                      const sptr<IRemoteObject>& object)
{
    (void)descriptor;
    (void)object;
    return nullptr;  // Mock: 返回空指针
}

} // namespace OHOS
