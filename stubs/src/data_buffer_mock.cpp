/*
 * DataBuffer Mock Implementation for macOS
 *
 * OpenHarmony DataBuffer 类的 macOS Mock 空实现
 */

#include "data_buffer.h"

namespace OHOS {
namespace DistributedHardware {

// DataBuffer 构造函数
DataBuffer::DataBuffer(size_t capacity) : capacity_(capacity)
{
    // Mock: 空实现
}

// DataBuffer 析构函数
DataBuffer::~DataBuffer()
{
    // Mock: 空实现
}

// DataBuffer 方法的空实现
size_t DataBuffer::Size() const
{
    return rangeLength_;  // Mock: 返回范围长度
}

size_t DataBuffer::Offset() const
{
    return rangeOffset_;  // Mock: 返回偏移量
}

size_t DataBuffer::Capacity() const
{
    return capacity_;  // Mock: 返回容量
}

uint8_t* DataBuffer::Data() const
{
    return data_;  // Mock: 返回数据指针
}

int32_t DataBuffer::SetRange(size_t offset, size_t size)
{
    rangeOffset_ = offset;
    rangeLength_ = size;
    return 0;  // Mock: 总是成功
}

void DataBuffer::SetInt32(const std::string name, int32_t value)
{
    int32Map_[name] = value;
}

void DataBuffer::SetInt64(const std::string name, int64_t value)
{
    int64Map_[name] = value;
}

void DataBuffer::SetString(const std::string name, std::string value)
{
    stringMap_[name] = value;
}

bool DataBuffer::FindInt32(const std::string& name, int32_t& value)
{
    auto it = int32Map_.find(name);
    if (it != int32Map_.end()) {
        value = it->second;
        return true;
    }
    return false;
}

bool DataBuffer::FindInt64(const std::string& name, int64_t& value)
{
    auto it = int64Map_.find(name);
    if (it != int64Map_.end()) {
        value = it->second;
        return true;
    }
    return false;
}

bool DataBuffer::FindString(const std::string& name, std::string& value)
{
    auto it = stringMap_.find(name);
    if (it != stringMap_.end()) {
        value = it->second;
        return true;
    }
    return false;
}

int64_t DataBuffer::GetTimeStamp()
{
    return 0;  // Mock: 返回0时间戳
}

} // namespace DistributedHardware
} // namespace OHOS
