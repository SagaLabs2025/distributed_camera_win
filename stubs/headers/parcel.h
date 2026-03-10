#ifndef STUBS_PARCEL_H
#define STUBS_PARCEL_H

#include <cstdint>
#include <cstring>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "refbase.h"

namespace OHOS {

class Parcel;

class Parcelable : public virtual RefBase {
public:
    virtual ~Parcelable() override = default;

    Parcelable() : asRemote_(false), behavior_(0) {}
    explicit Parcelable(bool asRemote) : asRemote_(asRemote), behavior_(0) {}

    virtual bool Marshalling(Parcel& parcel) const = 0;

    bool asRemote_;
    mutable uint8_t behavior_;
};

class Parcel {
public:
    Parcel() = default;
    virtual ~Parcel() = default;

    bool WriteInt32(int32_t value)
    {
        return WritePOD(value);
    }

    bool WriteUint32(uint32_t value)
    {
        return WritePOD(value);
    }

    bool ReadInt32(int32_t& out)
    {
        return ReadPOD(out);
    }

    int32_t ReadInt32()
    {
        int32_t out = 0;
        (void)ReadInt32(out);
        return out;
    }

    uint32_t ReadUint32()
    {
        uint32_t out = 0;
        (void)ReadPOD(out);
        return out;
    }

    bool WriteBool(bool value)
    {
        const uint8_t v = value ? 1 : 0;
        return WritePOD(v);
    }

    bool ReadBool(bool& out)
    {
        uint8_t v = 0;
        if (!ReadPOD(v)) {
            out = false;
            return false;
        }
        out = (v != 0);
        return true;
    }

    bool ReadBool()
    {
        bool out = false;
        (void)ReadBool(out);
        return out;
    }

    bool WriteString(const std::string& value)
    {
        if (!WriteInt32(static_cast<int32_t>(value.size()))) {
            return false;
        }
        return WriteBytes(value.data(), value.size());
    }

    std::string ReadString()
    {
        int32_t size = 0;
        if (!ReadInt32(size) || size < 0) {
            return {};
        }
        std::string out;
        out.resize(static_cast<size_t>(size));
        if (!ReadBytes(out.data(), static_cast<size_t>(size))) {
            return {};
        }
        return out;
    }

    bool WriteString16(const std::u16string& value)
    {
        const int32_t count = static_cast<int32_t>(value.size());
        if (!WriteInt32(count)) {
            return false;
        }
        return WriteBytes(reinterpret_cast<const char*>(value.data()), static_cast<size_t>(count) * sizeof(char16_t));
    }

    std::u16string ReadString16()
    {
        int32_t count = 0;
        if (!ReadInt32(count) || count < 0) {
            return {};
        }
        std::u16string out;
        out.resize(static_cast<size_t>(count));
        if (!ReadBytes(reinterpret_cast<char*>(out.data()), static_cast<size_t>(count) * sizeof(char16_t))) {
            return {};
        }
        return out;
    }

    bool WriteFileDescriptor(int fd)
    {
        return WriteInt32(fd);
    }

    int ReadFileDescriptor()
    {
        return ReadInt32();
    }

    void ResetReadPosition()
    {
        readPos_ = 0;
    }

protected:
    bool WriteBytes(const void* data, size_t size)
    {
        const auto* bytes = static_cast<const uint8_t*>(data);
        buffer_.insert(buffer_.end(), bytes, bytes + size);
        return true;
    }

    bool ReadBytes(void* out, size_t size)
    {
        if (readPos_ + size > buffer_.size()) {
            return false;
        }
        std::memcpy(out, buffer_.data() + readPos_, size);
        readPos_ += size;
        return true;
    }

    template <typename T>
    bool WritePOD(const T& value)
    {
        static_assert(std::is_trivially_copyable_v<T>);
        return WriteBytes(&value, sizeof(T));
    }

    template <typename T>
    bool ReadPOD(T& out)
    {
        static_assert(std::is_trivially_copyable_v<T>);
        return ReadBytes(&out, sizeof(T));
    }

    std::vector<uint8_t> buffer_;
    size_t readPos_ { 0 };
};

} // namespace OHOS

#endif // STUBS_PARCEL_H
