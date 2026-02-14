# CLAUDE.md

## 项目概述

这是一个 **macOS 模拟框架**，用于 OpenHarmony 分布式相机系统的开发和测试。项目通过引用 OpenHarmony 源代码并创建必要的 mock 存根，在 macOS 上实现 Source（控制端，SA_ID=4803）和 Sink（被控端，SA_ID=4804）的分布式相机功能。

## 代码路径配置

### 1. OpenHarmony 源代码路径

**环境变量**: `OHOS_DCAMERA_SOURCE_ROOT`

**默认路径**:
```
../distributedhardware_distributed_camera
```
（相对于项目根目录的上一级）

**完整路径示例**:
```
/Users/donghuibin/Work/distributedhardware_distributed_camera
```

### 2. 外部依赖代码路径

**位置**: `/Users/donghuibin/Work/external/`

**相对路径**: `../external/`（相对于项目根目录）

## 目录结构

```
distributed_camera_test/              # 项目根目录
├── CLAUDE.md                          # 本文件（全局上下文约束）
├── CMakeLists.txt                     # 主构建配置
├── src/                               # 主要源代码实现
├── include/                           # 公共 API 头文件
├── adapters/                          # 平台特定适配器
├── stubs/                             # OpenHarmony 系统 mock
│   ├── headers/                       # Mock 头文件（优先级第2）
│   └── src/                           # Mock 实现
├── tests/                             # 测试套件
├── docs/                              # 文档
├── cmake/                             # CMake 模块
└── build/                             # 编译输出目录

external/                              # 外部依赖（优先级第1）
├── ability_ability_runtime/
├── c_utils/
├── cJSON/
├── communication_dsoftbus/
├── communication_ipc/
├── device_manager/
├── distributedhardware_distributed_hardware_fwk/
├── drivers_hdf_core/
├── drivers_interface/
├── graphic_surface/
├── hiviewdfx_hilog/
├── hiviewdfx_hicollie/
├── hiviewdfx_hitrace/
├── multimedia_av_codec/
├── multimedia_camera_framework/
├── multimedia_media_foundation/
├── resourceschedule_ffrt/
├── security_access_token/
├── systemabilitymgr_safwk/
├── systemabilitymgr_samgr/
└── ...（其他 17 个代码仓）

../distributedhardware_distributed_camera/  # OpenHarmony 源代码引用（优先级第3）
```

## 编译器定义

- `__APPLE__` - macOS 平台标志
- `__MACOS__` - macOS 平台标志
- `HI_LOG_ENABLE=0` - 禁用 HiLog，使用标准输出
- `DCAMERA_SOURCE_EXPORTS` / `DCAMERA_SINK_EXPORTS` - 动态库导出

## 重要约束

### 开发规则

1. **禁止修改 OpenHarmony 源代码** - 所有修复必须在 `stubs/` 目录中
2. **Mock 实现应返回成功（0）** - 用于模拟目的
3. **保持 API 兼容性** - 签名应与 OpenHarmony 匹配
4. **编译修复仅在 stubs 中** - 永不修改引用的源代码仓库

### Include 路径优先级

```cmake
target_include_directories(dcamera_source PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers    # MUST be first
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${OHOS_DCAMERA_SOURCE_ROOT}/...
    ${EXTERNAL_DIR}/...
)
```

优先级：**stubs/headers** > **include/** > **OHOS_DCAMERA_SOURCE_ROOT** > **external/**

## 依赖映射说明

BUILD.gn 中的 `external_deps` 映射到 external 文件夹中的代码仓：

| BUILD.gn 依赖 | 代码仓 | 位置 |
|--------------|--------|------|
| `access_token:*` | security_access_token | `../external/security_access_token/` |
| `av_codec:*` | multimedia_av_codec | `../external/multimedia_av_codec/` |
| `camera_framework:*` | multimedia_camera_framework | `../external/multimedia_camera_framework/` |
| `cJSON:cjson` | cJSON | `../external/cJSON/` |
| `c_utils:utils` | c_utils | `../external/c_utils/` |
| `device_manager:*` | device_manager | `../external/device_manager/` |
| `distributed_hardware_fwk:*` | distributedhardware_distributed_hardware_fwk | `../external/distributedhardware_distributed_hardware_fwk/` |
| `dsoftbus:*` | communication_dsoftbus | `../external/communication_dsoftbus/` |
| `eventhandler:*` | ability_ability_runtime | `../external/ability_ability_runtime/` |
| `ffrt:*` | resourceschedule_ffrt | `../external/resourceschedule_ffrt/` |
| `graphic_surface:*` | graphic_surface | `../external/graphic_surface/` |
| `hdf_core:*` | drivers_hdf_core | `../external/drivers_hdf_core/` |
| `hilog:*` | hiviewdfx_hilog | `../external/hiviewdfx_hilog/` |
| `hitrace:*` | hiviewdfx_hitrace | `../external/hiviewdfx_hitrace/` |
| `ipc:*` | communication_ipc | `../external/communication_ipc/` |
| `media_foundation:*` | multimedia_media_foundation | `../external/multimedia_media_foundation/` |
| `safwk:*` | systemabilitymgr_safwk | `../external/systemabilitymgr_safwk/` |
| `samgr:*` | systemabilitymgr_samgr | `../external/systemabilitymgr_samgr/` |

## 已下载的外部依赖

external 文件夹包含以下 OpenHarmony 代码仓：

| 序号 | 代码仓 | 说明 |
|------|--------|------|
| 1 | ability_ability_runtime | Ability 运行时（包含 EventHandler） |
| 2 | c_utils | C 工具库 |
| 3 | cJSON | JSON 解析库 |
| 4 | communication_dsoftbus | 分布式软总线 |
| 5 | communication_ipc | IPC/RPC 通信 |
| 6 | device_manager | 设备管理器 |
| 7 | distributedhardware_distributed_hardware_fwk | 分布式硬件框架核心 |
| 8 | drivers_hdf_core | HDF 驱动框架核心 |
| 9 | drivers_interface | HDI 接口定义 |
| 10 | graphic_surface | 图形 Surface 组件 |
| 11 | hiviewdfx_hicollie | 卡死检测框架 |
| 12 | hiviewdfx_hilog | 日志系统 |
| 13 | hiviewdfx_hitrace | 分布式追踪 |
| 14 | hiviewdfx_hitrace | 分布式追踪 |
| 15 | multimedia_av_codec | 音视频编解码 |
| 16 | multimedia_camera_framework | 相机框架 |
| 17 | multimedia_media_foundation | 媒体基础库 |
| 18 | resourceschedule_ffrt | 函数流运行时（并发编程） |
| 19 | security_access_token | 权限管理 |
| 20 | systemabilitymgr_safwk | 系统能力框架 |
| 21 | systemabilitymgr_samgr | 系统能力管理器 |

## 构建系统

使用 **CMake + Ninja** 构建：

### 构建
```bash
./build.sh                    # 标准构建
./build.sh --clean           # 清理并重建
```

### 手动构建
```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j$(sysctl -n hw.ncpu)
```

## 测试

使用 **Google Test (gtest)** 框架：

### 运行测试
```bash
# 构建测试
./build.sh

# 运行测试（需要先构建）
cd build/tests
./test_distributed_camera
```

## 主要组件

### Source Service (SA 4803)
- **入口**: `dcamera_source_dll.cpp`
- **核心服务**: `DistributedCameraSourceService`
- **数据通道**: 基于 SoftBus 的数据传输

### Sink Service (SA 4804)
- **入口**: `dcamera_sink_dll.cpp`
- **核心服务**: `DistributedCameraSinkService`
- **数据通道**: 基于 SoftBus 的数据传输

### 数据处理
- **数据处理管道**: 支持图像编解码、颜色空间转换、缩放、帧率调整、旋转
- **缓冲管理**: 统一的缓冲区分配和释放

## 版本信息

- **OpenHarmony**: 基于主分支
- **CMake**: 3.20+
- **C++ 标准**: C++17
- **平台**: macOS (Darwin)

## 重要文件

- **CMakeLists.txt**: 主构建配置
- **build.sh**: 标准构建脚本
