/*
 * string_ex minimal implementation for macOS
 */

#include "string_ex.h"

#include <cstddef>
#include <cstdint>
#include <cstring>

#if defined(__APPLE__)
#include <CoreFoundation/CoreFoundation.h>
#else
#include <codecvt>
#include <locale>
#endif

namespace OHOS {

std::string Str16ToStr8(const std::u16string& str)
{
    if (str.empty()) {
        return {};
    }

#if defined(__APPLE__)
    CFStringRef cfStr = CFStringCreateWithCharactersNoCopy(
        kCFAllocatorDefault,
        reinterpret_cast<const UniChar*>(str.data()),
        static_cast<CFIndex>(str.size()),
        kCFAllocatorNull);
    if (cfStr == nullptr) {
        std::string out;
        out.reserve(str.size());
        for (char16_t ch : str) {
            out.push_back(ch <= 0x7F ? static_cast<char>(ch) : '?');
        }
        return out;
    }

    CFIndex maxSize =
        CFStringGetMaximumSizeForEncoding(CFStringGetLength(cfStr), kCFStringEncodingUTF8) + 1;
    if (maxSize <= 1) {
        CFRelease(cfStr);
        return {};
    }

    std::string out(static_cast<size_t>(maxSize), '\0');
    Boolean ok = CFStringGetCString(cfStr, out.data(), maxSize, kCFStringEncodingUTF8);
    CFRelease(cfStr);
    if (!ok) {
        out.clear();
        out.reserve(str.size());
        for (char16_t ch : str) {
            out.push_back(ch <= 0x7F ? static_cast<char>(ch) : '?');
        }
        return out;
    }

    out.resize(std::strlen(out.c_str()));
    return out;
#else
    try {
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
        return convert.to_bytes(str);
    } catch (...) {
        std::string out;
        out.reserve(str.size());
        for (char16_t ch : str) {
            out.push_back(ch <= 0x7F ? static_cast<char>(ch) : '?');
        }
        return out;
    }
#endif
}

std::u16string Str8ToStr16(const std::string& str)
{
    if (str.empty()) {
        return {};
    }

#if defined(__APPLE__)
    CFStringRef cfStr = CFStringCreateWithBytes(
        kCFAllocatorDefault,
        reinterpret_cast<const UInt8*>(str.data()),
        static_cast<CFIndex>(str.size()),
        kCFStringEncodingUTF8,
        false);
    if (cfStr == nullptr) {
        std::u16string out;
        out.reserve(str.size());
        for (unsigned char ch : str) {
            out.push_back(static_cast<char16_t>(ch));
        }
        return out;
    }

    CFIndex len = CFStringGetLength(cfStr);
    if (len <= 0) {
        CFRelease(cfStr);
        return {};
    }

    std::u16string out(static_cast<size_t>(len), u'\0');
    CFStringGetCharacters(cfStr, CFRangeMake(0, len), reinterpret_cast<UniChar*>(out.data()));
    CFRelease(cfStr);
    return out;
#else
    try {
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
        return convert.from_bytes(str);
    } catch (...) {
        std::u16string out;
        out.reserve(str.size());
        for (unsigned char ch : str) {
            out.push_back(static_cast<char16_t>(ch));
        }
        return out;
    }
#endif
}

} // namespace OHOS
