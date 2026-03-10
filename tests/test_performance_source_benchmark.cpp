#include <dlfcn.h>
#include <fcntl.h>
#include <unistd.h>

#include <atomic>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>

#include "idistributed_hardware_source.h"

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

class RegisterCallbackImpl final : public OHOS::DistributedHardware::RegisterCallback {
public:
    explicit RegisterCallbackImpl(std::atomic<int>& counter) : counter_(counter) {}

    int32_t OnRegisterResult(const std::string& networkId, const std::string& dhId, int32_t status,
        const std::string& data) override
    {
        (void)networkId;
        (void)dhId;
        (void)data;
        if (status == 0) {
            counter_.fetch_add(1, std::memory_order_relaxed);
        }
        return 0;
    }

private:
    std::atomic<int>& counter_;
};

using GetSourceHandlerFn = OHOS::DistributedHardware::IDistributedHardwareSource* (*)();

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
    const char* libPath = (argc >= 2) ? argv[1] : "../build/libdcamera_source.dylib";
    // Benchmark focuses on SDK direct-call overhead; keep service side minimal for deterministic behavior.
    (void)setenv("DCAMERA_SOURCE_SERVICE_MODE", "minimal", 1);

    void* handle = dlopen(libPath, RTLD_NOW | RTLD_LOCAL);
    if (handle == nullptr) {
        std::cerr << "dlopen failed: " << dlerror() << "\n";
        return 1;
    }

    auto* sym = dlsym(handle, "GetSourceHardwareHandler");
    if (sym == nullptr) {
        std::cerr << "dlsym(GetSourceHardwareHandler) failed: " << dlerror() << "\n";
        dlclose(handle);
        return 2;
    }

    auto getHandler = reinterpret_cast<GetSourceHandlerFn>(sym);
    auto* handler = getHandler();
    if (handler == nullptr) {
        std::cerr << "GetSourceHardwareHandler returned null\n";
        dlclose(handle);
        return 3;
    }

    OHOS::DistributedHardware::EnableParam param;
    param.sinkVersion = "sink_v1";
    param.sinkAttrs = "attrs";
    param.sourceVersion = "source_v1";
    param.sourceAttrs = "attrs";
    param.subtype = "camera";

    // Ensure SA is started and callback remote object is ready.
    {
        ScopedSilenceStdoutStderr silence;
        (void)handler->InitSource("{\"mock\":\"params\"}");
    }

    constexpr int initLoops = 5000;
    constexpr int regLoops = 5000;

    int64_t initUs = 0;
    int64_t regUs = 0;
    std::atomic<int> okCallbackCount { 0 };

    {
        ScopedSilenceStdoutStderr silence;
        initUs = MeasureUs([&]() {
            for (int i = 0; i < initLoops; i++) {
                (void)handler->InitSource("{\"mock\":\"params\"}");
            }
        });

        regUs = MeasureUs([&]() {
            for (int i = 0; i < regLoops; i++) {
                auto cb = std::make_shared<RegisterCallbackImpl>(okCallbackCount);
                const std::string dhId = "camera_perf_" + std::to_string(i);
                (void)handler->RegisterDistributedHardware("network1", dhId, param, cb);
            }
        });
    }

    (void)handler->ReleaseSource();
    dlclose(handle);

    std::cout << "=== Source Perf Benchmark (print-only) ===\n";
    std::cout << "InitSource: loops=" << initLoops << " total_us=" << initUs
              << " avg_us=" << (static_cast<double>(initUs) / initLoops) << "\n";
    std::cout << "RegisterDistributedHardware: loops=" << regLoops << " total_us=" << regUs
              << " avg_us=" << (static_cast<double>(regUs) / regLoops)
              << " ok_callback_count=" << okCallbackCount.load() << "\n";
    return 0;
}
