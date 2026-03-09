#ifndef STUBS_DCAMERA_HANDLER_H
#define STUBS_DCAMERA_HANDLER_H

// The real `dcamera_handler.h` pulls in camera framework headers which are not available/compatible on macOS.
// For local compilation we only provide a placeholder so service code can be built.

namespace OHOS {
namespace DistributedHardware {

class DCameraHandler {
public:
    static DCameraHandler& GetInstance()
    {
        static DCameraHandler instance;
        return instance;
    }

private:
    DCameraHandler() = default;
    ~DCameraHandler() = default;
};

} // namespace DistributedHardware
} // namespace OHOS

#endif // STUBS_DCAMERA_HANDLER_H

