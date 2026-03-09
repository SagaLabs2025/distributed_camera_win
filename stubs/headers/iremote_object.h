#ifndef STUBS_IREMOTE_OBJECT_H
#define STUBS_IREMOTE_OBJECT_H

#include <cstdint>
#include <string>
#include <vector>

#include "ipc_types.h"
#include "parcelable.h"
#include "message_option.h"
#include "message_parcel.h"

namespace OHOS {

class IRemoteBroker;

class IRemoteObject : public virtual Parcelable, public virtual RefBase {
public:
    class DeathRecipient : public virtual RefBase {
    public:
        virtual ~DeathRecipient() override = default;
        virtual void OnRemoteDied(const wptr<IRemoteObject>& object) = 0;
    };

    virtual ~IRemoteObject() override = default;

    virtual int32_t GetObjectRefCount() = 0;
    virtual int SendRequest(uint32_t code, MessageParcel& data, MessageParcel& reply, MessageOption& option) = 0;

    virtual bool IsProxyObject() const { return false; }
    virtual bool IsObjectDead() const { return false; }
    virtual std::u16string GetInterfaceDescriptor() { return descriptor_; }
    virtual bool CheckObjectLegality() const { return true; }

    virtual bool AddDeathRecipient(const sptr<DeathRecipient>& recipient) = 0;
    virtual bool RemoveDeathRecipient(const sptr<DeathRecipient>& recipient) = 0;

    bool Marshalling(Parcel& parcel) const override
    {
        (void)parcel;
        return true;
    }

    static sptr<IRemoteObject> Unmarshalling(Parcel& parcel)
    {
        (void)parcel;
        return nullptr;
    }

    static bool Marshalling(Parcel& parcel, const sptr<IRemoteObject>& object)
    {
        (void)parcel;
        (void)object;
        return true;
    }

    virtual sptr<IRemoteBroker> AsInterface() { return nullptr; }

    virtual int Dump(int fd, const std::vector<std::u16string>& args) = 0;

    std::u16string GetObjectDescriptor() const { return descriptor_; }

protected:
    explicit IRemoteObject(std::u16string descriptor = {}) : descriptor_(std::move(descriptor)) {}

    const std::u16string descriptor_;
};

} // namespace OHOS

#endif // STUBS_IREMOTE_OBJECT_H
