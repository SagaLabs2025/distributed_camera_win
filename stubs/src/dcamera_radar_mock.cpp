/*
 * DcameraRadar Mock Implementation for macOS
 *
 * Provide empty implementations so camera code can link on macOS.
 */

#include "dcamera_radar.h"

namespace OHOS {
namespace DistributedHardware {

FWK_IMPLEMENT_SINGLE_INSTANCE(DcameraRadar);

bool DcameraRadar::ReportDcameraInit(const std::string& func, CameraInit bizStage, BizState bizState, int32_t errCode)
{
    (void)func;
    (void)bizStage;
    (void)bizState;
    (void)errCode;
    return true;
}

bool DcameraRadar::ReportDcameraInitProgress(const std::string& func, CameraInit bizStage, int32_t errCode)
{
    (void)func;
    (void)bizStage;
    (void)errCode;
    return true;
}

bool DcameraRadar::ReportDcameraOpen(const std::string& func, CameraOpen bizStage, BizState bizState, int32_t errCode)
{
    (void)func;
    (void)bizStage;
    (void)bizState;
    (void)errCode;
    return true;
}

bool DcameraRadar::ReportDcameraOpenProgress(const std::string& func, CameraOpen bizStage, int32_t errCode)
{
    (void)func;
    (void)bizStage;
    (void)errCode;
    return true;
}

bool DcameraRadar::ReportDcameraClose(const std::string& func, CameraClose bizStage, BizState bizState, int32_t errCode)
{
    (void)func;
    (void)bizStage;
    (void)bizState;
    (void)errCode;
    return true;
}

bool DcameraRadar::ReportDcameraCloseProgress(const std::string& func, CameraClose bizStage, int32_t errCode)
{
    (void)func;
    (void)bizStage;
    (void)errCode;
    return true;
}

bool DcameraRadar::ReportDcameraUnInit(const std::string& func, CameraUnInit bizStage, BizState bizState, int32_t errCode)
{
    (void)func;
    (void)bizStage;
    (void)bizState;
    (void)errCode;
    return true;
}

} // namespace DistributedHardware
} // namespace OHOS
