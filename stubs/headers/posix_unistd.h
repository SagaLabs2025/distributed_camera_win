/*
 * POSIX unistd.h Stub for macOS Mock
 *
 * POSIX 函数的 macOS 兼容层
 */

#ifndef STUBS_POSIX_UNISTD_H
#define STUBS_POSIX_UNISTD_H

#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

// usleep 在 macOS 上已废弃，但在 OpenHarmony 代码中仍在使用
// 提供兼容性定义
#ifndef usleep
#define usleep(usec) ::usleep(usec)
#endif

#ifdef __cplusplus
}
#endif

#endif // STUBS_POSIX_UNISTD_H
