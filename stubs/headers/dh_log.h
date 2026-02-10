/*
 * Distributed Camera Log - OpenHarmony - macOS Stub
 *
 * 分布式硬件日志的 macOS 空实现
 */

#ifndef STUBS_DISTRIBUTED_CAMERA_LOG_H
#define STUBS_DISTRIBUTED_CAMERA_LOG_H

#include "dh_log.h"
#include <stdio.h>

namespace OHOS {
namespace DistributedHardware {

// 日志宏（简单实现）
#define DHLOGI(fmt, ...) printf("[DHLOG-I] " fmt "\n", ##__VA_ARGS__)
#define DHLOGD(fmt, ...) printf("[DHLOG-D] " fmt "\n", ##__VA_ARGS__)
#define DHLOGE(fmt, ...) printf("[DHLOG-E] " fmt "\n", ##__VA_ARGS__)

// 错误检查宏
#define CHECK_NULL_RETURN(cond, ret, ...) \
    do { \
        if ((cond)) { \
            return (ret); \
        } \
    } while (0)

#define CHECK_NULL_FREE_RETURN(ptr, ret, root, ...) \
    do { \
        if ((ptr) == nullptr) { \
            if ((root) != nullptr) { \
                cJSON_Delete(root); \
            } \
            return (ret); \
        } \
    } while (0)

// 空指针删除（无操作）
#define DH_FREE(ptr) (void)(ptr)

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DISTRIBUTED_CAMERA_LOG_H
