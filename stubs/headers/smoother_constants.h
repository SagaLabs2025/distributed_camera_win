/*
 * Smoother Constants - OpenHarmony - macOS Stub
 *
 * 平滑处理器常量定义
 */

#ifndef STUBS_SMOOTHER_CONSTANTS_H
#define STUBS_SMOOTHER_CONSTANTS_H

namespace OHOS {
namespace DistributedHardware {

typedef enum {
    SMOOTH_START = 0,
    SMOOTH_STOP = 1,
} SmoothState;

typedef enum {
    SMOOTH_SUCCESS = 0,
    SMOOTH_IS_STARTED = 1,
    SMOOTH_IS_STOPED = 2,
} SmoothErrorCode;

typedef enum {
    NOTIFY_SUCCESS = 0,
    NOTIFY_FAILED = 1,
} SmootherListnerState;

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_SMOOTHER_CONSTANTS_H
