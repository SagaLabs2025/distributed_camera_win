/*
 * DCamera Open Info Command - OpenHarmony Distributed Camera - macOS Mock
 *
 * 相机打开信息命令的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_OPEN_INFO_CMD_H
#define STUBS_DCAMERA_OPEN_INFO_CMD_H

#include <string>

namespace OHOS {
namespace DistributedHardware {

// DCameraOpenInfo - 相机打开信息
struct DCameraOpenInfo {
    std::string devId_;
    std::string dhId_;

    DCameraOpenInfo() = default;
    ~DCameraOpenInfo() = default;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_OPEN_INFO_CMD_H
