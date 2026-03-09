/*
 * Functional tester for libdcamera_source.dylib
 *
 * - dlopen the dylib
 * - dlsym GetSourceHardwareHandler
 * - call IDistributedHardwareSource methods
 * - capture dylib stdout/stderr and forward to original output stream
 */

#include <dlfcn.h>
#include <unistd.h>

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

#include "idistributed_hardware_source.h"

namespace {

class ScopedStdoutStderrCaptureForward {
public:
    ScopedStdoutStderrCaptureForward()
    {
        std::fflush(stdout);
        std::fflush(stderr);

        savedStdout_ = ::dup(STDOUT_FILENO);
        savedStderr_ = ::dup(STDERR_FILENO);
        if (savedStdout_ < 0 || savedStderr_ < 0) {
            throw std::runtime_error("dup(STDOUT/STDERR) failed");
        }
        forwardFd_ = savedStdout_;

        int fds[2] = { -1, -1 };
        if (::pipe(fds) != 0) {
            throw std::runtime_error("pipe() failed");
        }
        readFd_ = fds[0];
        writeFd_ = fds[1];

        (void)::dup2(writeFd_, STDOUT_FILENO);
        (void)::dup2(writeFd_, STDERR_FILENO);
        ::close(writeFd_);
        writeFd_ = -1;

        setvbuf(stdout, nullptr, _IONBF, 0);
        setvbuf(stderr, nullptr, _IONBF, 0);

        reader_ = std::thread([this]() { this->ReaderLoop(); });
    }

    ~ScopedStdoutStderrCaptureForward()
    {
        Stop();
    }

    ScopedStdoutStderrCaptureForward(const ScopedStdoutStderrCaptureForward&) = delete;
    ScopedStdoutStderrCaptureForward& operator=(const ScopedStdoutStderrCaptureForward&) = delete;

    void Stop()
    {
        bool expected = false;
        if (!stopped_.compare_exchange_strong(expected, true, std::memory_order_acq_rel)) {
            return;
        }

        std::fflush(stdout);
        std::fflush(stderr);

        // Restore stdout/stderr first; this closes the pipe write ends (fd 1/2) so ReaderLoop hits EOF.
        if (savedStdout_ >= 0) {
            (void)::dup2(savedStdout_, STDOUT_FILENO);
        }
        if (savedStderr_ >= 0) {
            (void)::dup2(savedStderr_, STDERR_FILENO);
        }

        if (reader_.joinable()) {
            reader_.join();
        }

        if (readFd_ >= 0) {
            ::close(readFd_);
            readFd_ = -1;
        }

        if (savedStdout_ >= 0) {
            ::close(savedStdout_);
            savedStdout_ = -1;
        }
        if (savedStderr_ >= 0) {
            ::close(savedStderr_);
            savedStderr_ = -1;
        }
    }

private:
    void ReaderLoop()
    {
        // Forward captured output to the original output stream (forwardFd_) so we don't recurse.
        char buf[4096];
        while (true) {
            const ssize_t n = ::read(readFd_, buf, sizeof(buf));
            if (n > 0) {
                (void)::write(forwardFd_, buf, static_cast<size_t>(n));
                continue;
            }
            // EOF or error.
            break;
        }
    }

    int forwardFd_ { -1 };
    int savedStdout_ { -1 };
    int savedStderr_ { -1 };
    int readFd_ { -1 };
    int writeFd_ { -1 };
    std::atomic<bool> stopped_ { false };
    std::thread reader_;
};

class RegisterCallbackImpl final : public OHOS::DistributedHardware::RegisterCallback {
public:
    explicit RegisterCallbackImpl(std::atomic<int>& okCount, std::mutex& mu, std::condition_variable& cv)
        : okCount_(okCount), mu_(mu), cv_(cv)
    {}

    int32_t OnRegisterResult(const std::string& networkId, const std::string& dhId, int32_t status,
        const std::string& data) override
    {
        (void)networkId;
        (void)dhId;
        (void)data;
        if (status == 0) {
            okCount_.fetch_add(1, std::memory_order_relaxed);
        }
        {
            std::lock_guard<std::mutex> lock(mu_);
            done_ = true;
        }
        cv_.notify_one();
        return 0;
    }

    bool Done() const
    {
        return done_.load(std::memory_order_acquire);
    }

private:
    std::atomic<int>& okCount_;
    std::mutex& mu_;
    std::condition_variable& cv_;
    std::atomic<bool> done_ { false };
};

class UnregisterCallbackImpl final : public OHOS::DistributedHardware::UnregisterCallback {
public:
    explicit UnregisterCallbackImpl(std::atomic<int>& okCount, std::mutex& mu, std::condition_variable& cv)
        : okCount_(okCount), mu_(mu), cv_(cv)
    {}

    int32_t OnUnregisterResult(const std::string& networkId, const std::string& dhId, int32_t status,
        const std::string& data) override
    {
        (void)networkId;
        (void)dhId;
        (void)data;
        if (status == 0) {
            okCount_.fetch_add(1, std::memory_order_relaxed);
        }
        {
            std::lock_guard<std::mutex> lock(mu_);
            done_ = true;
        }
        cv_.notify_one();
        return 0;
    }

    bool Done() const
    {
        return done_.load(std::memory_order_acquire);
    }

private:
    std::atomic<int>& okCount_;
    std::mutex& mu_;
    std::condition_variable& cv_;
    std::atomic<bool> done_ { false };
};

using GetSourceHandlerFn = OHOS::DistributedHardware::IDistributedHardwareSource* (*)();

static std::string ArgValue(int argc, char** argv, const std::string& key, const std::string& fallback = {})
{
    for (int i = 1; i + 1 < argc; i++) {
        if (argv[i] == key) {
            return argv[i + 1];
        }
    }
    return fallback;
}

static bool HasFlag(int argc, char** argv, const std::string& flag)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i] == flag) {
            return true;
        }
    }
    return false;
}

} // namespace

int main(int argc, char** argv)
{
    const std::string libPath = ArgValue(argc, argv, "--lib", "../build/libdcamera_source.dylib");
    const std::string devId = ArgValue(argc, argv, "--dev", "network1");
    const std::string dhId = ArgValue(argc, argv, "--dh", "camera_func_0");

    try {
        if (HasFlag(argc, argv, "--real-service")) {
            (void)setenv("DCAMERA_SOURCE_SERVICE_MODE", "real", 1);
        }
        if (HasFlag(argc, argv, "--minimal-service")) {
            (void)setenv("DCAMERA_SOURCE_SERVICE_MODE", "minimal", 1);
        }

        ScopedStdoutStderrCaptureForward capture;

        void* handle = dlopen(libPath.c_str(), RTLD_NOW | RTLD_LOCAL);
        if (handle == nullptr) {
            std::cerr << "dlopen failed: " << dlerror() << "\n";
            return 1;
        }

        void* sym = dlsym(handle, "GetSourceHardwareHandler");
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

        std::cout << "=== dcamera_source functional test ===\n";
        std::cout << "lib: " << libPath << "\n";
        std::cout << "devId: " << devId << " dhId: " << dhId << "\n";

        int32_t ret = handler->InitSource("{\"mock\":\"params\"}");
        std::cout << "InitSource ret=" << ret << "\n";

        std::mutex mu;
        std::condition_variable cv;
        std::atomic<int> regOk { 0 };
        std::atomic<int> unregOk { 0 };

        auto regCb = std::make_shared<RegisterCallbackImpl>(regOk, mu, cv);
        ret = handler->RegisterDistributedHardware(devId, dhId, param, regCb);
        std::cout << "RegisterDistributedHardware ret=" << ret << "\n";

        {
            std::unique_lock<std::mutex> lock(mu);
            (void)cv.wait_for(lock, std::chrono::seconds(2), [&]() { return regCb->Done(); });
        }
        std::cout << "Register callback ok_count=" << regOk.load() << "\n";

        ret = handler->ConfigDistributedHardware(devId, dhId, "mock_key", "mock_value");
        std::cout << "ConfigDistributedHardware ret=" << ret << "\n";

        OHOS::DistributedHardware::WorkModeParam wm(-1, 0, 0, false);
        ret = handler->UpdateDistributedHardwareWorkMode(devId, dhId, wm);
        std::cout << "UpdateDistributedHardwareWorkMode ret=" << ret << "\n";

        auto unregCb = std::make_shared<UnregisterCallbackImpl>(unregOk, mu, cv);
        ret = handler->UnregisterDistributedHardware(devId, dhId, unregCb);
        std::cout << "UnregisterDistributedHardware ret=" << ret << "\n";

        {
            std::unique_lock<std::mutex> lock(mu);
            (void)cv.wait_for(lock, std::chrono::seconds(2), [&]() { return unregCb->Done(); });
        }
        std::cout << "Unregister callback ok_count=" << unregOk.load() << "\n";

        ret = handler->ReleaseSource();
        std::cout << "ReleaseSource ret=" << ret << "\n";

        dlclose(handle);
        std::cout << "OK\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 10;
    }
}
