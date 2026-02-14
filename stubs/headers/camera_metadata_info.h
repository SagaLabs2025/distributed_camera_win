/*
 * Camera Metadata Info Stub for macOS Mock
 *
 * OpenHarmony 相机元数据信息的 macOS 兼容层
 */

#ifndef STUBS_CAMERA_METADATA_INFO_H
#define STUBS_CAMERA_METADATA_INFO_H

#include <stdint.h>
#include <vector>
#include <memory>

// 包含 Camera::CameraMetadata 定义
#include "camera_metadata_compat.h"

#ifdef __cplusplus

namespace OHOS {
namespace CameraStandard {

/**
 * @brief 相机元数据项
 */
struct camera_metadata_item_t {
    uint32_t index;
    uint32_t item;
    uint32_t data_type;
    uint32_t count;
    union {
        uint8_t* u8;
        int32_t* i32;
        float* f;
        int64_t* i64;
        double* d;
        void* data_ptr;
    } data;
};

/**
 * @brief 相机元数据信息类
 */
class CameraMetadataInfo {
public:
    CameraMetadataInfo() = default;
    virtual ~CameraMetadataInfo() = default;

    /**
     * @brief 添加元数据项
     */
    virtual int32_t AddEntry(uint32_t tag, const void* data, size_t data_count)
    {
        (void)tag;
        (void)data;
        (void)data_count;
        return 0;  // Mock: 总是成功
    }

    /**
     * @brief 获取元数据项
     */
    virtual int32_t FindEntry(uint32_t tag, camera_metadata_item_t* item)
    {
        (void)tag;
        (void)item;
        return -1;  // Mock: 未找到
    }

    /**
     * @brief 更新元数据项
     */
    virtual int32_t UpdateEntry(uint32_t tag, const void* data, size_t data_count)
    {
        (void)tag;
        (void)data;
        (void)data_count;
        return 0;  // Mock: 总是成功
    }

    /**
     * @brief 删除元数据项
     */
    virtual int32_t DeleteEntry(uint32_t tag)
    {
        (void)tag;
        return 0;  // Mock: 总是成功
    }
};

} // namespace CameraStandard
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_CAMERA_METADATA_INFO_H
