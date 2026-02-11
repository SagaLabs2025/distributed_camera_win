/*
 * IPC Types Stub for macOS Mock
 *
 * OpenHarmony IPC 通用类型定义的 macOS 兼容层
 */

#ifndef STUBS_IPC_TYPES_H
#define STUBS_IPC_TYPES_H

#include <string>

#ifdef __cplusplus
namespace OHOS {

/**
 * @brief 字符串转换工具
 */
inline std::u16string Str8ToStr16(const std::string& str)
{
    // Mock: 简单转换，实际应使用正确的 UTF-8 到 UTF-16 转换
    std::u16string result;
    for (char c : str) {
        result.push_back(static_cast<char16_t>(c));
    }
    return result;
}

inline std::string Str16ToStr8(const std::u16string& str)
{
    // Mock: 简单转换
    std::string result;
    for (char16_t c : str) {
        result.push_back(static_cast<char>(c));
    }
    return result;
}

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IPC_TYPES_H
