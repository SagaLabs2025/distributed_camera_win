/*
 * IRemoteBroker Stub for macOS Mock
 *
 * OpenHarmony IPC 远程对象代理接口的 macOS 兼容层
 */

#ifndef STUBS_IREMOTE_BROKER_H
#define STUBS_IREMOTE_BROKER_H

#include <string>

#ifdef __cplusplus
namespace OHOS {

// 前向声明
template<typename T> class sptr;
class IRemoteObject;

/**
 * @brief 远程对象代理接口
 * 所有 IPC 服务的基类
 * 添加引用计数方法以支持 sptr 智能指针
 */
class IRemoteBroker {
public:
    virtual ~IRemoteBroker() = default;

    /**
     * @brief 获取接口描述符
     * @return 接口描述符 UTF-16 字符串
     */
    virtual std::u16string GetDescriptor()
    {
        return u"IRemoteBroker";
    }

    /**
     * @brief 获取对象描述符
     * @return 对象描述符
     */
    virtual int32_t GetObjectReference()
    {
        return 0;
    }

    /**
     * @brief 增加强引用计数（sptr 兼容）
     * @param objectId 对象 ID
     */
    virtual void IncStrongRef(const void* objectId)
    {
        (void)objectId;
    }

    /**
     * @brief 减少强引用计数（sptr 兼容）
     * @param objectId 对象 ID
     */
    virtual void DecStrongRef(const void* objectId)
    {
        (void)objectId;
    }

    /**
     * @brief 获取 IRemoteObject 指针
     * @return IRemoteObject 原始指针（Mock 实现）
     */
    virtual IRemoteObject* AsObject()
    {
        return nullptr;  // Mock: 返回空指针
    }

    /**
     * @brief 获取常量 IRemoteObject 指针
     * @return 常量 IRemoteObject 原始指针（Mock 实现）
     */
    virtual const IRemoteObject* AsObject() const
    {
        return nullptr;  // Mock: 返回空指针
    }
};

/**
 * @brief iface_cast 模板函数（Mock 实现）
 * 将 IRemoteObject 转换为指定接口类型
 */
template <typename INTERFACE>
inline sptr<INTERFACE> iface_cast(const sptr<IRemoteObject>& object)
{
    (void)object;
    // Mock: 直接返回空指针，不进行实际转换
    return nullptr;
}

/**
 * @brief iface_cast 模板函数重载（原始指针版本）
 */
template <typename INTERFACE>
inline INTERFACE* iface_cast(IRemoteObject* object)
{
    (void)object;
    // Mock: 直接返回空指针，不进行实际转换
    return nullptr;
}

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IREMOTE_BROKER_H
