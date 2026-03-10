#ifndef STUBS_FFRT_INNER_H
#define STUBS_FFRT_INNER_H

#include <functional>
#include <memory>
#include <thread>
#include <utility>

#if defined(__APPLE__) && __has_include(<dispatch/dispatch.h>)
#include <dispatch/dispatch.h>
#define STUBS_HAVE_GCD 1
#else
#define STUBS_HAVE_GCD 0
#endif

namespace ffrt {

namespace detail {

class TaskBase {
public:
    TaskBase() = default;
    virtual ~TaskBase() = default;
    TaskBase(const TaskBase&) = delete;
    TaskBase& operator=(const TaskBase&) = delete;
    virtual void Run() = 0;
};

template <typename F>
class Task final : public TaskBase {
public:
    explicit Task(F&& f) : fn_(std::forward<F>(f)) {}
    ~Task() override = default;
    void Run() override { fn_(); }

private:
    F fn_;
};

#if STUBS_HAVE_GCD
inline void DispatchThunk(void* ctx)
{
    std::unique_ptr<TaskBase> task(static_cast<TaskBase*>(ctx));
    task->Run();
}
#endif

} // namespace detail

template <typename F>
inline void submit(F&& f)
{
#if STUBS_HAVE_GCD
    using Fn = std::decay_t<F>;
    auto* task = new detail::Task<Fn>(std::forward<F>(f));
    ::dispatch_async_f(::dispatch_get_global_queue(QOS_CLASS_DEFAULT, 0), task, detail::DispatchThunk);
#else
    std::thread(std::forward<F>(f)).detach();
#endif
}

} // namespace ffrt

#endif // STUBS_FFRT_INNER_H
