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

// 定义 LOG_CORE - 源代码仓 distributed_hardware_log.h 需要这个
// 使用 LOG_APP 作为类型，domain 作为标识
#ifndef LOG_DOMAIN
#define LOG_DOMAIN 0
#endif

#ifndef LOG_TAG
#define LOG_TAG NULL
#endif

// LOG_CORE 宏定义：用于源代码仓的 HILOG_DEBUG/INFO/WARN/ERROR 宏
// 格式：LOG_CORE 是一个 (LogType, domain) 元组
#define LOG_CORE (LOG_APP, LOG_DOMAIN)

// HiLog 函数声明（macOS stub 实现）
int OH_LOG_Print(LogType type, LogLevel level, unsigned int domain, const char *tag, const char *fmt, ...);
bool OH_LOG_IsLoggable(unsigned int domain, const char *tag, LogLevel level);

// HiLog 宏定义（兼容 OpenHarmony）
#define OH_LOG_DEBUG(type, ...) ((void)OH_LOG_Print((type), LOG_DEBUG, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
#define OH_LOG_INFO(type, ...) ((void)OH_LOG_Print((type), LOG_INFO, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
#define OH_LOG_WARN(type, ...) ((void)OH_LOG_Print((type), LOG_WARN, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
#define OH_LOG_ERROR(type, ...) ((void)OH_LOG_Print((type), LOG_ERROR, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))
#define OH_LOG_FATAL(type, ...) ((void)OH_LOG_Print((type), LOG_FATAL, LOG_DOMAIN, LOG_TAG, __VA_ARGS__))

// 兼容源代码仓中使用的格式
// 源代码仓使用: HILOG_DEBUG(LOG_CORE, fmt, ...)
// 这里直接使用 OH_LOG_* 宏
#define HILOG_DEBUG(...) OH_LOG_DEBUG(__VA_ARGS__)
#define HILOG_INFO(...) OH_LOG_INFO(__VA_ARGS__)
#define HILOG_WARN(...) OH_LOG_WARN(__VA_ARGS__)
#define HILOG_ERROR(...) OH_LOG_ERROR(__VA_ARGS__)
#define HILOG_FATAL(...) OH_LOG_FATAL(__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif // HIVIEWDFX_HILOG_H
