#ifndef STUBS_IPC_TYPES_H
#define STUBS_IPC_TYPES_H

#include <cstdint>

namespace OHOS {

// Minimal IPC error codes for local (in-process) mock.
// Keep values stable within this test project; real OpenHarmony values are not required here.
constexpr int32_t ERR_NONE = 0;
constexpr int32_t ERR_OK = 0;
constexpr int32_t ERR_INVALID_DATA = -1;
constexpr int32_t ERR_INVALID_VALUE = -2;
constexpr int32_t ERR_PERMISSION_DENIED = -3;
constexpr int32_t ERR_DEAD_OBJECT = -4;

} // namespace OHOS

#endif // STUBS_IPC_TYPES_H

