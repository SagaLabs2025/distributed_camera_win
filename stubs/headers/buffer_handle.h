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
    int32_t width;
    int32_t stride;
    int32_t height;
    int32_t size;
    int32_t format;
    uint64_t usage;
    void* virAddr;
    uint64_t phyAddr;
    int32_t reserveFds;
    int32_t reserveInts;
} BufferHandle;

#ifdef __cplusplus
}
#endif

#endif // STUBS_BUFFER_HANDLE_H
