# OpenHarmony 分布式相机项目 - 外部依赖完整映射表

## 📦 基础信息

- **项目名称**: distributed_camera
- **源码路径**: /Users/donghuibin/Work/distributedhardware_distributed_camera
- **BUILD.gn 文件**: distributedhardware_distributed_camera/test/distributedcameraclienttest/BUILD.gn
- **分析时间**: 2026-02-11 08:00

---

## 🔍 BUILD.gn 外部依赖完整列表

### 1. 外部依赖（external_deps）

| 序号 | 模块名称 | BUILD.gn 路径 | 对应代码仓 | 仓类型 | 说明 |
|------|----------|------------|------------|--------|------|
| 1 | access_token | access_token:libaccesstoken_sdk | OpenHarmony-SIG | 访问令牌 SDK |
| 2 | access_token | access_token:libnativetoken_shared | OpenHarmony-SIG | 访问令牌 SDK (原生) |
| 3 | access_token | access_token:libtokensetproc_shared | OpenHarmony-SIG | 访问令牌 SDK (设置) |
| 4 | av_codec | av_codec:av_codec_client | av_codec | 音视频编解码 |
| 5 | c_utils | c_utils:utils | c_utils | C 语言通用工具 |
| 6 | camera_framework | camera_framework:camera_framework | camera_framework | 相机框架 |
| 7 | distributed_hardware_fwk | distributed_hardware_fwk:libdhfwk_sdk | distributed_hardware_fwk | 分布式硬件框架 |
| 8 | drivers_interface_camera | drivers_interface_camera:metadata | drivers_peripheral | 相机驱动接口 |
| 9 | graphic_surface | graphic_surface:surface | graphic_graphic | 图形 Surface |
| 10 | hilog | hilog:libhilog | hiview | 日志框架 |
| 11 | ipc | ipc:ipc_core | communication_ipc | IPC 通信 |

---

## 🗺️ 内部依赖（deps）

| 序号 | 模块名称 | BUILD.gn 路径 | 对应目录 | 依赖关系 |
|------|----------|------------|----------|--------|
| 1 | distributed_camera_utils | common:distributed_camera_utils | common/include | - |
| 2 | distributed_camera_client | cameraoperator/client | - | 依赖 common |
| 3 | distributed_camera_sink | sinkservice | - | 依赖 common |

---

## 📦 GitCode 仓库映射表

### OpenHarmony 标准仓（Gitee.com）

| 序号 | 仓库名称 | 仓库地址 | 功能描述 | 对应 BUILD.gn 依赖 |
|------|----------|------------|----------|-------------------|
| 1 | c_utils | https://gitee.com/openharmony/c_utils | C 语言工具 | c_utils:utils |
| 2 | av_codec | https://gitee.com/openharmony/av_codec | 音视频编解码 | av_codec:av_codec_client |
| 3 | camera_standard | https://gitee.com/openharmony/camera_standard | 相机标准接口 | camera_framework |
| 4 | distributed_hardware_fwk | https://gitee.com/openharmony/distributed_hardware_fwk | 分布式硬件框架 | distributed_hardware_fwk:libdhfwk_sdk |
| 5 | drivers_peripheral | https://gitee.com/openharmony/drivers_peripheral | 驱动外设 | drivers_interface_camera |
| 6 | graphic_graphic | https://gitee.com/openharmony/graphic_graphic | 图形接口 | graphic_surface |
| 7 | hiview | https://gitee.com/openharmony/hiview | 日志查看器 | hilog:libhilog |
| 8 | communication_ipc | https://gitee.com/openharmony/communication_ipc | IPC 通信 | ipc:ipc_core |

### OpenHarmony SIG 仓（gitee.com）

| 序号 | 仓库名称 | 仓库地址 | 功能描述 | 对应 BUILD.gn 依赖 |
|------|----------|------------|----------|-------------------|
| 1 | access_token_id | https://gitee.com/openharmony-sig/access_token_id | 访问令牌 | access_token 相关 |

### OpenHarmony 测试工具仓

| 序号 | 仓库名称 | 仓库地址 | 功能描述 | 对应 BUILD.gn 依赖 |
|------|----------|------------|----------|-------------------|
| 1 | cts_utils | //test/xts/tools/build/suite.gni | 测试工具 | cts_utils |

---

## 📂 目录映射关系

### BUILD.gn 路径 → 源码目录

| BUILD.gn 路径 | 源码目录 | 说明 |
|------------|----------|------|
| $base_root/foundation/distributedhardware/distributed_camera/common | common | 通用工具和定义 |
| $base_root/foundation/distributedhardware/distributed_camera/services/cameraservice/base | services/cameraservice/base | Base 工具 |
| $base_root/foundation/distributedhardware/distributed_camera/services/cameraservice/cameraoperator/client | services/cameraservice/cameraoperator/client | Source 客户端 |
| $base_root/foundation/distributedhardware/distributed_camera/services/cameraservice/sinkservice | services/cameraservice/sinkservice | Sink 服务 |

---

## 📋 依赖层次关系图

```
distributed_camera_clienttest
    ├── distributed_camera_utils (内部)
    ├── distributed_camera_client (内部)
    ├── distributed_camera_sink (内部)
    ├── access_token_id (外部)
    ├── c_utils (外部)
    ├── av_codec (外部)
    ├── camera_standard (外部)
    ├── distributed_hardware_fwk (外部)
    ├── drivers_interface_camera (外部)
    ├── graphic_surface (外部)
    ├── hilog (外部)
    ├── ipc_core (外部)
    └── cts_utils (测试工具)
```

---

## 🔧 构建系统

### OpenHarmony 构建系统
- **主构建系统**: GN (Generate Ninja)
- **配置文件**: BUILD.gn
- **构建输出**: .ninja 文件
- **依赖管理**: GN 声明式依赖

### macOS 测试项目构建系统
- **主构建系统**: CMake
- **配置文件**: CMakeLists.txt
- **构建输出**: Makefile
- **依赖管理**: CMake target_link_libraries

---

## 📖 Stub 策略建议

### 1. 最小化 Stub 实现
```cmake
# 只实现必要的接口，避免完整复现
add_definitions(-DDCAMERA_MACOS_MINIMAL_STUB)
```

### 2. 按模块分层 Stub
```cmake
# Base 模块
set(DCAMERA_STUB_DIR ${CMAKE_SOURCE_DIR}/stubs/base)
# Service 模块
set(DCAMERA_STUB_DIR ${CMAKE_SOURCE_DIR}/stubs/service)
# Framework 模块
set(DCAMERA_STUB_DIR ${CMAKE_SOURCE_DIR}/stubs/framework)
```

### 3. 依赖模块化
```cmake
# 独立的 stub 库
add_library(dcamera_stub_base ...)
add_library(dcamera_stub_service ...)
add_library(dcamera_stub_framework ...)
```

---

## ✅ 分析完成

- ✅ 完整的 BUILD.gn 外部依赖列表
- ✅ GitCode 仓库映射表
- ✅ 目录映射关系
- ✅ 依赖层次关系图
- ✅ 构建系统对比
- ✅ Stub 策略建议

---

**下一步行动**:
1. 使用映射表验证当前 stub 实现完整性
2. 根据缺失的依赖补充 stub 文件
3. 优化 CMakeLists.txt 的依赖管理
4. 考虑模块化 stub 库

---

**报告生成时间**: 2026-02-11 08:10
