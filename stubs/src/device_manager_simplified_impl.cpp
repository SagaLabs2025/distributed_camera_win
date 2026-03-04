/*
 * Simplified DeviceManager Implementation
 * 
 * 只实现 3 个实际使用的方法
 */

#include "device_manager.h"
#include "dm_device_info.h"
#include <vector>

namespace OHOS {
namespace DistributedHardware {

// Simple implementation class
class SimpleDeviceManagerImpl : public DeviceManager {
public:
    SimpleDeviceManagerImpl() = default;
    virtual ~SimpleDeviceManagerImpl() = default;

    // Method 1: Get trusted device list (returns empty list for testing)
    int32_t GetTrustedDeviceList(
        const std::string& pkgName,
        const std::string& extra,
        std::vector<DmDeviceInfo>& deviceList) override
    {
        (void)pkgName;
        (void)extra;
        deviceList.clear();
        return 0;  // Success, but no devices
    }

    // Method 2: Initialize device manager (always succeeds for testing)
    int32_t InitDeviceManager(
        const std::string& pkgName,
        std::shared_ptr<DmInitCallback> dmInitCallback) override
    {
        (void)pkgName;
        (void)dmInitCallback;
        return 0;  // Success
    }

    // Method 3: Check source access control (always allows for testing)
    bool CheckSrcAccessControl(
        const DmAccessCaller& caller,
        const DmAccessCallee& callee) override
    {
        (void)caller;
        (void)callee;
        return true;  // Always allow access in test environment
    }
};

// Global singleton instance
static SimpleDeviceManagerImpl g_deviceManagerInstance;

// GetInstance implementation
DeviceManager& DeviceManager::GetInstance()
{
    return g_deviceManagerInstance;
}

} // namespace DistributedHardware
} // namespace OHOS
