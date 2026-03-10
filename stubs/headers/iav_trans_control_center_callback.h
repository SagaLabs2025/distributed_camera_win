/*
 * iav_trans_control_center_callback.h Compatibility Stub
 *
 * 这是一个兼容性头文件，用于解决 external 代码仓中的文件命名和依赖问题
 * 
 * 问题：
 * 1. idistributed_hardware.h 引用 "iav_trans_control_center_callback.h"
 *    但实际文件名是 "av_trans_control_center_callback.h"（没有前缀 i）
 * 2. av_trans_control_center_callback.h 有复杂的依赖链，在 macOS 测试环境中不需要
 *
 * 解决方案：提供最小化的接口定义，满足编译需求
 */

#ifndef STUBS_IAV_TRANS_CONTROL_CENTER_CALLBACK_H
#define STUBS_IAV_TRANS_CONTROL_CENTER_CALLBACK_H

#include <memory>
#include <string>
#include "iremote_broker.h"
#include "av_trans_types.h"

namespace OHOS {
namespace DistributedHardware {

/**
 * @brief AV传输控制中心回调接口（最小化定义）
 */
class IAVTransControlCenterCallback : public IRemoteBroker {
public:
    DECLARE_INTERFACE_DESCRIPTOR(u"ohos.distributedHardware.IAVTransControlCenterCallback");

    virtual ~IAVTransControlCenterCallback() = default;

    // 最小化接口定义（Mock环境不需要实际实现）
    virtual int32_t OnAVTransEvent(const AVTransEvent& event) = 0;
};

// 类型别名：兼容不同的命名约定
using IAvTransControlCenterCallback = IAVTransControlCenterCallback;

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_IAV_TRANS_CONTROL_CENTER_CALLBACK_H
