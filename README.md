# 分布式相机测试工程 (macOS)

## 项目概述

这是 OpenHarmony 分布式相机的 macOS 模拟测试工程，将 OpenHarmony 分布式相机源码编译为 macOS 动态库，用于功能测试和验证。

## 目录结构

```
distributed_camera_test/
├── src/                    # 源文件（dylib 入口点）
├── include/                # 公共 API 头文件
├── adapters/               # 平台适配层（FFmpeg、Socket、Virtual Camera）
├── stubs/                  # OpenHarmony 系统 Mock 实现
│   ├── headers/           # Mock 头文件（40+）
│   └── src/               # Mock 实现文件
├── tests/                  # 测试套件
├── scripts/                # 构建和测试脚本
├── docs/                   # 文档
├── cmake/                  # CMake 模块
├── external/               # 外部依赖
│   ├── c_utils/           # OpenHarmony C 工具库
│   └── drivers_interface/ # HDF 驱动接口
└── CMakeLists.txt          # 主构建配置
```

## 构建说明

### 前置要求

- macOS 10.15+
- Xcode Command Line Tools
- CMake 3.20+

### 快速构建

```bash
# 创建构建目录并编译
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j$(sysctl -n hw.ncpu)

# 输出动态库
# libdcamera_source.dylib
# libdcamera_sink.dylib
```

### 使用脚本构建

```bash
# 一键构建
./build.sh

# 清理并重新构建
./build.sh --clean
```

## 测试

```bash
# API 加载测试
./build/test_api_load

# Socket 通道测试
./build/test_socket_channel

# 虚拟相机测试
./build/test_virtual_camera
```

## 依赖说明

### OpenHarmony 源码

项目引用 OpenHarmony 分布式相机源码，路径：
- 环境变量: `OHOS_DCAMERA_SOURCE_ROOT`
- 默认: `../distributedhardware_distributed_camera`

### 外部依赖

- **c_utils**: OpenHarmony C 工具库
- **drivers_interface**: HDF 驱动接口定义

可通过以下命令下载：
```bash
./scripts/setup_deps.sh
```

## Mock 实现

本工程使用 Mock 方式解决 OpenHarmony 系统依赖：
- **IPC 框架**: IRemoteBroker, IRemoteObject
- **事件系统**: EventHandler, EventRunner
- **日志系统**: DHLog, HiLog
- **System Ability**: SA 框架
- **HDF 接口**: V1_1 分布式相机接口

所有 Mock 实现返回成功（0），用于模拟测试。

## 开发说明

### 添加新的 Mock 头文件

1. 在 `stubs/headers/` 创建头文件
2. 实现 Mock 类和函数（返回成功）
3. 更新 CMakeLists.txt 包含路径
4. 重新编译

### 编译规则

1. **禁止修改 OpenHarmony 源码**: 所有修改仅在 `stubs/` 目录
2. **保持 API 兼容**: Mock 签名必须与 OpenHarmony 一致
3. **Mock 返回成功**: 所有 Mock 实现 return 0

## 项目状态

- ✅ 项目结构恢复完成
- ✅ 40+ Stub 头文件创建
- ✅ 构建系统配置完成
- 🔄 待编译验证

## 相关文档

- [CLAUDE.md](CLAUDE.md) - Claude Code 工作指南
- [FIX_PROGRESS_REPORT.md](FIX_PROGRESS_REPORT.md) - 编译修复进度
- [TODO.md](TODO.md) - 待办事项

## 许可证

Apache License 2.0

## 参考资源

- [OpenHarmony 分布式硬件](https://gitee.com/openharmony/distributedhardware_distributed_hardware_fwk)
- [OpenHarmony 分布式相机](https://gitee.com/openharmony/distributedhardware_distributed_camera)
