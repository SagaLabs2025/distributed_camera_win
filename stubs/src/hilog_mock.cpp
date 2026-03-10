/*
 * HiLog Mock Implementation for macOS
 *
 * 提供 OH_LOG_Print 函数的 mock 实现。
 *
 * 兼容 OpenHarmony hilog 格式扩展：
 * - `%{public}s` / `%{private}d` 等需要转换为标准 printf 的 `%s` / `%d`
 *   才能在 macOS 的 vprintf 上正确替换参数。
 */

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <string>

#include "hilog/log.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline void ReplaceAll(std::string& s, const char* from, const char* to)
{
    if (from == nullptr || to == nullptr) {
        return;
    }
    const size_t fromLen = std::strlen(from);
    if (fromLen == 0) {
        return;
    }
    size_t pos = 0;
    while ((pos = s.find(from, pos)) != std::string::npos) {
        s.replace(pos, fromLen, to);
        pos += std::strlen(to);
    }
}

static inline std::string NormalizeHilogFormat(const char* fmt)
{
    std::string out = (fmt != nullptr) ? std::string(fmt) : std::string();
    ReplaceAll(out, "%{public}", "%");
    ReplaceAll(out, "%{private}", "%");
    return out;
}

/**
 * @brief HiLog 打印函数的 mock 实现
 * 在 macOS 上直接输出到控制台
 */
int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...) {
    (void)type;
    (void)level;
    (void)domain;

    va_list args;
    va_start(args, fmt);

    const std::string normalized = NormalizeHilogFormat(fmt);

    printf("[%s] ", tag ? tag : "NULL");
    vprintf(normalized.c_str(), args);
    printf("\n");

    va_end(args);
    return 0;  // 返回成功
}

#ifdef __cplusplus
}
#endif
