/*
 * Metadata Utils Stub for macOS Mock
 *
 * OpenHarmony 元数据工具的 macOS 兼容层
 */

#ifndef STUBS_METADATA_UTILS_H
#define STUBS_METADATA_UTILS_H

#include <cstdint>

namespace OHOS {
namespace DistributedHardware {

/**
 * @brief 节点基本信息结构体
 */
struct NodeBasicInfo {
    int32_t nodeId = 0;
    const char* nodeName = nullptr;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_METADATA_UTILS_H
