/*
 * DCamera Channel Info Command - OpenHarmony Distributed Camera - macOS Mock
 *
 * 相机通道信息命令的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_CHANNEL_INFO_CMD_H
#define STUBS_DCAMERA_CHANNEL_INFO_CMD_H

#include <string>
#include <vector>

namespace OHOS {
namespace DistributedHardware {

// DCameraChannelDetail - 通道详细信息
struct DCameraChannelDetail {
    std::string channelId_;
    int32_t channelType_;
};

// DCameraChannelInfo - 通道信息
struct DCameraChannelInfo {
    std::string devId_;
    std::string dhId_;
    std::vector<DCameraChannelDetail> channelDetails_;

    DCameraChannelInfo() = default;
    ~DCameraChannelInfo() = default;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_CHANNEL_INFO_CMD_H
