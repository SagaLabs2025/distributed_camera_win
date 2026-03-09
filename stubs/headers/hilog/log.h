/*
 * HiLog Stub for macOS
 *
 * 提供源代码仓 distributed_hardware_log.h 所需的 LOG_CORE 定义
 * 兼容 OpenHarmony HiLog 接口
 */

#ifndef HIVIEWDFX_HILOG_H
#define HIVIEWDFX_HILOG_H

#include <cstdio>
#include <cstdarg>

#ifdef __cplusplus
extern "C" {
#endif

// 日志类型枚举（来自 external/hiviewdfx_hilog）
typedef enum {
    LOG_APP = 0,
} LogType;

// 日志级别枚举
typedef enum {
    LOG_DEBUG = 0,
    LOG_INFO = 1,
    LOG_WARN = 2,
    LOG_ERROR = 3,
    LOG_FATAL = 4,
} LogLevel;

// Define LOG_CORE - used by OpenHarmony headers as the first argument of HILOG_* macros.
// We model it as a label struct (type/domain/tag) instead of a comma tuple so it works in C++.
#ifndef LOG_DOMAIN
#define LOG_DOMAIN 0
#endif

#ifndef LOG_TAG
#define LOG_TAG NULL
#endif

typedef struct HiLogLabel {
    LogType type;
    unsigned int domain;
    const char* tag;
} HiLogLabel;

#ifdef __cplusplus
#define LOG_CORE HiLogLabel{LOG_APP, LOG_DOMAIN, LOG_TAG}
#else
#define LOG_CORE ((HiLogLabel){LOG_APP, LOG_DOMAIN, LOG_TAG})
#endif

// HiLog 函数声明（macOS stub 实现）
int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...);
bool OH_LOG_IsLoggable(unsigned int domain, const char *tag, LogLevel level);

// HiLog 宏定义（兼容 OpenHarmony）
// OpenHarmony usage: HILOG_INFO(LOG_CORE, fmt, ...)
#define HILOG_DEBUG(label, ...) ((void)OH_LOG_Print((label).type, LOG_DEBUG, (label).domain, (label).tag, __VA_ARGS__))
#define HILOG_INFO(label, ...) ((void)OH_LOG_Print((label).type, LOG_INFO, (label).domain, (label).tag, __VA_ARGS__))
#define HILOG_WARN(label, ...) ((void)OH_LOG_Print((label).type, LOG_WARN, (label).domain, (label).tag, __VA_ARGS__))
#define HILOG_ERROR(label, ...) ((void)OH_LOG_Print((label).type, LOG_ERROR, (label).domain, (label).tag, __VA_ARGS__))
#define HILOG_FATAL(label, ...) ((void)OH_LOG_Print((label).type, LOG_FATAL, (label).domain, (label).tag, __VA_ARGS__))

// Compatibility aliases (rarely used in our codebase, but keep for completeness).
#define OH_LOG_DEBUG(label, ...) HILOG_DEBUG(label, __VA_ARGS__)
#define OH_LOG_INFO(label, ...) HILOG_INFO(label, __VA_ARGS__)
#define OH_LOG_WARN(label, ...) HILOG_WARN(label, __VA_ARGS__)
#define OH_LOG_ERROR(label, ...) HILOG_ERROR(label, __VA_ARGS__)
#define OH_LOG_FATAL(label, ...) HILOG_FATAL(label, __VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif // HIVIEWDFX_HILOG_H
