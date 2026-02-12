/*
 * Parameter Access Stub for macOS Mock
 *
 * OpenHarmony 参数访问接口的 macOS 兼容层
 */

#ifndef STUBS_PARAMETER_H
#define STUBS_PARAMETER_H

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

int GetParameter(const char *key, const char *def, char *value, uint32_t len);
int SetParameter(const char *key, const char *value);

#ifdef __cplusplus
}
#endif

#endif // STUBS_PARAMETER_H
