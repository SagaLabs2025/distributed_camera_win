/*
 * DCamera HDF Types - macOS Mock
 *
 * OpenHarmony 分布式相机 HDF 额外类型定义
 */

#ifndef STUBS_V1_1_DCAMERA_HDF_TYPES_H
#define STUBS_V1_1_DCAMERA_HDF_TYPES_H

#include <cstdint>
#include <string>
#include <vector>

namespace OHOS {
namespace HDI {
namespace DistributedCamera {
namespace V1_1 {

/**
 * @brief 分布式硬件基础信息
 */
struct DHBase {
    std::string dhId;      // 分布式硬件ID
};

/**
 * @brief 相机能力信息
 */
struct DCameraAbility {
    int32_t width;         // 宽度
    int32_t height;        // 高度

    DCameraAbility() : width(0), height(0) {}
};

/**
 * @brief 相机HDF事件
 */
struct DCameraHDFEvent {
    int32_t eventType;     // 事件类型
    int32_t eventResult;   // 事件结果
    std::string eventData; // 事件数据

    DCameraHDFEvent() : eventType(0), eventResult(0) {}
};

} // namespace V1_1
} // namespace DistributedCamera
} // namespace HDI
} // namespace OHOS

#endif // STUBS_V1_1_DCAMERA_HDF_TYPES_H
