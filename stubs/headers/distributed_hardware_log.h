/*
 * Distributed Camera Log - OpenHarmony - macOS Stub
 *
 * 分布式硬件日志头文件
 * 实际实现请参见 h_log.h
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_HARDWARE_LOG_H
#define STUBS_DISTRIBUTED_CAMERA_HARDWARE_LOG_H

#include "h_log.h"

// 保持兼容性的别名定义
#define distributed_hardware_log h_log
#define DHLog DHLog
#define DHLOGD DHLOGD
#define DHLOGI DHLOGI
#define DHLOGE DHLOGE
#define DHLOGW DHLOGW

// 命名空间别名（保持与源码一致）
namespace OHOS {
namespace DistributedHardware {
// 实际实现在 h_log.h 中
// 这里提供别名以确保兼容性
} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DISTRIBUTED_CAMERA_HARDWARE_LOG_H
