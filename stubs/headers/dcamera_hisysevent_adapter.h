/*
 * DCamera HiSysEvent Adapter - OpenHarmony Distributed Camera - macOS Mock
 *
 * 分布式相机 HiSysEvent 适配器的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_HISYSEVENT_ADAPTER_H
#define STUBS_DCAMERA_HISYSEVENT_ADAPTER_H

#include <string>

namespace OHOS {
namespace DistributedHardware {

// HiSysEvent 事件上报
inline void ReportCameraSysEvent(const std::string& eventName, const std::string& devId,
                                  const std::string& dhId, int32_t result) {
    (void)eventName;
    (void)devId;
    (void)dhId;
    (void)result;
}

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_HISYSEVENT_ADAPTER_H
