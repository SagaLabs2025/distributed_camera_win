#ifndef STUBS_IPC_OBJECT_STUB_H
#define STUBS_IPC_OBJECT_STUB_H

#include <string>
#include <vector>

#include "iremote_object.h"
#include "message_option.h"
#include "message_parcel.h"

namespace OHOS {

class IPCObjectStub : public IRemoteObject {
public:
    explicit IPCObjectStub(std::u16string descriptor = {}, bool serialInvokeFlag = false);
    ~IPCObjectStub() override;

    void OnLastStrongRef(const void* objectId) override;
    void OnFirstStrongRef(const void* objectId) override;

    int SendRequest(uint32_t code, MessageParcel& data, MessageParcel& reply, MessageOption& option) override;
    virtual int OnRemoteDump(uint32_t code, MessageParcel& data, MessageParcel& reply, MessageOption& option);
    virtual int ProcessProto(uint32_t code, MessageParcel& data, MessageParcel& reply, MessageOption& option);

    virtual int OnRemoteRequest(uint32_t code, MessageParcel& data, MessageParcel& reply, MessageOption& option);

    bool AddDeathRecipient(const sptr<DeathRecipient>& recipient) override;
    bool RemoveDeathRecipient(const sptr<DeathRecipient>& recipient) override;

    int32_t GetObjectRefCount() override;
    int Dump(int fd, const std::vector<std::u16string>& args) override;

    int GetAndSaveDBinderData(int cmd, uint32_t handle);
    int DBinderClearServiceState(uint32_t code, MessageParcel& data, MessageParcel& reply, MessageOption& option);
    int GetObjectType() const;

private:
    bool serialInvokeFlag_ { false };
};

} // namespace OHOS

#endif // STUBS_IPC_OBJECT_STUB_H
