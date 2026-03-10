#ifndef STUBS_REFBASE_H
#define STUBS_REFBASE_H

#include <atomic>
#include <cstddef>
#include <type_traits>
#include <utility>

namespace OHOS {

class WeakRefCounter {
public:
    bool AttemptIncStrongRef(const void* objectId);
    void* GetRefPtr();
};

class RefBase {
public:
    RefBase() = default;
    virtual ~RefBase() = default;

    void IncStrongRef(const void* objectId)
    {
        const int32_t previous = strongRefs_.fetch_add(1, std::memory_order_relaxed);
        if (previous == 0) {
            OnFirstStrongRef(objectId);
        }
    }

    void DecStrongRef(const void* objectId)
    {
        const int32_t previous = strongRefs_.fetch_sub(1, std::memory_order_acq_rel);
        if (previous == 1) {
            OnLastStrongRef(objectId);
            delete this;
        }
    }

    bool AttemptIncStrongRef(const void* objectId)
    {
        IncStrongRef(objectId);
        return true;
    }

    int32_t GetStrongRefCount() const
    {
        return strongRefs_.load(std::memory_order_relaxed);
    }

    virtual void RefPtrCallback() {}
    virtual void OnFirstStrongRef(const void*) {}
    virtual void OnLastStrongRef(const void*) {}
    virtual void OnLastWeakRef(const void*) {}
    virtual bool OnAttemptPromoted(const void*) { return true; }

private:
    std::atomic<int32_t> strongRefs_ { 0 };
};

template <typename T>
class sptr {
public:
    sptr() = default;
    sptr(std::nullptr_t) : ptr_(nullptr) {}

    explicit sptr(T* ptr) : ptr_(ptr)
    {
        Inc();
    }

    sptr(const sptr& other) : ptr_(other.ptr_)
    {
        Inc();
    }

    template <typename U, typename = std::enable_if_t<std::is_convertible_v<U*, T*>>>
    sptr(const sptr<U>& other) : ptr_(other.GetRefPtr())
    {
        Inc();
    }

    sptr(sptr&& other) noexcept : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }

    ~sptr()
    {
        Dec();
    }

    sptr& operator=(const sptr& other)
    {
        if (this == &other) {
            return *this;
        }
        Reset(other.ptr_);
        return *this;
    }

    sptr& operator=(sptr&& other) noexcept
    {
        if (this == &other) {
            return *this;
        }
        Dec();
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
        return *this;
    }

    sptr& operator=(std::nullptr_t)
    {
        Reset(nullptr);
        return *this;
    }

    sptr& operator=(T* ptr)
    {
        Reset(ptr);
        return *this;
    }

    T* GetRefPtr() const { return ptr_; }
    T* Get() const { return ptr_; }

    void Reset(T* ptr = nullptr)
    {
        if (ptr_ == ptr) {
            return;
        }
        Dec();
        ptr_ = ptr;
        Inc();
    }

    explicit operator bool() const { return ptr_ != nullptr; }
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }

    friend bool operator==(const sptr& a, std::nullptr_t) { return a.ptr_ == nullptr; }
    friend bool operator!=(const sptr& a, std::nullptr_t) { return a.ptr_ != nullptr; }
    friend bool operator==(std::nullptr_t, const sptr& a) { return a.ptr_ == nullptr; }
    friend bool operator!=(std::nullptr_t, const sptr& a) { return a.ptr_ != nullptr; }
    friend bool operator==(const sptr& a, const sptr& b) { return a.ptr_ == b.ptr_; }
    friend bool operator!=(const sptr& a, const sptr& b) { return a.ptr_ != b.ptr_; }

private:
    void Inc()
    {
        if constexpr (std::is_base_of_v<RefBase, T>) {
            if (ptr_ != nullptr) {
                ptr_->IncStrongRef(this);
            }
        }
    }

    void Dec()
    {
        if constexpr (std::is_base_of_v<RefBase, T>) {
            if (ptr_ != nullptr) {
                ptr_->DecStrongRef(this);
            }
        }
        ptr_ = nullptr;
    }

    T* ptr_ { nullptr };
};

template <typename T>
class wptr {
public:
    wptr() = default;
    wptr(std::nullptr_t) : ptr_(nullptr) {}

    wptr(const sptr<T>& strong) : ptr_(strong.GetRefPtr()) {}

    sptr<T> Promote() const
    {
        if (ptr_ == nullptr) {
            return sptr<T>(nullptr);
        }
        return sptr<T>(ptr_);
    }

    sptr<T> promote() const
    {
        return Promote();
    }

    T* GetRefPtr() const { return ptr_; }

private:
    T* ptr_ { nullptr };
};

} // namespace OHOS

#endif // STUBS_REFBASE_H
