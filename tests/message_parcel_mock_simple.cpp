/*
 * Simplified MessageParcel Mock Implementation for Testing
 *
 * This is a simplified version for testing callback object passing
 */

#include "message_parcel.h"
#include "iremote_object.h"
#include <map>
#include <mutex>
#include <string>
#include <vector>

namespace OHOS {

// ============================================================================
// 全局对象引用存储
// ============================================================================

/**
 * @brief 全局对象引用管理器
 * 
 * 在进程内模式下，MessageParcel 通过此管理器存储和检索 IRemoteObject 指针。
 */
class RemoteObjectRefManager {
public:
    static RemoteObjectRefManager& GetInstance() {
        static RemoteObjectRefManager instance;
        return instance;
    }
    
    int32_t StoreObject(const sptr<IRemoteObject>& object) {
        std::lock_guard<std::mutex> lock(mutex_);
        int32_t index = nextIndex_++;
        objects_[index] = object;
        return index;
    }
    
    sptr<IRemoteObject> GetObject(int32_t index) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = objects_.find(index);
        if (it == objects_.end()) {
            return nullptr;
        }
        return it->second;
    }
    
    void RemoveObject(int32_t index) {
        std::lock_guard<std::mutex> lock(mutex_);
        objects_.erase(index);
    }
    
private:
    RemoteObjectRefManager() : nextIndex_(0) {}
    
    std::map<int32_t, sptr<IRemoteObject>> objects_;
    std::mutex mutex_;
    int32_t nextIndex_;
};

// ============================================================================
// MessageParcel 实现
// ============================================================================

MessageParcel::MessageParcel() {}

MessageParcel::~MessageParcel() {}

bool MessageParcel::WriteInt32(int value) {
    data_.push_back(value);
    return true;
}

int MessageParcel::ReadInt32() {
    if (readPos_ >= data_.size()) {
        return -1;
    }
    return data_[readPos_++];
}

bool MessageParcel::WriteString(const std::string& value) {
    strings_.push_back(value);
    return true;
}

std::string MessageParcel::ReadString() {
    if (stringReadPos_ >= strings_.size()) {
        return "";
    }
    return strings_[stringReadPos_++];
}

bool MessageParcel::WriteRemoteObject(const sptr<IRemoteObject>& object) {
    if (object == nullptr) {
        return WriteInt32(-1);
    }
    
    int32_t index = RemoteObjectRefManager::GetInstance().StoreObject(object);
    return WriteInt32(index);
}

sptr<IRemoteObject> MessageParcel::ReadRemoteObject() {
    int32_t index = ReadInt32();
    
    if (index < 0) {
        return nullptr;
    }
    
    return RemoteObjectRefManager::GetInstance().GetObject(index);
}

} // namespace OHOS
