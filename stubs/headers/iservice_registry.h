/*
 * ServiceRegistry Interface Stub for macOS Mock
 *
 * OpenHarmony 服务注册接口的 macOS 兼容层
 */

#ifndef STUBS_ISERVICE_REGISTRY_H
#define STUBS_ISERVICE_REGISTRY_H

#include <cstdint>
#include <string>

#ifdef __cplusplus
namespace OHOS {

/**
 * @brief 服务注册接口
 */
class IServiceRegistry {
public:
    virtual ~IServiceRegistry() = default;

    // Mock 方法 - 总是返回成功
    static int32_t Publish(int32_t saId, void* ability)
    {
        (void)saId; (void)ability; return 0;  // Mock: 总是发布成功
    }

    static void Unpublish(int32_t saId)
    {
        (void)saId;  // Mock: 空实现
    }
};

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_ISERVICE_REGISTRY_H
