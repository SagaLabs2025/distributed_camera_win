/*
 * AVSharedMemory Stub for macOS Mock
 *
 * OpenHarmony 音视频共享内存的 macOS 兼容层
 */

#ifndef STUBS_BUFFER_AVSHAREDMEMORY_H
#define STUBS_BUFFER_AVSHAREDMEMORY_H

#include <cstdint>
#include <memory>
#include <string>

#ifdef __cplusplus
namespace OHOS {
namespace Media {

// 前向声明
class AVSharedMemory;

/**
 * @brief 共享内存创建选项
 */
struct AVSharedMemoryConfig {
    int32_t size = 0;
    int32_t flags = 0;
    std::string name;
};

/**
 * @brief 共享内存类
 */
class AVSharedMemory {
public:
    /**
     * @brief 创建共享内存
     * @param config 共享内存配置
     * @return 共享内存对象指针
     */
    static std::shared_ptr<AVSharedMemory> Create(const AVSharedMemoryConfig& config)
    {
        (void)config;  // Mock: 返回空指针
        return nullptr;
    }

    /**
     * @brief 从已有文件描述符创建共享内存
     * @param fd 文件描述符
     * @param size 大小
     * @return 共享内存对象指针
     */
    static std::shared_ptr<AVSharedMemory> CreateFromRemote(int32_t fd, int32_t size)
    {
        (void)fd; (void)size;  // Mock: 返回空指针
        return nullptr;
    }

    AVSharedMemory() = default;
    virtual ~AVSharedMemory() = default;

    /**
     * @brief 获取内存基地址
     * @return 内存指针
     */
    void* GetBase()
    {
        return nullptr;  // Mock: 返回空指针
    }

    /**
     * @brief 获取内存大小
     * @return 大小
     */
    int32_t GetSize()
    {
        return 0;  // Mock: 返回 0
    }

    /**
     * @brief 获取文件描述符
     * @return 文件描述符
     */
    int32_t GetFd()
    {
        return -1;  // Mock: 返回无效文件描述符
    }
};

} // namespace Media
} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_BUFFER_AVSHAREDMEMORY_H
