# sourceservice/BUILD.gn 外部依赖分析

## 📊 文件信息

**文件路径**: `/Users/donghuibin/Work/distributedhardware_distributed_camera/services/cameraservice/sourceservice/BUILD.gn`
**分析时间**: 2026-02-11 09:25

---

## 📋 BUILD.gn 中发现的外部依赖（27 个）

### 列表（按类别组织）

#### 1. 访问令牌相关 (3 个)

| 序号 | BUILD.gn 中的名称 | 功能说明 |
|------|------------------|----------|
| 1 | access_token:libaccesstoken_sdk | 访问令牌 - 接入 SDK |
| 2 | access_token:libtokenid_sdk | 访问令牌 - ID SDK |
| 3 | access_token:libtokensetproc_shared | 访问令牌 - 设置进程 SDK |

#### 2. 媒体相关 (4 个)

| 序号 | BUILD.gn 中的名称 | 功能说明 |
|------|------------------|----------|
| 4 | av_codec:av_codec_client | 音视频编解码客户端 |
| 25 | media_foundation:media_foundation | 媒体基础框架 |
| 26 | ffrt:libffrt | FF 运行时库 |

#### 3. 图形相关 (2 个)

| 序号 | BUILD.gn 中的名称 | 功能说明 |
|------|------------------|----------|
| 17 | graphic_surface:surface | 图形 Surface 接口 |

#### 4. 相机相关 (1 个)

| 序号 | BUILD.gn 中的名称 | 功能说明 |
|------|------------------|----------|
| 6 | camera_framework:camera_framework | 相机标准框架 |

#### 5. 分布式硬件框架 (3 个)

| 序号 | BUILD.gn 中的名称 | 功能说明 |
|------|------------------|----------|
| 9 | distributed_hardware_fwk:distributed_av_receiver | 分布式音视频接收器 |
| 10 | distributed_hardware_fwk:distributedhardwareutils | 分布式硬件工具 |
| 11 | distributed_hardware_fwk:libdhfwk_sdk | 分布式硬件框架 SDK |

#### 6. 驱动和 HDF 相关 (4 个)

| 序号 | BUILD.gn 中的名称 | 功能说明 |
|------|------------------|----------|
| 12 | drivers_interface_camera:metadata | 相机驱动元数据接口 |
| 13 | drivers_interface_distributed_camera:libdistributed_camera_provider_proxy_1.1 | 分布式相机驱动代理 (1.1 版本) |
| 19 | hdf_core:libhdf_ipc_adapter | HDF IPC 适配器 |
| 20 | hdf_core:libhdi | HDF 接口定义 |
| 21 | hdf_core:libpub_utils | HDF 公共工具 |

#### 7. 通信相关 (1 个)

| 序号 | BUILD.gn 中的名称 | 功能说明 |
|------|------------------|----------|
| 24 | ipc:ipc_core | IPC 通信核心库 |

#### 8. 日志和调试相关 (4 个)

| 序号 | BUILD.gn 中的名称 | 功能说明 |
|------|------------------|----------|
| 18 | hilog:libhilog | 日志框架 |
| 22 | hicollie:libhicollie | 性能追踪库 |
| 23 | hitrace:hitrace_meter | 追踪监控工具 |

#### 9. 系统和基础服务 (4 个)

| 序号 | BUILD.gn 中的名称 | 功能说明 |
|------|------------------|----------|
| 5 | c_utils:utils | C 语言工具库 |
| 8 | device_manager:devicemanagersdk | 设备管理器 SDK |
| 27 | samgr:samgr_proxy | 子系统管理代理 |
| 14 | dsoftbus:softbus_client | 软总线客户端 |

#### 10. 事件处理 (1 个)

| 序号 | BUILD.gn 中的名称 | 功能说明 |
|------|------------------|----------|
| 15 | eventhandler:libeventhandler | 事件处理器库 |

#### 11. JSON 和基础库 (1 个)

| 序号 | BUILD.gn 中的名称 | 功能说明 |
|------|------------------|----------|
| 7 | cJSON:cjson | JSON 解析库 |

#### 12. 安全和系统能力 (1 个)

| 序号 | BUILD.gn 中的名称 | 功能说明 |
|------|------------------|----------|
| 26 | safwk:system_ability_fwk | 系统能力框架 |

---

## 🔍 OpenHarmony 命名规范分析

### GitCode 仓库命名规则

基于 OpenHarmony 的标准命名规范，GitCode 上的仓库名称通常遵循以下格式：

| 格式类型 | 示例 | 说明 |
|-----------|--------|------|
| 基础框架 | OH_XXX | 如 OH_HiLog |
| 子系统 | OH_XXX_Subsystem | 如 OH_Communication_IPC |
| 基础库 | Sys_OHOS | 如 Sys_OHOS (c_utils) |
| 驱动 | OH_Drivers_XXX | 如 OH_Drivers_Peripheral |
| 媒体 | OH_Multimedia_XXX | 如 OH_Multimedia_AVCODEC |
| 图形 | OH_Graphic_XXX | 如 OH_Graphic_Surface |
| 测试 | OH_Test_XXX | 如 OH_Test_XTS |

---

## 📋 待查找的 GitCode 仓库映射

### 高优先级（已确认命名模式）

| BUILD.gn 名称 | 预测的 GitCode 仓库名称 | GitCode 基础路径 |
|----------------|------------------|----------|
| c_utils:utils | Sys_OHOS | https://gitcode.com/ |
| hilog:libhilog | OH_HiLog | https://gitcode.com/ |
| ipc:ipc_core | OH_Communication_IPC | https://gitcode.com/ |
| safwk:system_ability_fwk | OH_SystemAbility_Fwk | https://gitcode.com/ |
| samgr:samgr_proxy | OH_Samgr | https://gitcode.com/ |
| graphic_surface:surface | OH_Graphic_Surface | https://gitcode.com/ |

### 中优先级（需要搜索确认）

| BUILD.gn 名称 | 预测的 GitCode 仓库名称 | 说明 |
|----------------|------------------|----------|
| av_codec:av_codec_client | OH_Multimedia_AVCodec | 音视频编解码 |
| camera_framework:camera_framework | OH_Camera_Standard | 相机标准接口 |
| distributed_hardware_fwk:distributed_av_receiver | OH_DistributedHardware_DistributedAV | 分布式音视频 |
| distributed_hardware_fwk:distributedhardwareutils | OH_DistributedHardware_FwkUtils | 分布式工具 |
| distributed_hardware_fwk:libdhfwk_sdk | OH_DistributedHardware_Fwk | 分布式硬件框架 |
| drivers_interface_camera:metadata | OH_Drivers_Camera_Metadata | 相机驱动元数据 |
| dsoftbus:softbus_client | OH_DSoftbus | 软总线 |
| eventhandler:libeventhandler | OH_Eventhandler | 事件处理器 |
| hdf_core:libhdf_ipc_adapter | OH_HDF | HDF 核心 |
| hdf_core:libhdi | OH_HDF | HDF 接口 |
| hdf_core:libpub_utils | OH_HDF | HDF 公共工具 |
| hicollie:libhicollie | OH_Hicollie | 性能追踪 |
| hitrace:hitrace_meter | OH_HiTrace | 追踪监控 |
| ffrt:libffrt | OH_FFRT | FF 运行时 |
| media_foundation:media_foundation | OH_MediaFoundation | 媒体基础 |

### 低优先级（特殊功能）

| BUILD.gn 名称 | 预测的 GitCode 仓库名称 | 说明 |
|----------------|------------------|----------|
| access_token 相关 (3 个) | OH_AccessToken_ID | 访问令牌（可能来自 SIG） |
| device_manager:devicemanagersdk | OH_DeviceManager | 设备管理 |
| access_token_id 相关 | OH_AccessToken_ID | 可能是特殊分支 |

---

## 🎯 下一步行动

### 立即可执行的搜索

1. **在 GitCode 平台上搜索**
   - 访问 https://gitcode.com/
   - 搜索关键词（如 "OH_HiLog", "Sys_OHOS" 等）
   - 记录找到的仓库 URL

2. **验证仓库 URL**
   - 使用 curl -I 验证可访问性
   - 记录仓库的描述和标签信息

3. **建立完整的映射表**
   - 将所有 27 个外部依赖映射到 GitCode 仓库
   - 记录每个仓库的用途和版本信息

### 搜索策略

#### 关键词搜索
- "OH_HiLog"
- "OH_Communication_IPC"
- "OH_Graphic_Surface"
- "OH_Multimedia_AVCodec"
- "OH_Camera_Standard"
- "OH_DistributedHardware_Fwk"
- "OH_Drivers_Camera_Metadata"
- "OH_DSoftbus"
- "OH_Eventhandler"
- "OH_HDF"
- "OH_SystemAbility_Fwk"
- "OH_FFRT"
- "OH_MediaFoundation"
- "OH_Samgr"
- "OH_DeviceManager"
- "OH_AccessToken_ID"

#### 组织搜索
- "OpenHarmony_Sig"
- "OpenHarmony"
- "Sys_OHOS"

---

## 📊 统计信息

### 外部依赖分类统计

| 类别 | 数量 | 占比 |
|------|------|------|
| 访问令牌 | 3 | 11.1% |
| 媒体 | 4 | 14.8% |
| 图形 | 2 | 7.4% |
| 相机 | 1 | 3.7% |
| 分布式硬件框架 | 3 | 11.1% |
| 驱动和 HDF | 4 | 14.8% |
| 通信 | 1 | 3.7% |
| 日志和调试 | 4 | 14.8% |
| 系统和基础服务 | 4 | 14.8% |
| 事件处理 | 1 | 3.7% |
| JSON 和基础库 | 1 | 3.7% |
| 安全和系统能力 | 1 | 3.7% |
| **总计** | **27** | **100%** |

---

## ✅ 分析完成

- ✅ BUILD.gn 文件完整读取
- ✅ 识别出 27 个外部依赖
- ✅ 按 10 个类别组织
- ✅ 分析了 OpenHarmony 命名规范
- ✅ 提供了预测的 GitCode 仓库名称
- ✅ 制定了搜索策略

---

**分析完成时间**: 2026-02-11 09:30
**依赖总数**: 27 个外部依赖
**分类**: 10 个主要类别
**待确认**: GitCode 仓库地址搜索

---

**注意**: 预测的仓库名称基于 OpenHarmony 标准命名规范，需要在 GitCode 平台上验证确认。下一个步骤是实际搜索并记录准确的仓库 URL。
