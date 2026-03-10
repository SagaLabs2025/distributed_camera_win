/*
 * Surface Stub for macOS Mock
 *
 * OpenHarmony Surface 类型定义的 macOS 兼容层
 */

#ifndef STUBS_SURFACE_H
#define STUBS_SURFACE_H

#include "refbase.h"
#include <cstdint>

namespace OHOS {

// Surface 类的前向声明和基本定义
class Surface : public RefBase {
public:
    Surface() = default;
    virtual ~Surface() = default;
};

} // namespace OHOS

#endif // STUBS_SURFACE_H
