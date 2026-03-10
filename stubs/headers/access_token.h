/*
 * AccessToken Stub for macOS Mock
 *
 * OpenHarmony AccessToken 类型定义的 macOS 兼容层
 */

#ifndef STUBS_ACCESS_TOKEN_H
#define STUBS_ACCESS_TOKEN_H

#include <string>
#include <cstdint>

namespace OHOS {
namespace Security {
namespace AccessToken {

class AccessTokenKit {
public:
    static int VerifyAccessToken(uint32_t tokenId, const std::string& permissionName);
};

} // namespace AccessToken
} // namespace Security
} // namespace OHOS

#endif // STUBS_ACCESS_TOKEN_H
