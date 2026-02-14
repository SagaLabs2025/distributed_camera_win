# 设计文档

## 概述

本设计文档描述了OpenHarmony分布式相机系统的macOS构建和测试框架的技术架构。该框架通过CMake构建系统、Stub适配层和外部依赖管理，实现在macOS平台上编译OpenHarmony分布式相机源代码，生成libdcamera_source.dylib和libdcamera_sink.dylib两个动态库。

设计的核心原则：
1. **零侵入性**：不修改OpenHarmony源代码，所有适配在stub层完成
2. **API兼容性**：保持与OpenHarmony接口的完全兼容
3. **模块化**：清晰的层次结构，便于维护和扩展
4. **可测试性**：支持独立编译和测试各个组件

## 架构

### 系统层次结构

```
┌─────────────────────────────────────────────────────────┐
│                    动态库输出层                          │
│  libdcamera_source.dylib    libdcamera_sink.dylib      │
└─────────────────────────────────────────────────────────┘
                          ↑
┌─────────────────────────────────────────────────────────┐
│              OpenHarmony分布式相机源代码                 │
│  ├─ Base模块（命令和事件）                              │
│  ├─ SourceService（控制端服务）                         │
│  ├─ SinkService（被控端服务）                           │
│  ├─ 状态机（State Machine）                             │
│  ├─ 通道模块（Channel）                                 │
│  └─ 数据处理（Data Process）                            │
└─────────────────────────────────────────────────────────┘
                          ↑
┌─────────────────────────────────────────────────────────┐
│                  Stub适配层（macOS）                     │
│  ├─ HiLog Mock（日志系统）                              │
│  ├─ IPC Mock（进程间通信）                              │
│  ├─ System Ability Mock（系统能力）                     │
│  ├─ Device Manager Mock（设备管理）                     │
│  ├─ Softbus Mock（软总线）                              │
│  └─ Codec Mock（编解码器）                              │
└─────────────────────────────────────────────────────────┘
                          ↑
┌─────────────────────────────────────────────────────────┐
│              外部依赖（21个OpenHarmony仓库）             │
│  ├─ c_utils（基础工具）                                 │
│  ├─ communication_ipc（IPC框架）                        │
│  ├─ hiviewdfx_hilog（日志框架）                         │
│  ├─ systemabilitymgr_safwk（系统能力框架）             │
│  ├─ distributed_hardware_fwk（分布式硬件框架）          │
│  └─ ... （其他16个依赖）                                │
└─────────────────────────────────────────────────────────┘
                          ↑
┌─────────────────────────────────────────────────────────┐
│                  CMake构建系统                           │
│  ├─ 平台检测和编译器配置                                │
│  ├─ 依赖检查和路径解析                                  │
│  ├─ 源文件收集和编译                                    │
│  └─ 链接和产物生成                                      │
└─────────────────────────────────────────────────────────┘
```

### 数据流

```
开发者 → CMake配置 → 依赖检查 → 源文件编译 → Stub链接 → 动态库生成
                                    ↓
                            错误诊断和报告
```

## 组件和接口

### 1. CMake构建系统

**职责**：
- 检测macOS平台并配置Clang编译器
- 管理包含路径优先级（stubs > include > OHOS源码 > external）
- 收集和验证源文件
- 配置编译选项和链接库
- 生成构建产物

**关键配置**：
```cmake
# 平台宏定义
add_definitions(-D__APPLE__)
add_definitions(-D__MACOS__)
add_definitions(-DDCAMERA_LOCAL_TEST)
add_definitions(-DHI_LOG_ENABLE=0)

# C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 编译器标志
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
```

**包含路径优先级**：
1. `stubs/headers/hilog` - HiLog适配（最高优先级）
2. `stubs/headers` - 其他stub头文件
3. `external/` - 外部依赖头文件
4. OpenHarmony源码头文件
5. 源文件所在目录

**接口**：
- `cmake -B build` - 配置构建
- `cmake --build build` - 执行构建
- `cmake --build build --target install` - 安装产物
- `cmake --build build --target clean` - 清理产物

### 2. Stub适配层

**职责**：
- 提供OpenHarmony系统API的macOS兼容实现
- 返回模拟成功值用于编译和基本测试
- 记录API调用用于调试
- 保持API签名与OpenHarmony完全一致

**核心Stub模块**：

#### 2.1 HiLog Mock
```cpp
// distributed_hardware_log.h
#define DHLOGI(fmt, ...) printf("[INFO] " fmt "\n", ##__VA_ARGS__)
#define DHLOGW(fmt, ...) printf("[WARN] " fmt "\n", ##__VA_ARGS__)
#define DHLOGE(fmt, ...) printf("[ERROR] " fmt "\n", ##__VA_ARGS__)
#define DHLOGD(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
```

#### 2.2 IPC Mock
```cpp
// 模拟MessageParcel、MessageOption等IPC类型
class MessageParcel {
public:
    bool WriteInt32(int32_t value) { return true; }
    bool ReadInt32(int32_t& value) { value = 0; return true; }
    // ... 其他方法
};
```

#### 2.3 System Ability Mock
```cpp
// 模拟系统能力管理器
class SystemAbilityManagerClient {
public:
    static SystemAbilityManagerClient& GetInstance();
    sptr<IRemoteObject> GetSystemAbility(int32_t systemAbilityId);
};
```

#### 2.4 HiSysEvent Mock
```cpp
// dcamera_hisysevent_adapter.cpp
int32_t ReportDcameraInitFail(const std::string& dhId, int32_t errCode) {
    printf("[HiSysEvent] DCamera init fail: dhId=%s, errCode=%d\n", 
           dhId.c_str(), errCode);
    return 0;
}
```

**Stub设计原则**：
- 所有函数返回成功（0或true）
- 输出参数设置为合理默认值
- 记录关键调用用于调试
- 不实现实际业务逻辑

### 3. Source服务动态库

**职责**：
- 实现分布式相机控制端（SA 4803）
- 管理相机设备发现和连接
- 处理相机控制命令
- 管理HDF虚拟相机驱动

**包含模块**：
- Base模块：命令和事件定义
- SourceService：服务入口和IPC接口
- 状态机：设备状态管理
- 控制器：相机控制逻辑
- 数据输入：流数据处理
- HDF接口：虚拟相机驱动

**导出接口**：
```cpp
extern "C" {
    int32_t DCameraSourceInitialize();
    int32_t DCameraSourceCleanup();
}
```

**编译配置**：
```cmake
add_library(dcamera_source SHARED
    src/dcamera_source_dll.cpp
    ${DCAMERA_SOURCE_SOURCES}
)

target_compile_definitions(dcamera_source PRIVATE
    DH_LOG_TAG="dcamerasource"
    LOG_DOMAIN=0xD004150
)

target_link_libraries(dcamera_source PRIVATE c++ cjson)
```

### 4. Sink服务动态库

**职责**：
- 实现分布式相机被控端（SA 4804）
- 提供本地相机访问
- 处理远程控制命令
- 管理相机流传输

**包含模块**：
- Base模块：命令和事件定义
- SinkService：服务入口和IPC接口
- Camera Client：本地相机访问
- 数据处理：流编码和传输

**导出接口**：
```cpp
extern "C" {
    int32_t DCameraSinkInitialize();
    int32_t DCameraSinkCleanup();
}
```

**编译配置**：
```cmake
add_library(dcamera_sink SHARED
    src/dcamera_sink_dll.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/hilog_mock.cpp
)

target_compile_definitions(dcamera_sink PRIVATE
    DH_LOG_TAG="dcamerasink"
    LOG_DOMAIN=0xD004151
)

target_link_libraries(dcamera_sink PRIVATE c++ cjson)
```

### 5. 外部依赖管理

**依赖仓库列表**（21个）：
1. c_utils - 基础工具类
2. communication_ipc - IPC框架
3. hiviewdfx_hilog - 日志框架
4. systemabilitymgr_safwk - 系统能力框架
5. distributed_hardware_fwk - 分布式硬件框架
6. security_access_token - 访问令牌
7. multimedia_av_codec - 音视频编解码
8. resourceschedule_ffrt - 任务调度
9. systemabilitymgr_samgr - 系统能力管理
10. multimedia_media_foundation - 媒体基础
11. hiviewdfx_hitrace - 性能跟踪
12. communication_dsoftbus - 软总线
13. ability_ability_runtime - 能力运行时
14. device_manager - 设备管理
15. drivers_interface - 驱动接口
16. cJSON - JSON解析
17. ... （其他依赖）

**依赖检查机制**：
```cmake
if(EXISTS "${C_UTILS_INCLUDE_DIR}")
    message(STATUS "✓ 找到 c_utils: ${C_UTILS_INCLUDE_DIR}")
else()
    message(STATUS "✗ 未找到 c_utils，部分功能可能受限")
endif()
```

**依赖组织**：
```
../external/
├── c_utils/
│   └── base/include/
├── communication_ipc/
│   └── interfaces/innerkits/
├── hiviewdfx_hilog/
│   └── interfaces/native/kits/include/
├── distributed_hardware_fwk/
│   ├── common/utils/include/
│   └── av_transport/
└── ... (其他仓库)
```

### 6. 源文件组织

**Source服务源文件**：
```
Base模块：
- dcamera_capture_info_cmd.cpp
- dcamera_channel_info_cmd.cpp
- dcamera_event_cmd.cpp
- dcamera_info_cmd.cpp
- dcamera_open_info_cmd.cpp
- dcamera_sink_frame_info.cpp
- dcamera_metadata_setting_cmd.cpp

SourceService模块：
- dcamera_source_event.cpp
- dcamera_source_callback_proxy.cpp
- distributed_camera_source_stub.cpp
- dcamera_source_hidumper.cpp
- dcamera_source_dev.cpp
- dcamera_source_service_ipc.cpp

状态机模块：
- dcamera_source_state_machine.cpp
- dcamera_source_controller.cpp
- dcamera_source_input.cpp
- dcamera_stream_data_process.cpp

Common模块：
- anonymous_string.cpp
- dcamera_utils_tools.cpp
```

**源文件验证**：
```cmake
foreach(SOURCE_FILE ${DCAMERA_SOURCE_SOURCES})
    if(EXISTS "${SOURCE_FILE}")
        list(APPEND EXISTING_SOURCES "${SOURCE_FILE}")
    else()
        message(STATUS "源文件不存在，跳过: ${SOURCE_FILE}")
    endif()
endforeach()
```

## 数据模型

### 1. 相机命令模型

```cpp
// dcamera_info_cmd.h
class DCameraInfoCmd {
public:
    std::string dhId_;           // 设备ID
    std::string command_;        // 命令类型
    std::string value_;          // 命令参数
    
    std::string Marshal();       // 序列化为JSON
    int32_t Unmarshal(const std::string& jsonStr);  // 从JSON反序列化
};
```

### 2. 通道信息模型

```cpp
// dcamera_channel_info_cmd.h
class DCameraChannelInfoCmd {
public:
    std::string dhId_;
    std::string openInfo_;       // 打开信息
    std::string detail_;         // 详细信息
    
    std::string Marshal();
    int32_t Unmarshal(const std::string& jsonStr);
};
```

### 3. 事件模型

```cpp
// dcamera_event_cmd.h
class DCameraEventCmd {
public:
    std::string dhId_;
    int32_t eventType_;          // 事件类型
    std::string eventContent_;   // 事件内容
    
    std::string Marshal();
    int32_t Unmarshal(const std::string& jsonStr);
};
```

### 4. 帧信息模型

```cpp
// dcamera_sink_frame_info.h
class DCameraSinkFrameInfo {
public:
    int32_t width_;              // 帧宽度
    int32_t height_;             // 帧高度
    int32_t format_;             // 像素格式
    int64_t timestamp_;          // 时间戳
    
    std::string Marshal();
    int32_t Unmarshal(const std::string& jsonStr);
};
```

## 正确性属性

*属性是一个特征或行为，应该在系统的所有有效执行中保持为真——本质上是关于系统应该做什么的形式化陈述。属性作为人类可读规范和机器可验证正确性保证之间的桥梁。*


### 属性1：构建过程保持源代码不变性

*对于任何*构建操作（配置、编译、链接、清理），OpenHarmony源代码文件和外部依赖文件的内容应保持不变。

**验证需求：2.3, 5.4, 8.5**

### 属性2：Stub函数返回成功值

*对于任何*Stub层提供的模拟函数，当被调用时应返回表示成功的值（0、true或有效对象），除非该函数的语义明确要求返回失败。

**验证需求：4.1**

## 错误处理

### 1. 配置阶段错误

**缺失依赖处理**：
```cmake
if(NOT EXISTS "${OHOS_DCAMERA_SOURCE_ROOT}")
    message(WARNING "OpenHarmony源码目录不存在: ${OHOS_DCAMERA_SOURCE_ROOT}")
    message(FATAL_ERROR "无法继续构建，请设置正确的源码路径")
endif()

if(NOT EXISTS "${C_UTILS_INCLUDE_DIR}")
    message(STATUS "✗ 未找到 c_utils，部分功能可能受限")
    # 继续构建，但记录警告
endif()
```

**错误级别**：
- FATAL_ERROR：关键依赖缺失（OpenHarmony源码）
- WARNING：可选依赖缺失（部分external仓库）
- STATUS：信息性消息（依赖检查结果）

### 2. 编译阶段错误

**源文件缺失**：
```cmake
foreach(SOURCE_FILE ${DCAMERA_SOURCE_SOURCES})
    if(EXISTS "${SOURCE_FILE}")
        list(APPEND EXISTING_SOURCES "${SOURCE_FILE}")
    else()
        message(STATUS "源文件不存在，跳过: ${SOURCE_FILE}")
    endif()
endforeach()
```

**头文件缺失**：
- 编译器自动报告缺失的头文件
- 错误消息包含：缺失的头文件名、包含它的源文件、行号
- **重要约束**：当需要在stub中新增头文件时，必须先询问用户确认，不得自动添加

**编译警告**：
```cmake
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter")
```
- 启用大部分警告（-Wall -Wextra）
- 禁用未使用参数警告（-Wno-unused-parameter）
- 警告不阻止编译

### 3. 链接阶段错误

**未定义符号**：
- 链接器报告未定义的符号
- 建议检查：
  1. 是否缺少stub实现
  2. 是否缺少源文件
  3. 是否缺少链接库

**示例错误消息**：
```
Undefined symbols for architecture x86_64:
  "OHOS::DistributedHardware::SomeFunction()", referenced from:
      dcamera_source_dev.cpp.o
ld: symbol(s) not found for architecture x86_64

建议：检查stubs/src/目录是否包含SomeFunction的mock实现
```

### 4. 运行时错误

**库加载失败**：
```cpp
// 使用dlopen加载库
void* handle = dlopen("libdcamera_source.dylib", RTLD_LAZY);
if (!handle) {
    fprintf(stderr, "无法加载库: %s\n", dlerror());
    return -1;
}
```

**符号查找失败**：
```cpp
typedef int32_t (*InitFunc)();
InitFunc init = (InitFunc)dlsym(handle, "DCameraSourceInitialize");
if (!init) {
    fprintf(stderr, "无法找到初始化函数: %s\n", dlerror());
    dlclose(handle);
    return -1;
}
```

### 5. 错误恢复策略

**配置错误**：
1. 检查错误消息中的路径
2. 验证OHOS_DCAMERA_SOURCE_ROOT环境变量
3. 确认external目录结构
4. 重新运行cmake配置

**编译错误**：
1. 检查缺失的头文件
2. **如需添加stub头文件，先询问用户确认**
3. 添加必要的stub实现
4. 验证包含路径优先级
5. 检查C++标准兼容性

**链接错误**：
1. 添加缺失的stub函数实现
2. 检查函数签名是否匹配
3. 验证链接库配置
4. 使用nm命令检查符号

## 测试策略

### 1. 构建验证测试

**目标**：验证构建系统能够正确配置和编译

**测试用例**：
1. 完整构建测试
   - 前置条件：所有依赖就绪
   - 操作：运行cmake配置和构建
   - 验证：生成libdcamera_source.dylib和libdcamera_sink.dylib

2. 缺失依赖测试
   - 前置条件：移除某个external仓库
   - 操作：运行cmake配置
   - 验证：显示警告但配置成功

3. 增量构建测试
   - 前置条件：完整构建完成
   - 操作：修改一个源文件，重新构建
   - 验证：只重新编译受影响的文件

4. 清理测试
   - 前置条件：构建完成
   - 操作：运行clean目标
   - 验证：构建产物被删除，源文件完好

### 2. 平台兼容性测试

**目标**：验证在不同macOS版本上的兼容性

**测试环境**：
- macOS 12 (Monterey)
- macOS 13 (Ventura)
- macOS 14 (Sonoma)

**测试内容**：
- CMake配置成功
- 编译无错误
- 动态库可加载
- 基本功能可用

### 3. API兼容性测试

**目标**：验证stub实现与OpenHarmony接口兼容

**测试方法**：
1. 符号导出检查
   ```bash
   nm -g libdcamera_source.dylib | grep DCameraSource
   ```

2. 函数签名验证
   - 使用C++编译器的类型检查
   - 确保stub函数签名与OpenHarmony头文件匹配

3. 链接测试
   - 编写测试程序调用导出的API
   - 验证可以成功链接和调用

### 4. Stub功能测试

**目标**：验证stub实现提供正确的模拟行为

**测试用例**：
1. HiLog Mock测试
   ```cpp
   DHLOGI("Test message");
   // 验证：控制台输出包含"Test message"
   ```

2. IPC Mock测试
   ```cpp
   MessageParcel parcel;
   bool result = parcel.WriteInt32(42);
   // 验证：result为true
   ```

3. System Ability Mock测试
   ```cpp
   auto sam = SystemAbilityManagerClient::GetInstance();
   auto obj = sam.GetSystemAbility(4803);
   // 验证：obj不为nullptr
   ```

### 5. 错误处理测试

**目标**：验证错误情况下的正确行为

**测试用例**：
1. 缺失源文件
   - 从源文件列表中移除一个文件
   - 验证：显示警告消息，继续构建

2. 缺失头文件
   - 移除一个stub头文件
   - 验证：编译失败，显示清晰的错误消息

3. 链接失败
   - 移除一个stub实现
   - 验证：链接失败，报告未定义符号

### 6. 性能测试

**目标**：验证构建性能满足开发需求

**测试指标**：
1. 完整构建时间
   - 目标：< 5分钟（取决于机器性能）

2. 增量构建时间
   - 修改单个源文件：< 30秒
   - 修改头文件：< 2分钟

3. 配置时间
   - 目标：< 30秒

### 7. 文档测试

**目标**：验证文档的完整性和准确性

**测试内容**：
1. README存在性检查
2. 快速入门指南可执行性
3. 故障排除指南覆盖常见问题
4. Stub架构文档清晰度

### 测试执行流程

```
1. 环境准备
   ├─ 安装CMake 3.20+
   ├─ 安装Clang编译器
   ├─ 克隆OpenHarmony源码
   └─ 准备external依赖

2. 构建验证
   ├─ 运行cmake配置
   ├─ 检查配置输出
   ├─ 运行构建
   └─ 验证产物

3. 功能测试
   ├─ 加载动态库
   ├─ 调用导出函数
   └─ 验证返回值

4. 兼容性测试
   ├─ 检查符号导出
   ├─ 验证API签名
   └─ 测试链接

5. 错误场景测试
   ├─ 模拟各种错误
   ├─ 验证错误消息
   └─ 测试恢复流程

6. 性能测试
   ├─ 测量构建时间
   ├─ 测量增量构建
   └─ 分析瓶颈

7. 文档验证
   ├─ 检查文档完整性
   ├─ 验证示例可执行
   └─ 测试故障排除指南
```

### 测试自动化

**构建脚本**：
```bash
#!/bin/bash
# build_test.sh - 自动化构建测试脚本

set -e

echo "=== 清理旧构建 ==="
rm -rf build

echo "=== CMake配置 ==="
cmake -B build -DCMAKE_BUILD_TYPE=Debug

echo "=== 构建 ==="
cmake --build build

echo "=== 验证产物 ==="
if [ -f "build/libdcamera_source.dylib" ]; then
    echo "✓ libdcamera_source.dylib 生成成功"
else
    echo "✗ libdcamera_source.dylib 生成失败"
    exit 1
fi

if [ -f "build/libdcamera_sink.dylib" ]; then
    echo "✓ libdcamera_sink.dylib 生成成功"
else
    echo "✗ libdcamera_sink.dylib 生成失败"
    exit 1
fi

echo "=== 检查符号导出 ==="
nm -g build/libdcamera_source.dylib | grep DCameraSource

echo "=== 测试完成 ==="
```

**持续集成**：
- 使用GitHub Actions或类似CI系统
- 每次提交自动运行构建测试
- 定期运行完整测试套件
- 生成测试报告和覆盖率报告
