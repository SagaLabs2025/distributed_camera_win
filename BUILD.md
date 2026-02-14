# 分布式相机 macOS 编译指南

## 前置条件

1. macOS 系统（已在 macOS 14.6 上测试）
2. CMake 3.20 或更高版本
3. Clang 编译器（Xcode Command Line Tools）
4. OpenHarmony 分布式相机源码
5. 外部依赖库（external 目录）

## 目录结构要求

```
workspace/
├── distributed_camera_test/          # 本项目
│   ├── CMakeLists.txt
│   ├── src/
│   ├── stubs/
│   └── ...
├── distributedhardware_distributed_camera/  # OpenHarmony 源码
│   ├── services/
│   ├── common/
│   └── ...
└── external/                          # 外部依赖
    ├── c_utils/
    ├── cJSON/
    ├── distributedhardware_distributed_hardware_fwk/
    └── ...
```

## 快速开始

### 1. 配置 CMake

```bash
cd distributed_camera_test
cmake .
```

CMake 会自动：
- 检测 macOS 平台
- 查找 OpenHarmony 源码（默认在 `../distributedhardware_distributed_camera`）
- 检查外部依赖（默认在 `../external`）
- 生成 Makefile

### 2. 编译

```bash
make
```

或者使用并行编译加速：

```bash
make -j8
```

### 3. 验证构建产物

编译成功后，会在当前目录生成：

```bash
ls -lh *.dylib *.a
```

应该看到：
- `libdcamera_source.dylib` - Source 服务动态库（约 2.8MB）
- `libdcamera_sink.dylib` - Sink 服务动态库（约 19KB）
- `libcjson.a` - cJSON 静态库（约 42KB）

### 4. 检查符号导出

```bash
# 检查 Source 库导出的符号
nm -gU libdcamera_source.dylib | grep DCameraSource

# 检查 Sink 库导出的符号
nm -gU libdcamera_sink.dylib | grep DCameraSink
```

应该看到：
- `DCameraSourceInitialize` - Source 初始化函数
- `DCameraSourceCleanup` - Source 清理函数
- `DCameraSinkInitialize` - Sink 初始化函数
- `DCameraSinkCleanup` - Sink 清理函数

### 5. 检查库依赖

```bash
# 检查 Source 库依赖
otool -L libdcamera_source.dylib

# 检查 Sink 库依赖
otool -L libdcamera_sink.dylib
```

应该只依赖系统库：
- `/usr/lib/libc++.1.dylib`
- `/usr/lib/libSystem.B.dylib`

## 清理构建产物

```bash
make clean
```

或者完全清理（包括 CMake 缓存）：

```bash
rm -rf CMakeFiles CMakeCache.txt cmake_install.cmake Makefile *.dylib *.a
```

## 自定义配置

### 指定 OpenHarmony 源码路径

如果源码不在默认位置，可以设置环境变量：

```bash
export OHOS_DCAMERA_SOURCE_ROOT=/path/to/distributedhardware_distributed_camera
cmake .
make
```

### Debug 模式编译

```bash
cmake -DCMAKE_BUILD_TYPE=Debug .
make
```

Debug 模式会：
- 包含调试符号（-g）
- 禁用优化（-O0）
- 便于使用 lldb 调试

### Release 模式编译

```bash
cmake -DCMAKE_BUILD_TYPE=Release .
make
```

Release 模式会：
- 启用优化（-O2）
- 定义 NDEBUG 宏
- 生成更小的库文件

## 常见问题

### 1. 找不到 OpenHarmony 源码

**错误信息：**
```
CMake Error: OpenHarmony 源码目录不存在
```

**解决方法：**
- 确保 `distributedhardware_distributed_camera` 目录存在
- 或设置 `OHOS_DCAMERA_SOURCE_ROOT` 环境变量

### 2. 缺少外部依赖

**错误信息：**
```
✗ 未找到 c_utils
✗ 未找到 cJSON
```

**解决方法：**
- 确保 `external` 目录存在
- 确保包含必需的依赖：c_utils、cJSON、distributed_hardware_fwk

### 3. 编译警告

某些格式警告是正常的，不影响构建：
```
warning: format specifies type 'int' but the argument has type 'size_t'
```

这些警告来自 OpenHarmony 源码，我们不修改源码。

### 4. 链接错误

如果遇到 "Undefined symbols" 错误：
- 检查是否所有 stub mock 文件都已添加到 CMakeLists.txt
- 确保 mock 实现的函数签名与源码调用匹配

## 增量编译

修改源文件后，只需运行：

```bash
make
```

CMake 会自动检测变化并只重新编译受影响的文件。

## 构建统计

当前配置：
- 源文件数量：53 个
- OpenHarmony 源文件：24 个
- Stub mock 文件：29 个
- 编译时间：约 30-60 秒（首次完整编译）
- 增量编译：约 5-10 秒

## 下一步

构建成功后，您可以：
1. 使用 `dlopen` 加载动态库
2. 调用 `DCameraSourceInitialize` 和 `DCameraSinkInitialize`
3. 进行功能测试
4. 集成到您的应用程序中

## 技术支持

如有问题，请检查：
1. CMake 配置输出（依赖检查部分）
2. 编译错误信息
3. tasks.md 中的任务状态
