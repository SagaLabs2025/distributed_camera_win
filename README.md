# 分布式相机 macOS 测试工程

这是一个用于在 macOS 平台上编译和测试 OpenHarmony 分布式相机组件的项目。

## 快速开始

### 方法 1: 使用编译脚本（推荐）

```bash
# 普通编译
./build.sh

# 清理后重新编译
./build.sh -c

# Debug 模式编译
./build.sh -d

# 查看所有选项
./build.sh -h
```

### 方法 2: 手动编译

```bash
# 1. 配置 CMake
cmake .

# 2. 编译
make -j8

# 3. 验证
./verify_build.sh
```

## 验证构建

运行验证脚本检查构建产物：

```bash
./verify_build.sh
```

该脚本会检查：
- ✓ 构建产物是否存在
- ✓ 文件大小是否正常
- ✓ 符号导出是否正确
- ✓ 库依赖是否正确
- ✓ 架构信息

## 构建产物

成功编译后会生成：

| 文件 | 大小 | 说明 |
|------|------|------|
| `libdcamera_source.dylib` | ~2.8MB | Source 服务动态库 |
| `libdcamera_sink.dylib` | ~19KB | Sink 服务动态库 |
| `libcjson.a` | ~42KB | cJSON 静态库 |

## 目录结构

```
distributed_camera_test/
├── CMakeLists.txt          # CMake 配置文件
├── BUILD.md                # 详细编译文档
├── README.md               # 本文件
├── build.sh                # 快速编译脚本
├── verify_build.sh         # 构建验证脚本
├── src/                    # 入口点实现
│   ├── dcamera_source_dll.cpp
│   └── dcamera_sink_dll.cpp
└── stubs/                  # Mock 实现
    ├── headers/            # Stub 头文件
    └── src/                # Stub 实现文件
```

## 前置条件

1. **macOS 系统**（已在 macOS 14.6 上测试）
2. **CMake 3.20+**
   ```bash
   brew install cmake
   ```
3. **Xcode Command Line Tools**
   ```bash
   xcode-select --install
   ```
4. **OpenHarmony 源码**
   - 位置：`../distributedhardware_distributed_camera`
   - 或设置环境变量：`export OHOS_DCAMERA_SOURCE_ROOT=/path/to/source`
5. **外部依赖**
   - 位置：`../external`
   - 必需：c_utils、cJSON、distributed_hardware_fwk

## 常用命令

```bash
# 完整重新编译
./build.sh -c

# Debug 模式编译（包含调试符号）
./build.sh -d

# 清理构建产物
make clean

# 查看导出符号
nm -gU libdcamera_source.dylib | grep DCameraSource

# 查看库依赖
otool -L libdcamera_source.dylib

# 查看库信息
file libdcamera_source.dylib
```

## 编译选项

### Debug 模式
```bash
cmake -DCMAKE_BUILD_TYPE=Debug .
make
```
- 包含调试符号（-g）
- 禁用优化（-O0）
- 便于使用 lldb 调试

### Release 模式
```bash
cmake -DCMAKE_BUILD_TYPE=Release .
make
```
- 启用优化（-O2）
- 定义 NDEBUG 宏
- 生成更小的库文件

## 故障排除

### 找不到 OpenHarmony 源码
```bash
export OHOS_DCAMERA_SOURCE_ROOT=/path/to/distributedhardware_distributed_camera
cmake .
make
```

### 缺少外部依赖
确保 `../external` 目录包含：
- c_utils
- cJSON
- distributedhardware_distributed_hardware_fwk

### 编译错误
1. 清理后重新编译：`./build.sh -c`
2. 检查 CMake 输出的依赖检查信息
3. 查看详细编译信息：`./build.sh -v`

## 技术架构

### Stub 层设计
本项目使用 Stub/Mock 层来模拟 OpenHarmony 系统 API：
- **HiLog**: 日志系统 mock
- **IPC**: 进程间通信 mock
- **Softbus**: 软总线 mock
- **System Ability**: 系统能力 mock
- **Device Manager**: 设备管理 mock
- **Codec**: 编解码器 mock

所有 mock 实现返回成功值，用于编译测试。

### 编译统计
- 源文件数量：53 个
- OpenHarmony 源文件：24 个
- Stub mock 文件：29 个
- 编译时间：约 30-60 秒（首次完整编译）
- 增量编译：约 5-10 秒

## 文档

- [BUILD.md](BUILD.md) - 详细编译指南
- [tasks.md](.kiro/specs/mac-distributed-camera-build/tasks.md) - 任务列表
- [design.md](.kiro/specs/mac-distributed-camera-build/design.md) - 设计文档
- [requirements.md](.kiro/specs/mac-distributed-camera-build/requirements.md) - 需求文档

## 许可证

本项目遵循 OpenHarmony 项目的许可证。

## 贡献

欢迎提交 Issue 和 Pull Request。

## 联系方式

如有问题，请查看文档或提交 Issue。
