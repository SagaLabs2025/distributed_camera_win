/*
 * SystemAbilityManagerClient Mock Implementation for macOS
 *
 * OpenHarmony SystemAbilityManagerClient 的 macOS Mock 实现
 * 增强版：使用 ServiceRegistry 查找 Service 对象，支持 SDK 和 Service 在同一进程内的直接对接
 */

#include "system_ability_manager_unified.h"
#include "service_registry.h"
#include "remote_object_mock.h"
#include "distributed_hardware_log.h"

namespace OHOS {

/**
 * @brief MockSystemAbilityManager::CheckSystemAbility 实现
 * 
 * 检查指定的 System Ability 是否存在
 * 在 Mock 模式下，从 ServiceRegistry 查询 Service 是否已注册
 * 
 * @param saId System Ability ID（如 4803 for Source, 4804 for Sink）
 * @return 0 表示 SA 存在，-1 表示 SA 不存在
 */
int32_t MockSystemAbilityManager::CheckSystemAbility(int32_t saId)
{
    DHLOGD("MockSystemAbilityManager::CheckSystemAbility called with SA ID: %d", saId);
    
    // 从 ServiceRegistry 查询 Service 是否已注册
    bool isRegistered = DistributedHardware::ServiceRegistry::GetInstance().IsServiceRegistered(saId);
    
    if (isRegistered) {
        DHLOGD("Service %d is registered", saId);
        return 0;  // SA 存在
    } else {
        DHLOGW("Service %d is not registered", saId);
        return -1;  // SA 不存在
    }
}

/**
 * @brief MockSystemAbilityManager::CheckSystemAbility 实现（带 deviceId）
 * 
 * 获取指定的 System Ability 对象
 * 在 Mock 模式下，从 ServiceRegistry 获取 Service 对象，并包装为 RemoteObjectMock
 * 
 * @param saId System Ability ID（如 4803 for Source, 4804 for Sink）
 * @param deviceId 设备 ID（在进程内模式下忽略）
 * @return RemoteObjectMock 智能指针，如果 Service 未注册则返回 nullptr
 */
sptr<IRemoteObject> MockSystemAbilityManager::CheckSystemAbility(int32_t saId, const std::string& deviceId)
{
    (void)deviceId;  // 进程内模式下忽略 deviceId
    
    DHLOGD("MockSystemAbilityManager::CheckSystemAbility (with deviceId) called with SA ID: %d", saId);
    
    // 从 ServiceRegistry 获取 Service 对象
    sptr<IRemoteObject> service = DistributedHardware::ServiceRegistry::GetInstance().GetService(saId);
    
    if (service == nullptr) {
        DHLOGE("Service %d not found in ServiceRegistry", saId);
        return sptr<IRemoteObject>(nullptr);
    }
    
    // 创建 RemoteObjectMock 包装 Service 对象
    // 注意：这里直接传递 Service 对象，RemoteObjectMock 会持有其引用
    DHLOGD("Creating RemoteObjectMock for Service %d", saId);
    sptr<IRemoteObject> remoteMock = new DistributedHardware::RemoteObjectMock(service);
    
    return remoteMock;
}

} // namespace OHOS
