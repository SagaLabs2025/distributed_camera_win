#ifndef ID_CAMERA_HDF_CALLBACK_H
#define ID_CAMERA_HDF_CALLBACK_H

#include <string>
#include <cstdint>
#include "refbase.h"
#include "dcamera_types.h"

namespace OHOS {
namespace HDI {
namespace DistributedCamera {
namespace V1_1 {

// HDF 回调接口 Mock
class IDCameraHdfCallback {
public:
    virtual ~IDCameraHdfCallback() = default;
    
    // 引用计数方法（用于 sptr 兼容性）
    virtual void IncStrongRef(const void* objectId) {
        (void)objectId;
    }
    
    virtual void DecStrongRef(const void* objectId) {
        (void)objectId;
    }
    
    // HDF 事件回调（匹配源码中的 override 签名）
    virtual int32_t NotifyEvent(int32_t devId, const DCameraHDFEvent& event)
    {
        (void)devId;
        (void)event;
        return 0; // 成功
    }
};

// 为了兼容性，添加别名
using FwkDCameraHdfCallback = IDCameraHdfCallback;

} // V1_1
} // DistributedCamera
} // HDI
} // OHOS

#endif // ID_CAMERA_HDF_CALLBACK_H
