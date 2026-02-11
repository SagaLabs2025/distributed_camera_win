/*
 * dcamera_hisysevent_adapter Stub for macOS Mock
 *
 * OpenHarmony 分布式相机 HiSysEvent 适配器的 macOS 兼容层
 * 提供事件上报和消息格式化功能的 Mock 实现
 */

#include "dcamera_hisysevent_adapter.h"
#include <cstdarg>
#include <cstdio>

namespace OHOS {
namespace DistributedHardware {

constexpr int32_t MSG_MAX_LEN = 2048;

// Mock 实现：事件上报函数（本地测试环境不需要实际上报）
void ReportDcamerInitFail(const std::string& eventName, int32_t errCode, const std::string& errMsg)
{
    (void)eventName; (void)errCode; (void)errMsg;
    // Mock: 本地测试环境不需要实际上报 HiSysEvent
}

void ReportRegisterCameraFail(const std::string& eventName, const std::string& devId, const std::string& dhId,
    std::string version, const std::string& errMsg)
{
    (void)eventName; (void)devId; (void)dhId; (void)version; (void)errMsg;
    // Mock: 本地测试环境不需要实际上报 HiSysEvent
}

void ReportDcamerOptFail(const std::string& eventName, int32_t errCode, const std::string& errMsg)
{
    (void)eventName; (void)errCode; (void)errMsg;
    // Mock: 本地测试环境不需要实际上报 HiSysEvent
}

void ReportSaEvent(const std::string& eventName, int32_t saId, const std::string& errMsg)
{
    (void)eventName; (void)saId; (void)errMsg;
    // Mock: 本地测试环境不需要实际上报 HiSysEvent
}

void ReportRegisterCameraEvent(const std::string& eventName, const std::string& devId, const std::string& dhId,
    std::string version, const std::string& errMsg)
{
    (void)eventName; (void)devId; (void)dhId; (void)version; (void)errMsg;
    // Mock: 本地测试环境不需要实际上报 HiSysEvent
}

void ReportCameraOperaterEvent(const std::string& eventName, const std::string& devId, const std::string& dhId,
    const std::string& errMsg)
{
    (void)eventName; (void)devId; (void)dhId; (void)errMsg;
    // Mock: 本地测试环境不需要实际上报 HiSysEvent
}

void ReportStartCaptureEvent(const std::string& eventName, EventCaptureInfo& capture, const std::string& errMsg)
{
    (void)eventName; (void)capture; (void)errMsg;
    // Mock: 本地测试环境不需要实际上报 HiSysEvent
}

// 消息格式化函数实现（实际功能）
std::string CreateMsg(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    char msg[MSG_MAX_LEN] = {0};
    vsnprintf(msg, sizeof(msg), format, args);
    va_end(args);
    return msg;
}

} // namespace DistributedHardware
} // namespace OHOS
