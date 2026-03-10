#include <dlfcn.h>

#include <atomic>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <cstdlib>

#include "idistributed_hardware_source.h"

namespace {
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
            counter_.fetch_add(1);
        }
        return 0;
    }

private:
    std::atomic<int>& counter_;
};

using GetSourceHandlerFn = OHOS::DistributedHardware::IDistributedHardwareSource* (*)();
} // namespace

int main(int argc, char** argv)
{
    const char* libPath = (argc >= 2) ? argv[1] : "../build/libdcamera_source.dylib";
    // Keep this test stable: rely on MinimalSourceServiceMock for immediate callback behavior.
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

    int32_t ret = handler->InitSource("{\"mock\":\"params\"}");
    if (ret != 0) {
        std::cerr << "InitSource failed, ret=" << ret << "\n";
        dlclose(handle);
        return 4;
    }

    OHOS::DistributedHardware::EnableParam param;
    param.sinkVersion = "sink_v1";
    param.sinkAttrs = "attrs";
    param.sourceVersion = "source_v1";
    param.sourceAttrs = "attrs";
    param.subtype = "camera";

    constexpr int threadCount = 8;
    constexpr int perThreadCalls = 25;
    std::atomic<int> okCallbackCount { 0 };

    std::vector<std::thread> threads;
    threads.reserve(threadCount);
    for (int t = 0; t < threadCount; t++) {
        threads.emplace_back([&, t]() {
            for (int i = 0; i < perThreadCalls; i++) {
                auto cb = std::make_shared<RegisterCallbackImpl>(okCallbackCount);
                const std::string dhId = "camera_" + std::to_string(t) + "_" + std::to_string(i);
                (void)handler->RegisterDistributedHardware("network1", dhId, param, cb);
            }
        });
    }

    for (auto& th : threads) {
        th.join();
    }

    const int expected = threadCount * perThreadCalls;
    if (okCallbackCount.load() != expected) {
        std::cerr << "Expected callback count " << expected << ", got " << okCallbackCount.load() << "\n";
        dlclose(handle);
        return 5;
    }

    (void)handler->ReleaseSource();
    dlclose(handle);
    std::cout << "OK\n";
    return 0;
}
