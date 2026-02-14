/*
 * Distributed Camera Common Definitions Stub for macOS Mock
 *
 * 提供分布式相机相关的常量和类型定义
 * 只包含源码中**不存在**的定义
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_COMMON_H
#define STUBS_DISTRIBUTED_CAMERA_COMMON_H

#include <cstdint>
#include <vector>
#include <string>

// 包含必要的类型和枚举定义
namespace OHOS {
namespace DistributedHardware {

// ========== 数据处理类型（源码中不存在） ==========

// 数据类型枚举
enum {
    DCAMERA_MESSAGE = 0,
    DCAMERA_OPERATION = 1,
    DCAMERA_SINK_STOP = 2,
    DCAMERE_GETFULLCAP = 3,
} DCameraEventType;

// 授权状态枚举
enum {
    DCAMERA_AUTHORIZATION_DEFAULT = 0,
    DCAMERA_AUTHORIZATION_AGREE = 1,
    DCAMERA_AUTHORIZATION_REJECT = 2,
    DCAMERA_AUTHORIZATION_TIMEOUT = 3,
} AuthorizationState;

// 访问控制类型枚举
enum {
    DCAMERA_SAME_ACCOUNT = 0,
    DCAMERA_DIFF_ACCOUNT = 1,
    DCAMERA_NO_ACCOUNT = 2,
} AccessControlType;

// 相机服务状态枚举
enum {
    DCAMERA_SRV_STATE_NOT_START,
    DCAMERA_SRV_STATE_RUNNING,
} DCameraServiceState;

// ========== 函数声明（源码中不存在） ==========

// 匿名字符化函数（如果源码中有定义则不添加）
// inline std::string GetAnonyString(const std::string& value);

// 相机能力辅助类（如果源码中有定义则不添加）
// class CameraAdapterHelper {
// public:
//     static int32_t GetCameraCodecType(const std::string& codecType);
// };

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DISTRIBUTED_CAMERA_COMMON_H
