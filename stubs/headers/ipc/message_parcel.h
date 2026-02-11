/*
 * MessageParcel Stub for macOS Mock
 *
 * OpenHarmony IPC 数据传输包的 macOS 兼容层
 */

#ifndef STUBS_MESSAGE_PARCEL_H
#define STUBS_MESSAGE_PARCEL_H

#include <cstdint>
#include <string>
#include <vector>
#include <memory>

// Forward declarations to avoid circular dependencies
class MessageOption;

#ifdef __cplusplus
namespace OHOS {

// Forward declare sptr template
template<typename T> class sptr;
class IRemoteObject;

/**
 * @brief IPC 消息数据包
 * 用于跨进程数据传输
 */
class MessageParcel {
public:
    MessageParcel() = default;
    ~MessageParcel() = default;

    // 写入数据
    bool WriteInt32(int32_t value) { data_.push_back(value); return true; }
    bool WriteUInt32(uint32_t value) { data_.push_back(static_cast<int32_t>(value)); return true; }
    bool WriteInt64(int64_t value) { data64_.push_back(value); return true; }
    bool WriteString(const std::string& value) { strings_.push_back(value); return true; }
    bool WriteString16(const std::u16string& value) { strings16_.push_back(value); return true; }
    bool WriteBuffer(const void* data, size_t size) {
        (void)data; (void)size;
        return true;
    }
    bool WriteRemoteObject(const void* object) {
        (void)object;
        return true;
    }
    bool WriteInterfaceToken(const std::string& descriptor) {
        (void)descriptor;
        return true;  // Mock: 总是成功
    }
    bool WriteInterfaceToken(const std::u16string& descriptor) {
        (void)descriptor;
        return true;  // Mock: 总是成功
    }

    // 读取数据
    bool ReadInt32(int32_t& value) {
        if (idx_ < data_.size()) {
            value = data_[idx_++];
            return true;
        }
        return false;
    }
    int32_t ReadInt32() {
        if (idx_ < data_.size()) {
            return data_[idx_++];
        }
        return 0;  // Mock: 返回默认值
    }
    bool ReadUInt32(uint32_t& value) {
        if (idx_ < data_.size()) {
            value = static_cast<uint32_t>(data_[idx_++]);
            return true;
        }
        return false;
    }
    bool ReadInt64(int64_t& value) {
        if (idx64_ < data64_.size()) {
            value = data64_[idx64_++];
            return true;
        }
        return false;
    }
    bool ReadString(std::string& value) {
        if (idxStr_ < strings_.size()) {
            value = strings_[idxStr_++];
            return true;
        }
        return false;
    }
    std::string ReadString() {
        if (idxStr_ < strings_.size()) {
            return strings_[idxStr_++];
        }
        return "";  // Mock: 返回空字符串
    }
    bool ReadString16(std::u16string& value) {
        if (idxStr16_ < strings16_.size()) {
            value = strings16_[idxStr16_++];
            return true;
        }
        return false;
    }
    std::u16string ReadInterfaceToken() {
        // Mock: 返回空 UTF-16 字符串
        return u"";
    }
    IRemoteObject* ReadRemoteObject() {
        // Mock: 返回空指针
        return nullptr;
    }
    int32_t ReadFileDescriptor() {
        // Mock: 返回默认文件描述符
        return -1;
    }
    uint32_t ReadUint32() {
        // 别名，调用 ReadUInt32 的无参版本
        uint32_t value = 0;
        if (idx_ < data_.size()) {
            value = static_cast<uint32_t>(data_[idx_++]);
        }
        return value;
    }

    // 工具方法
    void RewindRead(uint32_t size) {
        (void)size;
        idx_ = 0;
        idx64_ = 0;
        idxStr_ = 0;
        idxStr16_ = 0;
    }
    size_t GetDataSize() const { return data_.size() * sizeof(int32_t); }
    const void* GetData() const { return data_.data(); }
    bool SetDataCapacity(size_t size) {
        (void)size;
        return true;
    }

private:
    std::vector<int32_t> data_;
    std::vector<int64_t> data64_;
    std::vector<std::string> strings_;
    std::vector<std::u16string> strings16_;
    size_t idx_ = 0;
    size_t idx64_ = 0;
    size_t idxStr_ = 0;
    size_t idxStr16_ = 0;
};

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_MESSAGE_PARCEL_H
