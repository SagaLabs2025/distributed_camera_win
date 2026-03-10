/*
 * DCameraSourceController Mock Implementation for macOS
 *
 * OpenHarmony DCameraSourceController 的 macOS Mock 空实现
 */

#include <string>
#include <memory>

namespace OHOS {
namespace DistributedHardware {

// 前向声明
class DCameraSourceStateMachine;
class DCameraSourceDev;

class DCameraSourceController {
public:
    // Constructor with references
    DCameraSourceController(const std::string& devId,
                            const std::string& dhId,
                            std::shared_ptr<DCameraSourceStateMachine>& stateMachine,
                            std::shared_ptr<DCameraSourceDev>& sourceDev);
    
    // Constructor with values (for std::make_shared)
    DCameraSourceController(std::string devId,
                            std::string dhId,
                            std::shared_ptr<DCameraSourceStateMachine>& stateMachine,
                            std::shared_ptr<DCameraSourceDev>& sourceDev);
    
    virtual ~DCameraSourceController() = default;
};

// 实现
DCameraSourceController::DCameraSourceController(
    const std::string& devId,
    const std::string& dhId,
    std::shared_ptr<DCameraSourceStateMachine>& stateMachine,
    std::shared_ptr<DCameraSourceDev>& sourceDev)
{
    (void)devId;
    (void)dhId;
    (void)stateMachine;
    (void)sourceDev;
}

DCameraSourceController::DCameraSourceController(
    std::string devId,
    std::string dhId,
    std::shared_ptr<DCameraSourceStateMachine>& stateMachine,
    std::shared_ptr<DCameraSourceDev>& sourceDev)
{
    (void)devId;
    (void)dhId;
    (void)stateMachine;
    (void)sourceDev;
}

} // namespace DistributedHardware
} // namespace OHOS
