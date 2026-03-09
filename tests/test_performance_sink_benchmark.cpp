#include <dlfcn.h>
#include <fcntl.h>
#include <unistd.h>

#include <chrono>
#include <cstdint>
#include <iostream>
#include <string>

#include "idistributed_hardware_sink.h"

namespace {
class ScopedSilenceStdoutStderr {
public:
    ScopedSilenceStdoutStderr()
    {
        fflush(stdout);
        fflush(stderr);
        savedStdout_ = dup(STDOUT_FILENO);
        savedStderr_ = dup(STDERR_FILENO);
        devNull_ = open("/dev/null", O_WRONLY);
        if (savedStdout_ >= 0 && devNull_ >= 0) {
            (void)dup2(devNull_, STDOUT_FILENO);
        }
        if (savedStderr_ >= 0 && devNull_ >= 0) {
            (void)dup2(devNull_, STDERR_FILENO);
        }
    }

    ~ScopedSilenceStdoutStderr()
    {
        fflush(stdout);
        fflush(stderr);
        if (savedStdout_ >= 0) {
            (void)dup2(savedStdout_, STDOUT_FILENO);
            close(savedStdout_);
        }
        if (savedStderr_ >= 0) {
            (void)dup2(savedStderr_, STDERR_FILENO);
            close(savedStderr_);
        }
        if (devNull_ >= 0) {
            close(devNull_);
        }
    }

    ScopedSilenceStdoutStderr(const ScopedSilenceStdoutStderr&) = delete;
    ScopedSilenceStdoutStderr& operator=(const ScopedSilenceStdoutStderr&) = delete;

private:
    int savedStdout_ { -1 };
    int savedStderr_ { -1 };
    int devNull_ { -1 };
};

using GetSinkHandlerFn = OHOS::DistributedHardware::IDistributedHardwareSink* (*)();

template <typename F>
static int64_t MeasureUs(F&& f)
{
    const auto start = std::chrono::steady_clock::now();
    f();
    const auto end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}
} // namespace

int main(int argc, char** argv)
{
    const char* libPath = (argc >= 2) ? argv[1] : "../build/libdcamera_sink.dylib";

    void* handle = dlopen(libPath, RTLD_NOW | RTLD_LOCAL);
    if (handle == nullptr) {
        std::cerr << "dlopen failed: " << dlerror() << "\n";
        return 1;
    }

    auto* sym = dlsym(handle, "GetSinkHardwareHandler");
    if (sym == nullptr) {
        std::cerr << "dlsym(GetSinkHardwareHandler) failed: " << dlerror() << "\n";
        dlclose(handle);
        return 2;
    }

    auto getHandler = reinterpret_cast<GetSinkHandlerFn>(sym);
    auto* handler = getHandler();
    if (handler == nullptr) {
        std::cerr << "GetSinkHardwareHandler returned null\n";
        dlclose(handle);
        return 3;
    }

    {
        ScopedSilenceStdoutStderr silence;
        (void)handler->InitSink("{\"mock\":\"params\"}");
    }

    constexpr int initLoops = 5000;
    constexpr int subLoops = 5000;

    int64_t initUs = 0;
    int64_t subscribeUs = 0;

    {
        ScopedSilenceStdoutStderr silence;
        initUs = MeasureUs([&]() {
            for (int i = 0; i < initLoops; i++) {
                (void)handler->InitSink("{\"mock\":\"params\"}");
            }
        });

        subscribeUs = MeasureUs([&]() {
            for (int i = 0; i < subLoops; i++) {
                const std::string dhId = "camera_perf_" + std::to_string(i);
                (void)handler->SubscribeLocalHardware(dhId, "{}");
            }
        });
    }

    (void)handler->ReleaseSink();
    dlclose(handle);

    std::cout << "=== Sink Perf Benchmark (print-only) ===\n";
    std::cout << "InitSink: loops=" << initLoops << " total_us=" << initUs
              << " avg_us=" << (static_cast<double>(initUs) / initLoops) << "\n";
    std::cout << "SubscribeLocalHardware: loops=" << subLoops << " total_us=" << subscribeUs
              << " avg_us=" << (static_cast<double>(subscribeUs) / subLoops) << "\n";
    return 0;
}

