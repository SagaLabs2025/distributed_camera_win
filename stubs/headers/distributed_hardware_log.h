/*
 * Copyright (c) 2021-2024 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OHOS_DISTRIBUTED_HARDWARE_LOG_H
#define OHOS_DISTRIBUTED_HARDWARE_LOG_H

#include <stdio.h>
#include "hilog_log_adapter.h"

namespace OHOS {
namespace DistributedHardware {

// 使用项目中定义的 DH_LOG_TAG
// 如果未定义，使用默认值
#ifndef DH_LOG_TAG
#define DH_LOG_TAG "DHFWK"
#endif

// 分布式硬件日志宏 - macOS 简化版本
// 移除了 OpenHarmony 特有的 %{public}s 格式说明符
#undef DHLOGD
#define DHLOGD(fmt, ...) HILOG_DEBUG(LOG_CORE, "[%s][%s]:" fmt, DH_LOG_TAG, __FUNCTION__, ##__VA_ARGS__)

#undef DHLOGI
#define DHLOGI(fmt, ...) HILOG_INFO(LOG_CORE, "[%s][%s]:" fmt, DH_LOG_TAG, __FUNCTION__, ##__VA_ARGS__)

#undef DHLOGW
#define DHLOGW(fmt, ...) HILOG_WARN(LOG_CORE, "[%s][%s]:" fmt, DH_LOG_TAG, __FUNCTION__, ##__VA_ARGS__)

#undef DHLOGE
#define DHLOGE(fmt, ...) HILOG_ERROR(LOG_CORE, "[%s][%s]:" fmt, DH_LOG_TAG, __FUNCTION__, ##__VA_ARGS__)

// 工具宏 - 参数检查
#define CHECK_NULL_RETURN(cond, ret, ...)       \
    do {                                        \
        if ((cond)) {                           \
            return (ret);                       \
        }                                       \
    } while (0)

#define CHECK_AND_RETURN_RET_LOG(cond, ret, fmt, ...)   \
    do {                                                \
        if ((cond)) {                                   \
            DHLOGE(fmt, ##__VA_ARGS__);                 \
            return (ret);                               \
        }                                               \
    } while (0)

#define CHECK_AND_RETURN_LOG(cond, fmt, ...)   \
    do {                                       \
        if ((cond)) {                          \
            DHLOGE(fmt, ##__VA_ARGS__);        \
            return;                            \
        }                                      \
    } while (0)

#define CHECK_AND_LOG(cond, fmt, ...)          \
    do {                                       \
        if ((cond)) {                          \
            DHLOGE(fmt, ##__VA_ARGS__);        \
        }                                      \
    } while (0)

// 暂时不支持 cJSON 相关的宏
#define CHECK_NULL_FREE_RETURN(ptr, ret, root, ...)    \
    do {                                               \
        if ((ptr) == nullptr) {                        \
            DHLOGE("Address pointer is null");         \
            return (ret);                              \
        }                                              \
    } while (0)

#define CHECK_AND_FREE_RETURN_RET_LOG(cond, ret, root, fmt, ...)    \
    do {                                                            \
        if ((cond)) {                                               \
            DHLOGE(fmt, ##__VA_ARGS__);                             \
            return (ret);                                           \
        }                                                           \
    } while (0)

} // namespace DistributedHardware
} // namespace OHOS

#endif // OHOS_DISTRIBUTED_HARDWARE_LOG_H
