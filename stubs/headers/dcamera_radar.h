/*
 * DCamera Radar - OpenHarmony Distributed Camera - macOS Mock
 *
 * 分布式相机雷达上报的 macOS 空实现
 */

#ifndef STUBS_DCAMERA_RADAR_H
#define STUBS_DCAMERA_RADAR_H

#include <string>

namespace OHOS {
namespace DistributedHardware {

// DcameraRadar - 雷达上报类
class DcameraRadar {
public:
    // 上报拍摄捕获事件
    static void ReportShootCapture(const std::string& bizStat) {
        (void)bizStat;
    }

    static void ReportShootCapture(const std::string& bizStat, const std::string& bizScene) {
        (void)bizStat;
        (void)bizScene;
    }
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_RADAR_H
