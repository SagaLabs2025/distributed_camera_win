/*
 * SecureC Stub for macOS Mock
 *
 * 华为安全 C 库的 macOS 兼容层
 * 提供安全字符串函数的 macOS 标准库映射
 */

#ifndef STUBS_SECUREC_H
#define STUBS_SECUREC_H

#include <cstring>
#include <cstdio>
#include <cstdarg>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 安全 snprintf 函数（macOS 兼容版本）
 * 注：macOS 上使用标准 vsnprintf，不进行溢出检测
 */
#define vsnprintf_s(dest, destMax, count, format, args) \
    vsnprintf(dest, destMax, format, args)

/**
 * @brief 安全 snprintf 函数（macOS 兼容版本）
 */
#define snprintf_s(dest, destMax, count, format, ...) \
    snprintf(dest, destMax, format, ##__VA_ARGS__)

/**
 * @brief 安全 strcpy 函数（macOS 兼容版本）
 */
#define strcpy_s(dest, destMax, src) \
    (((destMax) > strlen(src)) ? (strcpy(dest, src), 0) : -1)

/**
 * @brief 安全 strncpy 函数（macOS 兼容版本）
 */
#define strncpy_s(dest, destMax, src, count) \
    strncpy(dest, src, (count) < (destMax) ? (count) : (destMax - 1))

/**
 * @brief 安全 strcat 函数（macOS 兼容版本）
 */
#define strcat_s(dest, destMax, src) \
    (((destMax) > strlen(dest) + strlen(src)) ? (strcat(dest, src), 0) : -1)

/**
 * @brief 安全 memcpy 函数（macOS 兼容版本）
 */
#define memcpy_s(dest, destMax, src, count) \
    (((destMax) >= (count)) ? (memcpy(dest, src, count), 0) : -1)

/**
 * @brief 安全 memmove 函数（macOS 兼容版本）
 */
#define memmove_s(dest, destMax, src, count) \
    (((destMax) >= (count)) ? (memmove(dest, src, count), 0) : -1)

#ifdef __cplusplus
}
#endif

#endif // STUBS_SECUREC_H
