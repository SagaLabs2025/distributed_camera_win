/*
 * ServiceRegistry Unit Test
 *
 * 测试 ServiceRegistry 的基本功能
 */

#include "service_registry.h"
#include "iremote_object.h"
#include <iostream>
#include <thread>
#include <vector>
#include <cassert>

using namespace OHOS;
using namespace OHOS::DistributedHardware;

// Mock IRemoteObject for testing
class MockRemoteObject : public IRemoteObject {
public:
    MockRemoteObject() : IRemoteObject(u"MockRemoteObject") {}
    
    int SendRequest(uint32_t code, MessageParcel& data, 
                   MessageParcel& reply, MessageOption& option) override {
        return 0;
    }
};

// 测试1：基本注册和查询
void TestBasicRegisterAndGet() {
    std::cout << "Test 1: Basic Register and Get..." << std::endl;
    
    ServiceRegistry& registry = ServiceRegistry::GetInstance();
    registry.ClearAll();
    
    // 注册 Service
    sptr<IRemoteObject> service = new MockRemoteObject();
    bool ret = registry.RegisterService(4803, service);
    assert(ret == true);
    
    // 查询 Service
    sptr<IRemoteObject> retrieved = registry.GetService(4803);
    assert(retrieved != nullptr);
    assert(retrieved.GetRefPtr() == service.GetRefPtr());
    
    std::cout << "  ✓ Basic register and get passed" << std::endl;
}

// 测试2：Service 不存在
void TestServiceNotFound() {
    std::cout << "Test 2: Service Not Found..." << std::endl;
    
    ServiceRegistry& registry = ServiceRegistry::GetInstance();
    registry.ClearAll();
    
    // 查询不存在的 Service
    sptr<IRemoteObject> retrieved = registry.GetService(9999);
    assert(retrieved == nullptr);
    
    std::cout << "  ✓ Service not found test passed" << std::endl;
}

// 测试3：注册空指针
void TestRegisterNullService() {
    std::cout << "Test 3: Register Null Service..." << std::endl;
    
    ServiceRegistry& registry = ServiceRegistry::GetInstance();
    registry.ClearAll();
    
    // 尝试注册空指针
    bool ret = registry.RegisterService(4803, nullptr);
    assert(ret == false);
    
    // 验证未注册
    assert(registry.IsServiceRegistered(4803) == false);
    
    std::cout << "  ✓ Register null service test passed" << std::endl;
}

// 测试4：替换已注册的 Service
void TestReplaceService() {
    std::cout << "Test 4: Replace Service..." << std::endl;
    
    ServiceRegistry& registry = ServiceRegistry::GetInstance();
    registry.ClearAll();
    
    // 注册第一个 Service
    sptr<IRemoteObject> service1 = new MockRemoteObject();
    registry.RegisterService(4803, service1);
    
    // 注册第二个 Service（替换）
    sptr<IRemoteObject> service2 = new MockRemoteObject();
    bool ret = registry.RegisterService(4803, service2);
    assert(ret == true);
    
    // 验证是第二个 Service
    sptr<IRemoteObject> retrieved = registry.GetService(4803);
    assert(retrieved.GetRefPtr() == service2.GetRefPtr());
    
    std::cout << "  ✓ Replace service test passed" << std::endl;
}

// 测试5：注销 Service
void TestUnregisterService() {
    std::cout << "Test 5: Unregister Service..." << std::endl;
    
    ServiceRegistry& registry = ServiceRegistry::GetInstance();
    registry.ClearAll();
    
    // 注册 Service
    sptr<IRemoteObject> service = new MockRemoteObject();
    registry.RegisterService(4803, service);
    assert(registry.IsServiceRegistered(4803) == true);
    
    // 注销 Service
    bool ret = registry.UnregisterService(4803);
    assert(ret == true);
    assert(registry.IsServiceRegistered(4803) == false);
    
    // 尝试注销不存在的 Service
    ret = registry.UnregisterService(9999);
    assert(ret == false);
    
    std::cout << "  ✓ Unregister service test passed" << std::endl;
}

// 测试6：多个 Service
void TestMultipleServices() {
    std::cout << "Test 6: Multiple Services..." << std::endl;
    
    ServiceRegistry& registry = ServiceRegistry::GetInstance();
    registry.ClearAll();
    
    // 注册多个 Service
    sptr<IRemoteObject> sourceService = new MockRemoteObject();
    sptr<IRemoteObject> sinkService = new MockRemoteObject();
    
    registry.RegisterService(4803, sourceService);
    registry.RegisterService(4804, sinkService);
    
    // 验证都能查询到
    assert(registry.IsServiceRegistered(4803) == true);
    assert(registry.IsServiceRegistered(4804) == true);
    
    sptr<IRemoteObject> retrieved1 = registry.GetService(4803);
    sptr<IRemoteObject> retrieved2 = registry.GetService(4804);
    
    assert(retrieved1.GetRefPtr() == sourceService.GetRefPtr());
    assert(retrieved2.GetRefPtr() == sinkService.GetRefPtr());
    
    std::cout << "  ✓ Multiple services test passed" << std::endl;
}

// 测试7：线程安全 - 并发注册
void TestConcurrentRegister() {
    std::cout << "Test 7: Concurrent Register..." << std::endl;
    
    ServiceRegistry& registry = ServiceRegistry::GetInstance();
    registry.ClearAll();
    
    const int NUM_THREADS = 10;
    const int NUM_SERVICES = 100;
    std::vector<std::thread> threads;
    
    // 创建多个线程并发注册
    for (int t = 0; t < NUM_THREADS; t++) {
        threads.emplace_back([&registry, t]() {
            for (int i = 0; i < NUM_SERVICES; i++) {
                int saId = t * NUM_SERVICES + i;
                sptr<IRemoteObject> service = new MockRemoteObject();
                registry.RegisterService(saId, service);
            }
        });
    }
    
    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }
    
    // 验证所有 Service 都注册成功
    for (int t = 0; t < NUM_THREADS; t++) {
        for (int i = 0; i < NUM_SERVICES; i++) {
            int saId = t * NUM_SERVICES + i;
            assert(registry.IsServiceRegistered(saId) == true);
        }
    }
    
    std::cout << "  ✓ Concurrent register test passed (registered " 
              << NUM_THREADS * NUM_SERVICES << " services)" << std::endl;
}

// 测试8：线程安全 - 并发查询
void TestConcurrentGet() {
    std::cout << "Test 8: Concurrent Get..." << std::endl;
    
    ServiceRegistry& registry = ServiceRegistry::GetInstance();
    registry.ClearAll();
    
    // 先注册一些 Service
    const int NUM_SERVICES = 10;
    std::vector<sptr<IRemoteObject>> services;
    for (int i = 0; i < NUM_SERVICES; i++) {
        sptr<IRemoteObject> service = new MockRemoteObject();
        services.push_back(service);
        registry.RegisterService(i, service);
    }
    
    // 创建多个线程并发查询
    const int NUM_THREADS = 20;
    const int NUM_QUERIES = 1000;
    std::vector<std::thread> threads;
    std::atomic<int> successCount(0);
    
    for (int t = 0; t < NUM_THREADS; t++) {
        threads.emplace_back([&registry, &successCount]() {
            for (int i = 0; i < NUM_QUERIES; i++) {
                int saId = i % NUM_SERVICES;
                sptr<IRemoteObject> service = registry.GetService(saId);
                if (service != nullptr) {
                    successCount++;
                }
            }
        });
    }
    
    // 等待所有线程完成
    for (auto& thread : threads) {
        thread.join();
    }
    
    // 验证所有查询都成功
    assert(successCount == NUM_THREADS * NUM_QUERIES);
    
    std::cout << "  ✓ Concurrent get test passed (" 
              << successCount << " successful queries)" << std::endl;
}

// 测试9：ClearAll
void TestClearAll() {
    std::cout << "Test 9: Clear All..." << std::endl;
    
    ServiceRegistry& registry = ServiceRegistry::GetInstance();
    registry.ClearAll();
    
    // 注册多个 Service
    for (int i = 0; i < 10; i++) {
        sptr<IRemoteObject> service = new MockRemoteObject();
        registry.RegisterService(i, service);
    }
    
    // 清空所有
    registry.ClearAll();
    
    // 验证所有 Service 都被清除
    for (int i = 0; i < 10; i++) {
        assert(registry.IsServiceRegistered(i) == false);
    }
    
    std::cout << "  ✓ Clear all test passed" << std::endl;
}

// 测试10：单例模式
void TestSingleton() {
    std::cout << "Test 10: Singleton Pattern..." << std::endl;
    
    ServiceRegistry& registry1 = ServiceRegistry::GetInstance();
    ServiceRegistry& registry2 = ServiceRegistry::GetInstance();
    
    // 验证是同一个实例
    assert(&registry1 == &registry2);
    
    // 在一个实例中注册，在另一个实例中查询
    registry1.ClearAll();
    sptr<IRemoteObject> service = new MockRemoteObject();
    registry1.RegisterService(4803, service);
    
    sptr<IRemoteObject> retrieved = registry2.GetService(4803);
    assert(retrieved.GetRefPtr() == service.GetRefPtr());
    
    std::cout << "  ✓ Singleton pattern test passed" << std::endl;
}

int main() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  ServiceRegistry Unit Tests" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    try {
        TestBasicRegisterAndGet();
        TestServiceNotFound();
        TestRegisterNullService();
        TestReplaceService();
        TestUnregisterService();
        TestMultipleServices();
        TestConcurrentRegister();
        TestConcurrentGet();
        TestClearAll();
        TestSingleton();
        
        std::cout << "\n========================================" << std::endl;
        std::cout << "  All Tests Passed! ✓" << std::endl;
        std::cout << "========================================\n" << std::endl;
        
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "\n✗ Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
}
