/*
 * DistributedHardwareFwkKit mock implementation for macOS
 */

#include "distributed_hardware_fwk_kit.h"

#include "dcamera_hdf_operate.h"

namespace OHOS {
namespace DistributedHardware {

DistributedHardwareFwkKit::DistributedHardwareFwkKit() = default;

DistributedHardwareFwkKit::~DistributedHardwareFwkKit() = default;

int32_t DistributedHardwareFwkKit::LoadDistributedHDF(const DHType dhType)
{
    (void)dhType;
    return DCameraHdfOperate::GetInstance().LoadDcameraHDFImpl(nullptr);
}

int32_t DistributedHardwareFwkKit::UnLoadDistributedHDF(const DHType dhType)
{
    (void)dhType;
    return DCameraHdfOperate::GetInstance().UnLoadDcameraHDFImpl();
}

} // namespace DistributedHardware
} // namespace OHOS

