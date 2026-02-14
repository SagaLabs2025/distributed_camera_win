/*
 * DCameraSoftbusLatency Mock Implementation for macOS
 *
 * OpenHarmony DCameraSoftbusLatency 的 macOS Mock 空实现
 */

#include <string>

namespace OHOS {
namespace DistributedHardware {

// 前向声明
struct TimeSyncInfo {
    int64_t localTime;
    int64_t remoteTime;
};

class DCameraSoftbusLatency {
public:
    static DCameraSoftbusLatency& GetInstance();
    TimeSyncInfo GetTimeSyncInfo(const std::string& networkId);
};

// 实现
DCameraSoftbusLatency& DCameraSoftbusLatency::GetInstance()
{
    static DCameraSoftbusLatency instance;
    return instance;
}

TimeSyncInfo DCameraSoftbusLatency::GetTimeSyncInfo(const std::string& networkId)
{
    (void)networkId;
    TimeSyncInfo info;
    info.localTime = 0;
    info.remoteTime = 0;
    return info;  // Mock: 返回空的时间同步信息
}

} // namespace DistributedHardware
} // namespace OHOS
