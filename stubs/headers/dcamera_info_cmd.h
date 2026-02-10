/*
 * DCamera Info Command - OpenHarmony Distributed Camera - macOS Mock
 *
 * 相机信息命令的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_INFO_CMD_H
#define STUBS_DCAMERA_INFO_CMD_H

#include <string>

namespace OHOS {
namespace DistributedHardware {

// DCameraInfo - 相机信息
struct DCameraInfo {
    std::string devId_;
    std::string dhId_;

    DCameraInfo() = default;
    ~DCameraInfo() = default;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_INFO_CMD_H
