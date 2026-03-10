/*
 * Device Manager Compatibility Layer for macOS
 *
 * 提供与源代码期望的 DeviceManager API 兼容的定义
 * 必须在 device_manager.h 之后包含
 */

#ifndef DM_DEVICE_INFO_COMPAT_H
#define DM_DEVICE_INFO_COMPAT_H

#include <string>
#include <cstring>

namespace OHOS {
namespace DistributedHardware {

// Access control types that may be missing in older DM versions
struct DmAccessCaller {
    std::string pkgName;
    std::string tokenId;
};

struct DmAccessCallee {
    std::string pkgName;
    std::string tokenId;
};

// Add missing methods to DeviceManager class
// Note: This is a workaround for API version mismatch
class DeviceManagerCompat {
public:
    static bool CheckSrcAccessControl(const DmAccessCaller& caller, const DmAccessCallee& callee)
    {
        (void)caller;
        (void)callee;
        return true;  // Mock: always allow access in test environment
    }
};

} // namespace DistributedHardware
} // namespace OHOS

// Macro to add extraData field access to DmDeviceInfo
// Since we cannot modify the struct, we provide a helper function
namespace OHOS {
namespace DistributedHardware {

inline const char* GetDmDeviceInfoExtraData(const DmDeviceInfo& info)
{
    (void)info;
    return "{}";  // Mock: return empty JSON
}

} // namespace DistributedHardware
} // namespace OHOS

#endif // DM_DEVICE_INFO_COMPAT_H
