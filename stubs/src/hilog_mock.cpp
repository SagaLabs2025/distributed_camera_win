/*
 * HiLog Mock Implementation for macOS
 *
 * 提供 OH_LOG_Print 函数的 mock 实现
 *
 * 简化版本：直接输出，不处理复杂的格式说明符
 */

#include <cstdarg>
#include <cstdio>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief HiLog 打印函数的 mock 实现
 * 在 macOS 上直接输出到控制台
 */
int OH_LOG_Print(int type, int level, unsigned int domain, const char *tag, const char *fmt, ...) {
    (void)type;      // 未使用的参数
    (void)level;     // 未使用的参数
    (void)domain;    // 未使用的参数

    va_list args;
    va_start(args, fmt);

    // 直接输出到控制台，不处理复杂的格式说明符
    printf("[%s] ", tag ? tag : "NULL");
    vprintf(fmt, args);
    printf("\n");

    va_end(args);
    return 0;  // 返回成功
}

#ifdef __cplusplus
}
#endif
