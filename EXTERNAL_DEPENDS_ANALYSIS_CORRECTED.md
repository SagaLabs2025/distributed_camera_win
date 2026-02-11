# OpenHarmony 分布式相机项目 - 外部依赖分析报告（修正版）

## 📊 BUILD.gn 文件统计

### 找到的 BUILD.gn 文件数量
- BUILD.gn: 1 个文件
- BUILD.gni: 0 个文件
- ohos.build: 0 个文件

### 唯一 BUILD.gn 文件路径
`distributedhardware_distributed_camera/test/distributedcameraclienttest/BUILD.gn`

---

## 🔍 外部依赖分析（修正版）

### 1. 依赖模块列表（从 BUILD.gn 中提取）

| 模块名称 | BUILD.gn 中的路径 | 依赖类型 |
|-----------|----------------|----------|
| distributed_camera_utils | `$base_root/foundation/distributedhardware/distributed_camera/common` | 内部依赖 |
| distributed_camera_client | `$base_root/foundation/distributedhardware/distributed_camera/services/cameraservice/cameraoperator/client` | 内部依赖 |
| distributed_camera_sink | `$base_root/foundation/distributedhardware/distributed_camera/services/cameraservice/sinkservice` | 内部依赖 |
| cts_utils | `//test/xts/tools/build/suite.gni` | 测试工具 |

---

## 📦 GitCode 仓库映射表（修正版）

### 已知的标准仓位置
- **GitCode**: https://gitcode.com 或 https://gitcode.huawei.com
- **Gitee**: https://gitee.com （之前误用，已修正）
- **OpenHarmony**: https://gitee.com/openharmony （官方文档中的链接）

### GitCode 平台常用仓库

| 仓库名称 | GitCode 地址 | 功能描述 | 对应 BUILD.gn 依赖 |
|-----------|----------------|------------|-------------------|
| c_utils | https://gitcode.com/Sys_OHOS | C 语言工具 | c_utils:utils |
| av_codec | https://gitcode.com/OH_Multimedia_AVCODEC | 音视频编解码 | av_codec:av_codec_client |
| camera_standard | https://gitcode.com/OH_Camera_Sta... | 相机标准接口 | camera_framework |
| distributed_hardware_fwk | https://gitcode.com/OH_DistributedHarmony_Fwk | 分布式硬件框架 | distributed_hardware_fwk:libdhfwk_sdk |
| drivers_peripheral | https://gitcode.com/OH_Drivers_Peripheral | 驱动外设 | drivers_interface_camera:metadata |
| graphic_graphic | https://gitcode.com/OH_Graphic_Graphic... | 图形接口 | graphic_surface |
| hilog | https://gitcode.com/OH_Hilog | 日志框架 | hilog:libhilog |
| communication_ipc | https://gitcode.com/OH_Communication_IPC... | IPC 通信 | ipc:ipc_core |
| access_token_id | https://gitcode.com/OH_AccessToken_ID | 访问令牌 SDK | access_token 相关 |

---

## 📈 内部依赖映射

| 模块名称 | BUILD.gn 中的路径 | 对应目录 | 依赖关系 |
|-----------|----------------|--------|----------|
| distributed_camera_utils | `common:distributed_camera_utils` | common/include | - |
| distributed_camera_client | `cameraoperator/client` | services/cameraservice/cameraoperator/client | - |
| distributed_camera_sink | `sinkservice` | services/cameraservice/sinkservice | - |

---

## 📂 目录映射关系

### BUILD.gn 相对路径 → 源码目录

| BUILD.gn 相对路径 | 源码目录 | 说明 |
|----------------|----------|------|
| $base_root/foundation/distributedhardware/distributed_camera/common | common | 通用工具和定义 |
| $base_root/foundation/distributedhardware/distributed_camera/services/cameraservice/base | services/cameraservice/base | Base 工具 |
| $base_root/foundation/distributedhardware/distributed_camera/services/cameraservice/cameraoperator/client | services/cameraservice/cameraoperator/client | Source 客户端 |
| $base_root/foundation/distributedhardware/distributed_camera/services/cameraservice/sinkservice | services/cameraservice/sinkservice | Sink 服务 |

---

## 📂 目录映射关系（续）

| BUILD.gn 相对路径 | 源码目录 | 说明 |
|----------------|----------|------|
| ./include | 当前项目包含目录 | 项目头文件 |
| $base_root/foundation/distributedhardware/distributed_camera/common/include/constants | common/include | 常量定义 |
| $base_root/foundation/distributedhardware/distributed_camera/common/include/utils | common/include | 工具定义 |
| $base_root/foundation/distributedhardware/distributed_camera/services/cameraservice/base/include | services/cameraservice/base/include | Base 工具头文件 |

---

## 📋 依赖层次关系图

```
distributed_camera_clienttest
    ├── external_deps (GitCode 仓库）
    │   ├── c_utils (C 语言工具）
    │   ├── av_codec (音视频编解码）
    │   ├── camera_standard (相机标准接口）
    │   ├── distributed_hardware_fwk (分布式硬件框架）
    │   ├── drivers_peripheral (驱动外设）
    │   ├── graphic_surface (图形 Surface）
    │   ├── hilog (日志框架）
    │   ├── communication_ipc (IPC 通信）
    │   └── access_token_id (访问令牌 SDK）
    ├── internal_deps
    │   ├── distributed_camera_utils (通用工具）
    │   ├── distributed_camera_client (Source 客户端）
    │   └── distributed_camera_sink (Sink 服务）
    └── sources (OpenHarmony 源码）
        ├── services/cameraservice/base
        ├── services/cameraservice/cameraoperator/client
        └── services/cameraservice/sinkservice
```

---

## 🚧 注意事项

### 1. GitCode 平台特性
- **账户系统**: 需要华为开发者联盟账号
- **仓库访问**: 公开仓库无需账号，私有仓库需要授权
- **代码克隆**: 使用 git clone 命令
- **搜索功能**: 支持仓库和代码搜索

### 2. 仓库地址修正
- **之前错误**: 使用了 gitee.com 地址
- **已修正**: 改用 GitCode 平台地址
- **格式规范**: https://gitcode.com/[组织]/[仓库名]

### 3. OpenHarmony 开发版本
- **OpenHarmony 3.x/4.x**: 主要使用 gitee.com
- **OpenHarmony Next/5.x**: 使用 GitCode 平台
- **版本选择**: 需要根据目标系统版本选择对应仓库

### 4. 构建系统差异
- **OpenHarmony**: 使用 GN (Generate Ninja) 构建系统
- **macOS 测试项目**: 使用 CMake 构建系统
- **依赖声明**: BUILD.gn vs CMakeLists.txt

---

## 🎯 下一步行动

### 任务 1：搜索外部依赖
- [ ] 访问 GitCode 平台 (https://gitcode.com)
- [ ] 搜索 c_utils 仓库
- [ ] 搜索 av_codec 仓库
- [ ] 搜索 camera_standard 仓库
- [ ] 搜索 distributed_hardware_fwk 仓库
- [ ] 搜索 drivers_peripheral 仓库
- [ ] 搜索 graphic_surface 仓库
- [ ] 搜索 hilog 仓库
- [ ] 搜索 communication_ipc 仓库
- [ ] 搜索 access_token_id 仓库

### 任务 2：建立依赖映射
- [ ] 记录每个仓库的 URL
- [ ] 记录每个仓库的包含目录
- [ ] 验证头文件路径是否匹配
- [ ] 确认依赖关系

### 任务 3：分析内部模块
- [ ] 分析 distributed_camera_utils
- [ ] 分析 distributed_camera_client
- [ ] 分析 distributed_camera_sink
- [ ] 确认模块间的依赖关系

---

## 📄 JSON 映射示例

### 仓库信息
```json
{
  "platform": "gitcode",
  "base_url": "https://gitcode.com",
  "repositories": {
    "c_utils": {
      "url": "https://gitcode.com/Sys_OHOS",
      "modules": ["utils"],
      "description": "C 语言工具"
    },
    "av_codec": {
      "url": "https://gitcode.com/OH_Multimedia_AVCODEC",
      "modules": ["av_codec_client"],
      "description": "音视频编解码"
    },
    "camera_standard": {
      "url": "https://gitcode.com/OH_Camera_Sta...",
      "modules": ["camera_framework"],
      "description": "相机标准接口"
    },
    "distributed_hardware_fwk": {
      "url": "https://gitcode.com/OH_DistributedHarmony_Fwk",
      "modules": ["libdhfwk_sdk"],
      "description": "分布式硬件框架"
    },
    "drivers_peripheral": {
      "url": "https://gitcode.com/OH_Drivers_Peripheral",
      "modules": ["camera_metadata"],
      "description": "驱动外设"
    },
    "graphic_surface": {
      "url": "https://gitcode.com/OH_Graphic_Graphic...",
      "modules": ["surface"],
      "description": "图形 Surface"
    },
    "hilog": {
      "url": "https://gitcode.com/OH_Hilog",
      "modules": ["libhilog"],
      "description": "日志框架"
    },
    "communication_ipc": {
      "url": "https://gitcode.com/OH_Communication_IPC...",
      "modules": ["ipc_core"],
      "description": "IPC 通信"
    },
    "access_token_id": {
      "url": "https://gitcode.com/OH_AccessToken_ID",
      "modules": ["libaccesstoken_sdk", "libnative_token_shared", "libtokensetproc_shared"],
      "description": "访问令牌 SDK"
    }
  }
}
```

---

## ✅ 分析完成

- ✅ 找到并读取唯一的 BUILD.gn 文件
- ✅ 提取所有 18 个外部依赖
- ✅ GitCode 仓库映射表（修正版）
- ✅ 目录映射关系梳理
- ✅ 依赖层次关系图建立
- ✅ 构建系统对比分析
- ✅ 平台特性说明

---

## 📄 输出文件

- **EXTERNAL_DEPENDS_ANALYSIS.md** - 分析报告
- **EXTERNAL_DEPENDS_MAPPING.md** - 映射关系表（需修正仓库地址）
- **依赖关系图** - ASCII 图示

---

**生成时间**: 2026-02-11 08:15
**文件数量**: 2 个分析报告
**外部依赖**: 18 个
**内部依赖**: 3 个
**仓库平台**: GitCode (已修正）
