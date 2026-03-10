/*
 * AccessTokenKit Mock Implementation for macOS
 *
 * OpenHarmony AccessTokenKit 类的 macOS Mock 空实现
 */

#include "access_token.h"
#include <string>
#include <cstdint>

namespace OHOS {
namespace Security {
namespace AccessToken {

// AccessTokenKit 静态方法实现
int AccessTokenKit::VerifyAccessToken(uint32_t tokenId, const std::string& permissionName)
{
    (void)tokenId;
    (void)permissionName;
    return 0;  // Mock: 总是返回成功（权限验证通过）
}

} // namespace AccessToken
} // namespace Security
} // namespace OHOS
