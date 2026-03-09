#ifndef STUBS_IPC_SKELETON_H
#define STUBS_IPC_SKELETON_H

#include <cstdint>
#include <string>

namespace OHOS {

class IPCSkeleton {
public:
    static uint32_t GetCallingTokenID();
    static int GetCallingUid();
    static int GetCallingPid();
    static std::string ResetCallingIdentity();
    static bool SetCallingIdentity(const std::string& identity);
};

} // namespace OHOS

#endif // STUBS_IPC_SKELETON_H

