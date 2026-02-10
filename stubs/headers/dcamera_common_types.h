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

#ifndef OHOS_DCAMERA_COMMON_TYPES_H
#define OHOS_DCAMERA_COMMON_TYPES_H

#include <string>
#include <memory>
#include <stdint.h>
#include <vector>

namespace OHOS {
namespace DistributedHardware {

// 在 Mock 模式下，提前包含 HDF 类型定义
// 注意：必须在命名空间内包含，避免命名空间冲突
#ifdef DCAMERA_MACOS_MOCK
#include "v1_1/dcamera_types.h"
#endif

// ============================================================================
// 条件编译：根据是否在 Mock 模式下选择不同的类型定义
// ============================================================================

#ifdef DCAMERA_MACOS_MOCK
// ----------------------------------------------------------------------------
// Mock 编译模式：使用 HDF 命名空间的类型
// ----------------------------------------------------------------------------

// 在命名空间外包含 HDF 类型定义
namespace HDI {
    namespace DistributedCamera {
        namespace V1_1 {
            class DCStreamType;
            class DCEncodingType;
        }
    }
}

// 使用类型别名
using DCStreamType = ::OHOS::HDI::DistributedCamera::V1_1::DCStreamType;
using DCEncodeType = ::OHOS::HDI::DistributedCamera::V1_1::DCEncodingType;

#else
// ----------------------------------------------------------------------------
// 原始编译模式：保持 OpenHarmony 原始代码不变
// ----------------------------------------------------------------------------

/**
 * @brief 流类型枚举
 */
enum DCStreamType {
    SNAPSHOT_STREAM = 0,
    CONTINUOUS_FRAME = 1,
    END = 2
};

/**
 * @brief 编码类型枚举
 */
enum DCEncodeType {
    ENCODE_TYPE_NONE = 0,
    ENCODE_TYPE_H264 = 1,
    ENCODE_TYPE_H265 = 2,
    ENCODE_TYPE_JPEG = 3
};

#endif // DCAMERA_MACOS_MOCK

// ============================================================================
// 通用类型定义（Mock 和原始模式都使用）
// ============================================================================

// DCameraEvent 和 DCameraEventCmd 在源码的 dcamera_event_cmd.h 中完整定义
// 此处包含该头文件，确保完整类型可用
#include "dcamera_event_cmd.h"

// DCSettingsType - 设置类型枚举（用于 OpenHarmony 源码）
enum DCSettingsType {
    DCAMERA_SETTINGS_TYPE_INVALID = 0,
    DCAMERA_SETTINGS_TYPE_ISP = 1,
    DCAMERA_SETTINGS_TYPE_REGION = 2,
    DCAMERA_SETTINGS_TYPE_AEC = 3,
};

/**
 * @brief 相机设置类
 * 描述相机捕获的设置参数
 * 注意：此类型不在 OpenHarmony 源码中定义，为 Mock 特有
 */
class DCameraSettings {
public:
    int32_t type_;        // 设置类型
    std::string value_;   // 设置值

    DCameraSettings() : type_(0) {}
    ~DCameraSettings() = default;
};

/**
 * @brief 分布式相机注册参数
 * 注意：此类型不在 OpenHarmony 源码中定义，为 Mock 特有
 */
struct DCameraRegistParam {
    std::string devId_;      // 设备ID
    std::string dhId_;       // 分布式硬件ID
    std::string reqId_;      // 请求ID
    std::string version_;    // 版本信息
    int32_t state_;          // 状态
    int32_t dataType_;       // 数据类型
    int32_t position_;       // 位置
    std::string sinkParam_;  // 接收端参数（JSON字符串）
    std::string srcParam_;   // 发送端参数（JSON字符串）

    DCameraRegistParam() : state_(0), dataType_(0), position_(0) {}
};

/**
 * @brief 分布式相机事件结果枚举
 */
enum DCameraEventResult {
    DCAMERA_EVENT_RESULT_SUCCESS = 0,
    DCAMERA_EVENT_RESULT_FAILED = -1,
    DCAMERA_EVENT_RESULT_TIMEOUT = -2,
};

/**
 * @brief 分布式相机事件类型枚举
 */
enum DCAMERA_EVENT {
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
    DCAMERA_EVENT_OPEN_CHANNEL_ERROR = 12,
    DCAMERA_EVENT_CLOSE_CHANNEL_ERROR = 13,
    DCAMERA_EVENT_CONFIG_STREAMS_ERROR = 14,
    DCAMERA_EVENT_RELEASE_STREAMS_ERROR = 15,
    DCAMERA_EVENT_START_CAPTURE_ERROR = 16,
    DCAMERA_EVENT_STOP_CAPTURE_ERROR = 17,
    DCAMERA_EVENT_UPDATE_SETTINGS_ERROR = 18,
    // 添加额外的事件类型（Mock 特有）
    DCAMERA_EVENT_CHANNEL_DISCONNECTED = 19,
};

// DCAMERA_MESSAGE - 事件消息类型（用于状态机）
enum DCAMERA_MESSAGE {
    DCAMERA_MESSAGE_UNKNOWN = 0,
    DCAMERA_MESSAGE_START_CAPTURE = 1,
    DCAMERA_MESSAGE_STOP_CAPTURE = 2,
};

/**
 * @brief 分布式相机服务状态类型枚举
 * 用于 DistributedCameraSourceService 的状态管理
 */
enum DCameraServiceState {
    DCAMERA_SRV_STATE_NOT_START = 0,     // 未启动
    DCAMERA_SRV_STATE_STARTING = 1,      // 启动中
    DCAMERA_SRV_STATE_STARTED = 2,       // 已启动
    DCAMERA_SRV_STATE_STOPPING = 3,      // 停止中
    DCAMERA_SRV_STATE_STOPPED = 4,       // 已停止
};

/**
 * @brief 分布式相机状态类型枚举
 * 注意：这个类型在 OpenHarmony 源码的 dcamera_source_state.h 中已定义，此处不重复定义
 * 只保留用于 Mock 的额外定义
 */

/**
 * @brief 分布式硬件启用参数
 */
struct EnableParam {
    std::string dhId;            // 分布式硬件ID
    std::string reqId;           // 请求ID
    std::string sinkVersion;     // 接收端版本
    std::string sourceVersion;   // 发送端版本
    std::string sourceAttrs;     // 发送端属性
    std::string sinkAttrs;       // 接收端属性
    std::string subtype;         // 子类型
    int32_t version;             // 版本号

    EnableParam() : version(0) {}
};

/**
 * @brief 分布式硬件工作模式参数
 */
struct WorkModeParam {
    int32_t mode;                // 工作模式
    std::string param;           // 参数字符串

    WorkModeParam() : mode(0) {}
};

/**
 * @brief 相机系统开关信息
 * 注意：此类型不在 OpenHarmony 源码中定义，为 Mock 特有
 */
class DCameraSystemSwitchInfo {
public:
    static DCameraSystemSwitchInfo& GetInstance();
    void SetSystemSwitchFlagAndRotation(const std::string& devId, const std::string& dhId, int32_t result);

private:
    DCameraSystemSwitchInfo() = default;
    ~DCameraSystemSwitchInfo() = default;
};

// 注意：以下类型已在 OpenHarmony 源码中定义，此处不再重复定义：
// - DCameraChannelDetail (在 dcamera_channel_info_cmd.h 中)
// - DCameraChannelInfo (在 dcamera_channel_info_cmd.h 中)
// - DCameraCaptureInfo (在 dcamera_capture_info_cmd.h 中)
// - DCameraInfo (在 dcamera_info_cmd.h 中)
// - DCameraOpenInfo (在 dcamera_open_info_cmd.h 中)
// - DCStreamInfo (在 v1_1/dcamera_types.h 中)
// - DCCaptureInfo (在 v1_1/dcamera_types.h 中)

} // namespace DistributedHardware
} // namespace OHOS

#endif // OHOS_DCAMERA_COMMON_TYPES_H
