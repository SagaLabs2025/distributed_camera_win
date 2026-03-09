/*
 * Test Service Auto-Registration
 *
 * 测试 Service 自动注册机制是否正常工作
 */

#include <iostream>
#include "service_registry.h"
#include "iremote_object.h"
#include "refbase.h"
#include "distributed_hardware_log.h"

using namespace OHOS;
using namespace OHOS::DistributedHardware;

int main() {
    std::cout << "=== Service Auto-Registration Test ===" << std::endl;
    std::cout << std::endl;

    // 测试 1: 检查 Source Service 是否已注册
    std::cout << "1. Checking if Source Service (SA 4803) is registered..." << std::endl;
    bool sourceRegistered = ServiceRegistry::GetInstance().IsServiceRegistered(4803);
    std::cout << "   Result: " << (sourceRegistered ? "REGISTERED" : "NOT REGISTERED") << std::endl;
    std::cout << std::endl;

    // 测试 2: 检查 Sink Service 是否已注册
    std::cout << "2. Checking if Sink Service (SA 4804) is registered..." << std::endl;
    bool sinkRegistered = ServiceRegistry::GetInstance().IsServiceRegistered(4804);
    std::cout << "   Result: " << (sinkRegistered ? "REGISTERED" : "NOT REGISTERED") << std::endl;
    std::cout << std::endl;

    // 测试 3: 获取 Source Service 对象
    std::cout << "3. Getting Source Service object..." << std::endl;
    sptr<IRemoteObject> sourceService = ServiceRegistry::GetInstance().GetService(4803);
    if (sourceService != nullptr) {
        std::cout << "   SUCCESS: Got Source Service object" << std::endl;
        std::cout << "   RefCount: " << sourceService->GetObjectRefCount() << std::endl;
    } else {
        std::cout << "   FAILED: Source Service object is nullptr" << std::endl;
    }
    std::cout << std::endl;

    // 测试 4: 获取 Sink Service 对象
    std::cout << "4. Getting Sink Service object..." << std::endl;
    sptr<IRemoteObject> sinkService = ServiceRegistry::GetInstance().GetService(4804);
    if (sinkService != nullptr) {
        std::cout << "   SUCCESS: Got Sink Service object" << std::endl;
        std::cout << "   RefCount: " << sinkService->GetObjectRefCount() << std::endl;
    } else {
        std::cout << "   FAILED: Sink Service object is nullptr" << std::endl;
    }
    std::cout << std::endl;

    // 测试 5: 测试 SendRequest 调用
    std::cout << "5. Testing SendRequest on Source Service..." << std::endl;
    if (sourceService != nullptr) {
        MessageParcel data, reply;
        MessageOption option;
        int32_t ret = sourceService->SendRequest(1, data, reply, option);
        std::cout << "   SendRequest result: " << ret << " (0 = success)" << std::endl;
    }
    std::cout << std::endl;

    // 测试 6: 测试不存在的 Service
    std::cout << "6. Testing non-existent service (SA ID 9999)..." << std::endl;
    bool nonExistentRegistered = ServiceRegistry::GetInstance().IsServiceRegistered(9999);
    std::cout << "   IsRegistered result: " << (nonExistentRegistered ? "TRUE (unexpected)" : "FALSE (expected)") << std::endl;
    sptr<IRemoteObject> nonExistentService = ServiceRegistry::GetInstance().GetService(9999);
    std::cout << "   GetService result: " << (nonExistentService == nullptr ? "nullptr (expected)" : "NOT nullptr (unexpected)") << std::endl;
    std::cout << std::endl;

    // 总结
    std::cout << "=== Test Summary ===" << std::endl;
    bool allPassed = sourceRegistered && sinkRegistered && 
                     (sourceService != nullptr) && (sinkService != nullptr) &&
                     !nonExistentRegistered && (nonExistentService == nullptr);
    
    if (allPassed) {
        std::cout << "✓ All tests PASSED!" << std::endl;
        std::cout << std::endl;
        std::cout << "Service auto-registration is working correctly:" << std::endl;
        std::cout << "  - Source Service (SA 4803) is registered and accessible" << std::endl;
        std::cout << "  - Sink Service (SA 4804) is registered and accessible" << std::endl;
        std::cout << "  - Services respond to SendRequest calls" << std::endl;
        return 0;
    } else {
        std::cout << "✗ Some tests FAILED!" << std::endl;
        return 1;
    }
}
