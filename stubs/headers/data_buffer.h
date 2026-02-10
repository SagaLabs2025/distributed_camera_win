/*
 * Data Buffer - OpenHarmony - macOS Stub
 *
 * 数据缓冲区
 */

#ifndef STUBS_DATA_BUFFER_H
#define STUBS_DATA_BUFFER_H

#include <cstdint>
#include <memory>
#include <vector>

namespace OHOS {
namespace DistributedHardware {

// DataBuffer - 数据缓冲区
struct DataBuffer {
    std::vector<uint8_t> data_;

    DataBuffer() = default;
    explicit DataBuffer(size_t size) : data_(size) {}

    size_t Size() const { return data_.size(); }
    uint8_t* Data() { return data_.data(); }
    const uint8_t* Data() const { return data_.data(); }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DATA_BUFFER_H
