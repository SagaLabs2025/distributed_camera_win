/*
 * HiSysEvent Stub for macOS Mock
 *
 * OpenHarmony HiSysEvent 事件上报的 macOS 兼容层
 */

#ifndef STUBS_HISYSEVENT_H
#define STUBS_HISYSEVENT_H

#include <string>
#include <cstdint>
#include <cstdarg>

#ifdef __cplusplus
namespace OHOS {
namespace HiviewDFX {

/**
 * @brief HiSysEvent 域名定义（简化版本）
 */
namespace Domain {
constexpr const char* DISTRIBUTED_CAMERA = "DISTRIBUTED_CAMERA";
}

/**
 * @brief HiSysEvent 事件类型
 */
enum class EventType {
    FAULT = 0,
    STATISTIC = 1,
    SECURITY = 2,
    BEHAVIOR = 3,
};

/**
 * @brief HiSysEvent 类（Mock 实现）
 */
class HiSysEvent {
public:
    /**
     * @brief 写入 HiSysEvent（Mock：空实现，返回成功）
     */
    static int32_t Write(const std::string& domain, const std::string& eventName,
                        EventType type, const char* key1 = "", const char* val1 = "", ...)
    {
        (void)domain; (void)eventName; (void)type;
        (void)key1; (void)val1;
        return 0;  // Mock: 总是成功
    }

    // 嵌套 EventType，与 OpenHarmony 原生 API 兼容
    using EventTypeNested = EventType;
};

} // namespace HiviewDFX
} // namespace OHOS

// HiSysEventWrite 函数声明（C 风格，支持可变参数）
inline int32_t HiSysEventWrite(const std::string& domain, const std::string& eventName,
                               OHOS::HiviewDFX::EventType type, ...)
{
    (void)domain; (void)eventName; (void)type;
    return 0;  // Mock: 总是成功
}

#endif // __cplusplus

#endif // STUBS_HISYSEVENT_H
