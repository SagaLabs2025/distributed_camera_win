#include <dlfcn.h>

#include <cstdint>
#include <iostream>

#include "idistributed_hardware_sink.h"

namespace {
using GetSinkHandlerFn = OHOS::DistributedHardware::IDistributedHardwareSink* (*)();
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

    int32_t ret = handler->InitSink("{\"mock\":\"params\"}");
    if (ret != 0) {
        std::cerr << "InitSink failed, ret=" << ret << "\n";
        dlclose(handle);
        return 4;
    }

    ret = handler->ReleaseSink();
    if (ret != 0) {
        std::cerr << "ReleaseSink failed, ret=" << ret << "\n";
        dlclose(handle);
        return 5;
    }

    dlclose(handle);
    std::cout << "OK\n";
    return 0;
}

