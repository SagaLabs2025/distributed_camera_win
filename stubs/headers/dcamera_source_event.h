/*
 * DCameraSourceEvent - OpenHarmony Distributed Camera - macOS Mock
 *
 * 相机源事件的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_SOURCE_EVENT_H
#define STUBS_DCAMERA_SOURCE_EVENT_H

#include <string>
#include <cstdint>

namespace OHOS {
namespace DistributedHardware {

// DCameraSourceEvent - 相机源事件
class DCameraSourceEvent {
public:
    DCameraSourceEvent() = default;
    virtual ~DCameraSourceEvent() = default;

    int32_t GetEventType() const { return eventType_; }
    void SetEventType(int32_t type) { eventType_ = type; }

private:
    int32_t eventType_ = 0;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_SOURCE_EVENT_H
