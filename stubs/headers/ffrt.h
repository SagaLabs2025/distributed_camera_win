/*
 * FFRT Namespace Stub for macOS Mock
 *
 * OpenHarmony FFRT 内核的 macOS 兼容层
 */

#ifndef STUBS_FFRT_H
#define STUBS_FFRT_H

#include <functional>
#include <utility>

#ifdef __cplusplus
namespace OHOS {
namespace ffrt {

// 简化的 FFRT 常量和类型定义
constexpr int32_t OPERATOR_LITE = 0;
constexpr int32_t OPERATOR_HARD = 1;

// QoS 级别
constexpr int qos_user_initiated = 0;
constexpr int qos_default = 1;
constexpr int qos_utility = 2;
constexpr int qos_background = 3;

/**
 * @brief Task Attr（任务属性）
 */
struct task_attr {
    const char* name_;
    int qos_;

    task_attr() : name_(nullptr), qos_(qos_default) {}

    task_attr& name(const char* n) {
        name_ = n;
        return *this;
    }

    task_attr& qos(int q) {
        qos_ = q;
        return *this;
    }
};

/**
 * @brief 提交异步任务（Mock 实现）
 * @param task 要执行的任务（可调用对象）
 * @param attr 任务属性（可选）
 */
template<typename F, typename... Attrs>
void submit(F&& task, Attrs&&... attrs) {
    (void)sizeof...(attrs);
    // Mock: 在 macOS 上同步执行任务（简化实现）
    // 在实际环境中，这会异步执行任务
    task();
}

} // namespace ffrt
} // namespace OHOS

// 全局命名空间别名，允许直接使用 ffrt::
namespace ffrt = OHOS::ffrt;

#endif // __cplusplus

#endif // STUBS_FFRT_H
