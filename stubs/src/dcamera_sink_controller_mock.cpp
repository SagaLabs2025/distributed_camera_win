/*
 * DCameraSinkController Mock Implementation for macOS
 *
 * OpenHarmony DCameraSinkController 的 macOS Mock 空实现
 */

#include <string>
#include <vector>
#include <memory>

namespace OHOS {
namespace DistributedHardware {

// 前向声明
class DataBuffer;
class DCameraEvent;
class ICameraSinkAccessControl;
class IDCameraSinkCallback;
namespace HDI {
namespace DistributedCamera {
namespace V1_1 {
class DCameraSettings;
}
}
}

template<typename T>
class sptr {
public:
    T* ptr_;
    sptr() : ptr_(nullptr) {}
    sptr(T* p) : ptr_(p) {}
};

class DCameraSinkController {
public:
    DCameraSinkController(std::shared_ptr<ICameraSinkAccessControl>& accessControl,
                          const sptr<IDCameraSinkCallback>& callback);
    
    void OnSessionError(int eventType, int eventReason, const std::string& detail);
    void OnSessionState(int state, const std::string& detail);
    void OnDataReceived(std::vector<std::shared_ptr<DataBuffer>>& buffers);
    void OnStateChanged(std::shared_ptr<DCameraEvent>& event);
    void OnMetadataResult(std::vector<std::shared_ptr<HDI::DistributedCamera::V1_1::DCameraSettings>>& settings);
};

// 实现
DCameraSinkController::DCameraSinkController(std::shared_ptr<ICameraSinkAccessControl>& accessControl,
                                             const sptr<IDCameraSinkCallback>& callback)
{
    (void)accessControl;
    (void)callback;
}

void DCameraSinkController::OnSessionError(int eventType, int eventReason, const std::string& detail)
{
    (void)eventType;
    (void)eventReason;
    (void)detail;
    // Mock: 空实现
}

void DCameraSinkController::OnSessionState(int state, const std::string& detail)
{
    (void)state;
    (void)detail;
    // Mock: 空实现
}

void DCameraSinkController::OnDataReceived(std::vector<std::shared_ptr<DataBuffer>>& buffers)
{
    (void)buffers;
    // Mock: 空实现
}

void DCameraSinkController::OnStateChanged(std::shared_ptr<DCameraEvent>& event)
{
    (void)event;
    // Mock: 空实现
}

void DCameraSinkController::OnMetadataResult(std::vector<std::shared_ptr<HDI::DistributedCamera::V1_1::DCameraSettings>>& settings)
{
    (void)settings;
    // Mock: 空实现
}

} // namespace DistributedHardware
} // namespace OHOS
