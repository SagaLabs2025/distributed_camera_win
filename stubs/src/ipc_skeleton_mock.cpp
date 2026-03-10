/*
 * IPCSkeleton Mock Implementation for macOS
 *
 * Provides a minimal implementation required by SDK/Service code paths.
 */

#include "ipc_skeleton.h"

namespace OHOS {

uint32_t IPCSkeleton::GetCallingTokenID()
{
    return 0x12345678;
}

int IPCSkeleton::GetCallingUid()
{
    return 1000;
}

int IPCSkeleton::GetCallingPid()
{
    return 12345;
}

std::string IPCSkeleton::ResetCallingIdentity()
{
    return {};
}

bool IPCSkeleton::SetCallingIdentity(const std::string& identity)
{
    (void)identity;
    return true;
}

} // namespace OHOS

