/*
 * DistributedCameraSourceService Mock Implementation for macOS
 *
 * OpenHarmony DistributedCameraSourceService 部分方法的 macOS Mock 空实现
 */

#include <string>
#include "dcamera_index.h"

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
    static void CamDevErase(DCameraIndex& camIndex);
};

// 实现
void DistributedCameraSourceService::GetDumpInfo(CameraDumpInfo& dumpInfo)
{
    (void)dumpInfo;
    // Mock: 空实现
}

void DistributedCameraSourceService::CamDevErase(DCameraIndex& camIndex)
{
    (void)camIndex;
    // Mock: 空实现 - 在真实实现中会从设备列表中移除相机设备
}

} // namespace DistributedHardware
} // namespace OHOS
