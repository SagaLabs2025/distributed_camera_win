/*
 * Camera Metadata Compatibility Stub for macOS Mock
 *
 * OpenHarmony Camera::CameraMetadata 的 macOS 兼容层
 * 提供 Camera 命名空间和 CameraMetadata 类型的简化定义
 */

#ifndef STUBS_CAMERA_METADATA_COMPAT_H
#define STUBS_CAMERA_METADATA_COMPAT_H

#include <cstdint>
#include <memory>
#include <vector>

namespace OHOS {
namespace Camera {

/**
 * @brief 相机元数据类 - 简化的 Mock 实现
 * 
 * 这是一个简化的实现，用于在 macOS 上编译分布式相机代码。
 * 实际的 CameraMetadata 类在 OpenHarmony 的 multimedia_camera_framework 中定义。
 */
class CameraMetadata {
public:
    CameraMetadata() = default;
    
    /**
     * @brief 构造函数
     * @param entryCapacity 条目容量
     * @param dataCapacity 数据容量
     */
    CameraMetadata(uint32_t entryCapacity, uint32_t dataCapacity) {
        (void)entryCapacity;
        (void)dataCapacity;
    }
    
    virtual ~CameraMetadata() = default;
    
    /**
     * @brief 获取内部元数据头指针
     * @return 元数据头指针（Mock 实现返回 nullptr）
     */
    void* get() const {
        return nullptr;
    }
    
    /**
     * @brief 添加条目
     * @param tag 标签
     * @param data 数据指针
     * @param dataCount 数据数量
     * @return 成功返回 true
     */
    template<typename T>
    bool addEntry(uint32_t tag, const T* data, uint32_t dataCount) {
        (void)tag;
        (void)data;
        (void)dataCount;
        return true;  // Mock 实现总是返回成功
    }
    
    /**
     * @brief 查找元数据项索引（静态方法）
     * @param src 元数据头指针
     * @param tag 标签
     * @param index 输出索引
     * @param checkType 是否检查类型
     * @return 成功返回 0
     */
    static int FindCameraMetadataItemIndex(void* src, uint32_t tag, uint32_t* index, bool checkType = true) {
        (void)src;
        (void)tag;
        (void)checkType;
        if (index) {
            *index = 0;
        }
        return -1;  // Mock 实现返回未找到
    }
    
    /**
     * @brief 通过索引更新元数据项（静态方法）
     * @param src 元数据头指针
     * @param index 索引
     * @param data 数据指针
     * @param dataCount 数据数量
     * @param type 类型指针
     * @return 成功返回 0
     */
    template<typename T>
    static int UpdateCameraMetadataItemByIndex(void* src, uint32_t index, const T* data, 
                                                uint32_t dataCount, void* type) {
        (void)src;
        (void)index;
        (void)data;
        (void)dataCount;
        (void)type;
        return 0;  // Mock 实现总是返回成功
    }
    
    /**
     * @brief 添加元数据项（静态方法）
     * @param src 元数据头指针
     * @param tag 标签
     * @param data 数据指针
     * @param dataCount 数据数量
     * @return 成功返回 0
     */
    template<typename T>
    static int AddCameraMetadataItem(void* src, uint32_t tag, const T* data, uint32_t dataCount) {
        (void)src;
        (void)tag;
        (void)data;
        (void)dataCount;
        return 0;  // Mock 实现总是返回成功
    }
};

/**
 * @brief 元数据工具类
 */
class MetadataUtils {
public:
    /**
     * @brief 从字符串解码元数据
     * @param metadataStr 元数据字符串
     * @return 元数据对象指针
     */
    static std::shared_ptr<CameraMetadata> DecodeFromString(const std::string& metadataStr) {
        (void)metadataStr;
        return std::make_shared<CameraMetadata>();
    }
    
    /**
     * @brief 将元数据编码为字符串
     * @param metadata 元数据对象
     * @return 编码后的字符串
     */
    static std::string EncodeToString(const std::shared_ptr<CameraMetadata>& metadata) {
        (void)metadata;
        return "";
    }
};

} // namespace Camera
} // namespace OHOS

// 元数据返回码定义
#define CAM_META_SUCCESS 0
#define CAM_META_ITEM_NOT_FOUND -1
#define CAM_META_INVALID_PARAM -2

// 通用元数据头类型定义（简化版）
typedef struct common_metadata_header {
    uint32_t version;
    uint32_t size;
    uint32_t item_count;
    uint32_t item_capacity;
    uint32_t data_count;
    uint32_t data_capacity;
} common_metadata_header_t;

// 元数据项类型定义（简化版）
typedef struct camera_metadata_item {
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
} camera_metadata_item_t;

#endif // STUBS_CAMERA_METADATA_COMPAT_H
