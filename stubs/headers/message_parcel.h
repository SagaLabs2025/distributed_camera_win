#ifndef STUBS_MESSAGE_PARCEL_H
#define STUBS_MESSAGE_PARCEL_H

#include <vector>

#include "parcel.h"

namespace OHOS {

class IRemoteObject;

class MessageParcel : public Parcel {
public:
    MessageParcel() = default;
    ~MessageParcel() override = default;

    bool WriteRemoteObject(const sptr<IRemoteObject>& object);
    sptr<IRemoteObject> ReadRemoteObject();

    bool WriteInterfaceToken(std::u16string token)
    {
        return WriteString16(token);
    }

    std::u16string ReadInterfaceToken()
    {
        return ReadString16();
    }

private:
    // In-process optimization: keep strong refs in the parcel instance so lifetime is tied to the call.
    std::vector<sptr<IRemoteObject>> remoteObjects_;
};

} // namespace OHOS

#endif // STUBS_MESSAGE_PARCEL_H
