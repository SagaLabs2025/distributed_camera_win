/*
 * Callback Object Passing Test
 *
 * 测试回调对象在 SDK 和 Service 之间的传递机制
 * 
 * 测试内容：
 * 1. MessageParcel WriteRemoteObject/ReadRemoteObject 功能
 * 2. 回调对象从 SDK 传递到 Service
 * 3. Service 调用回调对象的方法
 * 4. 空回调对象的处理
 * 5. 回调对象的生命周期管理
 */

#include <iostream>
#include <string>
#include <cassert>
#include "message_parcel.h"
#include "iremote_object.h"
#include "iremote_stub.h"
#include "distributed_hardware_log.h"

using namespace OHOS;

// ============================================================================
// 测试用回调接口定义
// ============================================================================

/**
 * @brief 测试回调接口
 * 
 * 模拟 SDK 的回调接口，用于接收 Service 的通知
 */
class ITestCallback : public IRemoteBroker {
public:
    DECLARE_INTERFACE_DESCRIPTOR(u"ohos.test.ITestCallback");
    
    /**
     * @brief 事件通知回调
     * @param event 事件名称
     * @param data 事件数据
     */
    virtual void OnEvent(const std::string& event, const std::string& data) = 0;
    
    /**
     * @brief 错误通知回调
     * @param errorCode 错误码
     * @param errorMsg 错误消息
     */
    virtual void OnError(int32_t errorCode, const std::string& errorMsg) = 0;
};

/**
 * @brief 测试回调 Stub 实现
 * 
 * 实现回调接口的 Stub 端，用于接收 Service 的调用
 */
class TestCallbackStub : public IRemoteStub<ITestCallback> {
public:
    TestCallbackStub() : eventCalled_(false), errorCalled_(false), eventCount_(0) {}
    
    void OnEvent(const std::string& event, const std::string& data) override {
        std::cout << "[TestCallback] OnEvent called: event=" << event 
                  << ", data=" << data << std::endl;
        eventCalled_ = true;
        lastEvent_ = event;
        lastData_ = data;
        eventCount_++;
    }
    
    void OnError(int32_t errorCode, const std::string& errorMsg) override {
        std::cout << "[TestCallback] OnError called: code=" << errorCode 
                  << ", msg=" << errorMsg << std::endl;
        errorCalled_ = true;
        lastErrorCode_ = errorCode;
        lastErrorMsg_ = errorMsg;
    }
    
    // 测试辅助方法
    bool IsEventCalled() const { return eventCalled_; }
    bool IsErrorCalled() const { return errorCalled_; }
    int GetEventCount() const { return eventCount_; }
    std::string GetLastEvent() const { return lastEvent_; }
    std::string GetLastData() const { return lastData_; }
    int32_t GetLastErrorCode() const { return lastErrorCode_; }
    std::string GetLastErrorMsg() const { return lastErrorMsg_; }
    
    void Reset() {
        eventCalled_ = false;
        errorCalled_ = false;
        eventCount_ = 0;
        lastEvent_.clear();
        lastData_.clear();
        lastErrorCode_ = 0;
        lastErrorMsg_.clear();
    }
    
private:
    bool eventCalled_;
    bool errorCalled_;
    int eventCount_;
    std::string lastEvent_;
    std::string lastData_;
    int32_t lastErrorCode_;
    std::string lastErrorMsg_;
};

// ============================================================================
// 测试用 Service 实现
// ============================================================================

/**
 * @brief 测试 Service 类
 * 
 * 模拟 Service 端，接收回调对象并调用回调方法
 */
class TestService {
public:
    TestService() : callback_(nullptr) {}
    
    /**
     * @brief 注册回调对象
     * @param callback 回调对象
     * @return 0 成功，-1 失败
     */
    int32_t RegisterCallback(const sptr<ITestCallback>& callback) {
        if (callback == nullptr) {
            std::cerr << "[TestService] RegisterCallback: callback is null" << std::endl;
            return -1;
        }
        
        callback_ = callback;
        std::cout << "[TestService] Callback registered successfully" << std::endl;
        return 0;
    }
    
    /**
     * @brief 触发事件回调
     * @param event 事件名称
     * @param data 事件数据
     * @return 0 成功，-1 失败
     */
    int32_t TriggerEvent(const std::string& event, const std::string& data) {
        if (callback_ == nullptr) {
            std::cerr << "[TestService] TriggerEvent: callback is null" << std::endl;
            return -1;
        }
        
        std::cout << "[TestService] Triggering event: " << event << std::endl;
        callback_->OnEvent(event, data);
        return 0;
    }
    
    /**
     * @brief 触发错误回调
     * @param errorCode 错误码
     * @param errorMsg 错误消息
     * @return 0 成功，-1 失败
     */
    int32_t TriggerError(int32_t errorCode, const std::string& errorMsg) {
        if (callback_ == nullptr) {
            std::cerr << "[TestService] TriggerError: callback is null" << std::endl;
            return -1;
        }
        
        std::cout << "[TestService] Triggering error: " << errorCode << std::endl;
        callback_->OnError(errorCode, errorMsg);
        return 0;
    }
    
    /**
     * @brief 检查回调是否已注册
     * @return true 已注册，false 未注册
     */
    bool HasCallback() const {
        return callback_ != nullptr;
    }
    
    /**
     * @brief 注销回调对象
     */
    void UnregisterCallback() {
        callback_ = nullptr;
        std::cout << "[TestService] Callback unregistered" << std::endl;
    }
    
private:
    sptr<ITestCallback> callback_;
};

// ============================================================================
// 测试用例
// ============================================================================

/**
 * @brief 测试1：MessageParcel 写入和读取 RemoteObject
 */
void Test1_MessageParcelWriteReadRemoteObject() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Test 1: MessageParcel WriteRemoteObject/ReadRemoteObject" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // 创建回调对象
    sptr<TestCallbackStub> callback = new TestCallbackStub();
    assert(callback != nullptr);
    std::cout << "[Test1] Callback object created" << std::endl;
    
    // 写入 MessageParcel
    MessageParcel data;
    bool writeResult = data.WriteRemoteObject(callback->AsObject());
    assert(writeResult == true);
    std::cout << "[Test1] WriteRemoteObject succeeded" << std::endl;
    
    // 从 MessageParcel 读取
    sptr<IRemoteObject> readObj = data.ReadRemoteObject();
    assert(readObj != nullptr);
    std::cout << "[Test1] ReadRemoteObject succeeded" << std::endl;
    
    // 验证读取的对象是同一个对象
    assert(readObj.GetRefPtr() == callback->AsObject().GetRefPtr());
    std::cout << "[Test1] Object identity verified (same pointer)" << std::endl;
    
    std::cout << "[Test1] ✓ PASSED" << std::endl;
}

/**
 * @brief 测试2：空对象的写入和读取
 */
void Test2_NullObjectHandling() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Test 2: Null Object Handling" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // 写入空对象
    MessageParcel data;
    sptr<IRemoteObject> nullObj = nullptr;
    bool writeResult = data.WriteRemoteObject(nullObj);
    assert(writeResult == true);
    std::cout << "[Test2] WriteRemoteObject(nullptr) succeeded" << std::endl;
    
    // 读取应该返回 nullptr
    sptr<IRemoteObject> readObj = data.ReadRemoteObject();
    assert(readObj == nullptr);
    std::cout << "[Test2] ReadRemoteObject returned nullptr as expected" << std::endl;
    
    std::cout << "[Test2] ✓ PASSED" << std::endl;
}

/**
 * @brief 测试3：回调对象从 SDK 传递到 Service
 */
void Test3_CallbackPassingToService() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Test 3: Callback Passing from SDK to Service" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // 1. SDK 侧：创建回调对象
    sptr<TestCallbackStub> callback = new TestCallbackStub();
    std::cout << "[Test3] SDK: Callback object created" << std::endl;
    
    // 2. SDK 侧：将回调对象写入 MessageParcel（模拟 IPC 调用）
    MessageParcel data;
    data.WriteRemoteObject(callback->AsObject());
    std::cout << "[Test3] SDK: Callback written to MessageParcel" << std::endl;
    
    // 3. Service 侧：从 MessageParcel 读取回调对象
    sptr<IRemoteObject> callbackObj = data.ReadRemoteObject();
    assert(callbackObj != nullptr);
    std::cout << "[Test3] Service: Callback read from MessageParcel" << std::endl;
    
    // 4. Service 侧：转换为回调接口
    sptr<ITestCallback> callbackInterface = iface_cast<ITestCallback>(callbackObj);
    assert(callbackInterface != nullptr);
    std::cout << "[Test3] Service: Callback interface cast succeeded" << std::endl;
    
    // 5. Service 侧：注册回调
    TestService service;
    int32_t ret = service.RegisterCallback(callbackInterface);
    assert(ret == 0);
    assert(service.HasCallback() == true);
    std::cout << "[Test3] Service: Callback registered" << std::endl;
    
    std::cout << "[Test3] ✓ PASSED" << std::endl;
}

/**
 * @brief 测试4：Service 调用回调对象的方法
 */
void Test4_ServiceInvokeCallback() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Test 4: Service Invoke Callback Methods" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // 1. 创建回调对象
    sptr<TestCallbackStub> callback = new TestCallbackStub();
    
    // 2. 通过 MessageParcel 传递（模拟 IPC）
    MessageParcel data;
    data.WriteRemoteObject(callback->AsObject());
    sptr<IRemoteObject> callbackObj = data.ReadRemoteObject();
    sptr<ITestCallback> callbackInterface = iface_cast<ITestCallback>(callbackObj);
    
    // 3. Service 注册回调
    TestService service;
    service.RegisterCallback(callbackInterface);
    
    // 4. Service 触发事件回调
    int32_t ret = service.TriggerEvent("device_online", "device_001");
    assert(ret == 0);
    std::cout << "[Test4] Service triggered event callback" << std::endl;
    
    // 5. 验证回调被调用
    assert(callback->IsEventCalled() == true);
    assert(callback->GetLastEvent() == "device_online");
    assert(callback->GetLastData() == "device_001");
    std::cout << "[Test4] Callback OnEvent was called correctly" << std::endl;
    
    // 6. Service 触发错误回调
    callback->Reset();
    ret = service.TriggerError(100, "Connection failed");
    assert(ret == 0);
    std::cout << "[Test4] Service triggered error callback" << std::endl;
    
    // 7. 验证错误回调被调用
    assert(callback->IsErrorCalled() == true);
    assert(callback->GetLastErrorCode() == 100);
    assert(callback->GetLastErrorMsg() == "Connection failed");
    std::cout << "[Test4] Callback OnError was called correctly" << std::endl;
    
    std::cout << "[Test4] ✓ PASSED" << std::endl;
}

/**
 * @brief 测试5：多次回调调用
 */
void Test5_MultipleCallbackInvocations() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Test 5: Multiple Callback Invocations" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // 1. 创建并注册回调
    sptr<TestCallbackStub> callback = new TestCallbackStub();
    MessageParcel data;
    data.WriteRemoteObject(callback->AsObject());
    sptr<ITestCallback> callbackInterface = iface_cast<ITestCallback>(data.ReadRemoteObject());
    
    TestService service;
    service.RegisterCallback(callbackInterface);
    
    // 2. 多次触发回调
    service.TriggerEvent("event1", "data1");
    service.TriggerEvent("event2", "data2");
    service.TriggerEvent("event3", "data3");
    
    // 3. 验证回调被调用了3次
    assert(callback->GetEventCount() == 3);
    assert(callback->GetLastEvent() == "event3");
    assert(callback->GetLastData() == "data3");
    std::cout << "[Test5] Callback invoked 3 times successfully" << std::endl;
    
    std::cout << "[Test5] ✓ PASSED" << std::endl;
}

/**
 * @brief 测试6：Service 处理空回调
 */
void Test6_ServiceHandleNullCallback() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Test 6: Service Handle Null Callback" << std::endl;
    std::cout << "========================================" << std::endl;
    
    TestService service;
    
    // 1. 尝试注册空回调
    int32_t ret = service.RegisterCallback(nullptr);
    assert(ret == -1);
    assert(service.HasCallback() == false);
    std::cout << "[Test6] RegisterCallback(nullptr) returned error as expected" << std::endl;
    
    // 2. 尝试在没有回调的情况下触发事件
    ret = service.TriggerEvent("test_event", "test_data");
    assert(ret == -1);
    std::cout << "[Test6] TriggerEvent without callback returned error as expected" << std::endl;
    
    // 3. 尝试在没有回调的情况下触发错误
    ret = service.TriggerError(100, "test_error");
    assert(ret == -1);
    std::cout << "[Test6] TriggerError without callback returned error as expected" << std::endl;
    
    std::cout << "[Test6] ✓ PASSED" << std::endl;
}

/**
 * @brief 测试7：回调对象生命周期管理
 */
void Test7_CallbackLifecycleManagement() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Test 7: Callback Lifecycle Management" << std::endl;
    std::cout << "========================================" << std::endl;
    
    TestService service;
    
    // 1. 创建并注册回调
    {
        sptr<TestCallbackStub> callback = new TestCallbackStub();
        MessageParcel data;
        data.WriteRemoteObject(callback->AsObject());
        sptr<ITestCallback> callbackInterface = iface_cast<ITestCallback>(data.ReadRemoteObject());
        
        service.RegisterCallback(callbackInterface);
        assert(service.HasCallback() == true);
        std::cout << "[Test7] Callback registered" << std::endl;
        
        // 2. 触发回调
        int32_t ret = service.TriggerEvent("test_event", "test_data");
        assert(ret == 0);
        assert(callback->IsEventCalled() == true);
        std::cout << "[Test7] Callback invoked successfully" << std::endl;
    }
    // callback 对象离开作用域，但 service 仍持有引用（通过 sptr）
    
    // 3. 注销回调
    service.UnregisterCallback();
    assert(service.HasCallback() == false);
    std::cout << "[Test7] Callback unregistered" << std::endl;
    
    // 4. 尝试触发回调应该失败
    int32_t ret = service.TriggerEvent("test_event", "test_data");
    assert(ret == -1);
    std::cout << "[Test7] TriggerEvent after unregister returned error as expected" << std::endl;
    
    std::cout << "[Test7] ✓ PASSED" << std::endl;
}

/**
 * @brief 测试8：多个回调对象的传递
 */
void Test8_MultipleCallbackObjects() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "Test 8: Multiple Callback Objects" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // 1. 创建多个回调对象
    sptr<TestCallbackStub> callback1 = new TestCallbackStub();
    sptr<TestCallbackStub> callback2 = new TestCallbackStub();
    sptr<TestCallbackStub> callback3 = new TestCallbackStub();
    
    // 2. 将多个回调对象写入 MessageParcel
    MessageParcel data;
    data.WriteRemoteObject(callback1->AsObject());
    data.WriteRemoteObject(callback2->AsObject());
    data.WriteRemoteObject(callback3->AsObject());
    std::cout << "[Test8] Three callback objects written to MessageParcel" << std::endl;
    
    // 3. 按顺序读取回调对象
    sptr<IRemoteObject> obj1 = data.ReadRemoteObject();
    sptr<IRemoteObject> obj2 = data.ReadRemoteObject();
    sptr<IRemoteObject> obj3 = data.ReadRemoteObject();
    
    assert(obj1 != nullptr);
    assert(obj2 != nullptr);
    assert(obj3 != nullptr);
    std::cout << "[Test8] Three callback objects read from MessageParcel" << std::endl;
    
    // 4. 验证对象身份
    assert(obj1.GetRefPtr() == callback1->AsObject().GetRefPtr());
    assert(obj2.GetRefPtr() == callback2->AsObject().GetRefPtr());
    assert(obj3.GetRefPtr() == callback3->AsObject().GetRefPtr());
    std::cout << "[Test8] All callback objects identity verified" << std::endl;
    
    // 5. 验证每个回调都可以被调用
    sptr<ITestCallback> cb1 = iface_cast<ITestCallback>(obj1);
    sptr<ITestCallback> cb2 = iface_cast<ITestCallback>(obj2);
    sptr<ITestCallback> cb3 = iface_cast<ITestCallback>(obj3);
    
    cb1->OnEvent("event1", "data1");
    cb2->OnEvent("event2", "data2");
    cb3->OnEvent("event3", "data3");
    
    assert(callback1->IsEventCalled() && callback1->GetLastEvent() == "event1");
    assert(callback2->IsEventCalled() && callback2->GetLastEvent() == "event2");
    assert(callback3->IsEventCalled() && callback3->GetLastEvent() == "event3");
    std::cout << "[Test8] All callbacks invoked successfully" << std::endl;
    
    std::cout << "[Test8] ✓ PASSED" << std::endl;
}

// ============================================================================
// 主函数
// ============================================================================

int main() {
    std::cout << "\n" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Callback Object Passing Test Suite" << std::endl;
    std::cout << "========================================" << std::endl;
    
    try {
        Test1_MessageParcelWriteReadRemoteObject();
        Test2_NullObjectHandling();
        Test3_CallbackPassingToService();
        Test4_ServiceInvokeCallback();
        Test5_MultipleCallbackInvocations();
        Test6_ServiceHandleNullCallback();
        Test7_CallbackLifecycleManagement();
        Test8_MultipleCallbackObjects();
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "All Tests PASSED ✓" << std::endl;
        std::cout << "========================================\n" << std::endl;
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "\n========================================" << std::endl;
        std::cerr << "Test FAILED ✗" << std::endl;
        std::cerr << "Exception: " << e.what() << std::endl;
        std::cerr << "========================================\n" << std::endl;
        return 1;
    }
}
