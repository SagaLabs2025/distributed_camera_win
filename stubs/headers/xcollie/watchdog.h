/*
 * XCollie Watchdog Stub for macOS Mock
 *
 * OpenHarmony XCollie 看门狗服务的 macOS 兼容层
 */

#ifndef STUBS_XCOLLIE_WATCHDOG_H
#define STUBS_XCOLLIE_WATCHDOG_H

#include <cstdint>
#include <functional>
#include <string>

#ifdef __cplusplus
namespace OHOS {
namespace HiviewDFX {
namespace XCollie {

/**
 * @brief 看门狗类
 */
class Watchdog {
public:
    /**
     * @brief 构造函数
     * @param name 看门狗名称
     * @param timeoutMs 超时时间（毫秒）
     * @param callback 超时回调函数
     */
    Watchdog(const std::string& name, uint32_t timeoutMs, const std::function<void()>& callback)
        : name_(name), timeoutMs_(timeoutMs), callback_(callback)
    {
        // Mock: 空实现
    }

    ~Watchdog() = default;

    /**
     * @brief 获取单例实例
     * @return 看门狗实例指针
     */
    static Watchdog* GetInstance(const std::string& name, uint32_t timeoutMs, const std::function<void()>& callback)
    {
        (void)name; (void)timeoutMs; (void)callback;
        static Watchdog instance("", 0, nullptr);
        return &instance;
    }

    /**
     * @brief 启动看门狗
     */
    void Start()
    {
        // Mock: 空实现
    }

    /**
     * @brief 停止看门狗
     */
    void Stop()
    {
        // Mock: 空实现
    }

    /**
     * @brief 重置看门狗（喂狗）
     */
    void Reset()
    {
        // Mock: 空实现
    }

private:
    std::string name_;
    uint32_t timeoutMs_;
    std::function<void()> callback_;
};

/**
 * @brief 看门狗静态函数（可选实现）
 */
static inline void WatchdogRun(const std::string& name, uint32_t timeoutMs,
                                const std::function<void()>& callback)
{
    (void)name; (void)timeoutMs; (void)callback;  // Mock: 空实现
}

} // namespace XCollie
} // namespace HiviewDFX
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_XCOLLIE_WATCHDOG_H
