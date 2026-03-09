#ifndef STUBS_MESSAGE_OPTION_H
#define STUBS_MESSAGE_OPTION_H

#include <cstdint>

namespace OHOS {

class MessageOption {
public:
    enum Flags : int32_t {
        TF_SYNC = 0,
        TF_ASYNC = 1,
    };

    MessageOption(int flags = TF_SYNC, int waitTime = 0) : flags_(flags), waitTime_(waitTime) {}
    ~MessageOption() = default;

    int GetFlags() const { return flags_; }
    int GetWaitTime() const { return waitTime_; }

private:
    int flags_;
    int waitTime_;
};

} // namespace OHOS

#endif // STUBS_MESSAGE_OPTION_H
