/*
 * HDI Service Manager Stub for macOS Mock
 *
 * OpenHarmony HDI服务管理器的 macOS 兼容层
 */

#ifndef STUBS_ISERVMGR_HDI_H
#define STUBS_ISERVMGR_HDI_H

#include <memory>
#include <string>
#include "refbase.h"

#ifdef __cplusplus

namespace OHOS {
namespace HDI {
namespace ServiceManager {
namespace V1_0 {

/**
 * @brief HDI服务管理器接口
 */
class IServiceManager : public OHOS::RefBase {
public:
    virtual ~IServiceManager() = default;

    /**
     * @brief 获取服务管理器实例
     */
    static sptr<IServiceManager> Get()
    {
        static sptr<IServiceManager> instance = new IServiceManager();
        return instance;
    }

    /**
     * @brief 加载服务
     */
    virtual int32_t LoadService(const std::string& serviceName)
    {
        (void)serviceName;
        return 0;  // Mock: 总是成功
    }

    /**
     * @brief 获取服务
     */
    virtual sptr<IRemoteObject> GetService(const std::string& serviceName)
    {
        (void)serviceName;
        return nullptr;  // Mock: 返回空
    }

    /**
     * @brief 注册服务
     */
    virtual int32_t RegisterService(const std::string& serviceName, const sptr<IRemoteObject>& service)
    {
        (void)serviceName;
        (void)service;
        return 0;  // Mock: 总是成功
    }

    /**
     * @brief 注销服务
     */
    virtual int32_t UnregisterService(const std::string& serviceName)
    {
        (void)serviceName;
        return 0;  // Mock: 总是成功
    }
};

} // namespace V1_0
} // namespace ServiceManager
} // namespace HDI
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_ISERVMGR_HDI_H
