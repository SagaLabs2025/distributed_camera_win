/*
 * cJSON Compatibility Stub for macOS
 *
 * 解决 cJSON_IsNumber 返回类型不匹配问题
 */

#ifndef STUBS_CJSON_COMPAT_H
#define STUBS_CJSON_COMPAT_H

// 引用 external 的 cJSON
#include "cJSON.h"

// 为了避免类型不匹配警告，显式转换 cJSON_bool 为 bool
#ifdef __cplusplus
inline bool IsCJSONNumber(const cJSON* item) {
    return static_cast<bool>(cJSON_IsNumber(item));
}
#endif

#endif // STUBS_CJSON_COMPAT_H
