/*
 * Simplified DeviceManager Header for macOS
 * 
 * 只包含 dcamera_source_controller.cpp 实际使用的接口
 * 避免实现 61+ 个不需要的纯虚函数
 */

#ifndef OHOS_DEVICE_MANAGER_SIMPLIFIED_H
#define OHOS_DEVICE_MANAGER_SIMPLIFIED_H

#include <string>
#include <vector>
#include <memory>

namespace OHOS {
namespace DistributedHardware {

// Forward declarations - will be included from dm_device_info.h
struct DmDeviceInfo;
struct DmAccessCaller;
struct DmAccessCallee;
class DmInitCallback;  // Forward declaration - defined in device_manager_callback.h

// Simplified DeviceManager - only the 3 methods we need
class DeviceManager {
public:
    // Singleton access
    static DeviceManager& GetInstance();
    
    virtual ~DeviceManager() = default;

    // Method 1: Get trusted device list
    virtual int32_t GetTrustedDeviceList(
        const std::string& pkgName,
        const std::string& extra,
        std::vector<DmDeviceInfo>& deviceList) = 0;

    // Method 2: Initialize device manager
    virtual int32_t InitDeviceManager(
        const std::string& pkgName,
        std::shared_ptr<DmInitCallback> dmInitCallback) = 0;

    // Method 3: Check source access control
    virtual bool CheckSrcAccessControl(
        const DmAccessCaller& caller,
        const DmAccessCallee& callee) = 0;
};

} // namespace DistributedHardware
} // namespace OHOS

// Include the actual type definitions after our declarations
// This ensures our simplified DeviceManager is used, but we get the type definitions
#include "dm_device_info.h"
#include "device_manager_callback.h"

#endif // OHOS_DEVICE_MANAGER_SIMPLIFIED_H
