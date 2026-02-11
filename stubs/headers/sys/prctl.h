/*
 * Linux prctl.h Stub for macOS
 *
 * Linux process control functions 的 macOS 兼容层
 */

#ifndef STUBS_SYS_PRCTL_H
#define STUBS_SYS_PRCTL_H

#include <stdint.h>
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

// Linux prctl 选项常量
#define PR_SET_NAME 15
#define PR_GET_NAME 16

/**
 * @brief 进程控制函数 (Mock 实现) - 接受 unsigned long 参数
 * @param option 选项类型
 * @param arg2 参数2
 * @param arg3 参数3
 * @param arg4 参数4
 * @param arg5 参数5
 * @return 成功返回 0，失败返回 -1
 */
static inline int prctl(int option, unsigned long arg2, unsigned long arg3,
                        unsigned long arg4, unsigned long arg5)
{
    (void)arg3; (void)arg4; (void)arg5;

    switch (option) {
        case PR_SET_NAME:
            // macOS: 使用 pthread_setname_np 代替
#if defined(__APPLE__) && defined(__MACH__)
            pthread_setname_np((char*)arg2);
#endif
            return 0;
        case PR_GET_NAME:
            // macOS: 使用 pthread_getname_np 代替 (需要3个参数)
#if defined(__APPLE__) && defined(__MACH__)
            pthread_getname_np(pthread_self(), (char*)arg2, 16);
#endif
            return 0;
        default:
            return 0;  // Mock: 其他选项返回成功
    }
}

/**
 * @brief 进程控制函数 (Mock 实现) - 接受 const char* 参数（用于设置线程名）
 * @param option 选项类型
 * @param arg2 参数2（字符串指针）
 * @return 成功返回 0，失败返回 -1
 */
static inline int prctl(int option, const char* arg2)
{
    (void)arg2;

    switch (option) {
        case PR_SET_NAME:
            // macOS: 使用 pthread_setname_np 代替
#if defined(__APPLE__) && defined(__MACH__)
            if (arg2 != nullptr) {
                pthread_setname_np((char*)arg2);
            }
#endif
            return 0;
        default:
            return 0;  // Mock: 其他选项返回成功
    }
}

#ifdef __cplusplus
}
#endif

#endif // STUBS_SYS_PRCTL_H

