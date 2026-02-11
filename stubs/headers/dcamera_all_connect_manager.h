/*
 * DCameraAllConnectManager Stub for macOS Mock
 *
 * OpenHarmony 分布式相机连接管理器的 macOS 兼容层
 */

#ifndef STUBS_DCAMERA_ALL_CONNECT_MANAGER_H
#define STUBS_DCAMERA_ALL_CONNECT_MANAGER_H

#include <string>
#include <memory>
#include <cstdint>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

// 服务状态常量
constexpr int32_t SCM_IDLE = 0;
constexpr int32_t SCM_PREPARE = 1;
constexpr int32_t SCM_START = 2;
constexpr int32_t SCM_STOP = 3;

/**
 * @brief 分布式相机所有连接管理器（Mock）
 */
class DCameraAllConnectManager {
public:
    static DCameraAllConnectManager& GetInstance()
    {
        static DCameraAllConnectManager instance;
        return instance;
    }

    // 资源请求相关方法
    int32_t BuildResourceRequest(const std::string& devId, const std::string& dhId)
    {
        (void)devId; (void)dhId;
        return 0;  // Mock: 总是成功
    }

    int32_t ApplyAdvancedResource(const std::string& devId, const std::string& dhId)
    {
        (void)devId; (void)dhId;
        return 0;  // Mock: 总是成功
    }

    // 服务状态发布
    int32_t PublishServiceState(const std::string& devId, const std::string& dhId, int32_t state)
    {
        (void)devId; (void)dhId; (void)state;
        return 0;  // Mock: 总是成功
    }

private:
    DCameraAllConnectManager() = default;
    ~DCameraAllConnectManager() = default;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_DCAMERA_ALL_CONNECT_MANAGER_H
