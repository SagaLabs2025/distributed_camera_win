/*
 * DCameraTypes HDF Stub for macOS Mock
 *
 * OpenHarmony 分布式相机 HDF 类型定义的 macOS 兼容层
 */

#ifndef STUBS_V1_1_DCAMERA_TYPES_H
#define STUBS_V1_1_DCAMERA_TYPES_H

#include <string>
#include <vector>
#include <cstdint>

#ifdef __cplusplus
namespace OHOS {
namespace HDI {
namespace DistributedCamera {
namespace V1_1 {

// 枚举类型定义

/**
 * @brief 分布式相机元数据更新类型
 */
enum DCSettingsType {
    UPDATE_METADATA = 0,        // 设置完整元数据
    ENABLE_METADATA = 1,        // 启用元数据配置
    DISABLE_METADATA = 2,       // 禁用元数据配置
    METADATA_RESULT = 3,        // 返回元数据结果
    SET_FLASH_LIGHT = 4,        // 设置闪光灯
    FPS_RANGE = 5,              // 设置帧率范围
    UPDATE_FRAME_METADATA = 6,  // 设置帧元数据
};

/**
 * @brief HDI 接口返回值枚举
 */
enum DCamRetCode {
    SUCCESS = 0,               // 成功
    CAMERA_BUSY = 1,           // 相机忙
    INVALID_ARGUMENT = 2,      // 无效参数
    METHOD_NOT_SUPPORTED = 3,  // 不支持的方法
    CAMERA_OFFLINE = 4,        // 相机离线
    EXCEED_MAX_NUMBER = 5,     // 超过最大设备数
    DEVICE_NOT_INIT = 6,       // 设备未初始化
    FAILED = 7,                // 失败
};

/**
 * @brief 流数据编码类型枚举
 */
enum DCEncodeType {
    ENCODE_TYPE_NULL = 0,    // 未指定编码
    ENCODE_TYPE_H264 = 1,    // H.264 编码
    ENCODE_TYPE_H265 = 2,    // H.265 编码
    ENCODE_TYPE_JPEG = 3,    // JPEG 编码
    ENCODE_TYPE_MPEG4_ES = 4,// MPEG4-ES 编码
};

/**
 * @brief 分布式相机内部流类型枚举
 */
enum DCStreamType {
    CONTINUOUS_FRAME = 0,    // 连续捕获流（预览流、视频流）
    SNAPSHOT_FRAME = 1,      // 单次捕获流（拍照流）
};

// 前向声明
struct NativeBuffer;

/**
 * @brief 分布式硬件设备基础信息
 */
struct DHBase {
    std::string deviceId_;  // 设备 ID (networkId)
    std::string dhId_;      // 分布式硬件 ID
};

/**
 * @brief 分布式相机设备的控制设置
 */
struct DCameraSettings {
    int32_t type_;       // 设置类型 (DCSettingsType)
    std::string value_;  // 设置值（序列化的 bool、array、struct 等）
};

/**
 * @brief 分布式相机内部流信息
 * 用于在流创建时传递配置参数
 */
struct DCStreamInfo {
    int32_t streamId_;       // 流 ID，唯一标识相机设备上的一个流
    int32_t width_;          // 图像宽度
    int32_t height_;         // 图像高度
    int32_t stride_;         // 图像步长
    int32_t format_;         // 图像格式
    int32_t dataspace_;      // 图像色彩空间
    DCEncodeType encodeType_;     // 编码类型 (DCEncodeType)
    DCStreamType type_;           // 流类型 (DCStreamType)
    int32_t mode_;           // 当前场景模式
};

/**
 * @brief 分布式相机内部捕获请求信息
 */
struct DCCaptureInfo {
    std::vector<int32_t> streamIds_;          // 捕获的流 ID 列表
    int32_t width_;                           // 图像宽度
    int32_t height_;                          // 图像高度
    int32_t stride_;                          // 图像步长
    int32_t format_;                          // 图像格式
    int32_t dataspace_;                       // 图像色彩空间
    bool isCapture_;                          // 是否触发 sink 捕获
    DCEncodeType encodeType_;                 // 编码类型 (DCEncodeType)
    DCStreamType type_;                        // 流类型 (DCStreamType)
    std::vector<DCameraSettings> captureSettings_;  // 流设置
};

/**
 * @brief 本地缓冲区句柄（简化版本）
 */
struct NativeBuffer {
    void* handle_;    // 缓冲区句柄
    uint32_t size_;   // 缓冲区大小
};

/**
 * @brief 分布式相机内部缓冲区
 * 用于在处理捕获请求时获取缓冲区
 */
struct DCameraBuffer {
    int index_;                          // 缓冲区索引
    uint32_t size_;                      // 缓冲区大小
    NativeBuffer bufferHandle_;          // 本地缓冲区句柄
};

/**
 * @brief 分布式相机通知事件
 */
struct DCameraHDFEvent {
    int type_;          // 事件类型
    int result_;        // 事件结果
    std::string content_; // 扩展内容（可选）
};

} // namespace V1_1
} // namespace DistributedCamera
} // namespace HDI
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_V1_1_DCAMERA_TYPES_H
