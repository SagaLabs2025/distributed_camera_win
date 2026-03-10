/*
 * DcameraHidumper Mock Implementation for macOS
 *
 * OpenHarmony DcameraHidumper 的 macOS Mock 空实现
 */

namespace OHOS {
namespace DistributedHardware {

class DcameraHidumper {
public:
    static DcameraHidumper& GetInstance();
    void StartDump();
    void StopDump();
};

// 实现
DcameraHidumper& DcameraHidumper::GetInstance()
{
    static DcameraHidumper instance;
    return instance;
}

void DcameraHidumper::StartDump()
{
    // Mock: 空实现
}

void DcameraHidumper::StopDump()
{
    // Mock: 空实现
}

} // namespace DistributedHardware
} // namespace OHOS
