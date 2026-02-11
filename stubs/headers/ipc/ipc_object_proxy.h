/*
 * IPCObjectProxy Stub for macOS Mock
 *
 * OpenHarmony IPC 对象代理的 macOS 兼容层
 */

#ifndef STUBS_IPC_OBJECT_PROXY_H
#define STUBS_IPC_OBJECT_PROXY_H

#include "iremote_object.h"
#include "iremote_broker.h"
#include "refbase.h"

#ifdef __cplusplus
namespace OHOS {

/**
 * @brief IPC 对象代理基类
 */
class IPCObjectProxy : public IRemoteObject, public virtual IRemoteBroker {
public:
    IPCObjectProxy() = default;
    virtual ~IPCObjectProxy() = default;

    /**
     * @brief 获取远程对象
     * @return 自身指针
     */
    sptr<IRemoteObject> AsObject()
    {
        return this;
    }

    /**
     * @brief 获取描述符
     * @return 描述符 UTF-16 字符串
     */
    std::u16string GetDescriptor() override
    {
        return u"IPCObjectProxy";
    }

    /**
     * @brief 获取对象引用
     * @return 引用计数
     */
    int32_t GetObjectReference() override
    {
        return 0;
    }
};

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IPC_OBJECT_PROXY_H
