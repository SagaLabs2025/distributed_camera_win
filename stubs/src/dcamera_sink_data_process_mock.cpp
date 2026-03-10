/*
 * DCameraSinkDataProcess Mock Implementation for macOS
 *
 * OpenHarmony DCameraSinkDataProcess 的 macOS Mock 空实现
 */

#include <memory>

namespace OHOS {
namespace DistributedHardware {

// 前向声明
enum class DataProcessErrorType;
class DataBuffer;

class DCameraSinkDataProcess {
public:
    void OnError(DataProcessErrorType errorType);
    void OnProcessedVideoBuffer(const std::shared_ptr<DataBuffer>& buffer);
};

// 实现
void DCameraSinkDataProcess::OnError(DataProcessErrorType errorType)
{
    (void)errorType;
    // Mock: 空实现
}

void DCameraSinkDataProcess::OnProcessedVideoBuffer(const std::shared_ptr<DataBuffer>& buffer)
{
    (void)buffer;
    // Mock: 空实现
}

} // namespace DistributedHardware
} // namespace OHOS
