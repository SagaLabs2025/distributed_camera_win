/*
 * Linux Ashmem Stub for macOS
 *
 * Android/Linux 共享内存的 macOS 兼容层
 */

#ifndef STUBS_LINUX_ASHMEM_H
#define STUBS_LINUX_ASHMEM_H

#ifdef __cplusplus
extern "C" {
#endif

// Ashmem 文件描述符类型
typedef int ashmem_data_t;

// 创建共享内存区域
static inline int ashmem_create_region(const char* name, size_t size)
{
    (void)name;
    (void)size;
    return -1;  // Mock: 返回失败，需要时可以扩展
}

// 设置共享内存保护
static inline int ashmem_set_prot_region(int fd, int prot)
{
    (void)fd;
    (void)prot;
    return 0;  // Mock: 返回成功
}

// 锁定共享内存
static inline void* ashmem_mmap(int fd, size_t size)
{
    (void)fd;
    (void)size;
    return NULL;  // Mock: 返回 NULL
}

// 解锁共享内存
static inline int ashmem_munmap(void* addr, size_t size)
{
    (void)addr;
    (void)size;
    return 0;  // Mock: 返回成功
}

// 关闭共享内存
static inline int ashmem_close(int fd)
{
    (void)fd;
    return 0;  // Mock: 返回成功
}

// �行共享内存的 pin 操作
static inline int ashmem_pin(int fd, size_t size)
{
    (void)fd;
    (void)size;
    return 0;  // Mock: 返回成功
}

// 取消 pin 操作
static inline int ashmem_unpin(int fd, size_t size)
{
    (void)fd;
    (void)size;
    return 0;  // Mock: 返回成功
}

// 获取共享内存区域大小
static inline int ashmem_get_size_region(int fd)
{
    (void)fd;
    return 0;  // Mock: 返回 0
}

#ifdef __cplusplus
}
#endif

#endif // STUBS_LINUX_ASHMEM_H
