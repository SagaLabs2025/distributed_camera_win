/*
 * DistributedCameraSourceService Mock Implementation for macOS
 *
 * OpenHarmony DistributedCameraSourceService 部分方法的 macOS Mock 空实现
 */

namespace OHOS {
namespace DistributedHardware {

// 前向声明
struct CameraDumpInfo;

class DistributedCameraSourceService {
public:
    static int32_t GetDumpInfo(CameraDumpInfo& dumpInfo)
    {
        (void)dumpInfo;
        return 0;  // Mock: 总是成功
    }
};

} // namespace DistributedHardware
} // namespace OHOS
