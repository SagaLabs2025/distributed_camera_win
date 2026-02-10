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

#ifndef OHOS_IDISTRIBUTED_CAMERA_SOURCE_H
#define OHOS_IDISTRIBUTED_CAMERA_SOURCE_H

#include "iremote_broker.h"
#include "idcamera_source_callback.h"
#include "idistributed_hardware_source.h"

// 使用 IRemoteBroker
using ::OHOS::IRemoteBroker;

namespace OHOS {
namespace DistributedHardware {

class IDistributedCameraSource : public IRemoteBroker {
public:
    // Windows Mock: 使用普通字符串替代 char16_t 字符串
    DECLARE_INTERFACE_DESCRIPTOR("ohos.distributedhardware.distributedcamerasource");

    ~IDistributedCameraSource() override = default;
    virtual int32_t InitSource(const std::string& params, const std::shared_ptr<IDCameraSourceCallback>& callback) = 0;
    virtual int32_t ReleaseSource() = 0;
    virtual int32_t RegisterDistributedHardware(const std::string& devId, const std::string& dhId,
        const std::string& reqId, const EnableParam& param) = 0;
    virtual int32_t UnregisterDistributedHardware(const std::string& devId, const std::string& dhId,
        const std::string& reqId) = 0;
    virtual int32_t DCameraNotify(const std::string& devId, const std::string& dhId, std::string& events) = 0;
    virtual int32_t UpdateDistributedHardwareWorkMode(const std::string& devId, const std::string& dhId,
        const WorkModeParam& param) = 0;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // OHOS_IDISTRIBUTED_CAMERA_SOURCE_H
