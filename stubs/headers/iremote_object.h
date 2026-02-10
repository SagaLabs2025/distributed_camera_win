/*
 * IRemoteObject - OpenHarmony IPC - macOS Mock
 *
 * IPC 远程对象的 macOS 空实现
 */

#ifndef STUBS_IREMOTE_OBJECT_H
#define STUBS_IREMOTE_OBJECT_H

#include <memory>

namespace OHOS {

// IRemoteObject - 远程对象基类
class IRemoteObject {
public:
    virtual ~IRemoteObject() = default;
};

// sptr - 智能指针模板
template<typename T>
class sptr {
public:
    sptr() : sharedPtr_(nullptr) {}
    sptr(std::nullptr_t) : sharedPtr_(nullptr) {}
    sptr(T* ptr) : sharedPtr_(ptr) {}
    sptr(const std::shared_ptr<T>& ptr) : sharedPtr_(ptr) {}

    T& operator*() const { return *sharedPtr_; }
    T* operator->() const { return sharedPtr_.get(); }

    bool operator==(std::nullptr_t) const { return sharedPtr_ == nullptr; }
    bool operator!=(std::nullptr_t) const { return sharedPtr_ != nullptr; }

    explicit operator bool() const { return sharedPtr_ != nullptr; }

private:
    std::shared_ptr<T> sharedPtr_;
};

} // namespace OHOS

#endif // STUBS_IREMOTE_OBJECT_H
