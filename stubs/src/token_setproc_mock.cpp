/*
 * token_setproc mock implementation for macOS
 */

#include "token_setproc.h"

#include <atomic>

#include "ipc_skeleton.h"

namespace {
std::atomic<uint64_t> g_selfTokenId {0};
std::atomic<uint64_t> g_firstCallerTokenId {0};
} // namespace

extern "C" {

uint64_t GetSelfTokenID(void)
{
    return g_selfTokenId.load(std::memory_order_relaxed);
}

int SetSelfTokenID(uint64_t tokenID)
{
    g_selfTokenId.store(tokenID, std::memory_order_relaxed);
    return 0;
}

uint64_t GetFirstCallerTokenID(void)
{
    uint64_t cached = g_firstCallerTokenId.load(std::memory_order_relaxed);
    if (cached != 0) {
        return cached;
    }
    return static_cast<uint64_t>(OHOS::IPCSkeleton::GetCallingTokenID());
}

int SetFirstCallerTokenID(uint64_t tokenID)
{
    g_firstCallerTokenId.store(tokenID, std::memory_order_relaxed);
    return 0;
}

} // extern "C"

