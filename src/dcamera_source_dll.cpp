/*
 * DCamera Source DLL Entry Point - macOS Mock
 *
 * 分布式相机源端动态库入口点
 */

// 包含 distributed_hardware_log.h（已包含 hilog/log.h）
#include "distributed_hardware_log.h"

#include <iostream>

namespace OHOS {
namespace DistributedHardware {

// 初始化函数
extern "C" int32_t DCameraSourceInitialize() {
    DHLOGI("DCamera Source DLL Initialized");
    return 0;
}

// 清理函数
extern "C" int32_t DCameraSourceCleanup() {
    DHLOGI("DCamera Source DLL Cleanup");
    return 0;
}

} // namespace DistributedHardware
} // namespace OHOS

// DLL 主函数（用于测试）
int main() {
    std::cout << "DCamera Source Test Library" << std::endl;
    return 0;
}
