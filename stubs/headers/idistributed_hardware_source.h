/*
 * IDistributedHardwareSource - OpenHarmony Distributed Hardware - macOS Mock
 *
 * 分布式硬件源接口的 macOS 空实现
 */

#ifndef STUBS_IDISTRIBUTED_HARDWARE_SOURCE_H
#define STUBS_IDISTRIBUTED_HARDWARE_SOURCE_H

#include <string>

namespace OHOS {
namespace DistributedHardware {

// IDistributedHardwareSource - 分布式硬件源接口
class IDistributedHardwareSource {
public:
    virtual ~IDistributedHardwareSource() = default;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_IDISTRIBUTED_HARDWARE_SOURCE_H
