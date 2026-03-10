#ifndef ISERVSTAT_LISTENER_HDI_H
#define ISERVSTAT_LISTENER_HDI_H

#include <string>
#include <cstdint>
#include <memory>

namespace OHOS {
namespace HDI {
namespace ServiceManager {
namespace V1_0 {

// 服务状态枚举
enum ServiceStatusType {
    SERVIE_STATUS_START = 0,    // 服务启动
    SERVIE_STATUS_STOP = 1,     // 服务停止
    SERVIE_STATUS_DIED = 2,     // 服务崩溃
};

// 服务状态信息结构
struct ServiceStatus {
    std::string serviceName;
    uint16_t deviceClass;
    int32_t status;  // ServiceStatusType
    
    ServiceStatus() : deviceClass(0), status(SERVIE_STATUS_START) {}
};

// 为了兼容性，保留 ServiceStatusInfo 别名
using ServiceStatusInfo = ServiceStatus;

// HdiBase 基类 Mock
class HdiBase {
public:
    virtual ~HdiBase() = default;
};

// 服务状态监听器接口 Mock
class IServStatListener : public HdiBase {
public:
    virtual ~IServStatListener() = default;
    
    // 引用计数方法（用于 sptr 兼容性）
    virtual void IncStrongRef(const void* objectId) {
        (void)objectId;
    }
    
    virtual void DecStrongRef(const void* objectId) {
        (void)objectId;
    }
    
    // 接收服务状态变化通知（Mock 实现为空）
    virtual void OnReceive(const ServiceStatus& status) {
        // Mock 实现：忽略服务状态变化
        (void)status;
    }
};

// 服务状态监听器 Stub Mock
class ServStatListenerStub : public IServStatListener {
public:
    virtual ~ServStatListenerStub() = default;
};

} // V1_0
} // ServiceManager
} // HDI
} // OHOS

#endif // ISERVSTAT_LISTENER_HDI_H
