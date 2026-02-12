/*
 * Image Common Type Stub for macOS Mock
 *
 * OpenHarmony 图像通用类型定义的 macOS 兼容层
 */

#ifndef STUBS_IMAGE_COMMON_TYPE_H
#define STUBS_IMAGE_COMMON_TYPE_H

#include <cstdint>

#ifdef __cplusplus
namespace OHOS {
namespace Media {
namespace Image {

enum class ComponentName {
    YCBCR_422_SPD_8BIT = 0,
    YCBCR_422_SPD_10BIT = 1,
    YCBCR_420_SPD_8BIT = 2,
    YCBCR_422_P = 3,
    YCBCR_422_P_10BIT = 4,
};

enum class PixelFormat {
    YCBCR_420_SPD_8BIT = 0,
    YCBCR_422_SPD_8BIT = 1,
};

} // namespace Image
} // namespace Media
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IMAGE_COMMON_TYPE_H
