/*
 * DCamera Utils Tools - OpenHarmony - macOS Stub
 *
 * 分布式相机工具函数
 */

#ifndef STUBS_DCAMERA_UTILS_TOOLS_H
#define STUBS_DCAMERA_UTILS_TOOLS_H

#include <cstdint>
#include <string>

namespace OHOS {
namespace DistributedHardware {

// 基础时间工具
int64_t GetNowTimeStampMs();
int64_t GetNowTimeStampUs();

// Base64 编码解码
std::string Base64Encode(const unsigned char *toEncode, unsigned int len);
std::string Base64Decode(const std::string& basicString);
bool IsBase64(unsigned char c);

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_UTILS_TOOLS_H
