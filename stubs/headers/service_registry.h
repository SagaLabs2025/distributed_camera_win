/*
 * ServiceRegistry Header for macOS
 *
 * 全局 Service 注册表，用于 SDK 和 Service 在同一进程内的直接对接
 * 
 * 功能：
 * - 存储 Service 对象的引用（按 SA ID 索引）
 * - 提供线程安全的注册和查询接口
 * - 单例模式，全局唯一
 */

#ifndef OHOS_DISTRIBUTED_CAMERA_SERVICE_REGISTRY_H
#define OHOS_DISTRIBUTED_CAMERA_SERVICE_REGISTRY_H

#include <map>
#include <mutex>
#include <memory>
#include "refbase.h"

namespace OHOS {

// 前向声明
class IRemoteObject;

namespace DistributedHardware {

/**
 * @brief Service 注册表
 * 
 * 用于在 SDK 和 Service 合并到同一进程时，管理 Service 对象的注册和查询。
 * 替代真实的 SystemAbilityManager，提供进程内的 Service 发现机制。
 */
class ServiceRegistry {
public:
    /**
     * @brief 获取单例实例
     * @return ServiceRegistry 单例引用
     */
    static ServiceRegistry& GetInstance();

    /**
     * @brief 注册 Service 对象
     * @param saId System Ability ID（如 4803 for Source, 4804 for Sink）
     * @param service Service 对象的智能指针
     * @return true 注册成功，false 注册失败
     */
    bool RegisterService(int32_t saId, const sptr<IRemoteObject>& service);

    /**
     * @brief 查询 Service 对象
     * @param saId System Ability ID
     * @return Service 对象的智能指针，如果未找到则返回 nullptr
     */
    sptr<IRemoteObject> GetService(int32_t saId);

    /**
     * @brief 注销 Service 对象
     * @param saId System Ability ID
     * @return true 注销成功，false 注销失败（Service 不存在）
     */
    bool UnregisterService(int32_t saId);

    /**
     * @brief 检查 Service 是否已注册
     * @param saId System Ability ID
     * @return true Service 已注册，false Service 未注册
     */
    bool IsServiceRegistered(int32_t saId);

    /**
     * @brief 清空所有注册的 Service（用于测试和清理）
     */
    void ClearAll();

private:
    // 私有构造函数（单例模式）
    ServiceRegistry() = default;
    ~ServiceRegistry() = default;

    // 禁止拷贝和赋值
    ServiceRegistry(const ServiceRegistry&) = delete;
    ServiceRegistry& operator=(const ServiceRegistry&) = delete;

    // Service 存储映射：SA ID -> Service 对象
    std::map<int32_t, sptr<IRemoteObject>> services_;

    // 互斥锁，保护 services_ 的并发访问
    std::mutex mutex_;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // OHOS_DISTRIBUTED_CAMERA_SERVICE_REGISTRY_H
