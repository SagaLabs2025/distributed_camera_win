/*
 * WeakRefCounter Mock Implementation for macOS
 *
 * OpenHarmony WeakRefCounter 的 macOS Mock 空实现
 */

#include "refbase.h"

namespace OHOS {

bool WeakRefCounter::AttemptIncStrongRef(const void* objectId)
{
    (void)objectId;
    return true;  // Mock: 总是成功
}

void* WeakRefCounter::GetRefPtr()
{
    return nullptr;  // Mock: 返回空指针
}

} // namespace OHOS
