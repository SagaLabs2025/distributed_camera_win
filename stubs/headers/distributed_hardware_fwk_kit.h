/*
 * DistributedHardwareFwkKit Stub for macOS Mock
 *
 * OpenHarmony 分布式硬件框架 SDK 的 macOS 兼容层
 */

#ifndef STUBS_DISTRIBUTED_HARDWARE_FWK_KIT_H
#define STUBS_DISTRIBUTED_HARDWARE_FWK_KIT_H

#include <cstdint>
#include <string>
#include <vector>
#include <memory>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

// 前向声明 DHType（external 中已定义为 enum class）
enum class DHType : uint32_t;

// 前向声明 external 中已定义的类型
struct EnableParam;
struct WorkModeParam;
enum class EnableStep;

/**
 * @brief 分布式硬件框架工具类接口（Mock）
 */
class DistributedHardwareFwkKit {
public:
    DistributedHardwareFwkKit() = default;
    ~DistributedHardwareFwkKit() = default;

    int32_t SubscribeLocalHardware(const std::string& dhId)
    {
        (void)dhId; return 0;
    }

    int32_t UnsubscribeLocalHardware(const std::string& dhId)
    {
        (void)dhId; return 0;
    }

    int32_t StartDistributedHardware(DHType dhType, const std::string& networkId,
        const std::string& dhId, const std::string& reqId)
    {
        (void)dhType; (void)networkId; (void)dhId; (void)reqId; return 0;
    }

    int32_t StopDistributedHardware(DHType dhType, const std::string& networkId)
    {
        (void)dhType; (void)networkId; return 0;
    }

    int32_t GetDistributedHardware(const std::string& networkId, EnableStep enableStep, void* callback)
    {
        (void)networkId; (void)enableStep; (void)callback; return 0;
    }

    int32_t RegisterDHStatusListener(void* listener)
    {
        (void)listener; return 0;
    }

    int32_t UnregisterDHStatusListener(void* listener)
    {
        (void)listener; return 0;
    }

    int32_t RegisterDHStatusListener(const std::string& networkId, void* listener)
    {
        (void)networkId; (void)listener; return 0;
    }

    int32_t UnregisterDHStatusListener(const std::string& networkId, void* listener)
    {
        (void)networkId; (void)listener; return 0;
    }

    int32_t QuerySysCap(const std::string& networkId, void* jsonStr)
    {
        (void)networkId; (void)jsonStr; return 0;
    }

    int32_t RegisterAccessListener(const std::string& networkId, DHType dhType, void* callback)
    {
        (void)networkId; (void)dhType; (void)callback; return 0;
    }

    int32_t UnregisterAccessListener(const std::string& networkId, DHType dhType, void* callback)
    {
        (void)networkId; (void)dhType; (void)callback; return 0;
    }

    int32_t RegisterAccessListener(DHType dhType, void* callback, const std::string& pkgName)
    {
        (void)dhType; (void)callback; (void)pkgName; return 0;
    }

    int32_t UnregisterHardwareAccessListener(DHType dhType, void* callback, const std::string& pkgName)
    {
        (void)dhType; (void)callback; (void)pkgName; return 0;
    }

    void SetAuthorizationResult(DHType dhType, const std::string& requestId, bool granted)
    {
        (void)dhType; (void)requestId; (void)granted;
    }

    // 新增：Load/Unload HDF 方法（本地测试环境需要）
    int32_t LoadDistributedHDF(DHType dhType)
    {
        (void)dhType; return 0;  // Mock: 总是加载成功
    }

    int32_t UnLoadDistributedHDF(DHType dhType)
    {
        (void)dhType; return 0;  // Mock: 总是卸载成功
    }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_DISTRIBUTED_HARDWARE_FWK_KIT_H
