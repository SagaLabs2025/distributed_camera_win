/*
 * AccessToken Kit Stub for macOS Mock
 *
 * OpenHarmony 访问令牌管理服务的 macOS 兼容层
 */

#ifndef STUBS_ACCESSTOKEN_KIT_H
#define STUBS_ACCESSTOKEN_KIT_H

#include <cstdint>
#include <string>

#ifdef __cplusplus
namespace OHOS {
namespace Security {
namespace AccessToken {

// 令牌 ID 类型定义
typedef uint32_t AccessTokenID;

// 权限状态常量
enum {
    PERMISSION_GRANTED = 0,      // 权限已授予
    PERMISSION_DENIED = -1,       // 权限被拒绝
};

// AccessTokenKit 类 - 提供 accessToken 验证功能
class AccessTokenKit {
public:
    /**
     * @brief 验证调用者是否具有指定权限
     * @param tokenID 调用者的 accessToken ID
     * @param permissionName 权限名称
     * @return PERMISSION_GRANTED 表示有权限，其他值表示无权限
     */
    static int VerifyAccessToken(AccessTokenID tokenID, const std::string& permissionName)
    {
        (void)tokenID;
        (void)permissionName;
        // Mock: 总是返回权限授予
        return PERMISSION_GRANTED;
    }

    /**
     * @brief 获取第一个调用者的 Token ID
     * @return Token ID
     */
    static AccessTokenID GetFirstCallerTokenID()
    {
        return 0;  // Mock: 返回默认 Token ID
    }

private:
    AccessTokenKit() = delete;
    ~AccessTokenKit() = delete;
};

} // namespace AccessToken
} // namespace Security
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_ACCESSTOKEN_KIT_H
