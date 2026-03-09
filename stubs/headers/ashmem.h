#ifndef STUBS_ASHMEM_H
#define STUBS_ASHMEM_H

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <vector>

#include "refbase.h"

namespace OHOS {

class Ashmem : public RefBase {
public:
    Ashmem(int fd, size_t size) : fd_(fd), size_(size), buffer_(size) {}
    ~Ashmem() override = default;

    bool MapReadAndWriteAshmem()
    {
        mapped_ = true;
        return true;
    }

    const void* ReadFromAshmem(size_t size, size_t offset) const
    {
        if (!mapped_ || offset >= buffer_.size()) {
            return nullptr;
        }
        if (offset + size > buffer_.size()) {
            return nullptr;
        }
        return buffer_.data() + offset;
    }

    bool WriteToAshmem(const void* data, size_t size, size_t offset)
    {
        if (!mapped_ || data == nullptr) {
            return false;
        }
        if (offset + size > buffer_.size()) {
            return false;
        }
        std::memcpy(buffer_.data() + offset, data, size);
        return true;
    }

    void UnmapAshmem()
    {
        mapped_ = false;
    }

    void CloseAshmem()
    {
        fd_ = -1;
    }

private:
    int fd_ { -1 };
    size_t size_ { 0 };
    bool mapped_ { false };
    std::vector<uint8_t> buffer_;
};

} // namespace OHOS

#endif // STUBS_ASHMEM_H

