/*
 * Camera Framework Types Stub for macOS Mock
 *
 * OpenHarmony Camera Framework 类型定义的 macOS 兼容层
 */

#ifndef STUBS_CAMERA_FRAMEWORK_TYPES_H
#define STUBS_CAMERA_FRAMEWORK_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

// Camera position enum
typedef enum {
    OHOS_CAMERA_POSITION_UNSPECIFIED = 0,
    OHOS_CAMERA_POSITION_BACK = 1,
    OHOS_CAMERA_POSITION_FRONT = 2,
    OHOS_CAMERA_POSITION_OTHER = 3,
} camera_position_enum_t;

// Camera type enum
typedef enum {
    OHOS_CAMERA_TYPE_DEFAULT = 0,
    OHOS_CAMERA_TYPE_WIDE_ANGLE = 1,
    OHOS_CAMERA_TYPE_ULTRA_WIDE = 2,
    OHOS_CAMERA_TYPE_TELEPHOTO = 3,
    OHOS_CAMERA_TYPE_TRUE_DEPTH = 4,
    OHOS_CAMERA_TYPE_UNSPECIFIED = 5,
} camera_type_enum_t;

// Camera connection type
typedef enum {
    OHOS_CAMERA_CONNECTION_TYPE_BUILTIN = 0,
    OHOS_CAMERA_CONNECTION_TYPE_USB_PLUGIN = 1,
    OHOS_CAMERA_CONNECTION_TYPE_REMOTE = 2,
} camera_connection_type_t;

// Camera fold screen enum
typedef enum {
    OHOS_CAMERA_FOLDSCREEN_NONFOLDABLE = 0,
    OHOS_CAMERA_FOLDSCREEN_INNER = 1,
    OHOS_CAMERA_FOLDSCREEN_OUTER = 2,
    OHOS_CAMERA_FOLDSCREEN_OTHER = 3,
} camera_foldscreen_enum_t;

#ifdef __cplusplus
}
#endif

#endif // STUBS_CAMERA_FRAMEWORK_TYPES_H
