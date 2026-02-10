# CLAUDE.md - 分布式相机测试工程

## 项目概述

这是 OpenHarmony 分布式相机的 macOS 模拟测试工程，用于在不依赖 OpenHarmony 物理设备的情况下，编译和测试分布式相机功能。

## 核心目标

1. **编译目标**: 将 OpenHarmony 分布式相机源码编译为 macOS 动态库
   - `libdcamera_source.dylib` - 源端（控制器）服务
   - `libdcamera_sink.dylib` - 接收端服务

2. **依赖策略**: 所有 OpenHarmony 系统依赖使用 Mock 方式解决
   - IPC 框架 → IRemoteBroker/IRemoteObject Mock
   - System Ability → SA 框架 Mock
   - 事件系统 → EventHandler Mock
   - HDF 接口 → V1_1 接口 Mock

3. **隔离原则**: 禁止修改 OpenHarmony 源码
   - 所有修改仅在 `stubs/` 目录
   - 源码通过相对路径引用: `../distributedhardware_distributed_camera`

## 目录结构

```
distributed_camera_test/
├── src/                    # 源文件（dylib 入口点）
├── include/                # 公共 API 头文件
├── adapters/               # 平台适配层
├── stubs/                  # OpenHarmony 系统 Mock
│   ├── headers/           # Mock 头文件（40+）
│   └── src/               # Mock 实现文件
├── tests/                  # 测试套件
├── scripts/                # 构建和测试脚本
├── docs/                   # 文档
├── cmake/                  # CMake 模块
├── external/               # 外部依赖
└── CMakeLists.txt          # 主构建配置
```

## 构建命令

### 快速构建
```bash
./build.sh                    # 标准构建
./build.sh --clean           # 清理并重新构建
```

### 手动构建
```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j$(sysctl -n hw.ncpu)
```

### 下载外部依赖
```bash
./scripts/setup_deps.sh      # 下载 c_utils 和 drivers_interface
./scripts/setup_deps.sh --force  # 强制重新下载
```

## 重要配置

### OpenHarmony 源码路径
- **环境变量**: `OHOS_DCAMERA_SOURCE_ROOT`
- **默认路径**: `../distributedhardware_distributed_camera`

### 编译宏
- `__APPLE__` - macOS 平台标志
- `__MACOS__` - macOS 平台标志
- `HI_LOG_ENABLE=0` - 禁用 HiLog，使用标准输出
- `DCAMERA_MACOS_MOCK` - Mock 模式标志
- `DCAMERA_SOURCE_EXPORTS` / `DCAMERA_SINK_EXPORTS` - 动态库导出

### Include 路径优先级
CMakeLists.txt 中，stubs/headers **必须**是第一个：
```cmake
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers  # 必须第一
    ...
)
```

## 开发规则

### 1. 禁止修改 OpenHarmony 源码
- ❌ 修改 `../distributedhardware_distributed_camera/` 下的文件
- ✅ 在 `stubs/` 目录创建 Mock 替代

### 2. Mock 实现原则
- 所有 Mock 实现返回成功（0）
- 保持 API 签名与 OpenHarmony 一致
- 使用 `#ifdef DCAMERA_MACOS_MOCK` 隔离 Mock 代码

### 3. 添加新 Stub
1. 在 `stubs/headers/` 创建头文件
2. 实现 Mock 类和函数
3. 更新 CMakeLists.txt 包含路径
4. 重新编译验证

## 关键文件说明

### CMakeLists.txt
- 主构建配置文件
- 定义源文件列表
- 配置 include 路径
- 设置编译选项和宏

### stubs/headers/
所有 OpenHarmony 系统 API 的 Mock 实现：
- `system_ability.h` - System Ability 框架
- `iremote_broker.h` - IPC 远程代理
- `event_handler.h` - 事件处理框架
- `v1_1/dcamera_types.h` - HDF 类型定义

### src/
动态库入口点：
- `dcamera_source_dll.cpp` - 源端 dylib 入口
- `dcamera_sink_dll.cpp` - 接收端 dylib 入口

## 测试

### 测试程序
```bash
# API 加载测试
./build/test_api_load

# Socket 通道测试
./build/test_socket_channel

# 虚拟相机测试
./build/test_virtual_camera
```

### 预期输出
- 成功编译 `libdcamera_source.dylib`
- 成功编译 `libdcamera_sink.dylib`
- 测试程序加载 dylib 并调用接口

## 故障排查

### 编译错误

1. **找不到头文件**
   - 检查 `OHOS_DCAMERA_SOURCE_ROOT` 是否正确
   - 检查 CMakeLists.txt include 路径

2. **链接错误**
   - 检查源文件是否存在
   - 检查 OpenHarmony 源码路径

3. **命名空间错误**
   - 检查 stub 文件命名空间定义
   - 确保使用 `OHOS::HDI::DistributedCamera::V1_1`

### 运行时错误

1. **dylib 加载失败**
   - 检查 `@rpath` 设置
   - 使用 `otool -L` 查看依赖

2. **符号未找到**
   - 检查导出宏定义
   - 使用 `nm` 查看符号表

## 相关资源

- [OpenHarmony 分布式硬件框架](https://gitee.com/openharmony/distributedhardware_distributed_hardware_fwk)
- [OpenHarmony 分布式相机](https://gitee.com/openharmony/distributedhardware_distributed_camera)
- [README.md](README.md) - 项目说明
- [FIX_PROGRESS_REPORT.md](FIX_PROGRESS_REPORT.md) - 编译修复进度
