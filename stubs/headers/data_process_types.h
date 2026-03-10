/*
 * Data Process Types Stub for macOS Mock
 *
 * OpenHarmony 数据处理类型定义的 macOS 兼容层
 */

#ifndef STUBS_DATA_PROCESS_TYPES_H
#define STUBS_DATA_PROCESS_TYPES_H

#include <cstdint>

#ifdef __cplusplus
namespace OHOS {
namespace DistributedHardware {

enum DataProcessErrorType {
    DATA_PROCESS_OK = 0,
    DATA_PROCESS_ERROR_IPC_FAILED = 1,
    DATA_PROCESS_ERROR_DATA_EMPTY = 2,
};

enum VideoCodecType {
    VIDEO_CODEC_TYPE_H264 = 0,
    VIDEO_CODEC_TYPE_H265 = 1,
    VIDEO_CODEC_TYPE_JPEG = 2,
};

enum VideoFormat {
    VIDEO_DATA_TYPE_YUV420 = 0,
    VIDEO_DATA_TYPE_YUV422 = 1,
};

} // namespace DistributedHardware
} // namespace OHOS
#endif

#endif // STUBS_DATA_PROCESS_TYPES_H
