/*
 * DistributedCameraSourceService Mock Implementation for macOS
 *
 * OpenHarmony DistributedCameraSourceService 部分方法的 macOS Mock 空实现
 */

#include <string>

namespace OHOS {
namespace DistributedHardware {

// 前向声明
struct CameraDumpInfo {
    std::string devId;
    std::string dhId;
    std::string state;
};

class DistributedCameraSourceService {
public:
    void GetDumpInfo(CameraDumpInfo& dumpInfo);
};

// 实现
void DistributedCameraSourceService::GetDumpInfo(CameraDumpInfo& dumpInfo)
{
    (void)dumpInfo;
    // Mock: 空实现
}

} // namespace DistributedHardware
} // namespace OHOS
