/*
 * ICameraChannel Mock Implementation for macOS
 *
 * OpenHarmony ICameraChannel 虚函数的 macOS Mock 空实现
 */

namespace OHOS {
namespace DistributedHardware {

class ICameraChannel {
public:
    virtual ~ICameraChannel();
    
    // 提供虚函数的默认实现以生成vtable
    virtual int32_t OpenChannel();
    virtual int32_t CloseChannel();
};

// 实现
ICameraChannel::~ICameraChannel() = default;

int32_t ICameraChannel::OpenChannel()
{
    return 0;  // Mock: 总是成功
}

int32_t ICameraChannel::CloseChannel()
{
    return 0;  // Mock: 总是成功
}

} // namespace DistributedHardware
} // namespace OHOS
