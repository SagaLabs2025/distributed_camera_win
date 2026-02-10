/*
 * API Load Test - 分布式相机动态库接口验证测试
 *
 * 验证 dcamera_source.dylib 和 dcamera_sink.dylib 的接口可用性
 */

#include <iostream>
#include <dlfcn.h>

int main() {
    std::cout << "=== 分布式相机 API 加载测试 ===" << std::endl;

    // 测试加载 dcamera_source.dylib
    std::cout << "\n[测试] 加载 dcamera_source.dylib..." << std::endl;
    void* sourceHandle = dlopen("./libdcamera_source.dylib", RTLD_LAZY);
    if (sourceHandle) {
        std::cout << "✓ 成功加载 dcamera_source.dylib" << std::endl;

        // 获取初始化函数
        auto initFunc = (int32_t(*)())dlsym(sourceHandle, "DCameraSourceInitialize");
        if (initFunc) {
            std::cout << "✓ 找到 DCameraSourceInitialize 函数" << std::endl;
            int32_t result = initFunc();
            if (result == 0) {
                std::cout << "✓ DCameraSourceInitialize 执行成功" << std::endl;
            } else {
                std::cout << "✗ DCameraSourceInitialize 执行失败: " << result << std::endl;
            }
        } else {
            std::cout << "✗ 未找到 DCameraSourceInitialize 函数" << std::endl;
        }

        dlclose(sourceHandle);
    } else {
        std::cout << "✗ 加载失败: " << dlerror() << std::endl;
    }

    // 测试加载 dcamera_sink.dylib
    std::cout << "\n[测试] 加载 dcamera_sink.dylib..." << std::endl;
    void* sinkHandle = dlopen("./libdcamera_sink.dylib", RTLD_LAZY);
    if (sinkHandle) {
        std::cout << "✓ 成功加载 dcamera_sink.dylib" << std::endl;
        dlclose(sinkHandle);
    } else {
        std::cout << "✗ 加载失败: " << dlerror() << std::endl;
    }

    std::cout << "\n=== 测试完成 ===" << std::endl;
    return 0;
}
