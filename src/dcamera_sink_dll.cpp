/*
 * DCamera Sink DLL Entry Point - macOS Mock
 *
 * 分布式相机接收端动态库入口点
 */

// 包含 distributed_hardware_log.h（已包含 hilog/log.h）
#include "distributed_hardware_log.h"

#include <iostream>

namespace OHOS {
namespace DistributedHardware {

// 初始化函数
extern "C" int32_t DCameraSinkInitialize() {
    DHLOGI("DCamera Sink DLL Initialized");
    return 0;
}

// 清理函数
extern "C" int32_t DCameraSinkCleanup() {
    DHLOGI("DCamera Sink DLL Cleanup");
    return 0;
}

} // namespace DistributedHardware
} // namespace OHOS

// DLL 主函数（用于测试）
int main() {
    std::cout << "DCamera Sink Test Library" << std::endl;
    return 0;
}
