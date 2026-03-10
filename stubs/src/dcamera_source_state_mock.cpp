/*
 * DCameraSourceState Mock Implementation for macOS
 *
 * OpenHarmony DCameraSourceState 各状态类的 macOS Mock 空实现
 */

#include <memory>

namespace OHOS {
namespace DistributedHardware {

// 前向声明
class DCameraSourceStateMachine;

// 状态基类
class DCameraSourceState {
public:
    virtual ~DCameraSourceState() = default;
};

// 初始化状态
class DCameraSourceInitState : public DCameraSourceState {
public:
    explicit DCameraSourceInitState(std::shared_ptr<DCameraSourceStateMachine>& stateMachine);
    ~DCameraSourceInitState() override = default;
};

// 注册状态
class DCameraSourceRegistState : public DCameraSourceState {
public:
    explicit DCameraSourceRegistState(std::shared_ptr<DCameraSourceStateMachine>& stateMachine);
    ~DCameraSourceRegistState() override = default;
};

// 打开状态
class DCameraSourceOpenedState : public DCameraSourceState {
public:
    explicit DCameraSourceOpenedState(std::shared_ptr<DCameraSourceStateMachine>& stateMachine);
    ~DCameraSourceOpenedState() override = default;
};

// 配置流状态
class DCameraSourceConfigStreamState : public DCameraSourceState {
public:
    explicit DCameraSourceConfigStreamState(std::shared_ptr<DCameraSourceStateMachine>& stateMachine);
    ~DCameraSourceConfigStreamState() override = default;
};

// 捕获状态
class DCameraSourceCaptureState : public DCameraSourceState {
public:
    explicit DCameraSourceCaptureState(std::shared_ptr<DCameraSourceStateMachine>& stateMachine);
    ~DCameraSourceCaptureState() override = default;
};

// 实现
DCameraSourceInitState::DCameraSourceInitState(std::shared_ptr<DCameraSourceStateMachine>& stateMachine)
{
    (void)stateMachine;
}

DCameraSourceRegistState::DCameraSourceRegistState(std::shared_ptr<DCameraSourceStateMachine>& stateMachine)
{
    (void)stateMachine;
}

DCameraSourceOpenedState::DCameraSourceOpenedState(std::shared_ptr<DCameraSourceStateMachine>& stateMachine)
{
    (void)stateMachine;
}

DCameraSourceConfigStreamState::DCameraSourceConfigStreamState(std::shared_ptr<DCameraSourceStateMachine>& stateMachine)
{
    (void)stateMachine;
}

DCameraSourceCaptureState::DCameraSourceCaptureState(std::shared_ptr<DCameraSourceStateMachine>& stateMachine)
{
    (void)stateMachine;
}

} // namespace DistributedHardware
} // namespace OHOS
