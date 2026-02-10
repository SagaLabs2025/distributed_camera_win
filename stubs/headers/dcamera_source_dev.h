/*
 * Copyright (c) 2021-2025 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OHOS_DCAMERA_SOURCE_DEV_H
#define OHOS_DCAMERA_SOURCE_DEV_H

#include <set>
#include <map>
#include <string>
#include <memory>
#include <atomic>
#include <cstdint>
#include <functional>

#include "dcamera_index.h"
#include "dcamera_common_types.h"
#include "dcamera_macros.h"
#include "dcamera_source_event.h"
#include "dcamera_source_state_machine.h"
#include "event_handler.h"
#include "icamera_controller.h"
#include "icamera_state_listener.h"
#include "icamera_input.h"
#include "idistributed_camera_source.h"
#include "v1_1/dcamera_types.h"

#include "v1_1/id_camera_provider_callback.h"
#include "v1_1/id_camera_provider.h"

namespace OHOS {
namespace DistributedHardware {

// 前向声明
class ICameraStateListener;
class ICameraController;
class ICameraInput;
class DCameraSourceStateMachine;
class DCameraSourceController;
class DCameraSourceInput;

// DCameraRegistParam 已在 dcamera_common_types.h 中定义，此处不需要重复定义

// IDCameraProviderCallback 接口定义（兼容层）
class IDCameraProviderCallback {
public:
    virtual ~IDCameraProviderCallback() = default;
    virtual void OnCameraResult(const std::string& devId, int32_t result) = 0;
};

// 枚举定义
enum DcameraBusinessState : int32_t {
    UNKNOWN,
    IDLE,
    RUNNING,
    PAUSING
};

// 事件常量
const uint32_t EVENT_SOURCE_DEV_PROCESS = 0;
const uint32_t EVENT_HICOLLIE = 1;
const uint32_t EVENT_PROCESS_HDF_NOTIFY = 2;
const uint32_t EVENT_DCAMERA_FORCE_SWITCH = 4;

// DCameraSourceDev 类 - Windows Mock 实现
class DCameraSourceDev : public std::enable_shared_from_this<DCameraSourceDev> {
public:
    // 构造函数 - 由源码实现，这里只声明
    explicit DCameraSourceDev(std::string devId, std::string dhId,
        std::shared_ptr<ICameraStateListener>& stateLisener);

    virtual ~DCameraSourceDev();

    // 公共接口方法
    int32_t Initialize();
    int32_t Release();
    int32_t InitDCameraSourceDev();

    int32_t RegisterDistributedHardware(const std::string& devId, const std::string& dhId,
        const std::string& reqId, const EnableParam& param);
    int32_t UnRegisterDistributedHardware(const std::string devId, const std::string dhId,
        const std::string reqId);
    int32_t DCameraNotify(std::string& eventStr);
    int32_t OpenSession(DCameraIndex& camIndex);
    int32_t CloseSession(DCameraIndex& camIndex);
    int32_t ConfigCameraStreams(const std::vector<std::shared_ptr<DCStreamInfo>>& streamInfos);
    int32_t ReleaseCameraStreams(const std::vector<int>& streamIds);
    int32_t StartCameraCapture(const std::vector<std::shared_ptr<DCCaptureInfo>>& captureInfos);
    int32_t StopCameraCapture(const std::vector<int>& streamIds);
    int32_t UpdateCameraSettings(const std::vector<std::shared_ptr<DCameraSettings>>& settings);
    int32_t ProcessHDFEvent(const OHOS::HDI::DistributedCamera::V1_1::DCameraHDFEvent& event);
    int32_t GetStateInfo();
    std::string GetVersion();
    int32_t OnChannelConnectedEvent();
    int32_t OnChannelDisconnectedEvent();
    int32_t PostHicollieEvent();
    void SetHicollieFlag(bool flag);
    bool GetHicollieFlag();
    int32_t GetFullCaps();
    void SetTokenId(uint64_t token);
    int32_t UpdateDCameraWorkMode(const WorkModeParam& param);

    // EventHandler 内部类
    class DCameraSourceDevEventHandler : public AppExecFwk::EventHandler {
    public:
        DCameraSourceDevEventHandler(const std::shared_ptr<AppExecFwk::EventRunner> &runner,
            std::shared_ptr<DCameraSourceDev> srcDevPtr);
        ~DCameraSourceDevEventHandler() override = default;
        void ProcessEvent(const AppExecFwk::InnerEvent::Pointer &event) override;
    private:
        std::weak_ptr<DCameraSourceDev> srcDevPtrWPtr_;
    };

public:
    // 虚方法 - 供子类重写
    virtual int32_t Register(std::shared_ptr<DCameraRegistParam>& param);
    virtual int32_t UnRegister(std::shared_ptr<DCameraRegistParam>& param);
    virtual int32_t OpenCamera();
    virtual int32_t CloseCamera();
    virtual int32_t ConfigStreams(std::vector<std::shared_ptr<DCStreamInfo>>& streamInfos);
    virtual int32_t ReleaseStreams(std::vector<int>& streamIds, bool& isAllRelease);
    virtual int32_t ReleaseAllStreams();
    virtual int32_t StartCapture(std::vector<std::shared_ptr<DCCaptureInfo>>& captureInfos);
    virtual int32_t StopCapture(std::vector<int>& streamIds, bool& isAllStop);
    virtual int32_t StopAllCapture();
    virtual int32_t UpdateSettings(std::vector<std::shared_ptr<DCameraSettings>>& settings);
    virtual int32_t CameraEventNotify(std::shared_ptr<DCameraEvent>& events);

private:
    using DCameraNotifyFunc = void (DCameraSourceDev::*)(DCAMERA_EVENT eventType, DCameraSourceEvent& event,
        int32_t result);

    void NotifyResult(DCAMERA_EVENT eventType, DCameraSourceEvent& event, int32_t result);
    void NotifyRegisterResult(DCAMERA_EVENT eventType, DCameraSourceEvent& event, int32_t result);
    void NotifyHalResult(DCAMERA_EVENT eventType, DCameraSourceEvent& event, int32_t result);

    // 事件处理函数
    void DoHicollieProcess();
    void DoProcessData(const AppExecFwk::InnerEvent::Pointer& event);
    void DoProcesHDFEvent(const AppExecFwk::InnerEvent::Pointer& event);

private:
    std::string devId_;
    std::string dhId_;
    std::string version_;
    std::set<DCameraIndex> actualDevInfo_;
    std::shared_ptr<ICameraStateListener> stateListener_;
    std::shared_ptr<DCameraSourceDevEventHandler> srcDevEventHandler_ = nullptr;
    std::shared_ptr<DCameraSourceStateMachine> stateMachine_;
    std::shared_ptr<ICameraController> controller_;
    std::shared_ptr<ICameraInput> input_;
    std::atomic<bool> hicollieFlag_ = true;
    std::shared_ptr<IDCameraProviderCallback> hdiCallback_;
    int32_t sceneMode_ = 0;
    uint64_t tokenId_ = 0;

    std::map<uint32_t, DCameraNotifyFunc> memberFuncMap_;
    std::map<uint32_t, int32_t> eventResultMap_;  // 使用 int32_t 以支持 DCAMERA_EVENT 枚举值
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // OHOS_DCAMERA_SOURCE_DEV_H
