/*
 * EventHandler Stub for macOS
 *
 * 提供基本的 AppExecFwk::EventHandler 和 InnerEvent 定义
 * 用于源代码仓的继承和接口实现
 */

#ifndef OHOS_EVENT_HANDLER_STUB_H
#define OHOS_EVENT_HANDLER_STUB_H

#include <memory>
#include <functional>
#include <string>

namespace AppExecFwk {

// 前向声明
class EventRunner;
class EventQueue;

// Priority enum
enum class Priority {
    IMMEDIATE = 0,
    HIGH = 1,
    LOW = 2,
    IDLE = 3
};

// InnerEvent 类定义（简化版本）
class InnerEvent {
public:
    using Pointer = std::shared_ptr<InnerEvent>;

    InnerEvent() = default;
    virtual ~InnerEvent() = default;

    // Get event ID
    uint32_t GetInnerEventId() const { return eventId_; }
    
    // Static Get method - creates an InnerEvent with data
    template<typename T>
    static Pointer Get(uint32_t eventId, const std::shared_ptr<T>& data, int64_t param = 0)
    {
        (void)eventId;
        (void)data;
        (void)param;
        auto event = std::make_shared<InnerEvent>();
        event->eventId_ = eventId;
        return event;
    }

    // Static Get method - creates an InnerEvent without data
    static Pointer Get(uint32_t eventId, int64_t param = 0)
    {
        (void)eventId;
        (void)param;
        auto event = std::make_shared<InnerEvent>();
        event->eventId_ = eventId;
        return event;
    }

    // Get shared object from event
    template<typename T>
    std::shared_ptr<T> GetSharedObject() const
    {
        return nullptr;  // Mock: return null
    }

private:
    uint32_t eventId_ = 0;
};

// Get event data - non-member template function for extracting data from event
template<typename T>
inline std::shared_ptr<T> Get(const InnerEvent::Pointer& event)
{
    (void)event;
    return nullptr;  // Mock: return null
}

// EventQueue 类定义
class EventQueue {
public:
    // Priority enum inside EventQueue
    enum Priority {
        PRIORITY_IMMEDIATE = 0,
        IMMEDIATE = 0,  // Alias for PRIORITY_IMMEDIATE
        PRIORITY_HIGH = 1,
        HIGH = 1,  // Alias for PRIORITY_HIGH
        PRIORITY_LOW = 2,
        LOW = 2,  // Alias for PRIORITY_LOW
        PRIORITY_IDLE = 3,
        IDLE = 3  // Alias for PRIORITY_IDLE
    };
};

// EventRunner 类定义
class EventRunner {
public:
    using Pointer = std::shared_ptr<EventRunner>;

    EventRunner() = default;
    virtual ~EventRunner() = default;

    // Create event runner
    static Pointer Create(const std::string& name = "")
    {
        (void)name;
        return std::make_shared<EventRunner>();
    }

    // Create event runner with thread
    static Pointer Create(bool inNewThread)
    {
        (void)inNewThread;
        return std::make_shared<EventRunner>();
    }

    // Run event loop
    void Run() {}

    // Stop event loop
    void Stop() {}
};

// EventHandler 基类（简化版本，用于接口继承）
class EventHandler {
public:
    EventHandler() = default;
    explicit EventHandler(const std::shared_ptr<EventRunner>& runner) : runner_(runner) {}
    virtual ~EventHandler() = default;

    // 虚函数占位符
    virtual void ProcessEvent(const InnerEvent::Pointer &event) 
    {
        (void)event;
    }

    // Send event
    bool SendEvent(const InnerEvent::Pointer& event, int64_t delayTime = 0, EventQueue::Priority priority = EventQueue::PRIORITY_LOW)
    {
        (void)event;
        (void)delayTime;
        (void)priority;
        return true;  // Mock: always success
    }

    // Send event with priority
    bool SendEvent(uint32_t innerEventId, int64_t delayTime = 0, EventQueue::Priority priority = EventQueue::PRIORITY_LOW)
    {
        (void)innerEventId;
        (void)delayTime;
        (void)priority;
        return true;  // Mock: always success
    }

    // Remove event
    void RemoveEvent(uint32_t innerEventId)
    {
        (void)innerEventId;
    }

    // Get event runner
    std::shared_ptr<EventRunner> GetEventRunner() const
    {
        return runner_;
    }

private:
    std::shared_ptr<EventRunner> runner_;
};

} // namespace AppExecFwk

#endif // OHOS_EVENT_HANDLER_STUB_H
