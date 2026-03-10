/*
 * DcameraHitrace Mock Implementation for macOS
 *
 * OpenHarmony DcameraHitrace 的 macOS Mock 空实现
 */

#include <string>

namespace OHOS {
namespace DistributedHardware {

void DcameraStartAsyncTrace(const std::string& taskName, int taskId)
{
    (void)taskName;
    (void)taskId;
    // Mock: 空实现
}

void DcameraFinishAsyncTrace(const std::string& taskName, int taskId)
{
    (void)taskName;
    (void)taskId;
    // Mock: 空实现
}

} // namespace DistributedHardware
} // namespace OHOS
