/*
 * ICamera Operator - OpenHarmony - macOS Stub
 *
 * 相机操作接口
 */

#ifndef STUBS_ICAMERA_OPERATOR_H
#define STUBS_ICAMERA_OPERATOR_H

#include <cstdint>
#include <memory>
#include <string>
#include <vector>
#include "data_buffer.h"
#include "dcamera_capture_info_cmd.h"
#include "dcamera_event_cmd.h"
#include "dcamera_source_event.h"
#include "distributed_camera_errno.h"

namespace OHOS {
namespace DistributedHardware {

// 状态回调
class StateCallback {
public:
    StateCallback() = default;
    virtual ~StateCallback() = default;
    virtual void OnStateChanged(std::shared_ptr<DCameraEvent>& event) = 0;
    virtual void OnMetadataResult(std::vector<std::shared_ptr<DCameraSettings>>& settings) = 0;
};

// 结果回调
class ResultCallback {
public:
    ResultCallback() = default;
    virtual ~ResultCallback() = default;
    virtual void OnPhotoResult(std::shared_ptr<DataBuffer>& buffer) = 0;
    virtual void OnVideoResult(std::shared_ptr<DataBuffer>& buffer) = 0;
};

// 相机操作接口
class ICameraOperator {
public:
    ICameraOperator() = default;
    virtual ~ICameraOperator() = default;

    virtual int32_t Init() = 0;
    virtual int32_t UnInit() = 0;
    virtual int32_t UpdateSettings(std::vector<std::shared_ptr<DCameraSettings>>& settings) = 0;
    virtual int32_t StartCapture(std::vector<std::shared_ptr<DCCaptureInfo>>& captureInfos,
        void* surface, int32_t sceneMode) = 0;
    virtual int32_t PrepareCapture(std::vector<std::shared_ptr<DCCaptureInfo>>& captureInfos, int32_t sceneMode) = 0;
    virtual int32_t CommitCapture(void* surface) = 0;
    virtual int32_t StopCapture() = 0;
    virtual int32_t SetStateCallback(std::shared_ptr<StateCallback>& callback) = 0;
    virtual int32_t SetResultCallback(std::shared_ptr<ResultCallback>& callback) = 0;
    virtual int32_t PauseCapture() = 0;
    virtual int32_t ResumeCapture() = 0;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_ICAMERA_OPERATOR_H
