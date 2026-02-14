/*
 * CameraStandard::CameraServiceProxy Stub for macOS Mock
 *
 * OpenHarmony 相机服务代理的 macOS 兼容层
 */

#ifndef STUBS_CAMERA_SERVICE_PROXY_H
#define STUBS_CAMERA_SERVICE_PROXY_H

#include <string>
#include <memory>
#include <vector>
#include "refbase.h"
#include "camera_service.h"  // Include ICameraService definition

#ifdef __cplusplus
namespace CameraStandard {

/**
 * @brief 相机服务代理类
 * 
 * 用于与相机服务进行IPC通信的代理类
 */
class CameraServiceProxy {
public:
    CameraServiceProxy() = default;
    virtual ~CameraServiceProxy() = default;

    /**
     * @brief 获取相机服务代理实例
     */
    static std::shared_ptr<CameraServiceProxy> GetInstance()
    {
        static std::shared_ptr<CameraServiceProxy> instance = 
            std::make_shared<CameraServiceProxy>();
        return instance;
    }

    /**
     * @brief 初始化相机服务
     */
    virtual int32_t Initialize()
    {
        return 0;  // Mock: 总是成功
    }

    /**
     * @brief 释放相机服务
     */
    virtual int32_t Release()
    {
        return 0;  // Mock: 总是成功
    }

    /**
     * @brief 获取相机列表
     */
    virtual std::vector<std::string> GetCameraIds()
    {
        return {};  // Mock: 返回空列表
    }

    /**
     * @brief 打开相机设备
     */
    virtual int32_t OpenCamera(const std::string& cameraId)
    {
        (void)cameraId;
        return 0;  // Mock: 总是成功
    }

    /**
     * @brief 关闭相机设备
     */
    virtual int32_t CloseCamera(const std::string& cameraId)
    {
        (void)cameraId;
        return 0;  // Mock: 总是成功
    }

    /**
     * @brief 设置回调
     */
    virtual int32_t SetCallback(const void* callback)
    {
        (void)callback;
        return 0;  // Mock: 总是成功
    }
};

} // namespace CameraStandard

#endif // __cplusplus

#endif // STUBS_CAMERA_SERVICE_PROXY_H
