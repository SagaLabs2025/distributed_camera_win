/*
 * RefBase Stub for macOS Mock
 *
 * OpenHarmony 引用计数基类的 macOS 兼容层
 *
 * 重要原则：重定向到 sptr stub，不重复定义
 */

#ifndef STUBS_REFBASE_H
#define STUBS_REFBASE_H

// 重定向到 sptr stub 实现
#include "ipc/sptr.h"

// 确保使用 stub 的 sptr 而不是外部的 refbase.h
// 这确保了 sptr 到 std::shared_ptr 的转换能力

#endif // STUBS_REFBASE_H
