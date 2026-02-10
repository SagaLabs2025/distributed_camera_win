/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
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

#ifndef OHOS_DCAMERA_LOG_H
#define OHOS_DCAMERA_LOG_H

#include <cstdio>

namespace OHOS {
namespace DistributedHardware {

typedef enum {
    DH_LOG_DEBUG,
    DH_LOG_INFO,
    DH_LOG_WARN,
    DH_LOG_ERROR,
} DHLogLevel;

// DHLogManager 类 - macOS Mock
class DHLogManager {
public:
    static void Log(DHLogLevel logLevel, const char *fmt, ...) {
        (void)logLevel;
        va_list args;
        va_start(args, fmt);
        vprintf(fmt, args);
        printf("\n");
        va_end(args);
    }
};

// 日志函数
inline void DHLog(DHLogLevel logLevel, const char *fmt, ...) {
    (void)logLevel;
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    printf("\n");
    va_end(args);
}

// 日志宏
#define DHLOGD(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#define DHLOGI(fmt, ...) printf("[INFO] " fmt "\n", ##__VA_ARGS__)
#define DHLOGW(fmt, ...) printf("[WARN] " fmt "\n", ##__VA_ARGS__)
#define DHLOGE(fmt, ...) printf("[ERROR] " fmt "\n", ##__VA_ARGS__)

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

} // namespace DistributedHardware
} // namespace OHOS

#endif // OHOS_DCAMERA_LOG_H
