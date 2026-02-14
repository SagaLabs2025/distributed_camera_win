# 快速开始指南

## 一键编译

```bash
./build.sh
```

就这么简单！

## 验证构建

```bash
./verify_build.sh
```

## 常用命令

| 命令 | 说明 |
|------|------|
| `./build.sh` | 普通编译 |
| `./build.sh -c` | 清理后重新编译 |
| `./build.sh -d` | Debug 模式编译 |
| `./build.sh -v` | 显示详细编译信息 |
| `./build.sh -j4` | 使用 4 个线程编译 |
| `./verify_build.sh` | 验证构建产物 |
| `make clean` | 清理构建产物 |

## 手动编译

```bash
# 1. 配置
cmake .

# 2. 编译
make -j8

# 3. 验证
./verify_build.sh
```

## 构建产物

编译成功后会生成：

```
libdcamera_source.dylib  (~715KB)  - Source 服务
libdcamera_sink.dylib    (~15KB)   - Sink 服务
libcjson.a               (~36KB)   - cJSON 库
```

## 检查符号

```bash
# Source 库
nm -gU libdcamera_source.dylib | grep DCameraSource

# Sink 库
nm -gU libdcamera_sink.dylib | grep DCameraSink
```

## 检查依赖

```bash
# Source 库
otool -L libdcamera_source.dylib

# Sink 库
otool -L libdcamera_sink.dylib
```

## 故障排除

### 找不到源码
```bash
export OHOS_DCAMERA_SOURCE_ROOT=/path/to/source
cmake .
make
```

### 编译失败
```bash
./build.sh -c  # 清理后重新编译
```

### 查看详细信息
```bash
./build.sh -v  # 显示详细编译输出
```

## 更多信息

- 详细文档：[BUILD.md](BUILD.md)
- 项目说明：[README.md](README.md)
- 任务列表：[tasks.md](.kiro/specs/mac-distributed-camera-build/tasks.md)

## 编译时间

- 首次完整编译：约 25-30 秒
- 增量编译：约 5-10 秒
- 清理后编译：约 25-30 秒

## 系统要求

- macOS 14.6+
- CMake 3.20+
- Xcode Command Line Tools
- 8GB+ RAM（推荐）

## 快速测试

```bash
# 完整流程
./build.sh -c && ./verify_build.sh

# 查看帮助
./build.sh -h
```

## 成功标志

看到以下输出表示编译成功：

```
==========================================
  ✓ 编译成功！
==========================================

构建产物已生成:
  • libdcamera_source.dylib - Source 服务
  • libdcamera_sink.dylib   - Sink 服务
  • libcjson.a              - cJSON 库
```

## 下一步

1. 运行 `./verify_build.sh` 验证构建
2. 查看 `BUILD.md` 了解更多细节
3. 开始集成到您的应用程序
