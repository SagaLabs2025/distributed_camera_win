/*
 * ServiceRegistry Implementation for macOS
 *
 * 全局 Service 注册表的实现
 */

#include "service_registry.h"
#include "iremote_object.h"
#include "distributed_hardware_log.h"
#include <mutex>

namespace OHOS {
namespace DistributedHardware {

ServiceRegistry& ServiceRegistry::GetInstance()
{
    static ServiceRegistry instance;
    return instance;
}

bool ServiceRegistry::RegisterService(int32_t saId, const sptr<IRemoteObject>& service)
{
    if (service == nullptr) {
        DHLOGE("RegisterService failed: service is nullptr for SA %d", saId);
        return false;
    }

    std::lock_guard<std::mutex> lock(mutex_);
    
    // 检查是否已经注册
    auto it = services_.find(saId);
    if (it != services_.end()) {
        DHLOGW("Service %d already registered, will be replaced", saId);
    }
    
    services_[saId] = service;
    DHLOGI("Service %d registered successfully", saId);
    return true;
}

sptr<IRemoteObject> ServiceRegistry::GetService(int32_t saId)
{
    std::lock_guard<std::mutex> lock(mutex_);
    
    auto it = services_.find(saId);
    if (it == services_.end()) {
        DHLOGW("Service %d not found in registry", saId);
        return nullptr;
    }
    
    DHLOGD("Service %d found in registry", saId);
    return it->second;
}

bool ServiceRegistry::UnregisterService(int32_t saId)
{
    std::lock_guard<std::mutex> lock(mutex_);
    
    auto it = services_.find(saId);
    if (it == services_.end()) {
        DHLOGW("UnregisterService failed: Service %d not found", saId);
        return false;
    }
    
    services_.erase(it);
    DHLOGI("Service %d unregistered successfully", saId);
    return true;
}

bool ServiceRegistry::IsServiceRegistered(int32_t saId)
{
    std::lock_guard<std::mutex> lock(mutex_);
    return services_.find(saId) != services_.end();
}

void ServiceRegistry::ClearAll()
{
    std::lock_guard<std::mutex> lock(mutex_);
    services_.clear();
    DHLOGI("All services cleared from registry");
}

} // namespace DistributedHardware
} // namespace OHOS
