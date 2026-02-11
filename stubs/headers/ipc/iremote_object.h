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
#include "iremote_broker.h"

#ifdef __cplusplus

namespace OHOS {

// 前向声明
class MessageParcel;
class MessageOption;

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
     * 继承 IRemoteBroker 以支持 sptr 智能指针
     */
    class DeathRecipient : public virtual IRemoteBroker {
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

        // 实现 IRemoteBroker 的纯虚函数
        std::u16string GetDescriptor() override
        {
            return u"DeathRecipient";
        }

        IRemoteObject* AsObject() override
        {
            return nullptr;
        }

        const IRemoteObject* AsObject() const override
        {
            return nullptr;
        }
    };

    /**
     * @brief 发送请求到远程对象（Proxy 使用）
     * @param code 请求码
     * @param data 输入数据
     * @param reply 输出数据
     * @param option 选项
     * @return 成功返回 0
     */
    virtual int32_t SendRequest(uint32_t code, MessageParcel& data,
                               MessageParcel& reply, MessageOption& option)
    {
        (void)code; (void)data; (void)reply; (void)option;
        return 0;
    }

    /**
     * @brief 处理远程请求（Stub 使用）
     * @param code 请求码
     * @param data 输入数据
     * @param reply 输出数据
     * @param option 选项
     * @return 成功返回 0
     */
    virtual int32_t OnRemoteRequest(uint32_t code, MessageParcel& data,
                                    MessageParcel& reply, MessageOption& option)
    {
        (void)code; (void)data; (void)reply; (void)option;
        return 0;
    }

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
