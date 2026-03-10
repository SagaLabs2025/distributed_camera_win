/*
 * HiTrace Mock Implementation for macOS
 *
 * OpenHarmony HiTrace 性能跟踪 API 的 macOS Mock 实现
 */

#include <cstdint>
#include <string>

// HiTrace API Mock 实现

extern "C" {

/**
 * @brief 开始性能跟踪
 * @param label 跟踪标签
 * @param value 跟踪值/名称
 */
void StartTrace(uint64_t label, const std::string& value)
{
    // Mock 实现：不执行实际跟踪
    (void)label;
    (void)value;
}

/**
 * @brief 结束性能跟踪
 * @param label 跟踪标签
 */
void FinishTrace(uint64_t label)
{
    // Mock 实现：不执行实际跟踪
    (void)label;
}

/**
 * @brief 开始异步跟踪
 * @param label 跟踪标签
 * @param value 跟踪值/名称
 * @param taskId 任务ID
 */
void StartAsyncTrace(uint64_t label, const std::string& value, int32_t taskId)
{
    // Mock 实现：不执行实际跟踪
    (void)label;
    (void)value;
    (void)taskId;
}

/**
 * @brief 结束异步跟踪
 * @param label 跟踪标签
 * @param value 跟踪值/名称
 * @param taskId 任务ID
 */
void FinishAsyncTrace(uint64_t label, const std::string& value, int32_t taskId)
{
    // Mock 实现：不执行实际跟踪
    (void)label;
    (void)value;
    (void)taskId;
}

/**
 * @brief 计数跟踪
 * @param label 跟踪标签
 * @param name 计数器名称
 * @param count 计数值
 */
void CountTrace(uint64_t label, const std::string& name, int64_t count)
{
    // Mock 实现：不执行实际跟踪
    (void)label;
    (void)name;
    (void)count;
}

} // extern "C"
