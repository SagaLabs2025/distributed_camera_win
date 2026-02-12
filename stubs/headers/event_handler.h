/*
 * AppExecFwk Event Handler Stub for macOS Mock
 *
 * OpenHarmony 事件处理框架的 macOS 兼容层
 */

#ifndef STUBS_EVENT_HANDLER_H
#define STUBS_EVENT_HANDLER_H

#include <string>
#include <memory>
#include <cstdint>
#include <functional>

#ifdef __cplusplus
namespace AppExecFwk {

/**
 * @brief 内部事件
 */
class InnerEvent {
public:
    // 智能指针类型别名
    using Pointer = std::shared_ptr<InnerEvent>;

    uint32_t GetInnerEventId() const { return innerEventId_; }
    uint64_t GetParam() const { return param_; }

    // GetSharedObject - 获取存储的共享参数并转换为指定类型
    template<typename T>
    std::shared_ptr<T> GetSharedObject()
    {
        return std::static_pointer_cast<T>(sharedParam_);
    }

    // Get 方法 - 返回 Pointer (shared_ptr)
    // 版本1: eventId + shared_ptr (有参数版本)
    static Pointer Get(uint32_t eventId, const std::shared_ptr<void>& param)
    {
        auto event = std::make_shared<InnerEvent>();
        event->innerEventId_ = eventId;
        event->sharedParam_ = param;
        return event;
    }

    // 版本2: eventId + shared_ptr + priority (int32_t)
    static Pointer Get(uint32_t eventId, const std::shared_ptr<void>& param, int32_t priority)
    {
        auto event = std::make_shared<InnerEvent>();
        event->innerEventId_ = eventId;
        event->sharedParam_ = param;
        event->priorityValue_ = priority;
        return event;
    }

    // 版本3: 仅 eventId（无 param 版本，用于兼容某些调用）
    static Pointer Get(uint32_t eventId)
    {
        auto event = std::make_shared<InnerEvent>();
        event->innerEventId_ = eventId;
        event->sharedParam_ = nullptr;  // 无参数时设为空
        return event;
    }

    // 兼容旧版本 - eventId + uint64_t param
    static InnerEvent Get(uint32_t eventId, uint64_t param)
    {
        InnerEvent event;
        event.innerEventId_ = eventId;
        event.param_ = param;
        return event;
    }

private:
    uint32_t innerEventId_ = 0;
    uint64_t param_ = 0;
    std::shared_ptr<void> sharedParam_;
    int32_t priorityValue_ = 0;
};

/**
 * @brief 事件运行器
 */
class EventRunner {
public:
    EventRunner() = default;

    static EventRunner* Current()
    {
        static EventRunner runner;
        return &runner;
    }

    static std::shared_ptr<EventRunner> Create(bool run = false)
    {
        (void)run;
        static auto runner = std::make_shared<EventRunner>();
        return runner;
    }

    void Run() {}
    void Stop() {}
};

/**
 * @brief 事件处理器
 */
class EventHandler {
public:
    explicit EventHandler(EventRunner* runner)
    {
        (void)runner;
    }

    // Constructor taking shared_ptr<EventRunner>
    explicit EventHandler(const std::shared_ptr<EventRunner>& runner)
    {
        (void)runner;
    }

    virtual ~EventHandler() = default;

    virtual void ProcessEvent(const InnerEvent& event)
    {
        (void)event;
    }

    // ProcessEvent 方法 - Pointer 版本（支持子类重写）
    virtual void ProcessEvent(const InnerEvent::Pointer& event)
    {
        (void)event;
    }

    void SendEvent(uint32_t eventId, uint64_t param, int64_t delayTime = 0)
    {
        (void)eventId;
        (void)param;
        (void)delayTime;
    }

    void SendEvent(InnerEvent& event)
    {
        (void)event;
    }

    // SendEvent 方法 - Pointer + delayTime + priority
    void SendEvent(const InnerEvent::Pointer& event, int64_t delayTime, int32_t priority)
    {
        (void)event;
        (void)delayTime;
        (void)priority;
    }
};

/**
 * @brief 事件队列（简化版）
 */
class EventQueue {
public:
    // 嵌套的 Priority 结构体
    struct Priority {
        static constexpr int32_t LOW = 0;
        static constexpr int32_t IMMEDIATE = 1;
        static constexpr int32_t HIGH = 2;
    };

    static EventQueue& GetInstance()
    {
        static EventQueue queue;
        return queue;
    }

    void AddHandler(EventHandler* handler)
    {
        (void)handler;
    }

    void RemoveHandler(EventHandler* handler)
    {
        (void)handler;
    }

private:
    EventQueue() = default;
};

} // namespace AppExecFwk

#endif // __cplusplus

#endif // STUBS_EVENT_HANDLER_H
