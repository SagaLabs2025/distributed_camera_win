/*
 * PeerHolder Stub for macOS Mock
 *
 * OpenHarmony IPC 对象持有者的 macOS 兼容层
 */

#ifndef STUBS_PEER_HOLDER_H
#define STUBS_PEER_HOLDER_H

#include "iremote_object.h"
#include "refbase.h"

#ifdef __cplusplus
namespace OHOS {

/**
 * @brief 对象持有者模板
 * 用于管理远程对象的生命周期
 */
template<typename T>
class PeerHolder {
public:
    PeerHolder() = default;
    ~PeerHolder() = default;

    /**
     * @brief 设置远程对象
     * @param object 远程对象指针
     */
    void Set(sptr<IRemoteObject> object)
    {
        object_ = object;
    }

    /**
     * @brief 获取远程对象
     * @return 远程对象指针
     */
    sptr<IRemoteObject> Get()
    {
        return object_;
    }

    /**
     * @brief 检查是否有对象
     * @return true/false
     */
    bool Has()
    {
        return object_ != nullptr;
    }

private:
    sptr<IRemoteObject> object_;
};

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_PEER_HOLDER_H
