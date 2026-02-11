/*
 * HiLog Adapter for macOS Mock
 *
 * 这个头文件提供 OpenHarmony HiLog 的 macOS 兼容层
 * 用于桥接 external 中的 HiLog 头文件和项目需求
 */

#ifndef STUBS_HILOG_LOG_ADAPTER_H
#define STUBS_HILOG_LOG_ADAPTER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

// LogType 定义（来自 OpenHarmony）
typedef enum {
    LOG_APP = 0,
    LOG_INIT = 1,
    LOG_CORE = 3,
} LogType;

// LogLevel 定义
typedef enum {
    LOG_DEBUG = 3,
    LOG_INFO = 4,
    LOG_WARN = 5,
    LOG_ERROR = 6,
    LOG_FATAL = 7,
} LogLevel;

// macOS Mock 实现 - HiLogPrint
// 实际的日志打印函数
int HiLogPrint(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...);

// HILOG_IMPL 宏定义 - 当 HI_LOG_ENABLE=0 时的简化版本
#ifndef HI_LOG_ENABLE
#define HI_LOG_ENABLE 0
#endif

#if HI_LOG_ENABLE == 0
    // 禁用日志时的空实现
    #define HILOG_IMPL(type, level, domain, tag, fmt, ...) \
        do { \
            if (0) { \
                printf("[%s:%d] " fmt "\n", tag ? tag : "NULL", __LINE__, ##__VA_ARGS__); \
            } \
        } while(0)
#else
    // 启用日志时的实现
    #define HILOG_IMPL(type, level, domain, tag, fmt, ...) \
        HiLogPrint(type, level, domain, tag, fmt, ##__VA_ARGS__)
#endif

// HiLog 宏定义（全大写版本，用于 C 代码）
#define HILOG_DEBUG(type, ...) HILOG_IMPL((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, __VA_ARGS__)
#define HILOG_INFO(type, ...) HILOG_IMPL((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, __VA_ARGS__)
#define HILOG_WARN(type, ...) HILOG_IMPL((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, __VA_ARGS__)
#define HILOG_ERROR(type, ...) HILOG_IMPL((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, __VA_ARGS__)
#define HILOG_FATAL(type, ...) HILOG_IMPL((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, __VA_ARGS__)

// 确保默认的 LOG_DOMAIN 和 LOG_TAG 已定义
#ifndef LOG_DOMAIN
#define LOG_DOMAIN 0
#endif

#ifndef LOG_TAG
#define LOG_TAG NULL
#endif

#ifdef __cplusplus
}
#endif

#endif // STUBS_HILOG_LOG_ADAPTER_H
