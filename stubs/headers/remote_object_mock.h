/*
 * RemoteObjectMock Header for macOS
 *
 * RemoteObjectMock 实现，用于 SDK 和 Service 在同一进程内的直接调用
 * 
 * 功能：
 * - 拦截 SendRequest 调用
 * - 直接转发到 Service 的 OnRemoteRequest 方法
 * - 支持通过 SA ID 或直接持有 Service 对象
 */

#ifndef OHOS_REMOTE_OBJECT_MOCK_H
#define OHOS_REMOTE_OBJECT_MOCK_H

#include "iremote_object.h"
#include "refbase.h"

namespace OHOS {
namespace DistributedHardware {

/**
 * @brief RemoteObjectMock 实现类
 * 
 * 用于在 SDK 和 Service 合并到同一进程时，拦截 SendRequest 调用，
 * 直接转发到目标 Service 的 OnRemoteRequest 方法，实现进程内直接调用。
 */
class RemoteObjectMock : public IRemoteObject {
public:
    /**
     * @brief 构造函数
     * @param saId System Ability ID
     */
    explicit RemoteObjectMock(int32_t saId);
    
    /**
     * @brief 构造函数（直接持有 Service 对象）
     * @param service Service 对象的智能指针
     */
    explicit RemoteObjectMock(const sptr<IRemoteObject>& service);
    
    virtual ~RemoteObjectMock() = default;
    
    /**
     * @brief 发送 IPC 请求（Mock 实现）
     * 
     * 在 Mock 模式下，此方法不会真正发送 IPC 请求，而是：
     * 1. 从 ServiceRegistry 获取目标 Service 对象（如果未直接持有）
     * 2. 将 Service 对象转换为 IRemoteStub
     * 3. 直接调用 Service 的 OnRemoteRequest 方法
     * 4. 返回调用结果
     * 
     * @param code 请求码
     * @param data 请求数据
     * @param reply 响应数据
     * @param option 调用选项
     * @return 错误码，0 表示成功
     */
    int SendRequest(uint32_t code, MessageParcel& data, 
                   MessageParcel& reply, MessageOption& option) override;
    
    /**
     * @brief 获取对象引用计数（Mock 实现）
     * @return 引用计数
     */
    int32_t GetObjectRefCount() override { return 1; }
    
    /**
     * @brief 添加死亡通知（Mock 实现）
     * @param recipient 死亡通知接收者
     * @return true 表示成功
     */
    bool AddDeathRecipient(const sptr<DeathRecipient>& recipient) override { 
        (void)recipient;
        return true; 
    }
    
    /**
     * @brief 移除死亡通知（Mock 实现）
     * @param recipient 死亡通知接收者
     * @return true 表示成功
     */
    bool RemoveDeathRecipient(const sptr<DeathRecipient>& recipient) override { 
        (void)recipient;
        return true; 
    }
    
    /**
     * @brief Dump 对象信息（Mock 实现）
     * @param fd 文件描述符
     * @param args 参数列表
     * @return 0 表示成功
     */
    int Dump(int fd, const std::vector<std::u16string>& args) override {
        (void)fd;
        (void)args;
        return 0;
    }
    
    /**
     * @brief 设置目标 Service 对象
     * @param service Service 对象的智能指针
     */
    void SetTargetService(const sptr<IRemoteObject>& service);
    
    /**
     * @brief 获取目标 Service 对象
     * @return Service 对象的智能指针
     */
    sptr<IRemoteObject> GetTargetService() const;

private:
    int32_t saId_;                      // System Ability ID
    sptr<IRemoteObject> targetService_; // 目标 Service 对象
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // OHOS_REMOTE_OBJECT_MOCK_H
