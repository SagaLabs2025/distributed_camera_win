/*
 * Parameter Stub for macOS Mock
 *
 * OpenHarmony 系统参数 API 的 macOS 兼容层
 * 提供 GetParameter 和 SetParameter 函数的模拟实现
 */

#ifndef STUBS_PARAMETER_H
#define STUBS_PARAMETER_H

#include <cstring>
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief 获取系统参数
 * 
 * @param key 参数键名
 * @param def 默认值
 * @param value 输出缓冲区
 * @param len 缓冲区长度
 * @return 成功返回实际长度，失败返回 -1
 */
static inline int GetParameter(const char* key, const char* def, char* value, unsigned int len)
{
    if (key == nullptr || value == nullptr || len == 0) {
        return -1;
    }
    
    // Mock 实现：总是返回默认值
    if (def != nullptr) {
        size_t defLen = strlen(def);
        if (defLen < len) {
            strncpy(value, def, len - 1);
            value[len - 1] = '\0';
            return static_cast<int>(defLen);
        }
    }
    
    // 如果没有默认值或默认值太长，返回空字符串
    value[0] = '\0';
    return 0;
}

/**
 * @brief 设置系统参数
 * 
 * @param key 参数键名
 * @param value 参数值
 * @return 成功返回 0，失败返回 -1
 */
static inline int SetParameter(const char* key, const char* value)
{
    if (key == nullptr || value == nullptr) {
        return -1;
    }
    
    // Mock 实现：总是返回成功
    return 0;
}

/**
 * @brief 等待系统参数
 * 
 * @param key 参数键名
 * @param value 期望的参数值
 * @param timeout 超时时间（秒）
 * @return 成功返回 0，失败返回 -1
 */
static inline int WaitParameter(const char* key, const char* value, int timeout)
{
    if (key == nullptr || value == nullptr) {
        return -1;
    }
    
    (void)timeout;
    // Mock 实现：总是返回成功
    return 0;
}

/**
 * @brief 监听系统参数变化
 * 
 * @param key 参数键名
 * @param callback 回调函数
 * @param context 上下文指针
 * @return 成功返回 0，失败返回 -1
 */
typedef void (*ParameterChangeCallback)(const char* key, const char* value, void* context);

static inline int WatchParameter(const char* key, ParameterChangeCallback callback, void* context)
{
    if (key == nullptr || callback == nullptr) {
        return -1;
    }
    
    (void)context;
    // Mock 实现：总是返回成功
    return 0;
}

#ifdef __cplusplus
}
#endif

#endif // STUBS_PARAMETER_H
