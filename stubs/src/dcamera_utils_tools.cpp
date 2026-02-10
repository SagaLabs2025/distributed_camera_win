/*
 * DCamera Utils Tools Implementation - OpenHarmony - macOS
 *
 * 分布式相机工具函数实现
 */

#include "dcamera_utils_tools.h"
#include <chrono>
#include <ctime>
#include <iomanip>

namespace OHOS {
namespace DistributedHardware {

int64_t GetNowTimeStampMs()
{
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

int64_t GetNowTimeStampUs()
{
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
}

bool IsBase64(unsigned char c)
{
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string Base64Encode(const unsigned char *toEncode, unsigned int len)
{
    (void)toEncode;
    (void)len;
    // Stub implementation
    return "";
}

std::string Base64Decode(const std::string& basicString)
{
    (void)basicString;
    // Stub implementation
    return "";
}

} // namespace DistributedHardware
} // namespace OHOS
