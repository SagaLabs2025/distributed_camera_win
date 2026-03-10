#include <dlfcn.h>

#include <atomic>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>
#include <cstdlib>

#include "idistributed_hardware_source.h"

namespace {
class RegisterCallbackImpl final : public OHOS::DistributedHardware::RegisterCallback {
public:
    int32_t OnRegisterResult(const std::string& networkId, const std::string& dhId, int32_t status,
        const std::string& data) override
    {
        (void)networkId;
        (void)dhId;
        (void)data;
        lastStatus_.store(status);
        called_.store(true);
        return 0;
    }

    bool Called() const { return called_.load(); }
    int32_t LastStatus() const { return lastStatus_.load(); }

private:
    std::atomic<bool> called_ { false };
    std::atomic<int32_t> lastStatus_ { -1 };
};

class UnregisterCallbackImpl final : public OHOS::DistributedHardware::UnregisterCallback {
public:
    int32_t OnUnregisterResult(const std::string& networkId, const std::string& dhId, int32_t status,
        const std::string& data) override
    {
        (void)networkId;
        (void)dhId;
        (void)data;
        lastStatus_.store(status);
        called_.store(true);
        return 0;
    }

    bool Called() const { return called_.load(); }
    int32_t LastStatus() const { return lastStatus_.load(); }

private:
    std::atomic<bool> called_ { false };
    std::atomic<int32_t> lastStatus_ { -1 };
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

    auto regCb = std::make_shared<RegisterCallbackImpl>();
    ret = handler->RegisterDistributedHardware("network1", "camera1", param, regCb);
    if (ret != 0) {
        std::cerr << "RegisterDistributedHardware failed, ret=" << ret << "\n";
        dlclose(handle);
        return 5;
    }
    if (!regCb->Called() || regCb->LastStatus() != 0) {
        std::cerr << "Register callback not called or bad status, called=" << regCb->Called()
                  << " status=" << regCb->LastStatus() << "\n";
        dlclose(handle);
        return 6;
    }

    auto unregCb = std::make_shared<UnregisterCallbackImpl>();
    ret = handler->UnregisterDistributedHardware("network1", "camera1", unregCb);
    if (ret != 0) {
        std::cerr << "UnregisterDistributedHardware failed, ret=" << ret << "\n";
        dlclose(handle);
        return 7;
    }
    if (!unregCb->Called() || unregCb->LastStatus() != 0) {
        std::cerr << "Unregister callback not called or bad status, called=" << unregCb->Called()
                  << " status=" << unregCb->LastStatus() << "\n";
        dlclose(handle);
        return 8;
    }

    ret = handler->ReleaseSource();
    if (ret != 0) {
        std::cerr << "ReleaseSource failed, ret=" << ret << "\n";
        dlclose(handle);
        return 9;
    }

    dlclose(handle);
    std::cout << "OK\n";
    return 0;
}
