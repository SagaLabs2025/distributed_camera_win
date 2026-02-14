/*
 * DCameraSoftbusAdapter Mock Implementation for macOS
 *
 * OpenHarmony DCameraSoftbusAdapter 的 macOS Mock 空实现
 */

#include <string>
#include <memory>

namespace OHOS {
namespace DistributedHardware {

// 前向声明
class DCameraSoftbusSession;

class DCameraSoftbusAdapter {
public:
    static DCameraSoftbusAdapter& GetInstance();
    int32_t RecordSourceSocketSession(int sessionId, std::shared_ptr<DCameraSoftbusSession> session);
    int32_t CloseSessionWithNetWorkId(const std::string& networkId);
};

// 实现
DCameraSoftbusAdapter& DCameraSoftbusAdapter::GetInstance()
{
    static DCameraSoftbusAdapter instance;
    return instance;
}

int32_t DCameraSoftbusAdapter::RecordSourceSocketSession(int sessionId, std::shared_ptr<DCameraSoftbusSession> session)
{
    (void)sessionId;
    (void)session;
    return 0;  // Mock: 总是成功
}

int32_t DCameraSoftbusAdapter::CloseSessionWithNetWorkId(const std::string& networkId)
{
    (void)networkId;
    return 0;  // Mock: 总是成功
}

} // namespace DistributedHardware
} // namespace OHOS
