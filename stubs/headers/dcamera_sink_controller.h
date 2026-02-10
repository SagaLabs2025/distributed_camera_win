/*
 * DCamera Sink Controller - OpenHarmony - macOS Stub
 *
 * 分布式相机 Sink 控制器（简化版）
 */

#ifndef STUBS_DCAMERA_SINK_CONTROLLER_H
#define STUBS_DCAMERA_SINK_CONTROLLER_H

#include <cstdint>
#include <memory>
#include <vector>
#include <mutex>
#include <atomic>
#include "icamera_operator.h"
#include "dcamera_source_event.h"
#include "data_buffer.h"

namespace OHOS {
namespace DistributedHardware {

// Sink 控制器业务状态
enum DcameraBusinessState : int32_t {
    UNKNOWN,
    IDLE,
    RUNNING,
    PAUSING
};

// Sink 控制器接口（简化版）
class DCameraSinkController {
public:
    DCameraSinkController() = default;
    virtual ~DCameraSinkController() = default;

    virtual int32_t StartCapture(std::vector<std::shared_ptr<DCCaptureInfo>>& captureInfos, int32_t sceneMode) = 0;
    virtual int32_t StopCapture() = 0;
    virtual int32_t OpenChannel(std::shared_ptr<DCameraOpenInfo>& openInfo) = 0;
    virtual int32_t CloseChannel() = 0;
    virtual int32_t Init(std::vector<DCameraIndex>& indexs) = 0;
    virtual int32_t UnInit() = 0;
    virtual int32_t UpdateSettings(std::vector<std::shared_ptr<DCameraSettings>>& settings) = 0;
    virtual int32_t GetCameraInfo(std::shared_ptr<DCameraInfo>& camInfo) = 0;
    virtual void OnStateChanged(std::shared_ptr<DCameraEvent>& event) = 0;
    virtual void OnMetadataResult(std::vector<std::shared_ptr<DCameraSettings>>& settings) = 0;
    virtual void OnSessionState(int32_t state, std::string networkId) = 0;
    virtual void OnSessionError(int32_t eventType, int32_t eventReason, std::string detail) = 0;
    virtual void OnDataReceived(std::vector<std::shared_ptr<DataBuffer>>& buffers) = 0;

    void SetTokenId(uint64_t token) { tokenId_ = token; }
    uint64_t GetTokenId() const { return tokenId_; }

protected:
    std::atomic<uint64_t> tokenId_{0};
    DcameraBusinessState state_{DcameraBusinessState::UNKNOWN};
    std::mutex stateMutex_;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_SINK_CONTROLLER_H
