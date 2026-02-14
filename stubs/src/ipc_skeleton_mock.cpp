/*
 * IPCSkeleton Mock Implementation for macOS
 *
 * OpenHarmony IPCSkeleton 类的 macOS Mock 空实现
 */

#include <cstdint>
#include <string>

namespace OHOS {

// IPCSkeleton 类的静态方法实现
class IPCSkeleton {
public:
    /**
     * @brief 获取调用者的Token ID
     * @return Token ID
     */
    static uint32_t GetCallingTokenID();
    
    /**
     * @brief 获取调用者的UID
     * @return UID
     */
    static int GetCallingUid();
    
    /**
     * @brief 获取调用者的PID
     * @return PID
     */
    static int GetCallingPid();
    
    /**
     * @brief 重置调用者身份
     * @return 之前的身份标识
     */
    static std::string ResetCallingIdentity();
    
    /**
     * @brief 设置调用者身份
     * @param identity 身份标识
     * @return 是否成功
     */
    static bool SetCallingIdentity(const std::string& identity);
};

// 导出符号的实现
uint32_t IPCSkeleton::GetCallingTokenID()
{
    return 0x12345678;
}

int IPCSkeleton::GetCallingUid()
{
    return 1000;
}

int IPCSkeleton::GetCallingPid()
{
    return 12345;
}

std::string IPCSkeleton::ResetCallingIdentity()
{
    return "";
}

bool IPCSkeleton::SetCallingIdentity(const std::string& identity)
{
    (void)identity;
    return true;
}

} // namespace OHOS
