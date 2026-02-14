/*
 * DistributedCameraSinkService Mock Implementation for macOS
 *
 * OpenHarmony DistributedCameraSinkService 部分方法的 macOS Mock 空实现
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

class DistributedCameraSinkService {
public:
    void GetCamDumpInfo(CameraDumpInfo& dumpInfo);
};

// 实现
void DistributedCameraSinkService::GetCamDumpInfo(CameraDumpInfo& dumpInfo)
{
    (void)dumpInfo;
    // Mock: 空实现
}

} // namespace DistributedHardware
} // namespace OHOS
