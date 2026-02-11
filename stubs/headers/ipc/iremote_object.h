/*
 * IRemoteObject Stub for macOS Mock
 *
 * OpenHarmony IPC 远程对象接口的 macOS 兼容层
 */

#ifndef STUBS_IREMOTE_OBJECT_H
#define STUBS_IREMOTE_OBJECT_H

#include <cstdint>
#include <vector>
#include <string>

#ifdef __cplusplus

namespace OHOS {

// 前向声明 IRemoteBroker，避免循环包含
class IRemoteBroker;

// 通用宏定义
#define DISALLOW_COPY_AND_MOVE(classname) \
    classname(const classname&) = delete; \
    classname& operator=(const classname&) = delete; \
    classname(classname&&) = delete; \
    classname& operator=(classname&&) = delete

// 弱指针模板前向声明
template<typename T> class wptr;

/**
 * @brief 远程对象接口
 * 继承自 IRemoteBroker 以获得引用计数方法
 */
class IRemoteObject : public virtual IRemoteBroker {
public:
    IRemoteObject() = default;
    virtual ~IRemoteObject() = default;

    /**
     * @brief 死亡接收者接口
     * 用于监听远程对象死亡通知
     */
    class DeathRecipient {
    public:
        DeathRecipient() = default;
        virtual ~DeathRecipient() = default;

        /**
         * @brief 远程对象死亡回调
         * @param remote 远程对象弱指针
         */
        virtual void OnRemoteDied(const wptr<IRemoteObject>& remote)
        {
            (void)remote;
        }
    };

    /**
     * @brief 添加死亡监听器
     * @param recipient 死亡接收者
     * @return 成功返回 true
     */
    virtual bool AddDeathRecipient(const DeathRecipient* recipient)
    {
        (void)recipient;
        return true;
    }

    /**
     * @brief 移除死亡监听器
     * @param recipient 死亡接收者
     * @return 成功返回 true
     */
    virtual bool RemoveDeathRecipient(const DeathRecipient* recipient)
    {
        (void)recipient;
        return true;
    }

    /**
     * @brief 判断对象是否存活
     * @return true/false
     */
    virtual bool IsObjectAlive() const
    {
        return true;  // Mock: 总是存活
    }
};

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IREMOTE_OBJECT_H
