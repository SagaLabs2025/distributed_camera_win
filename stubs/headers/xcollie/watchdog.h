/*
 * Watchdog Stub for macOS Mock
 *
 * OpenHarmony XCollie Watchdog 的 macOS 兼容层
 */

#ifndef STUBS_XCOLLIE_WATCHDOG_H
#define STUBS_XCOLLIE_WATCHDOG_H

#include <cstdint>

namespace OHOS {
namespace HiviewDFX {

class Watchdog {
public:
    static constexpr int THREAD_FORKED = 0;
    
    static int AddThread(const char* name, int timeout = 0)
    {
        (void)name;
        (void)timeout;
        return 0;  // Mock: 总是成功
    }
};

} // namespace HiviewDFX
} // namespace OHOS

#endif // STUBS_XCOLLIE_WATCHDOG_H
