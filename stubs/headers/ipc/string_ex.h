/*
 * StringEx Stub for macOS Mock
 *
 * OpenHarmony 字符串扩展工具的 macOS 兼容层
 */

#ifndef STUBS_STRING_EX_H
#define STUBS_STRING_EX_H

#include <string>

#ifdef __cplusplus
namespace OHOS {

/**
 * @brief 字符串扩展类
 */
class StringEx : public std::string {
public:
    StringEx() : std::string() {}
    explicit StringEx(const std::string& str) : std::string(str) {}
    StringEx(const char* str) : std::string(str) {}

    /**
     * @brief 转换为整数
     * @return 整数值
     */
    int32_t ToInt() const
    {
        try {
            return std::stoi(*this);
        } catch (...) {
            return 0;
        }
    }

    /**
     * @brief 转换为布尔值
     * @return 布尔值
     */
    bool ToBool() const
    {
        return !empty() && (*this != "0");
    }
};

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_STRING_EX_H
