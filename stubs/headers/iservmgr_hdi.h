#ifndef ISERVMGR_HDI_H
#define ISERVMGR_HDI_H

#include <string>
#include <cstdint>
#include <memory>
#include <vector>
#include "refbase.h"
#include "iremote_object.h"
#include "iservstat_listener_hdi.h"

namespace OHOS {
namespace HDI {
namespace ServiceManager {
namespace V1_0 {

// 服务管理器接口 Mock
class IServiceManager : public HdiBase {
public:
    virtual ~IServiceManager() = default;
    
    // 引用计数方法（用于 sptr 兼容性）
    virtual void IncStrongRef(const void* objectId) {
        (void)objectId;
    }
    
    virtual void DecStrongRef(const void* objectId) {
        (void)objectId;
    }
    
    // 静态工厂方法 - 获取 IServiceManager 实例
    static sptr<IServiceManager> Get() {
        // Mock: 返回 nullptr，表示 HDF 服务不可用
        return nullptr;
    }
    
    // 注册服务状态监听器
    virtual int32_t RegisterServiceStatusListener(
        const sptr<IServStatListener>& listener,
        uint16_t deviceClass) {
        (void)listener;
        (void)deviceClass;
        return 0; // 成功
    }
    
    // 注销服务状态监听器
    virtual int32_t UnregisterServiceStatusListener(
        const sptr<IServStatListener>& listener) {
        (void)listener;
        return 0; // 成功
    }
    
    // 获取服务
    virtual sptr<IRemoteObject> GetService(const std::string& serviceName) {
        (void)serviceName;
        return nullptr; // Mock: 返回空
    }
    
    // 列出所有服务
    virtual int32_t ListAllService(std::vector<std::string>& serviceNames) {
        (void)serviceNames;
        return 0; // 成功
    }
};

// 获取服务管理器实例
inline sptr<IServiceManager> IServiceManager_Get() {
    return nullptr; // Mock: 返回空
}

// 静态工厂方法 - 获取 IServiceManager 实例
inline sptr<IServiceManager> Get() {
    return nullptr; // Mock: 返回空
}

} // V1_0
} // ServiceManager
} // HDI
} // OHOS

#endif // ISERVMGR_HDI_H
