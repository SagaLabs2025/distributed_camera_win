#ifndef STUBS_PEER_HOLDER_H
#define STUBS_PEER_HOLDER_H

#include "iremote_object.h"

namespace OHOS {

class PeerHolder {
public:
    PeerHolder() = default;
    explicit PeerHolder(const sptr<IRemoteObject>& object) : remote_(object) {}
    virtual ~PeerHolder() = default;

    sptr<IRemoteObject> Remote() { return remote_; }

private:
    sptr<IRemoteObject> remote_ { nullptr };
};

} // namespace OHOS

#endif // STUBS_PEER_HOLDER_H

