#ifndef STUBS_IREMOTE_PROXY_H
#define STUBS_IREMOTE_PROXY_H

#include "iremote_broker.h"
#include "peer_holder.h"

namespace OHOS {

template <typename INTERFACE>
class IRemoteProxy : public PeerHolder, public INTERFACE {
public:
    explicit IRemoteProxy(const sptr<IRemoteObject>& object) : PeerHolder(object) {}
    ~IRemoteProxy() override = default;

protected:
    sptr<IRemoteObject> AsObject() override
    {
        return Remote();
    }
};

} // namespace OHOS

#endif // STUBS_IREMOTE_PROXY_H

