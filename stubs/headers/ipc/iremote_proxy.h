/*
 * IRemoteProxy Stub for macOS Mock
 *
 * OpenHarmony IPC 远程代理基类的 macOS 兼容层
 */

#ifndef STUBS_IREMOTE_PROXY_H
#define STUBS_IREMOTE_PROXY_H

#include "iremote_broker.h"
#include "iremote_object.h"
#include "refbase.h"

#ifdef __cplusplus
namespace OHOS {

/**
 * @brief 远程代理基类模板
 * T 是服务接口类
 */
template<typename T>
class IRemoteProxy : public IRemoteObject, public T {
public:
    explicit IRemoteProxy(const sptr<IRemoteObject>& object)
        : remoteObject_(object)
    {
    }

    virtual ~IRemoteProxy() = default;

    /**
     * @brief 获取远程对象
     * @return 远程对象智能指针
     */
    sptr<IRemoteObject> AsObject()
    {
        return remoteObject_;
    }

    /**
     * @brief 获取远程对象（Remote() 方法兼容）
     * @return 远程对象智能指针
     */
    sptr<IRemoteObject> Remote()
    {
        return remoteObject_;
    }

    /**
     * @brief 获取接口描述符
     * @return 描述符 UTF-16 字符串
     */
    std::u16string GetDescriptor() override
    {
        return u"IRemoteProxy";
    }

    /**
     * @brief 获取对象引用
     * @return 对象引用
     */
    int32_t GetObjectReference() override
    {
        return 0;
    }

protected:
    sptr<IRemoteObject> remoteObject_;
};

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IREMOTE_PROXY_H
