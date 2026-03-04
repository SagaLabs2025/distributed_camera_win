# 分布式相机 Source 目标源文件对比报告

**对比时间**：2026-02-25  
**对比对象**：
- 原始仓库：`distributedhardware_distributed_camera/services/cameraservice/sourceservice/BUILD.gn`
- 测试工程：`distributed_camera_test/CMakeLists.txt` 中的 `dcamera_source` 目标

---

## 📊 统计概览

| 项目 | 原始 BUILD.gn | 测试工程 CMakeLists.txt | 差异 |
|------|--------------|------------------------|------|
| **SourceService 源文件数** | 29 | 14 | -15 (-51.7%) |
| **Base 模块源文件数** | 5 | 7 | +2 |
| **Channel 模块源文件数** | 0 | 2 | +2 |
| **Common 模块源文件数** | 0 | 2 | +2 |
| **Stub 实现文件数** | 0 | 30+ | +30+ |

---

## ✅ 完全一致的文件（14个）

以下文件在两个目标中都存在：

### 1. DistributedCamera 基础服务模块（3个）
```
src/distributedcamera/dcamera_source_callback_proxy.cpp
src/distributedcamera/dcamera_source_hidumper.cpp
src/distributedcamera/distributed_camera_source_stub.cpp
```

### 2. DistributedCameraMgr 核心管理模块（3个）
```
src/distributedcameramgr/dcamera_source_dev.cpp
src/distributedcameramgr/dcamera_source_event.cpp
src/distributedcameramgr/dcamera_source_service_ipc.cpp
```

### 3. State Machine 状态机模块（2个）
```
src/distributedcameramgr/dcamerastate/dcamera_source_state_machine.cpp
src/distributedcameramgr/dcamerastate/dcamera_source_state_factory.cpp
```

### 4. Data Process 数据处理模块（5个）
```
src/distributedcameramgr/dcameradata/dcamera_source_data_process.cpp
src/distributedcameramgr/dcameradata/dcamera_source_input.cpp
src/distributedcameramgr/dcameradata/dcamera_source_input_channel_listener.cpp
src/distributedcameramgr/dcameradata/dcamera_stream_data_process.cpp
src/distributedcameramgr/dcameradata/dcamera_stream_data_process_pipeline_listener.cpp
```

### 5. HDF 模块（1个）
```
src/distributedcameramgr/dcamerahdf/dcamera_provider_callback_impl.cpp
```

---

## ❌ 原始中有但测试工程中缺失的文件（15个）

### 1. DistributedCamera 服务模块（2个）
```
❌ src/distributedcamera/dcamera_service_state_listener.cpp
   原因：依赖 iav_trans_control_center，已在 CMakeLists.txt 中注释禁用

❌ src/distributedcamera/distributed_camera_source_service.cpp
   原因：依赖太多 camera framework，已在 CMakeLists.txt 中注释禁用
```

### 2. Control 控制模块（2个）
```
❌ src/distributedcameramgr/dcameracontrol/dcamera_source_controller.cpp
   原因：API 版本不匹配，已在 CMakeLists.txt 中注释禁用

❌ src/distributedcameramgr/dcameracontrol/dcamera_source_controller_channel_listener.cpp
   原因：依赖 dcamera_source_controller.cpp，未包含
```

### 3. Data Process 数据处理模块（1个）
```
❌ src/distributedcameramgr/dcameradata/dcamera_stream_data_process_producer.cpp
   原因：NativeBuffer API 不匹配，已在 CMakeLists.txt 中注释禁用
```

### 4. FeedingSmoother 平滑处理模块（5个）
```
❌ src/distributedcameramgr/dcameradata/feedingsmoother/base/ifeeding_smoother.cpp
❌ src/distributedcameramgr/dcameradata/feedingsmoother/base/time_statistician.cpp
❌ src/distributedcameramgr/dcameradata/feedingsmoother/derived/dcamera_feeding_smoother.cpp
❌ src/distributedcameramgr/dcameradata/feedingsmoother/derived/dcamera_time_statistician.cpp
❌ src/distributedcameramgr/dcameradata/feedingsmoother/feeding_smoother_listener.cpp
   原因：整个 FeedingSmoother 模块未包含（可能是性能优化相关，非核心功能）
```

### 5. State 状态模块（5个）
```
❌ src/distributedcameramgr/dcamerastate/dcamera_source_capture_state.cpp
❌ src/distributedcameramgr/dcamerastate/dcamera_source_config_stream_state.cpp
❌ src/distributedcameramgr/dcamerastate/dcamera_source_init_state.cpp
❌ src/distributedcameramgr/dcamerastate/dcamera_source_opened_state.cpp
❌ src/distributedcameramgr/dcamerastate/dcamera_source_regist_state.cpp
   原因：具体状态实现类未包含，只保留了状态机和工厂类
```

---

## ➕ 测试工程中额外包含的文件

### 1. Base 模块（7个 vs 原始的5个）
测试工程包含了更多 Base 模块文件：
```
✅ base/src/dcamera_capture_info_cmd.cpp
✅ base/src/dcamera_channel_info_cmd.cpp
✅ base/src/dcamera_event_cmd.cpp
✅ base/src/dcamera_info_cmd.cpp
✅ base/src/dcamera_open_info_cmd.cpp
✅ base/src/dcamera_sink_frame_info.cpp          # 额外
✅ base/src/dcamera_metadata_setting_cmd.cpp     # 额外
```

### 2. Channel 模块（2个，原始中通过依赖引入）
```
✅ services/channel/src/dcamera_channel_source_impl.cpp
✅ services/channel/src/allconnect/distributed_camera_allconnect_manager.cpp
```

### 3. Common 工具模块（2个，原始中通过依赖引入）
```
✅ common/src/utils/anonymous_string.cpp
✅ common/src/utils/dcamera_utils_tools.cpp
```

### 4. Stub 实现（30+ 个，测试工程特有）
测试工程包含大量 macOS 平台的 stub 实现：
```
✅ stubs/src/dcamera_hisysevent_adapter.cpp
✅ stubs/src/hilog_mock.cpp
✅ stubs/src/hitrace_mock.cpp
✅ stubs/src/softbus_mock.cpp
✅ stubs/src/ipc_object_stub_mock.cpp
✅ stubs/src/ipc_object_stub_constructor_mock.cpp
✅ stubs/src/peer_holder_mock.cpp
✅ stubs/src/ipc_skeleton_mock.cpp
✅ stubs/src/iremote_object_mock.cpp
✅ stubs/src/message_parcel_mock.cpp
✅ stubs/src/data_buffer_mock.cpp
✅ stubs/src/dcamera_pipeline_source_mock.cpp
✅ stubs/src/access_token_kit_mock.cpp
✅ stubs/src/dcamera_stream_data_process_producer_mock.cpp
✅ stubs/src/distributed_camera_source_service_mock.cpp
✅ stubs/src/icamera_channel_mock.cpp
✅ stubs/src/weak_ref_counter_mock.cpp
✅ stubs/src/broker_registration_impl.cpp
✅ stubs/src/dcamera_radar_mock.cpp
✅ stubs/src/dcamera_softbus_session_mock.cpp
✅ stubs/src/dcamera_source_state_mock.cpp
✅ stubs/src/dcamera_source_controller_mock.cpp
✅ stubs/src/dcamera_hitrace_mock.cpp
✅ stubs/src/system_ability_manager_client_mock.cpp
✅ stubs/src/dcamera_hidumper_mock.cpp
✅ stubs/src/video_config_params_mock.cpp
✅ stubs/src/dcamera_softbus_adapter_mock.cpp
✅ stubs/src/dcamera_softbus_latency_mock.cpp
... 等等
```

---

## 🔍 详细分析

### 1. 核心功能覆盖率

| 模块 | 原始文件数 | 测试工程文件数 | 覆盖率 |
|------|-----------|--------------|--------|
| **基础服务** | 5 | 3 | 60% |
| **核心管理** | 3 | 3 | 100% ✅ |
| **状态机** | 7 | 2 | 28.6% |
| **控制模块** | 2 | 0 | 0% |
| **数据处理** | 6 | 5 | 83.3% |
| **HDF 模块** | 1 | 1 | 100% ✅ |
| **平滑处理** | 5 | 0 | 0% |

### 2. 缺失模块的影响

#### 高影响（核心功能）
- ❌ **distributed_camera_source_service.cpp**：主服务类，负责服务注册和生命周期管理
- ❌ **dcamera_source_controller.cpp**：相机控制器，负责相机操作控制
- ❌ **dcamera_service_state_listener.cpp**：服务状态监听器

#### 中影响（状态管理）
- ❌ **5个具体状态类**：状态机的具体状态实现（Init、Regist、Opened、ConfigStream、Capture）
- ❌ **dcamera_source_controller_channel_listener.cpp**：控制通道监听器

#### 低影响（性能优化）
- ❌ **FeedingSmoother 模块（5个文件）**：数据平滑处理，主要用于性能优化
- ❌ **dcamera_stream_data_process_producer.cpp**：数据生产者

### 3. 测试工程的设计策略

测试工程采用了以下策略：

1. **保留核心框架**：
   - ✅ 保留了状态机框架（state_machine + factory）
   - ✅ 保留了数据处理流程
   - ✅ 保留了 IPC 通信框架

2. **使用 Mock 替代**：
   - ✅ 用 mock 实现替代缺失的具体状态类
   - ✅ 用 mock 实现替代缺失的控制器
   - ✅ 用 mock 实现替代缺失的服务类

3. **简化非核心功能**：
   - ❌ 移除了 FeedingSmoother 性能优化模块
   - ❌ 移除了部分依赖 camera framework 的功能

4. **增强平台适配**：
   - ✅ 添加了大量 macOS 平台的 stub 实现
   - ✅ 添加了 Channel 和 Common 模块的直接引用

---

## 📋 结论

### 完全一致性评估：❌ 不完全一致

**一致的部分**（48.3%）：
- ✅ 14 个核心源文件完全一致
- ✅ 核心管理模块 100% 一致
- ✅ HDF 模块 100% 一致
- ✅ 数据处理模块 83.3% 一致

**不一致的部分**（51.7%）：
- ❌ 缺失 15 个原始源文件
- ❌ 缺失主服务类和控制器
- ❌ 缺失 5 个具体状态实现
- ❌ 缺失 FeedingSmoother 模块

**额外的部分**：
- ✅ 增加了 30+ 个 macOS 平台 stub 实现
- ✅ 增加了 Base、Channel、Common 模块的直接引用

### 功能完整性评估

| 功能类别 | 状态 | 说明 |
|---------|------|------|
| **编译通过** | ✅ | 可以成功编译生成 dylib |
| **核心框架** | ✅ | 状态机、数据处理、IPC 框架完整 |
| **服务注册** | ⚠️ | 主服务类被 mock，功能受限 |
| **相机控制** | ⚠️ | 控制器被 mock，功能受限 |
| **状态管理** | ⚠️ | 只有框架，具体状态被 mock |
| **性能优化** | ❌ | FeedingSmoother 模块缺失 |

### 适用场景

测试工程的 dcamera_source 目标适用于：
- ✅ **编译验证**：验证代码在 macOS 上可以编译
- ✅ **接口测试**：测试 IPC 接口和数据结构
- ✅ **框架验证**：验证核心框架设计
- ⚠️ **功能测试**：部分功能被 mock，无法完整测试
- ❌ **性能测试**：缺失性能优化模块

---

## 💡 建议

### 如果目标是编译验证（当前状态）
- ✅ 当前配置已经足够
- ✅ 可以验证代码在 macOS 上的编译兼容性

### 如果目标是功能测试
需要补充以下文件：
1. **高优先级**：
   - distributed_camera_source_service.cpp（或完善 mock）
   - dcamera_source_controller.cpp（或完善 mock）
   - 5 个具体状态类（或完善 mock）

2. **中优先级**：
   - dcamera_service_state_listener.cpp
   - dcamera_source_controller_channel_listener.cpp
   - dcamera_stream_data_process_producer.cpp

3. **低优先级**：
   - FeedingSmoother 模块（5个文件）

### 如果目标是性能测试
- 必须补充 FeedingSmoother 模块的所有文件

---

**报告生成时间**：2026-02-25  
**对比基准**：distributedhardware_distributed_camera (OpenHarmony 源码)  
**测试工程**：distributed_camera_test (macOS 移植版本)
