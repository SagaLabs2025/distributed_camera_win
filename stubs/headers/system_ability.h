#ifndef STUBS_SYSTEM_ABILITY_H
#define STUBS_SYSTEM_ABILITY_H

#include <cstdint>

namespace OHOS {

class SystemAbility {
public:
    SystemAbility(int32_t /*saId*/, bool /*runOnCreate*/) {}
    virtual ~SystemAbility() = default;

    virtual void OnStart() {}
    virtual void OnStop() {}

protected:
    bool Publish(SystemAbility* /*ability*/)
    {
        return true;
    }
};

#define DECLARE_SYSTEM_ABILITY(ClassName)

} // namespace OHOS

#endif // STUBS_SYSTEM_ABILITY_H

