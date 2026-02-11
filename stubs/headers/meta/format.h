/*
 * Meta Format Stub for macOS Mock
 *
 * OpenHarmony 媒体格式定义的 macOS 兼容层
 */

#ifndef STUBS_META_FORMAT_H
#define STUBS_META_FORMAT_H

#include <cstdint>
#include <string>

#ifdef __cplusplus
namespace OHOS {
namespace Media {

/**
 * @brief 媒体格式枚举
 */
enum class MediaType : int32_t {
    MEDIA_TYPE_INVALID = -1,
    MEDIA_TYPE_AUD = 0,
    MEDIA_TYPE_VID,
    MEDIA_TYPE_SUBTITLE,
};

/**
 * @brief 视频格式枚举
 */
enum class VideoFormat : int32_t {
    VIDEO_INVALID_FORMAT = -1,
    VIDEO_H264 = 0,
    VIDEO_H265 = 1,
    VIDEO_MPEG4 = 2,
    VIDEO_VP8 = 3,
    VIDEO_VP9 = 4,
};

/**
 * @brief 音频格式枚举
 */
enum class AudioFormat : int32_t {
    AUDIO_INVALID_FORMAT = -1,
    AUDIO_PCM = 0,
    AUDIO_AAC = 1,
    AUDIO_MP3 = 2,
    AUDIO_FLAC = 3,
    AUDIO_OPUS = 4,
};

/**
 * @brief 像素格式枚举
 */
enum class PixelFormat : int32_t {
    PIXEL_FORMAT_INVALID = -1,
    PIXEL_FORMAT_RGBA_8888 = 0,
    PIXEL_FORMAT_RGB_565 = 1,
    PIXEL_FORMAT_RGB_888 = 2,
    PIXEL_FORMAT_YCBCR_420_888 = 3,
    PIXEL_FORMAT_YCRCB_420_SP = 4,
    PIXEL_FORMAT_YCBCR_422_SP = 5,
    PIXEL_FORMAT_JPEG = 6,
};

/**
 * @brief 媒体格式信息结构
 */
struct Format {
    MediaType mediaType = MediaType::MEDIA_TYPE_INVALID;
    int32_t width = 0;
    int32_t height = 0;
    int32_t frameRate = 0;
    int32_t bitrate = 0;
    PixelFormat pixelFormat = PixelFormat::PIXEL_FORMAT_INVALID;
    AudioFormat audioFormat = AudioFormat::AUDIO_INVALID_FORMAT;
    VideoFormat videoFormat = VideoFormat::VIDEO_INVALID_FORMAT;

    // Mock 方法
    void SetInt32(const std::string& key, int32_t value)
    {
        (void)key; (void)value;  // Mock: 空实现
    }

    int32_t GetInt32(const std::string& key) const
    {
        (void)key;  // Mock: 返回默认值
        return 0;
    }

    void SetString(const std::string& key, const std::string& value)
    {
        (void)key; (void)value;  // Mock: 空实现
    }

    std::string GetString(const std::string& key) const
    {
        (void)key;  // Mock: 返回空字符串
        return "";
    }
};

} // namespace Media
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_META_FORMAT_H
