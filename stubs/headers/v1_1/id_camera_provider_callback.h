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

#ifndef OHOS_HDI_DISTRIBUTED_CAMERA_V1_1_ID_CAMERA_PROVIDER_CALLBACK_H
#define OHOS_HDI_DISTRIBUTED_CAMERA_V1_1_ID_CAMERA_PROVIDER_CALLBACK_H

#include <vector>
#include <string>
#include <memory>
#include "dcamera_types.h"
#include "dcamera_hdf_types.h"

namespace OHOS {
namespace DistributedHardware {
// 前向声明
class DCameraSettings;
} // namespace DistributedHardware

namespace HDI {
namespace DistributedCamera {
namespace V1_1 {

// 前向声明 HDF 类型
struct DCStreamInfo;
struct DCCaptureInfo;

// 前向声明，避免循环依赖
using ::OHOS::DistributedHardware::DCameraSettings;

// IDCameroviderCallback 接口
class IDCameroviderCallback {
public:
    virtual ~IDCameroviderCallback() = default;

    virtual int32_t OpenSession(const DHBase& dhBase) = 0;
    virtual int32_t CloseSession(const DHBase& dhBase) = 0;
    virtual int32_t ConfigureStreams(const DHBase& dhBase, const std::vector<DCStreamInfo>& streamInfos) = 0;
    virtual int32_t ReleaseStreams(const DHBase& dhBase, const std::vector<int>& streamIds) = 0;
    virtual int32_t StartCapture(const DHBase& dhBase, const std::vector<DCCaptureInfo>& captureInfos) = 0;
    virtual int32_t StopCapture(const DHBase& dhBase, const std::vector<int>& streamIds) = 0;
    virtual int32_t UpdateSettings(const DHBase& dhBase, const std::vector<::OHOS::DistributedHardware::DCameraSettings>& settings) = 0;
    virtual int32_t NotifyEvent(const DHBase& dhBase, const DCameraHDFEvent& event) = 0;
};

} // namespace V1_1
} // namespace DistributedCamera
} // namespace HDI
} // namespace OHOS

#endif // OHOS_HDI_DISTRIBUTED_CAMERA_V1_1_ID_CAMERA_PROVIDER_CALLBACK_H
