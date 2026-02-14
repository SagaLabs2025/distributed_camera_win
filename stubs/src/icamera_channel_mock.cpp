/*
 * ICameraChannel Mock Implementation for macOS
 *
 * OpenHarmony ICameraChannel 虚函数的 macOS Mock 空实现
 */

namespace OHOS {
namespace DistributedHardware {

class ICameraChannel {
public:
    virtual ~ICameraChannel() = default;
    
    // 提供虚函数的默认实现以生成vtable
    virtual int32_t OpenChannel() { return 0; }
    virtual int32_t CloseChannel() { return 0; }
};

} // namespace DistributedHardware
} // namespace OHOS
