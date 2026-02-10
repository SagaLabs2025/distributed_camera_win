/*
 * Surface - OpenHarmony - macOS Stub
 *
 * Surface 接口（简化版）
 */

#ifndef STUBS_SURFACE_H
#define STUBS_SURFACE_H

#include <cstdint>
#include <memory>

namespace OHOS {
namespace Surface {

// Surface 类型标识
enum {
    SURFACE_TYPE = 0,
};

// Surface 缓冲区
struct BufferRequestConfig {
    int32_t width = 1920;
    int32_t height = 1080;
    int32_t strideAlignment = 1;
    int32_t format = 1; // RGBA_8888
    int32_t usage = 0;
};

// Surface 接口
class Surface {
public:
    Surface() = default;
    virtual ~Surface() = default;

    virtual int32_t RequestBuffer(const BufferRequestConfig& config) = 0;
    virtual int32_t FlushBuffer() = 0;
    virtual void* GetNativeWindow() = 0;
};

} // namespace Surface
} // namespace OHOS

#endif // STUBS_SURFACE_H
