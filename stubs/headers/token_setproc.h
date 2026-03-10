/*
 * token_setproc.h stub for macOS
 *
 * Provides minimal process token APIs used by OpenHarmony components.
 */

#ifndef STUBS_TOKEN_SETPROC_H
#define STUBS_TOKEN_SETPROC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint64_t GetSelfTokenID(void);
int SetSelfTokenID(uint64_t tokenID);
uint64_t GetFirstCallerTokenID(void);
int SetFirstCallerTokenID(uint64_t tokenID);

#ifdef __cplusplus
}
#endif

#endif // STUBS_TOKEN_SETPROC_H

