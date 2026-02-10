/*
 * Anonymous String - OpenHarmony - macOS Mock
 *
 * 匿名字符串处理的 macOS 空实现
 */

#ifndef STUBS_ANONYMOUS_STRING_H
#define STUBS_ANONYMOUS_STRING_H

#include <string>

namespace OHOS {
namespace DistributedHardware {

// 获取匿名字符串（用于隐私保护）
inline std::string GetAnonyString(const std::string& input) {
    if (input.empty()) {
        return "";
    }
    // Mock: 返回固定长度的匿名字符串
    return "***";
}

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_ANONYMOUS_STRING_H
