/*
 * DCamera Event Command - OpenHarmony Distributed Camera - macOS Mock
 *
 * 相机事件命令的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_EVENT_CMD_H
#define STUBS_DCAMERA_EVENT_CMD_H

#include <string>
#include <vector>

namespace OHOS {
namespace DistributedHardware {

// DCameraEvent - 相机事件
class DCameraEvent {
public:
    DCameraEvent() = default;
    virtual ~DCameraEvent() = default;

    int32_t eventType_;
    int32_t eventResult_;
    std::string value_;  // 事件值（JSON字符串）

    // Unmarshal 方法 - 从JSON字符串解析事件
    int32_t Unmarshal(const std::string& jsonStr) {
        (void)jsonStr;
        return 0;  // Mock: 返回成功
    }
};

// DCameraEventCmd - 事件命令
class DCameraEventCmd {
public:
    DCameraEventCmd() = default;
    ~DCameraEventCmd() = default;

    std::vector<DCameraEvent> events_;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_EVENT_CMD_H
