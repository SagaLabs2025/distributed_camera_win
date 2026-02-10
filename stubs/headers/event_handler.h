/*
 * EventHandler - OpenHarmony Event Framework - macOS Mock
 *
 * 事件处理框架的 macOS 空实现
 */

#ifndef STUBS_EVENT_HANDLER_H
#define STUBS_EVENT_HANDLER_H

#include <memory>
#include <cstdint>

namespace AppExecFwk {

// InnerEvent - 内部事件
class InnerEvent {
public:
    using Pointer = std::shared_ptr<InnerEvent>;

    InnerEvent() = default;
    virtual ~InnerEvent() = default;

    uint32_t GetInnerEventId() const { return 0; }
};

// EventRunner - 事件运行器
class EventRunner : public std::enable_shared_from_this<EventRunner> {
public:
    static std::shared_ptr<EventRunner> Create() {
        return std::make_shared<EventRunner>();
    }
};

// EventHandler - 事件处理器
class EventHandler {
public:
    EventHandler(const std::shared_ptr<EventRunner>& runner) {
        (void)runner;
    }
    virtual ~EventHandler() = default;

    virtual void ProcessEvent(const InnerEvent::Pointer& event) {
        (void)event;
    }
};

} // namespace AppExecFwk

#endif // STUBS_EVENT_HANDLER_H
