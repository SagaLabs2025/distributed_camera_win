/*
 * DistributedCameraAllConnectManager Stub for macOS Mock
 *
 * OpenHarmony 分布式相机连接管理器的 macOS 兼容层
 *
 * 重要原则：使用源码中的定义，不重复定义
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_ALLCONNECT_MANAGER_H
#define STUBS_DISTRIBUTED_CAMERA_ALLCONNECT_MANAGER_H

#include <string>
#include <memory>
#include <cstdint>
#include <functional>

// 引用源码中的 C API 定义（包含枚举和回调结构定义）
#include "dcamera_collaboration_manager_capi.h"

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

/**
 * @brief 分布式相机所有连接管理器（Mock）
 * 匹配源码中的方法签名
 */
class DCameraAllConnectManager {
public:
    static DCameraAllConnectManager& GetInstance()
    {
        static DCameraAllConnectManager instance;
        return instance;
    }

    // 初始化状态检查（静态方法 - 匹配源码）
    static bool IsInited()
    {
        return true;  // Mock: 总是已初始化
    }

    // 初始化管理器
    int32_t InitDCameraAllConnectManager()
    {
        return 0;  // Mock: 总是成功
    }

    // 反初始化管理器
    int32_t UnInitDCameraAllConnectManager()
    {
        return 0;  // Mock: 总是成功
    }

    // 注册生命周期回调（使用源码签名 - 无参数）
    int32_t RegisterLifecycleCallback()
    {
        return 0;  // Mock: 总是成功
    }

    // 注销生命周期回调
    int32_t UnRegisterLifecycleCallback()
    {
        return 0;  // Mock: 总是成功
    }

    // 资源请求相关方法
    std::shared_ptr<DCameraCollaborationResourceRequestInfoSets> BuildResourceRequest()
    {
        return nullptr;  // Mock: 返回空指针
    }

    int32_t ApplyAdvancedResource(const std::string& peerNetworkId,
                                  DCameraCollaborationResourceRequestInfoSets* resourceRequest)
    {
        (void)peerNetworkId; (void)resourceRequest;
        return 0;  // Mock: 总是成功
    }

    // 静态工具方法（匹配源码签名）
    static void SetSourceNetworkId(const std::string &networkId, int32_t socket)
    {
        (void)networkId; (void)socket;
    }

    static void SetSinkNetWorkId(const std::string &networkId, int32_t socket)
    {
        (void)networkId; (void)socket;
    }

    static void RemoveSinkNetworkId(int32_t sessionId)
    {
        (void)sessionId;
    }

    static void RemoveSourceNetworkId(int32_t sessionId)
    {
        (void)sessionId;
    }

    static std::string GetSinkDevIdBySocket(int32_t socket)
    {
        (void)socket;
        return "";
    }

    static int32_t GetSinkSocketByNetWorkId(const std::string &networkId)
    {
        (void)networkId;
        return 0;
    }

    static int32_t GetSourceSocketByNetworkId(const std::string &networkId)
    {
        (void)networkId;
        return 0;
    }

    // 服务状态发布（使用源码中的枚举类型）
    int32_t PublishServiceState(const std::string& peerNetworkId, const std::string& dhId,
                                DCameraCollaborationBussinessStatus state)
    {
        (void)peerNetworkId; (void)dhId; (void)state;
        return 0;  // Mock: 总是成功
    }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_DISTRIBUTED_CAMERA_ALLCONNECT_MANAGER_H
