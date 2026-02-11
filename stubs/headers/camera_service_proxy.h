/*
 * CameraStandard::ICameraService Stub for macOS Mock
 *
 * OpenHarmony 相机标准服务接口的 macOS 兼容层
 */

#ifndef STUBS_CAMERA_SERVICE_PROXY_H
#define STUBS_CAMERA_SERVICE_PROXY_H

#include <string>
#include "refbase.h"

#ifdef __cplusplus

// CameraStandard 命名空间 - OpenHarmony 相机标准接口
namespace CameraStandard {

class ICameraService {
public:
    virtual ~ICameraService() = default;

    virtual int32_t Initialize()
    {
        return 0;  // Mock: 总是成功
    }

    virtual int32_t Release()
    {
        return 0;  // Mock: 总是成功
    }

    virtual int32_t SetCallback(const void* callback)
    {
        (void)callback;
        return 0;  // Mock: 总是成功
    }
};

} // namespace CameraStandard

// 同时提供旧接口兼容（如果需要）
namespace OHOS {
namespace DistributedHardware {

using CameraStandard::ICameraService;

} // namespace DistributedHardware
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_CAMERA_SERVICE_PROXY_H
