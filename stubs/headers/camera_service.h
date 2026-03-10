/*
 * CameraStandard::ICameraService Stub for macOS Mock
 *
 * OpenHarmony 相机标准服务接口的 macOS 兼容层
 */

#ifndef STUBS_CAMERA_STANDARD_SERVICE_H
#define STUBS_CAMERA_STANDARD_SERVICE_H

#include <string>
#include <memory>
#include "refbase.h"
#include "iremote_broker.h"

#ifdef __cplusplus
namespace CameraStandard {

/**
 * @brief 相机标准服务接口
 */
class ICameraService : public OHOS::IRemoteBroker {
public:
    DECLARE_INTERFACE_DESCRIPTOR(u"CameraStandard.ICameraService");

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

/**
 * @brief 相机设备接口
 */
class ICameraDevice : public OHOS::RefBase {
public:
    virtual ~ICameraDevice() = default;

    virtual int32_t Open()
    {
        return 0;  // Mock: 总是成功
    }

    virtual int32_t Close()
    {
        return 0;  // Mock: 总是成功
    }
};

} // namespace CameraStandard

#endif // __cplusplus

#endif // STUBS_CAMERA_STANDARD_SERVICE_H
