#ifndef STUBS_IREMOTE_STUB_H
#define STUBS_IREMOTE_STUB_H

#include "ipc_object_stub.h"
#include "iremote_broker.h"

namespace OHOS {

template <typename INTERFACE>
class IRemoteStub : public IPCObjectStub, public INTERFACE {
public:
    explicit IRemoteStub(bool serialInvokeFlag = false) : IPCObjectStub(INTERFACE::GetDescriptor(), serialInvokeFlag) {}
    ~IRemoteStub() override = default;

    sptr<IRemoteObject> AsObject() override
    {
        return sptr<IRemoteObject>(static_cast<IRemoteObject*>(this));
    }

    sptr<IRemoteBroker> AsInterface() override
    {
        return sptr<IRemoteBroker>(static_cast<IRemoteBroker*>(this));
    }
};

} // namespace OHOS

#endif // STUBS_IREMOTE_STUB_H

