/*
 * Distributed Hardware Log - OpenHarmony - macOS Mock
 *
 * 分布式硬件日志的 macOS 空实现
 */

#ifndef STUBS_DISTRIBUTED_HARDWARE_LOG_H
#define STUBS_DISTRIBUTED_HARDWARE_LOG_H

#include <string>
#include "dh_log.h"

namespace OHOS {
namespace DistributedHardware {

// 日志标签定义（匹配源码）
constexpr int32_t DH_LOG_TAG = 0xD004101;

// 注册相机事件上报（Mock 实现）
inline void ReportRegisterCameraEvent(const std::string& eventName, const std::string& devId,
                                       const std::string& dhId, std::string version,
                                       const std::string& errMsg) {
    (void)eventName;
    (void)devId;
    (void)dhId;
    (void)version;
    (void)errMsg;
    DHLOGI("ReportRegisterCameraEvent: %s", eventName.c_str());
}

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DISTRIBUTED_HARDWARE_LOG_H
