/*
 * DCamera Source Event - OpenHarmony - macOS Stub
 *
 * 分布式相机 Source 事件定义
 */

#ifndef STUBS_DCAMERA_SOURCE_EVENT_H
#define STUBS_DCAMERA_SOURCE_EVENT_H

#include <variant>
#include <string>
#include <vector>
#include <memory>
#include "v1_1/dcamera_types.h"
#include "dcamera_event_cmd.h"

namespace OHOS {
namespace DistributedHardware {

// DCamera 索引类型（简化版本）
struct DCameraIndex {
    std::string dhId;
    std::string deviceId;
    int32_t index = 0;
};

// DCamera 信息类型
struct DCameraInfo {
    std::string dhId;
    std::string deviceId;
    std::string position;
};

// DCamera 打开信息
struct DCameraOpenInfo {
    std::string dhId;
    std::string deviceId;
    int32_t sourceType = 0;
};

// 注册参数
class DCameraRegistParam {
public:
    DCameraRegistParam() = default;
    DCameraRegistParam(std::string devId, std::string dhId, std::string reqId, std::string sinkParam,
        std::string srcParam) : devId_(devId), dhId_(dhId), reqId_(reqId), sinkParam_(sinkParam), srcParam_(srcParam)
    {}
    ~DCameraRegistParam() = default;
    std::string devId_;
    std::string dhId_;
    std::string reqId_;
    std::string sinkParam_;
    std::string srcParam_;
};

// DCamera 事件类型
typedef enum {
    DCAMERA_EVENT_REGIST = 0,
    DCAMERA_EVENT_UNREGIST = 1,
    DCAMERA_EVENT_OPEN = 2,
    DCAMERA_EVENT_CLOSE = 3,
    DCAMERA_EVENT_CONFIG_STREAMS = 4,
    DCAMERA_EVENT_RELEASE_STREAMS = 5,
    DCAMERA_EVENT_START_CAPTURE = 6,
    DCAMERA_EVENT_STOP_CAPTURE = 7,
    DCAMERA_EVENT_UPDATE_SETTINGS = 8,
    DCAMERA_EVENT_NOFIFY = 9,
    DCAMERA_EVENT_HICOLLIE = 10,
    DCAMERA_EVENT_GET_FULLCAPS = 11,
} DCAMERA_EVENT;

// 简化版 DCStreamInfo
struct DCStreamInfo {
    int32_t streamId = 0;
    int32_t width = 1920;
    int32_t height = 1080;
    int32_t format = 1; // JPEG
    int32_t dataspace = 0;
};

// 简化版 DCCaptureInfo
struct DCCaptureInfo {
    int32_t streamId = 0;
    bool isCapture = false;
    int32_t width = 1920;
    int32_t height = 1080;
};

// 简化版 DCameraSettings
struct DCameraSettings {
    int32_t streamId = 0;
    int32_t width = 1920;
    int32_t height = 1080;
};

// DCamera Source 事件类
class DCameraSourceEvent {
public:
    explicit DCameraSourceEvent() {}
    ~DCameraSourceEvent() = default;
    explicit DCameraSourceEvent(DCAMERA_EVENT eventType)
        : eventType_(eventType) {}
    explicit DCameraSourceEvent(DCAMERA_EVENT eventType, DCameraIndex& index)
        : eventType_(eventType)
    {
        eventParam_ = index;
    }

    explicit DCameraSourceEvent(DCAMERA_EVENT eventType,
        std::shared_ptr<DCameraRegistParam>& param) : eventType_(eventType)
    {
        eventParam_ = param;
    }

    explicit DCameraSourceEvent(DCAMERA_EVENT eventType,
        const std::vector<std::shared_ptr<DCStreamInfo>>& streamInfos) : eventType_(eventType)
    {
        eventParam_ = std::move(streamInfos);
    }

    explicit DCameraSourceEvent(DCAMERA_EVENT eventType,
        const std::vector<std::shared_ptr<DCCaptureInfo>>& captureInfos) : eventType_(eventType)
    {
        eventParam_ = std::move(captureInfos);
    }

    explicit DCameraSourceEvent(DCAMERA_EVENT eventType,
        const std::vector<std::shared_ptr<DCameraSettings>>& settings) : eventType_(eventType)
    {
        eventParam_ = std::move(settings);
    }

    explicit DCameraSourceEvent(DCAMERA_EVENT eventType, const std::vector<int>& streamIds)
        : eventType_(eventType)
    {
        eventParam_ = std::move(streamIds);
    }

    explicit DCameraSourceEvent(DCAMERA_EVENT eventType, std::shared_ptr<DCameraEvent>& camEvent)
        : eventType_(eventType)
    {
        eventParam_ = camEvent;
    }

    int32_t GetDCameraIndex(DCameraIndex& index);
    int32_t GetDCameraRegistParam(std::shared_ptr<DCameraRegistParam>& param);
    int32_t GetStreamInfos(std::vector<std::shared_ptr<DCStreamInfo>>& streamInfos);
    int32_t GetCaptureInfos(std::vector<std::shared_ptr<DCCaptureInfo>>& captureInfos);
    int32_t GetCameraSettings(std::vector<std::shared_ptr<DCameraSettings>>& settings);
    int32_t GetStreamIds(std::vector<int>& streamIds);
    int32_t GetCameraEvent(std::shared_ptr<DCameraEvent>& camEvent);
    DCAMERA_EVENT GetEventType();

private:
    using EventParam = std::variant<std::monostate,
        DCameraIndex,
        std::shared_ptr<DCameraRegistParam>,
        std::vector<std::shared_ptr<DCStreamInfo>>,
        std::vector<std::shared_ptr<DCCaptureInfo>>,
        std::vector<std::shared_ptr<DCameraSettings>>,
        std::vector<int>,
        std::shared_ptr<DCameraEvent>>;

private:
    DCAMERA_EVENT eventType_;
    EventParam eventParam_;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_SOURCE_EVENT_H
