#ifndef STUBS_XCOLLIE_WATCHDOG_H
#define STUBS_XCOLLIE_WATCHDOG_H

#include <cstdint>
#include <functional>
#include <string>

namespace OHOS {
namespace HiviewDFX {

class Watchdog {
public:
    static Watchdog& GetInstance()
    {
        static Watchdog instance;
        return instance;
    }

    void RunPeriodicalTask(const std::string& /*name*/, const std::function<void()>& /*task*/,
        uint64_t /*intervalMs*/, uint64_t /*delayMs*/)
    {
    }

private:
    Watchdog() = default;
    ~Watchdog() = default;
};

} // namespace HiviewDFX
} // namespace OHOS

#endif // STUBS_XCOLLIE_WATCHDOG_H

