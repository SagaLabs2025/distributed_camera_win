/*
 * IPC Skeleton Stub for macOS Mock
 *
 * OpenHarmony IPC 骨架类的 macOS 兼容层
 */

#ifndef STUBS_IPC_SKELETON_H
#define STUBS_IPC_SKELETON_H

#include <string>
#include <cstdint>

#ifdef __cplusplus
namespace OHOS {

// 前向声明
class MessageParcel;
class MessageOption;
class IRemoteBroker;

// 避免 AccessTokenID 类型重定义
// 不在这里定义，使用外部头文件中的定义

/**
 * @brief IPC 骨架类
 * 提供 IPC 基础功能
 */
class IPCSkeleton {
public:
    /**
     * @brief 设置当前远程对象
     * @param broker 远程对象代理
     * @return 成功返回 true
     */
    static bool SetCurrentObject(IRemoteBroker* broker)
    {
        (void)broker;
        return true;  // Mock: 总是返回成功
    }

    /**
     * @brief 获取当前远程对象
     * @return 远程对象指针
     */
    static IRemoteBroker* GetCurrentObject()
    {
        return nullptr;  // Mock: 返回空指针
    }

    /**
     * @brief 获取调用者的 Token ID
     * @return Token ID
     */
    static uint64_t GetCallingTokenID()
    {
        return 0;  // Mock: 返回默认 Token ID
    }

    /**
     * @brief 获取调用者的设备 ID
     * @return 设备 ID
     */
    static std::string GetCallingDeviceID()
    {
        return "";  // Mock: 返回空设备 ID
    }

    /**
     * @brief 获取调用者的 UID
     * @return UID
     */
    static uint32_t GetCallingUid()
    {
        return 0;  // Mock: 返回默认 UID
    }

    /**
     * @brief 获取调用者的 PID
     * @return PID
     */
    static uint32_t GetCallingPid()
    {
        return 0;  // Mock: 返回默认 PID
    }

    /**
     * @brief 重置调用者标识
     */
    static void ResetCallingIdentity()
    {
        // Mock: 空实现
    }
};

// IPC 错误码定义
namespace IPCCodes {
    constexpr int32_t ERR_INVALID_DATA = -1;
    constexpr int32_t ERR_NOT_IMPLEMENTED = -2;
    constexpr int32_t ERR_PERMISSION_DENIED = -3;
    constexpr int32_t ERR_DEAD_OBJECT = -4;
}

// 简化错误码定义
#ifndef ERR_INVALID_DATA
#define ERR_INVALID_DATA IPCCodes::ERR_INVALID_DATA
#endif

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IPC_SKELETON_H
