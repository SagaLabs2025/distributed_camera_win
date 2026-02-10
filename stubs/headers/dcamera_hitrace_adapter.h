/*
 * DCamera HiTrace Adapter - OpenHarmony Distributed Camera - macOS Mock
 *
 * 分布式相机 HiTrace 适配器的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_HITRACE_ADAPTER_H
#define STUBS_DCAMERA_HITRACE_ADAPTER_H

#include <string>

namespace OHOS {
namespace DistributedHardware {

// HiTrace 追踪开始
inline void StartCameraTrace(const std::string& name) {
    (void)name;
}

// HiTrace 追踪结束
inline void StopCameraTrace(const std::string& name) {
    (void)name;
}

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_HITRACE_ADAPTER_H
