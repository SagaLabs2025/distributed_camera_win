/*
 * DCameraLowLatency Mock Implementation for macOS
 *
 * OpenHarmony DCameraLowLatency 的 macOS Mock 实现
 */

#include <memory>
#include <string>

namespace OHOS {
namespace DistributedHardware {

// 前向声明
class DCameraLowLatency {
public:
    static std::shared_ptr<DCameraLowLatency> GetInstance();
    int32_t EnableLowLatency();
    int32_t DisableLowLatency();
    int32_t SetDeviceId(const std::string& devId);
};

// 单例实例
static std::shared_ptr<DCameraLowLatency> g_lowLatencyInstance = nullptr;

// 实现
std::shared_ptr<DCameraLowLatency> DCameraLowLatency::GetInstance()
{
    if (g_lowLatencyInstance == nullptr) {
        g_lowLatencyInstance = std::make_shared<DCameraLowLatency>();
    }
    return g_lowLatencyInstance;
}

int32_t DCameraLowLatency::EnableLowLatency()
{
    // Mock: 空实现，返回成功
    return 0;
}

int32_t DCameraLowLatency::DisableLowLatency()
{
    // Mock: 空实现，返回成功
    return 0;
}

int32_t DCameraLowLatency::SetDeviceId(const std::string& devId)
{
    (void)devId;
    // Mock: 空实现，返回成功
    return 0;
}

} // namespace DistributedHardware
} // namespace OHOS
