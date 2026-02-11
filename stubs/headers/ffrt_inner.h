/*
 * FFRT Inner Interface Stub for macOS Mock
 *
 * OpenHarmony Fiber Function Runtime (FFRT) 内部接口的 macOS 兼容层
 */

#ifndef STUBS_FFR_INNER_H
#define STUBS_FFR_INNER_H

#include <cstdint>
#include <functional>
#include <memory>

#ifdef __cplusplus
namespace ffrt {

// 前向声明
class Queue;

/**
 * @brief 任务优先级枚举
 */
enum TaskPriority {
    LOW,
    NORMAL,
    HIGH,
};

/**
 * @brief FFRT 队列类
 */
class Queue {
public:
    Queue() = default;
    virtual ~Queue() = default;

    // Mock 方法
    void SubmitTask(const std::function<void()>& task, TaskPriority priority = TaskPriority::NORMAL)
    {
        (void)task; (void)priority;  // Mock: 空实现
    }

    void Wait()
    {
        // Mock: 空实现
    }
};

/**
 * @brief FFRT 内部接口函数
 */

// 创建队列
static inline Queue* CreateQueue(const char* name, uint32_t flags = 0)
{
    (void)name; (void)flags;
    return new Queue();  // Mock: 返回新队列
}

// 销毁队列
static inline void DestroyQueue(Queue* queue)
{
    delete queue;  // Mock: 释放队列
}

// 提交任务到队列
static inline void Submit(Queue* queue, const std::function<void()>& task, TaskPriority priority = TaskPriority::NORMAL)
{
    if (queue) {
        queue->SubmitTask(task, priority);
    }
}

// 提交任务（无队列版本，用于全局提交）
static inline void Submit(const std::function<void()>& task, TaskPriority priority = TaskPriority::NORMAL)
{
    (void)task; (void)priority;  // Mock: 空实现
}

// 提交任务（小写版本，与源码一致）
static inline void submit(const std::function<void()>& task, TaskPriority priority = TaskPriority::NORMAL)
{
    (void)task; (void)priority;  // Mock: 空实现
}

// 获取当前队列
static inline Queue* GetCurrentQueue()
{
    return nullptr;  // Mock: 无当前队列
}

// 设置队列
static inline void SetCurrentQueue(Queue* queue)
{
    (void)queue;  // Mock: 空实现
}

} // namespace ffrt

// 常量定义（需要在命名空间外）
// 使用 const std::string 以支持 .c_str() 方法
namespace OHOS {
namespace DistributedHardware {
    const std::string REGISTER_SERVICE_NOTIFY = "regSvcNotify";
    const std::string UNREGISTER_SERVICE_NOTIFY = "unregSvcNotify";
    const std::string SINK_START_EVENT = "sinkStartEvent";
    const std::string SOURCE_START_EVENT = "srcStartEvent";
    const std::string DECODE_DATA_EVENT = "srcDecEvent";
    const std::string PIPELINE_SRC_EVENT = "srcPipeEvent";
    const std::string LOOPER_SMOOTH = "looperSmooth";
}
}

#endif // __cplusplus

#endif // STUBS_FFR_INNER_H
