# OpenHarmony 源代码文件清单

本文档列出了需要包含到编译目标中的 OpenHarmony 源代码文件。

---

## 📋 文件统计

| 模块 | 文件数量 |
|------|---------|
| Base 工具 | 8 |
| Source Service | 29 |
| Sink Service | 11 |
| Common 工具 | 9 |
| **总计** | **57** |

---

## 🗂️ Base 工具（shared）

这些文件被 source 和 sink service 共享使用。

```
services/cameraservice/base/src/
├── dcamera_capture_info_cmd.cpp
├── dcamera_channel_info_cmd.cpp
├── dcamera_event_cmd.cpp
├── dcamera_info_cmd.cpp
├── dcamera_metadata_setting_cmd.cpp
├── dcamera_open_info_cmd.cpp
└── dcamera_sink_frame_info.cpp
```

---

## 📡 Source Service

### Service 层（5个文件）

```
services/cameraservice/sourceservice/src/distributedcamera/
├── dcamera_service_state_listener.cpp
├── dcamera_source_callback_proxy.cpp
├── dcamera_source_hidumper.cpp
├── distributed_camera_source_service.cpp
└── distributed_camera_source_stub.cpp
```

### Manager 层（3个文件）

```
services/cameraservice/sourceservice/src/distributedcameramgr/
├── dcamera_source_dev.cpp
├── dcamera_source_event.cpp
└── dcamera_source_service_ipc.cpp
```

### Controller 模块（2个文件）

```
services/cameraservice/sourceservice/src/distributedcameramgr/dcameracontrol/
├── dcamera_source_controller.cpp
└── dcamera_source_controller_channel_listener.cpp
```

### Data Process 模块（7个文件）

```
services/cameraservice/sourceservice/src/distributedcameramgr/dcameradata/
├── dcamera_source_data_process.cpp
├── dcamera_source_input.cpp
├── dcamera_source_input_channel_listener.cpp
├── dcamera_stream_data_process.cpp
├── dcamera_stream_data_process_pipeline_listener.cpp
├── dcamera_stream_data_process_producer.cpp
└── feeding_smoother_listener.cpp
```

### Feeding Smoother 模块（5个文件）

```
services/cameraservice/sourceservice/src/distributedcameramgr/dcameradata/feedingsmoother/
├── base/
│   ├── ifeeding_smoother.cpp
│   └── time_statistician.cpp
└── derived/
    ├── dcamera_feeding_smoother.cpp
    └── dcamera_time_statistician.cpp
```

### HDF 模块（1个文件）

```
services/cameraservice/sourceservice/src/distributedcameramgr/dcamerahdf/
└── dcamera_provider_callback_impl.cpp
```

### State Machine 模块（6个文件）

```
services/cameraservice/sourceservice/src/distributedcameramgr/dcamerastate/
├── dcamera_source_capture_state.cpp
├── dcamera_source_config_stream_state.cpp
├── dcamera_source_init_state.cpp
├── dcamera_source_opened_state.cpp
├── dcamera_source_regist_state.cpp
├── dcamera_source_state_factory.cpp
└── dcamera_source_state_machine.cpp
```

---

## 📺 Sink Service

### Service 层（3个文件）

```
services/cameraservice/sinkservice/src/distributedcamera/
├── dcamera_sink_callback_proxy.cpp
├── dcamera_sink_hidumper.cpp
├── distributed_camera_sink_service.cpp
└── distributed_camera_sink_stub.cpp
```

### Manager 层（8个文件）

```
services/cameraservice/sinkservice/src/distributedcameramgr/
├── callback/
│   ├── dcamera_sink_controller_state_callback.cpp
│   └── dcamera_sink_output_result_callback.cpp
├── dcamera_sink_access_control.cpp
├── dcamera_sink_controller.cpp
├── dcamera_sink_data_process.cpp
├── dcamera_sink_dev.cpp
├── dcamera_sink_output.cpp
└── dcamera_sink_service_ipc.cpp
```

---

## 🛠️ Common 工具

### Utils 模块（9个文件）

```
common/src/utils/
├── anonymous_string.cpp
├── data_buffer.cpp
├── dcamera_buffer_handle.cpp
├── dcamera_hidumper.cpp
├── dcamera_hisysevent_adapter.cpp
├── dcamera_hitrace_adapter.cpp
├── dcamera_radar.cpp
├── dcamera_utils_tools.cpp
└── dh_log.cpp
```

---

## 📝 CMakeLists.txt 配置建议

### dcamera_source 动态库

```cmake
set(DCAMERA_SOURCE_SOURCES
    # Base 工具
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_capture_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_channel_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_event_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_open_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_sink_frame_info.cpp

    # Source Service - Service 层
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/dcamera_service_state_listener.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/dcamera_source_callback_proxy.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/dcamera_source_hidumper.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/distributed_camera_source_service.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/distributed_camera_source_stub.cpp

    # Source Service - Manager 层
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamera_source_dev.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamera_source_event.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamera_source_service_ipc.cpp

    # Source Service - Controller 模块
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameracontrol/dcamera_source_controller.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameracontrol/dcamera_source_controller_channel_listener.cpp

    # Source Service - Data Process 模块
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/dcamera_source_data_process.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/dcamera_source_input.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/dcamera_source_input_channel_listener.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/dcamera_stream_data_process.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/dcamera_stream_data_process_pipeline_listener.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/dcamera_stream_data_process_producer.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/feedingsmoother/feeding_smoother_listener.cpp

    # Source Service - Feeding Smoother 模块
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/feedingsmoother/base/ifeeding_smoother.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/feedingsmoother/base/time_statistician.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/feedingsmoother/derived/dcamera_feeding_smoother.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/feedingsmoother/derived/dcamera_time_statistician.cpp

    # Source Service - HDF 模块
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamerahdf/dcamera_provider_callback_impl.cpp

    # Source Service - State Machine 模块
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamerastate/dcamera_source_capture_state.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamerastate/dcamera_source_config_stream_state.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamerastate/dcamera_source_init_state.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamerastate/dcamera_source_opened_state.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamerastate/dcamera_source_regist_state.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamerastate/dcamera_source_state_factory.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamerastate/dcamera_source_state_machine.cpp

    # Common 工具
    ${DCAMERA_SOURCE_DIR}/common/src/utils/anonymous_string.cpp
    ${DCAMERA_SOURCE_DIR}/common/src/utils/data_buffer.cpp
    ${DCAMERA_SOURCE_DIR}/common/src/utils/dcamera_buffer_handle.cpp
    ${DCAMERA_SOURCE_DIR}/common/src/utils/dcamera_hidumper.cpp
    ${DCAMERA_SOURCE_DIR}/common/src/utils/dcamera_radar.cpp
    ${DCAMERA_SOURCE_DIR}/common/src/utils/dcamera_utils_tools.cpp
)
```

### dcamera_sink 动态库

```cmake
set(DCAMERA_SINK_SOURCES
    # Base 工具
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_capture_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_channel_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_event_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_open_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_sink_frame_info.cpp

    # Sink Service - Service 层
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcamera/dcamera_sink_callback_proxy.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcamera/dcamera_sink_hidumper.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcamera/distributed_camera_sink_service.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcamera/distributed_camera_sink_stub.cpp

    # Sink Service - Manager 层
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/callback/dcamera_sink_controller_state_callback.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/callback/dcamera_sink_output_result_callback.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/dcamera_sink_access_control.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/dcamera_sink_controller.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/dcamera_sink_data_process.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/dcamera_sink_dev.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/dcamera_sink_output.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/dcamera_sink_service_ipc.cpp

    # Common 工具
    ${DCAMERA_SOURCE_DIR}/common/src/utils/anonymous_string.cpp
    ${DCAMERA_SOURCE_DIR}/common/src/utils/data_buffer.cpp
    ${DCAMERA_SOURCE_DIR}/common/src/utils/dcamera_buffer_handle.cpp
    ${DCAMERA_SOURCE_DIR}/common/src/utils/dcamera_hidumper.cpp
    ${DCAMERA_SOURCE_DIR}/common/src/utils/dcamera_radar.cpp
    ${DCAMERA_SOURCE_DIR}/common/src/utils/dcamera_utils_tools.cpp
)
```

---

## 🎯 编译策略

### 阶段 1：Base 工具（7个文件）
先编译基础工具类，验证基础功能。

### 阶段 2：Common 工具（9个文件）
添加 common 模块的通用工具。

### 阶段 3：Source Service 核心（8个文件）
添加 source service 的核心功能。

### 阶段 4：Source Service 完整（21个文件）
添加所有 source service 模块。

### 阶段 5：Sink Service（15个文件）
添加 sink service 所有文件。

每个阶段完成后，确保编译通过再继续下一阶段。

---

## 📌 注意事项

1. **排除测试文件**：所有 `test/` 目录下的文件不包含
2. **共享依赖**：Base 工具被 source 和 sink 共享，只需编译一次
3. **渐进式集成**：建议分阶段编译，每个阶段验证后再继续
4. **Mock 依赖**：确保所有 OpenHarmony 特定依赖都有对应的 Mock 实现
