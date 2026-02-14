/*
 * VideoConfigParams Mock Implementation for macOS
 *
 * OpenHarmony VideoConfigParams 的 macOS Mock 空实现
 */

namespace OHOS {
namespace DistributedHardware {

class VideoConfigParams {
public:
    void SetSystemSwitchFlagAndRotation(bool flag, int rotation);
};

// 实现
void VideoConfigParams::SetSystemSwitchFlagAndRotation(bool flag, int rotation)
{
    (void)flag;
    (void)rotation;
    // Mock: 空实现
}

} // namespace DistributedHardware
} // namespace OHOS
