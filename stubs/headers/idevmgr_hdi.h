#ifndef IDEVMGR_HDI_H
#define IDEVMGR_HDI_H

#include <string>
#include <cstdint>
#include <memory>
#include <vector>
#include "refbase.h"

namespace OHOS {
namespace HDI {
namespace DeviceManager {
namespace V1_0 {

// 设备信息结构
struct DeviceInfo {
    std::string deviceName;
    uint16_t deviceClass;
    uint16_t deviceId;
    
    DeviceInfo() : deviceClass(0), deviceId(0) {}
};

// HdiBase 基类 Mock
class HdiBase {
public:
    virtual ~HdiBase() = default;
};

// 设备管理器接口 Mock
class IDeviceManager : public HdiBase {
public:
    virtual ~IDeviceManager() = default;
    
    // 引用计数方法（用于 sptr 兼容性）
    virtual void IncStrongRef(const void* objectId) {
        (void)objectId;
    }
    
    virtual void DecStrongRef(const void* objectId) {
        (void)objectId;
    }
    
    // 静态工厂方法 - 获取 IDeviceManager 实例
    static sptr<IDeviceManager> Get() {
        // Mock: 返回 nullptr，表示 HDF 服务不可用
        return nullptr;
    }
    
    // 加载设备
    virtual int32_t LoadDevice(const std::string& serviceName) {
        (void)serviceName;
        return 0; // 成功
    }
    
    // 卸载设备
    virtual int32_t UnloadDevice(const std::string& serviceName) {
        (void)serviceName;
        return 0; // 成功
    }
    
    // 查询设备信息
    virtual int32_t QueryDevice(std::vector<DeviceInfo>& deviceInfos) {
        (void)deviceInfos;
        return 0; // 成功
    }
};

} // V1_0
} // DeviceManager
} // HDI
} // OHOS

#endif // IDEVMGR_HDI_H
