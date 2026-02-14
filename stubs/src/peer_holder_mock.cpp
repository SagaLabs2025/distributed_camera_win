/*
 * PeerHolder Mock Implementation for macOS
 *
 * OpenHarmony PeerHolder 类的 macOS Mock 空实现
 */

#include "iremote_object.h"
#include "refbase.h"

namespace OHOS {

// PeerHolder 类的实现
class PeerHolder {
public:
    PeerHolder() = default;
    
    explicit PeerHolder(const sptr<IRemoteObject>& object);
    
    virtual ~PeerHolder() = default;
    
    // 获取远程对象
    sptr<IRemoteObject> Remote();

private:
    sptr<IRemoteObject> remote_;
};

// 导出符号的实现
PeerHolder::PeerHolder(const sptr<IRemoteObject>& object) : remote_(object)
{
    // Mock: 空实现
}

sptr<IRemoteObject> PeerHolder::Remote()
{
    return remote_;
}

} // namespace OHOS
