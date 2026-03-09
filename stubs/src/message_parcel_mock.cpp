/*
 * MessageParcel Mock Implementation for macOS
 *
 * Minimal in-process object passing support:
 * - WriteRemoteObject / ReadRemoteObject keep IRemoteObject references inside the parcel instance.
 */

#include "message_parcel.h"

#include "iremote_object.h"

namespace OHOS {

bool MessageParcel::WriteRemoteObject(const sptr<IRemoteObject>& object)
{
    if (object == nullptr) {
        return WriteInt32(-1);
    }
    remoteObjects_.push_back(object);
    const int32_t index = static_cast<int32_t>(remoteObjects_.size() - 1);
    return WriteInt32(index);
}

sptr<IRemoteObject> MessageParcel::ReadRemoteObject()
{
    const int32_t index = ReadInt32();
    if (index < 0) {
        return nullptr;
    }
    const size_t idx = static_cast<size_t>(index);
    if (idx >= remoteObjects_.size()) {
        return nullptr;
    }
    return remoteObjects_[idx];
}

} // namespace OHOS
