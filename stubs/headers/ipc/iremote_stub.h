/*
 * IRemoteStub Stub for macOS Mock
 *
 * OpenHarmony IPC 远程服务存根接口的 macOS 兼容层
 */

#ifndef STUBS_IREMOTE_STUB_H
#define STUBS_IREMOTE_STUB_H

#include "iremote_object.h"
#include "iremote_broker.h"

#ifdef __cplusplus
namespace OHOS {

/**
 * @brief 远程服务存根接口
 * 模板类，T 是服务接口类
 * IRemoteStub 继承自 IRemoteObject 和 T，这样存根类就可以访问接口的所有方法
 * IRemoteObject 已经继承自 IRemoteBroker，所以不需要再次继承
 */
template<typename T>
class IRemoteStub : public IRemoteObject, public virtual T {
public:
    // 构造函数 - 接受 bool 参数（isDefault）
    explicit IRemoteStub(bool isDefault = false)
    {
        (void)isDefault;  // Mock: 忽略此参数
    }

    virtual ~IRemoteStub() = default;

    /**
     * @brief 获取远程请求处理对象
     * @return 远程对象指针
     */
    virtual T* GetRemoteObject()
    {
        return nullptr;  // Mock: 返回空指针
    }

    /**
     * @brief 获取接口描述符
     * @return 描述符 UTF-16 字符串
     */
    std::u16string GetDescriptor() override
    {
        return u"IRemoteStub";
    }

    /**
     * @brief 获取对象引用
     * @return 对象引用
     */
    int32_t GetObjectReference() override
    {
        return 0;
    }
};

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IREMOTE_STUB_H
