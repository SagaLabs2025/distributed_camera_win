/*
 * Linux Types Stub for macOS
 *
 * Linux 特定类型的 macOS 兼容层
 */

#ifndef STUBS_LINUX_TYPES_H
#define STUBS_LINUX_TYPES_H

#include <stdint.h>
#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

// Linux 特定类型定义
#ifndef __kernel_size_t
#define __kernel_size_t size_t
#endif

#ifndef __kernel_ssize_t
#define __kernel_ssize_t ssize_t
#endif

#ifndef __kernel_off_t
#define __kernel_off_t off_t
#endif

#ifndef __kernel_pid_t
#define __kernel_pid_t pid_t
#endif

#ifndef __kernel_time_t
#define __kernel_time_t time_t
#endif

#ifndef __kernel_clock_t
#define __kernel_clock_t clock_t
#endif

// 基本类型定义（Linux kernel 风格）
typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint64_t __u64;

typedef int8_t __s8;
typedef int16_t __s16;
typedef int32_t __s32;
typedef int64_t __s64;

#ifdef __cplusplus
}
#endif

#endif // STUBS_LINUX_TYPES_H
