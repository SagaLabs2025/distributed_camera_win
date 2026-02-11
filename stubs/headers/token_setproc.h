/*
 * Token SetProc Stub for macOS Mock
 *
 * OpenHarmony Token 设置处理器的 macOS 兼容层
 */

#ifndef STUBS_TOKEN_SETPROC_H
#define STUBS_TOKEN_SETPROC_H

#include <cstdint>
#include <string>

#ifdef __cplusplus
namespace OHOS {
namespace Security {
namespace AccessToken {

/**
 * @brief Token 设置处理器类
 */
class TokenSetProc {
public:
    /**
     * @brief 设置进程 ID
     * @param pid 进程 ID
     * @return 成功返回 0
     */
    static int32_t SetProcessId(int32_t pid)
    {
        (void)pid;
        return 0;  // Mock: 总是返回成功
    }

    /**
     * @brief 获取进程 ID
     * @return 进程 ID
     */
    static int32_t GetProcessId()
    {
        return 0;  // Mock: 返回默认进程 ID
    }
};

} // namespace AccessToken
} // namespace Security
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_TOKEN_SETPROC_H
