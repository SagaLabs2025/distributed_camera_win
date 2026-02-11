/*
 * MessageOption Stub for macOS Mock
 *
 * OpenHarmony IPC 消息选项的 macOS 兼容层
 */

#ifndef STUBS_MESSAGE_OPTION_H
#define STUBS_MESSAGE_OPTION_H

#include <cstdint>

#ifdef __cplusplus
namespace OHOS {

/**
 * @brief IPC 消息选项
 */
class MessageOption {
public:
    /**
     * @brief 请求模式枚举
     */
    enum {
        TF_ASYNC = 0x01,
        TF_SYNC = 0x02,
        TF_WAIT_READY = 0x04,
    };

    /**
     * @brief 构造函数
     */
    MessageOption()
        : flags_(TF_SYNC), timeout_(5000)
    {
    }

    /**
     * @brief 构造函数
     * @param flags 标志位
     * @param timeout 超时时间（毫秒）
     */
    MessageOption(int32_t flags, int32_t timeout)
        : flags_(flags), timeout_(timeout)
    {
    }

    ~MessageOption() = default;

    int32_t GetFlags() const { return flags_; }
    void SetFlags(int32_t flags) { flags_ = flags; }
    int32_t GetTimeout() const { return timeout_; }
    void SetTimeout(int32_t timeout) { timeout_ = timeout; }

private:
    int32_t flags_;
    int32_t timeout_;
};

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_MESSAGE_OPTION_H
