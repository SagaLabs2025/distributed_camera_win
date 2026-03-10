#ifndef HDF_BASE_H
#define HDF_BASE_H

#include <cstdint>

// HDF 基础定义 Mock

// HDF 错误码
#define HDF_SUCCESS 0
#define HDF_FAILURE (-1)
#define HDF_ERR_INVALID_PARAM (-2)
#define HDF_ERR_INVALID_OBJECT (-3)
#define HDF_ERR_MALLOC_FAIL (-4)
#define HDF_ERR_TIMEOUT (-5)
#define HDF_ERR_THREAD_CREATE_FAIL (-6)
#define HDF_ERR_QUEUE_FULL (-7)
#define HDF_ERR_DEVICE_BUSY (-8)
#define HDF_ERR_IO (-9)
#define HDF_ERR_BAD_FD (-10)

// HDF 设备类别
#define DEVICE_CLASS_DEFAULT 0
#define DEVICE_CLASS_CAMERA 1

// HDF 服务名称
#define HDF_DCAMERA_EXT_SERVICE "distributed_camera_service"

#endif // HDF_BASE_H
