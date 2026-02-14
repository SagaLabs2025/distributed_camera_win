/*
 * DCameraSoftbusSession Mock Implementation for macOS
 *
 * OpenHarmony DCameraSoftbusSession 的 macOS Mock 空实现
 */

#include <string>
#include <memory>

namespace OHOS {
namespace DistributedHardware {

// 前向声明
class DataBuffer;
class ICameraChannelListener;
enum class DCameraSessionMode;

class DCameraSoftbusSession {
public:
    // Constructor with string references
    DCameraSoftbusSession(const std::string& mySessionName,
                          const std::string& peerSessionName,
                          const std::string& peerDevId,
                          const std::string& sourceDevId,
                          const std::string& dhId,
                          std::shared_ptr<ICameraChannelListener> listener,
                          DCameraSessionMode sessionMode);
    
    // Constructor with string values (for std::make_shared)
    DCameraSoftbusSession(std::string mySessionName,
                          std::string peerSessionName,
                          std::string peerDevId,
                          std::string sourceDevId,
                          std::string dhId,
                          std::shared_ptr<ICameraChannelListener> listener,
                          DCameraSessionMode sessionMode);
    
    virtual ~DCameraSoftbusSession();
    
    int32_t BindSocketServer();
    int32_t ReleaseSession();
    int32_t CloseSession();
    int32_t SendData(DCameraSessionMode mode, std::shared_ptr<DataBuffer>& buffer);
};

// 实现
DCameraSoftbusSession::DCameraSoftbusSession(
    const std::string& mySessionName,
    const std::string& peerSessionName,
    const std::string& peerDevId,
    const std::string& sourceDevId,
    const std::string& dhId,
    std::shared_ptr<ICameraChannelListener> listener,
    DCameraSessionMode sessionMode)
{
    (void)mySessionName;
    (void)peerSessionName;
    (void)peerDevId;
    (void)sourceDevId;
    (void)dhId;
    (void)listener;
    (void)sessionMode;
}

DCameraSoftbusSession::DCameraSoftbusSession(
    std::string mySessionName,
    std::string peerSessionName,
    std::string peerDevId,
    std::string sourceDevId,
    std::string dhId,
    std::shared_ptr<ICameraChannelListener> listener,
    DCameraSessionMode sessionMode)
{
    (void)mySessionName;
    (void)peerSessionName;
    (void)peerDevId;
    (void)sourceDevId;
    (void)dhId;
    (void)listener;
    (void)sessionMode;
}

DCameraSoftbusSession::~DCameraSoftbusSession() = default;

int32_t DCameraSoftbusSession::BindSocketServer()
{
    return 0;  // Mock: 总是成功
}

int32_t DCameraSoftbusSession::ReleaseSession()
{
    return 0;  // Mock: 总是成功
}

int32_t DCameraSoftbusSession::CloseSession()
{
    return 0;  // Mock: 总是成功
}

int32_t DCameraSoftbusSession::SendData(DCameraSessionMode mode, std::shared_ptr<DataBuffer>& buffer)
{
    (void)mode;
    (void)buffer;
    return 0;  // Mock: 总是成功
}

} // namespace DistributedHardware
} // namespace OHOS
