/*
 * Distributed Hardware Log Stub for macOS Mock
 *
 * 提供 DHLOGI/E/W 宏定义，直接映射到 external 的 OH_LOG_* 函数
 * 包含所有需要的工具宏定义
 */

#ifndef OHOS_DISTRIBUTED_HARDWARE_LOG_H
#define OHOS_DISTRIBUTED_HARDWARE_LOG_H

#include <cstdint>
#include <cstdio>
#include <string>

// 使用 external 的 hilog 函数声明
extern "C" {
int OH_LOG_Print(int type, int level, unsigned int domain, const char *tag, const char *fmt, ...);
}

// 引用 cJSON 兼容层
#include "cJSON_compat.h"

// 使用项目中定义的 DH_LOG_TAG
#ifndef DH_LOG_TAG
#define DH_LOG_TAG "DHFWK"
#endif

// 日志级别常量
const int LOG_DEBUG = 0;
const int LOG_INFO = 1;
const int LOG_WARN = 2;
const int LOG_ERROR = 3;
const int LOG_APP = 0;

// 分布式硬件日志宏 - macOS 简化版本

// Debug 日志
#undef DHLOGD
#define DHLOGD(fmt, ...) printf("[%s] " fmt "\n", DH_LOG_TAG, ##__VA_ARGS__)

// Info 日志
#undef DHLOGI
#define DHLOGI(fmt, ...) printf("[%s] " fmt "\n", DH_LOG_TAG, ##__VA_ARGS__)

// Warn 日志
#undef DHLOGW
#define DHLOGW(fmt, ...) printf("[%s] " fmt "\n", DH_LOG_TAG, ##__VA_ARGS__)

// Error 日志
#undef DHLOGE
#define DHLOGE(fmt, ...) printf("[%s] " fmt "\n", DH_LOG_TAG, ##__VA_ARGS__)

// 工具宏 - 参数检查
#define CHECK_NULL_RETURN(cond, ret, ...) \
    do { \
        if ((cond)) { \
            return (ret); \
        } \
    } while (0)

// 检查条件并返回日志（3参数版本：条件、返回值、错误消息）
#define CHECK_AND_RETURN_RET_LOG(cond, ret, fmt, ...) \
    do { \
        if ((cond)) { \
            DHLOGE(fmt, ##__VA_ARGS__); \
            return (ret); \
        } \
    } while (0)

// 检查条件并返回日志（无返回值）
#define CHECK_AND_RETURN_LOG(cond, fmt, ...) \
    do { \
        if ((cond)) { \
            DHLOGE(fmt, ##__VA_ARGS__); \
            return; \
        } \
    } while (0)

// 检查条件并记录日志（不返回）
#define CHECK_AND_LOG(cond, fmt, ...) \
    do { \
        if ((cond)) { \
            DHLOGE(fmt, ##__VA_ARGS__); \
        } \
    } while (0)

// 检查指针并释放返回（4参数版本：指针、返回值、根对象、错误消息）
#define CHECK_NULL_FREE_RETURN(ptr, ret, root, ...) \
    do { \
        if ((ptr) == nullptr) { \
            DHLOGE("Address pointer is null"); \
            cJSON_Delete((root)); \
            return (ret); \
        } \
    } while (0)

// 版本：返回值但打印日志（用于 4 参数的 CHECK_AND_FREE_RETURN_RET_LOG）
#define CHECK_AND_FREE_RETURN_RET_LOG(cond, ret, root, fmt, ...) \
    do { \
        if ((cond)) { \
            DHLOGE(fmt, ##__VA_ARGS__); \
            cJSON_Delete((root)); \
            return (ret); \
        } \
    } while (0)

#endif // OHOS_DISTRIBUTED_HARDWARE_LOG_H
