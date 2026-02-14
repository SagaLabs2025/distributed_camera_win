/*
 * Buffer Handle Stub for macOS Mock
 *
 * OpenHarmony Buffer Handle 的 macOS 兼容层
 */

#ifndef STUBS_BUFFER_HANDLE_H
#define STUBS_BUFFER_HANDLE_H

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int32_t fd;
    int32_t reserveFds;
    int32_t reserveInts;
} BufferHandle;

#ifdef __cplusplus
}
#endif

#endif // STUBS_BUFFER_HANDLE_H
