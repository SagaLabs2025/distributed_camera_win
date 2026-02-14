/*
 * DcameraRadar Mock Implementation for macOS
 *
 * OpenHarmony DcameraRadar 的 macOS Mock 空实现
 */

#include <string>

namespace OHOS {
namespace DistributedHardware {

// 前向声明枚举
enum class CameraOpen {};
enum class CameraClose {};
enum class BizState {};

class DcameraRadar {
public:
    static DcameraRadar& GetInstance();
    
    void ReportDcameraOpen(const std::string& devId, CameraOpen openType, BizState state, int result);
    void ReportDcameraClose(const std::string& devId, CameraClose closeType, BizState state, int result);
    void ReportDcameraOpenProgress(const std::string& devId, CameraOpen openType, int progress);
    void ReportDcameraCloseProgress(const std::string& devId, CameraClose closeType, int progress);
};

// 实现
DcameraRadar& DcameraRadar::GetInstance()
{
    static DcameraRadar instance;
    return instance;
}

void DcameraRadar::ReportDcameraOpen(const std::string& devId, CameraOpen openType, BizState state, int result)
{
    (void)devId;
    (void)openType;
    (void)state;
    (void)result;
    // Mock: 空实现
}

void DcameraRadar::ReportDcameraClose(const std::string& devId, CameraClose closeType, BizState state, int result)
{
    (void)devId;
    (void)closeType;
    (void)state;
    (void)result;
    // Mock: 空实现
}

void DcameraRadar::ReportDcameraOpenProgress(const std::string& devId, CameraOpen openType, int progress)
{
    (void)devId;
    (void)openType;
    (void)progress;
    // Mock: 空实现
}

void DcameraRadar::ReportDcameraCloseProgress(const std::string& devId, CameraClose closeType, int progress)
{
    (void)devId;
    (void)closeType;
    (void)progress;
    // Mock: 空实现
}

} // namespace DistributedHardware
} // namespace OHOS
