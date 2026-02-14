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
    static DcameraRadar& GetInstance()
    {
        static DcameraRadar instance;
        return instance;
    }
    
    void ReportDcameraOpen(const std::string& devId, CameraOpen openType, BizState state, int result)
    {
        (void)devId;
        (void)openType;
        (void)state;
        (void)result;
        // Mock: 空实现
    }
    
    void ReportDcameraClose(const std::string& devId, CameraClose closeType, BizState state, int result)
    {
        (void)devId;
        (void)closeType;
        (void)state;
        (void)result;
        // Mock: 空实现
    }
    
    void ReportDcameraOpenProgress(const std::string& devId, CameraOpen openType, int progress)
    {
        (void)devId;
        (void)openType;
        (void)progress;
        // Mock: 空实现
    }
};

} // namespace DistributedHardware
} // namespace OHOS
