/*
 * AppExecFwk EventHandler Stub for macOS Mock
 *
 * OpenHarmony Ability 框架事件处理器的 macOS 兼容层
 * 注意：这与 OHOS::Utils::EventHandler 不同
 */

#ifndef STUBS_EVENT_HANDLER_H
#define STUBS_EVENT_HANDLER_H

#include <cstdint>
#include <functional>
#include <memory>

namespace AppExecFwk {

// 前向声明
class EventRunner;

/**
 * @brief 内部事件类
 */
class InnerEvent {
public:
    using Pointer = std::shared_ptr<InnerEvent>;

    uint32_t innerEventId_;     // 事件 ID
    uint64_t param_;            // 参数
    std::shared_ptr<void> obj_; // 对象指针

    InnerEvent() : innerEventId_(0), param_(0), obj_(nullptr) {}
    virtual ~InnerEvent() = default;
};

class EventHandler {
public:
    using Callback = std::function<void()>;

    EventHandler() = default;
    virtual ~EventHandler() = default;

    // 禁用拷贝和赋值
    EventHandler(const EventHandler&) = delete;
    EventHandler& operator=(const EventHandler&) = delete;
    EventHandler(EventHandler&&) = delete;
    EventHandler& operator=(EventHandler&&) = delete;

    // Mock 方法 - 返回成功
    virtual bool ProcessEvent()
    {
        return true;  // Mock: 事件处理总是成功
    }

    virtual bool ProcessNextEvent()
    {
        return true;  // Mock: 总是有下一个事件
    }

    virtual void DropAllEvents()
    {
        // Mock: 空实现
    }

    virtual bool HasInnerEvent()
    {
        return false;  // Mock: 没有内部事件
    }

    // 处理 InnerEvent 的方法
    virtual void ProcessEvent(const InnerEvent::Pointer& event)
    {
        (void)event;  // Mock: 空实现
    }

protected:
    EventHandler(const std::shared_ptr<EventRunner>& runner)
    {
        (void)runner;  // Mock: 忽略 runner
    }
};

} // namespace AppExecFwk

#endif // STUBS_EVENT_HANDLER_H
