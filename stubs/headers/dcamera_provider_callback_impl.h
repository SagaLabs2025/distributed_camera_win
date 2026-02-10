/*
 * DCamera Provider Callback Implementation - OpenHarmony Distributed Camera - macOS Mock
 *
 * 分布式相机 HDF 提供者回调实现的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_PROVIDER_CALLBACK_IMPL_H
#define STUBS_DCAMERA_PROVIDER_CALLBACK_IMPL_H

#include "v1_1/id_camera_provider_callback.h"
#include <string>

namespace OHOS {
namespace DistributedHardware {

// DCameraProviderCallbackImpl - HDF 提供者回调实现
class DCameraProviderCallbackImpl : public ::OHOS::HDI::DistributedCamera::V1_1::IDCameroviderCallback {
public:
    DCameraProviderCallbackImpl() = default;
    ~DCameraProviderCallbackImpl() override = default;

    int32_t OpenSession(const ::OHOS::HDI::DistributedCamera::V1_1::DHBase& dhBase) override {
        (void)dhBase;
        return 0;  // Mock: 返回成功
    }

    int32_t CloseSession(const ::OHOS::HDI::DistributedCamera::V1_1::DHBase& dhBase) override {
        (void)dhBase;
        return 0;  // Mock: 返回成功
    }

    int32_t ConfigureStreams(const ::OHOS::HDI::DistributedCamera::V1_1::DHBase& dhBase,
                             const std::vector<::OHOS::HDI::DistributedCamera::V1_1::DCStreamInfo>& streamInfos) override {
        (void)dhBase;
        (void)streamInfos;
        return 0;  // Mock: 返回成功
    }

    int32_t ReleaseStreams(const ::OHOS::HDI::DistributedCamera::V1_1::DHBase& dhBase,
                          const std::vector<int>& streamIds) override {
        (void)dhBase;
        (void)streamIds;
        return 0;  // Mock: 返回成功
    }

    int32_t StartCapture(const ::OHOS::HDI::DistributedCamera::V1_1::DHBase& dhBase,
                        const std::vector<::OHOS::HDI::DistributedCamera::V1_1::DCCaptureInfo>& captureInfos) override {
        (void)dhBase;
        (void)captureInfos;
        return 0;  // Mock: 返回成功
    }

    int32_t StopCapture(const ::OHOS::HDI::DistributedCamera::V1_1::DHBase& dhBase,
                       const std::vector<int>& streamIds) override {
        (void)dhBase;
        (void)streamIds;
        return 0;  // Mock: 返回成功
    }

    int32_t UpdateSettings(const ::OHOS::HDI::DistributedCamera::V1_1::DHBase& dhBase,
                          const std::vector<DCameraSettings>& settings) override {
        (void)dhBase;
        (void)settings;
        return 0;  // Mock: 返回成功
    }

    int32_t NotifyEvent(const ::OHOS::HDI::DistributedCamera::V1_1::DHBase& dhBase,
                       const ::OHOS::HDI::DistributedCamera::V1_1::DCameraHDFEvent& event) override {
        (void)dhBase;
        (void)event;
        return 0;  // Mock: 返回成功
    }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_PROVIDER_CALLBACK_IMPL_H
