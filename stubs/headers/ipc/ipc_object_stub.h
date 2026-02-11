/*
 * IPCObjectStub Stub for macOS Mock
 *
 * OpenHarmony IPC 对象存根基类的 macOS 兼容层
 */

#ifndef STUBS_IPC_OBJECT_STUB_H
#define STUBS_IPC_OBJECT_STUB_H

#include "iremote_stub.h"
#include "message_parcel.h"
#include "message_option.h"

#ifdef __cplusplus
namespace OHOS {

/**
 * @brief IPC 对象存根基类
 * 提供通用的 OnRemoteRequest 实现
 */
class IPCObjectStub {
public:
    IPCObjectStub() = default;
    virtual ~IPCObjectStub() = default;

    /**
     * @brief 默认的远程请求处理
     * @param code 请求码
     * @param data 输入数据
     * @param reply 输出数据
     * @param option 选项
     * @return 错误码
     */
    virtual int32_t OnRemoteRequest(uint32_t code, MessageParcel& data,
                                    MessageParcel& reply, MessageOption& option)
    {
        (void)code; (void)data; (void)reply; (void)option;
        return -1;  // Mock: 返回错误
    }
};

} // namespace OHOS

#endif // __cplusplus

#endif // STUBS_IPC_OBJECT_STUB_H
