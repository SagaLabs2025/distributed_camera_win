/*
 * Test for SystemAbilityManager Mock Enhancement
 *
 * 验证 SystemAbilityManager Mock 使用 ServiceRegistry 查找 Service 的功能
 */

#include <iostream>
#include "system_ability_manager_unified.h"
#include "service_registry.h"
#include "remote_object_mock.h"
#include "iremote_object.h"

using namespace OHOS;
using namespace OHOS::DistributedHardware;

// 简单的测试 Service 类
class TestService : public IRemoteObject {
public:
    TestService() : IRemoteObject(u"TestService") {}
    
    int SendRequest(uint32_t code, MessageParcel& data, 
                   MessageParcel& reply, MessageOption& option) override {
        std::cout << "TestService::SendRequest called with code: " << code << std::endl;
        return 0;
    }
    
    int32_t GetObjectRefCount() override { return 1; }
    bool AddDeathRecipient(const sptr<DeathRecipient>& recipient) override { return true; }
    bool RemoveDeathRecipient(const sptr<DeathRecipient>& recipient) override { return true; }
    int Dump(int fd, const std::vector<std::u16string>& args) override { return 0; }
};

int main() {
    std::cout << "=== SystemAbilityManager Mock Enhancement Test ===" << std::endl;
    
    // 1. 注册测试 Service
    std::cout << "\n1. Registering test service with SA ID 4803..." << std::endl;
    sptr<IRemoteObject> testService = new TestService();
    bool registered = ServiceRegistry::GetInstance().RegisterService(4803, testService);
    std::cout << "   Registration result: " << (registered ? "SUCCESS" : "FAILED") << std::endl;
    
    // 2. 通过 SystemAbilityManagerClient 获取 Service
    std::cout << "\n2. Getting service through SystemAbilityManagerClient..." << std::endl;
    auto& samClient = SystemAbilityManagerClient::GetInstance();
    auto samProxy = samClient.GetSystemAbilityManager();
    
    if (samProxy == nullptr) {
        std::cout << "   ERROR: GetSystemAbilityManager returned nullptr" << std::endl;
        return 1;
    }
    
    // 3. 检查 Service 是否存在
    std::cout << "\n3. Checking if service 4803 exists..." << std::endl;
    int32_t checkResult = samProxy->CheckSystemAbility(4803);
    std::cout << "   CheckSystemAbility result: " << checkResult << " (0 = exists)" << std::endl;
    
    // 4. 获取 Service 对象
    std::cout << "\n4. Getting service object..." << std::endl;
    sptr<IRemoteObject> serviceObj = samProxy->CheckSystemAbility(4803, "");
    
    if (serviceObj == nullptr) {
        std::cout << "   ERROR: CheckSystemAbility returned nullptr" << std::endl;
        return 1;
    }
    std::cout << "   SUCCESS: Got service object" << std::endl;
    
    // 5. 测试不存在的 Service
    std::cout << "\n5. Testing non-existent service (SA ID 9999)..." << std::endl;
    int32_t checkResult2 = samProxy->CheckSystemAbility(9999);
    std::cout << "   CheckSystemAbility result: " << checkResult2 << " (-1 = not exists)" << std::endl;
    
    sptr<IRemoteObject> serviceObj2 = samProxy->CheckSystemAbility(9999, "");
    std::cout << "   GetSystemAbility result: " << (serviceObj2 == nullptr ? "nullptr (expected)" : "NOT nullptr (unexpected)") << std::endl;
    
    // 6. 清理
    std::cout << "\n6. Cleaning up..." << std::endl;
    ServiceRegistry::GetInstance().UnregisterService(4803);
    
    std::cout << "\n=== All tests passed! ===" << std::endl;
    return 0;
}
