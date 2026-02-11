/*
 * HiTrace Meter Stub for macOS Mock
 *
 * OpenHarmony 性能追踪工具的 macOS 兼容层
 */

#ifndef STUBS_HITRACE_METER_H
#define STUBS_HITRACE_METER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 追踪标签类型
 */
typedef uint64_t HiTraceId;

/**
 * @brief 追踪模式枚举
 */
enum HiTraceMode {
    HITRACE_MODE_DEFAULT = 0,
    HITRACE_MODE_INCLUDE = 1,
    HITRACE_MODE_EXCLUDE = 2,
};

/**
 * @brief 追踪通信类型枚举
 */
enum HiTraceCommunicationType {
    HITRACE_COMMUNICATION_TYPE_THREAD = 0,
    HITRACE_COMMUNICATION_TYPE_PROCESS = 1,
    HITRACE_COMMUNICATION_TYPE_DEVICE = 2,
};

/**
 * @brief 分布式相机追踪标签
 */
#define HITRACE_TAG_DISTRIBUTED_CAMERA 0xD004100

/**
 * @brief 追踪计量宏
 */
#define HITRACE_METER_NAME(label, value) \
    do { \
        (void)(label); \
        (void)(value); \
    } while(0)

/**
 * @brief 获取当前追踪 ID
 * @return 追踪 ID
 */
static inline HiTraceId HiTrace_GetId()
{
    return 0;  // Mock: 返回无效追踪 ID
}

/**
 * @brief 设置追踪 ID
 * @param id 追踪 ID
 */
static inline void HiTrace_SetId(HiTraceId id)
{
    (void)id;  // Mock: 空实现
}

/**
 * @brief 创建追踪 span
 * @param id 追踪 ID
 * @param nameSpan Span 名称
 * @param flags 标志位
 * @return 新的追踪 ID
 */
static inline HiTraceId HiTrace_BeginSpan(HiTraceId id, const char* nameSpan, uint32_t flags)
{
    (void)id; (void)nameSpan; (void)flags;
    return 0;  // Mock: 返回无效追踪 ID
}

/**
 * @brief 结束追踪 span
 * @param id 追踪 ID
 */
static inline void HiTrace_EndSpan(HiTraceId id)
{
    (void)id;  // Mock: 空实现
}

/**
 * @brief 追踪函数调用开始
 * @param name 函数名
 * @param flags 标志位
 * @return 追踪 ID
 */
static inline HiTraceId HiTrace_StartTrace(const char* name, uint32_t flags)
{
    (void)name; (void)flags;
    return 0;  // Mock: 返回无效追踪 ID
}

/**
 * @brief 追踪函数调用结束
 */
static inline void HiTrace_FinishTrace()
{
    // Mock: 空实现
}

/**
 * @brief 追踪计数
 * @param name 名称
 * @param count 计数值
 */
static inline void HiTrace_CountTrace(const char* name, int64_t count)
{
    (void)name; (void)count;  // Mock: 空实现
}

/**
 * @brief 判断是否启用追踪
 * @param mode 追踪模式
 * @return true/false
 */
static inline int HiTrace_IsTraceEnabled(HiTraceMode mode)
{
    (void)mode;
    return 0;  // Mock: 返回未启用
}

#ifdef __cplusplus
}
#endif

#endif // STUBS_HITRACE_METER_H
