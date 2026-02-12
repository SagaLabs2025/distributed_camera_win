/*
 * sptr (Smart Pointer) Stub for macOS Mock
 *
 * OpenHarmony 智能指针的 macOS 兼容层
 * 实现为 std::shared_ptr 的包装器
 */

#ifndef STUBS_IPC_SPTR_H
#define STUBS_IPC_SPTR_H

#include <memory>
#include <stdexcept>

#ifdef __cplusplus
namespace OHOS {

// 前向声明，用于友元声明
template<typename T> class sptr;

/**
 * @brief sptr - OpenHarmony 智能指针
 * 实现为 std::shared_ptr 的包装器，提供相同的语义
 */
template<typename T>
class sptr {
public:
    // 默认构造函数
    sptr() : ptr_(nullptr) {}

    // 从 nullptr 构造
    sptr(std::nullptr_t) : ptr_(nullptr) {}

    // 从原始指针构造（接管所有权）
    explicit sptr(T* p) : ptr_(p) {}

    // 从 std::shared_ptr 构造
    explicit sptr(const std::shared_ptr<T>& p) : ptr_(p) {}

    // 拷贝构造函数
    sptr(const sptr& other) : ptr_(other.ptr_) {}

    // 移动构造函数
    sptr(sptr&& other) noexcept : ptr_(std::move(other.ptr_)) {}

    // 转换构造函数（用于派生类到基类的转换）
    template<typename U>
    sptr(const sptr<U>& other) : ptr_(std::static_pointer_cast<T>(other.GetShared())) {}

    // 析构函数
    ~sptr() = default;

    // 赋值运算符
    sptr& operator=(const sptr& other) {
        if (this != &other) {
            ptr_ = other.ptr_;
        }
        return *this;
    }

    // 移动赋值运算符
    sptr& operator=(sptr&& other) noexcept {
        if (this != &other) {
            ptr_ = std::move(other.ptr_);
        }
        return *this;
    }

    // nullptr 赋值
    sptr& operator=(std::nullptr_t) {
        ptr_.reset();
        return *this;
    }

    // 从原始指针赋值
    sptr& operator=(T* p) {
        ptr_.reset(p);
        return *this;
    }

    // 解引用运算符
    T& operator*() const {
        return *ptr_;
    }

    // 箭头运算符
    T* operator->() const {
        return ptr_.get();
    }

    // 获取原始指针
    T* Get() const {
        return ptr_.get();
    }

    // 转换为 std::shared_ptr（公共方法用于模板转换）
    std::shared_ptr<T> GetShared() const {
        return ptr_;
    }

    // 转换运算符到 std::shared_ptr
    operator std::shared_ptr<T>() const {
        return ptr_;
    }

    // 重置指针
    void reset() {
        ptr_.reset();
    }

    // 检查是否为空
    bool operator==(std::nullptr_t) const {
        return ptr_ == nullptr;
    }

    bool operator!=(std::nullptr_t) const {
        return ptr_ != nullptr;
    }

    explicit operator bool() const {
        return ptr_ != nullptr;
    }

    // use_count 用于兼容性
    long use_count() const {
        return ptr_.use_count();
    }

    // 声明所有 sptr 实例为友元，允许访问私有成员
    template<typename U> friend class sptr;

private:
    std::shared_ptr<T> ptr_;
};

// 比较 sptr 与 nullptr
template<typename T>
bool operator==(std::nullptr_t, const sptr<T>& rhs) {
    return rhs == nullptr;
}

template<typename T>
bool operator!=(std::nullptr_t, const sptr<T>& rhs) {
    return rhs != nullptr;
}

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IPC_SPTR_H
