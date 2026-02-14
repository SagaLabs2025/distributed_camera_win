cmake_minimum_required(VERSION 3.20)
project(distributed_camera_test VERSION 1.0.0 LANGUAGES C CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 平台检测
if(NOT APPLE)
    message(FATAL_ERROR "此项目仅支持 macOS 平台")
endif()

message(STATUS "检测到平台: macOS (${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION})")
message(STATUS "编译器: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

# 设置编译选项
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter")
    # Force include std_compat.h to ensure standard headers are included early
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers/std_compat.h")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -DNDEBUG")
else()
    message(WARNING "推荐使用 Clang 编译器，当前编译器: ${CMAKE_CXX_COMPILER_ID}")
endif()

# 定义平台宏
add_definitions(-D__APPLE__)
add_definitions(-D__MACOS__)
add_definitions(-DHI_LOG_ENABLE=0)
add_definitions(-DDCAMERA_LOCAL_TEST)  # 分布式相机本地模拟测试

# 使用源码中的类型和常量定义（优先于 stub 中的定义）
add_definitions(-DUSE_SOURCE_DEFINITIONS=true)

# 取消 external 库中可能冲突的宏定义（如 avcodec_info.h 中的 max）
add_definitions(-Dmax=)

# 设置 OpenHarmony 源码根目录
if(NOT DEFINED OHOS_DCAMERA_SOURCE_ROOT)
    set(OHOS_DCAMERA_SOURCE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../distributedhardware_distributed_camera")
endif()

if(NOT EXISTS "${OHOS_DCAMERA_SOURCE_ROOT}")
    message(FATAL_ERROR "OpenHarmony 源码目录不存在: ${OHOS_DCAMERA_SOURCE_ROOT}\n"
                        "请设置 OHOS_DCAMERA_SOURCE_ROOT 环境变量或确保源码在默认位置")
endif()

message(STATUS "OpenHarmony 源码根目录: ${OHOS_DCAMERA_SOURCE_ROOT}")

# 外部依赖目录（移到项目上一级目录，与源代码仓同级）
set(EXTERNAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../external")
set(C_UTILS_INCLUDE_DIR "${EXTERNAL_DIR}/c_utils/base/include")
set(DRIVERS_INTERFACE_DIR "${EXTERNAL_DIR}/drivers_interface")
set(CJSON_DIR "${EXTERNAL_DIR}/cJSON")
set(CJSON_INCLUDE_DIR "${CJSON_DIR}")

# External 依赖头文件路径（优先使用 external 中的头文件）
set(DH_FWK_INCLUDE_DIR "${EXTERNAL_DIR}/distributedhardware_distributed_hardware_fwk")
set(DH_FWK_LOG_INCLUDE "${DH_FWK_INCLUDE_DIR}/common/log/include")
set(DH_FWK_UTILS_INCLUDE "${DH_FWK_INCLUDE_DIR}/common/utils/include")
set(IPC_CORE_INCLUDE "${EXTERNAL_DIR}/communication_ipc/interfaces/innerkits/ipc_core/include")
set(SAFWK_INCLUDE "${EXTERNAL_DIR}/systemabilitymgr_safwk/services/safwk/include")
set(HILOG_INCLUDE "${EXTERNAL_DIR}/hiviewdfx_hilog/interfaces/native/kits/include")

# 验证外部依赖
message(STATUS "")
message(STATUS "========== 外部依赖检查 ==========")

set(DEPENDENCY_CHECK_PASSED TRUE)

# 关键依赖检查（必须存在）
if(EXISTS "${C_UTILS_INCLUDE_DIR}")
    message(STATUS "✓ 找到 c_utils: ${C_UTILS_INCLUDE_DIR}")
else()
    message(STATUS "✗ 未找到 c_utils")
    set(DEPENDENCY_CHECK_PASSED FALSE)
endif()

if(EXISTS "${CJSON_INCLUDE_DIR}/cJSON.h")
    message(STATUS "✓ 找到 cJSON: ${CJSON_INCLUDE_DIR}")
else()
    message(STATUS "✗ 未找到 cJSON")
    set(DEPENDENCY_CHECK_PASSED FALSE)
endif()

if(EXISTS "${DH_FWK_INCLUDE_DIR}")
    message(STATUS "✓ 找到 distributed_hardware_fwk: ${DH_FWK_INCLUDE_DIR}")
else()
    message(STATUS "✗ 未找到 distributed_hardware_fwk")
    set(DEPENDENCY_CHECK_PASSED FALSE)
endif()

# 可选依赖检查（警告但不阻止构建）
set(OPTIONAL_DEPS
    "${EXTERNAL_DIR}/communication_ipc"
    "${EXTERNAL_DIR}/hiviewdfx_hilog"
    "${EXTERNAL_DIR}/systemabilitymgr_safwk"
    "${EXTERNAL_DIR}/systemabilitymgr_samgr"
    "${EXTERNAL_DIR}/security_access_token"
    "${EXTERNAL_DIR}/multimedia_av_codec"
    "${EXTERNAL_DIR}/multimedia_media_foundation"
    "${EXTERNAL_DIR}/multimedia_camera_framework"
    "${EXTERNAL_DIR}/resourceschedule_ffrt"
    "${EXTERNAL_DIR}/hiviewdfx_hitrace"
    "${EXTERNAL_DIR}/communication_dsoftbus"
    "${EXTERNAL_DIR}/ability_ability_runtime"
    "${EXTERNAL_DIR}/device_manager"
    "${EXTERNAL_DIR}/drivers_interface"
    "${EXTERNAL_DIR}/drivers_hdf_core"
    "${EXTERNAL_DIR}/graphic_surface"
    "${EXTERNAL_DIR}/graphic_utils"
    "${EXTERNAL_DIR}/idl_conversion"
)

set(OPTIONAL_DEPS_FOUND 0)
set(OPTIONAL_DEPS_MISSING 0)

foreach(DEP_PATH ${OPTIONAL_DEPS})
    get_filename_component(DEP_NAME ${DEP_PATH} NAME)
    if(EXISTS "${DEP_PATH}")
        math(EXPR OPTIONAL_DEPS_FOUND "${OPTIONAL_DEPS_FOUND} + 1")
    else()
        message(STATUS "⚠ 未找到可选依赖: ${DEP_NAME}")
        math(EXPR OPTIONAL_DEPS_MISSING "${OPTIONAL_DEPS_MISSING} + 1")
    endif()
endforeach()

message(STATUS "")
message(STATUS "依赖统计: ${OPTIONAL_DEPS_FOUND} 个可选依赖可用, ${OPTIONAL_DEPS_MISSING} 个缺失")
message(STATUS "")
if(OPTIONAL_DEPS_MISSING GREATER 0)
    message(STATUS "提示: 缺失的可选依赖不会影响编译，但可能导致某些功能受限")
    message(STATUS "      如需完整功能，请确保所有依赖仓库都已克隆到 ${EXTERNAL_DIR}")
endif()
message(STATUS "==================================")
message(STATUS "")

if(NOT DEPENDENCY_CHECK_PASSED)
    message(FATAL_ERROR "关键依赖缺失，无法继续构建。请检查 external 目录")
endif()

# 源码头文件目录
set(DCAMERA_SOURCE_DIR "${OHOS_DCAMERA_SOURCE_ROOT}")
set(DCAMERA_INCLUDE_DIR "${DCAMERA_SOURCE_DIR}/interfaces/innerkits/camera_source_sdk/include")
set(DCAMERA_COMMON_INCLUDE "${DCAMERA_SOURCE_DIR}/common/include")
set(SOFTBUS_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers")

# 正确的源文件路径（相对于 OHOS_DCAMERA_SOURCE_ROOT）
set(DCAMERA_SERVICE_DIR "${DCAMERA_SOURCE_DIR}/services/cameraservice")

# 包含目录
# 注意：按照全局规则，优先级顺序为：
# 1. external 依赖头文件（优先）
# 2. OpenHarmony 源码头文件
# 3. stubs 头文件（仅包含不重复的必要文件）

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/adapters
    ${CMAKE_SOURCE_DIR}/include

    # 0. Stub 特定适配层（最优先 - macOS 平台特定适配）
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers/hilog
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers

    # 1. External 依赖头文件（优先 - 使用真实的类型定义和接口）
    ${EXTERNAL_DIR}/idl_conversion  # iav_trans_control_center_callback.h 所在目录
    ${C_UTILS_INCLUDE_DIR}
    ${EXTERNAL_DIR}/c_utils/base/src  # event_handler.h 所在目录
    ${IPC_CORE_INCLUDE}
    ${EXTERNAL_DIR}/hiviewdfx_hilog/interfaces/native/kits/include
    ${SAFWK_INCLUDE}
    ${DH_FWK_UTILS_INCLUDE}
    ${EXTERNAL_DIR}/communication_ipc/interfaces/innerkits/ipc_core/include
    ${EXTERNAL_DIR}/communication_ipc/interfaces/innerkits/native/include/ipc
    ${EXTERNAL_DIR}/security_access_token/interfaces/innerkits/accesstoken/include
    ${EXTERNAL_DIR}/multimedia_av_codec/interfaces/inner_api/native
    ${EXTERNAL_DIR}/distributedhardware_distributed_hardware_fwk/av_transport/common/include  # av_trans_types.h
    ${EXTERNAL_DIR}/distributedhardware_distributed_hardware_fwk/av_transport/av_trans_control_center/inner_kits/include  # av_trans_control_center_callback.h（必须在 common/utils 之前）
    ${EXTERNAL_DIR}/distributedhardware_distributed_hardware_fwk/common/utils/include  # idistributed_hardware.h (需要上面的回调)
    ${EXTERNAL_DIR}/distributedhardware_distributed_hardware_fwk/interfaces/inner_kits/include  # distributed_hardware_fwk_kit.h
    ${EXTERNAL_DIR}/resourceschedule_ffrt/interfaces/inner_api  # ffrt_inner.h
    ${EXTERNAL_DIR}/systemabilitymgr_samgr/interfaces/innerkits/samgr_proxy/include
    ${EXTERNAL_DIR}/multimedia_media_foundation/interface/inner_api
    ${EXTERNAL_DIR}/multimedia_media_foundation/interface/inner_api/meta
    ${EXTERNAL_DIR}/multimedia_media_foundation/interface/inner_api/buffer
    ${EXTERNAL_DIR}/hiviewdfx_hitrace/interfaces/innerkits/native/include
    ${EXTERNAL_DIR}/hiviewdfx_hitrace/interfaces/native/innerkits/include/hitrace_meter  # hitrace_meter.h
    ${EXTERNAL_DIR}/communication_dsoftbus/interfaces/kits/native
    ${EXTERNAL_DIR}/communication_dsoftbus/interfaces/kits/bus_center  # softbus_bus_center.h
    ${EXTERNAL_DIR}/communication_dsoftbus/interfaces/kits/common  # softbus_common.h
    ${EXTERNAL_DIR}/communication_dsoftbus/interfaces/kits/transport  # trans_type.h, socket.h
    ${EXTERNAL_DIR}/communication_dsoftbus/interfaces/kits  # transport/trans_type.h parent directory
    ${EXTERNAL_DIR}/ability_ability_runtime/interfaces/innerkits/eventhandler/include
    ${EXTERNAL_DIR}/resourceschedule_ffrt/interfaces/kits
    ${EXTERNAL_DIR}/device_manager/interfaces/inner_kits/native/include
    ${EXTERNAL_DIR}/device_manager/interfaces/inner_kits/native_cpp/include  # device_manager.h
    ${EXTERNAL_DIR}/drivers_hdf_core/interfaces/inner_api/ipc  # iproxy_broker.h
    ${EXTERNAL_DIR}/graphic_surface/interfaces/kits  # surface.h
    ${EXTERNAL_DIR}/graphic_utils/interfaces/kits  # gfx_utils/pixel_format_utils.h
    ${EXTERNAL_DIR}/multimedia_camera_framework/interfaces/inner_api/native/camera/include  # camera_info.h parent
    ${EXTERNAL_DIR}/multimedia_camera_framework/interfaces/inner_api/native/camera/include/input  # camera_info.h

    # 2. OpenHarmony 源码头文件
    ${CJSON_INCLUDE_DIR}
    ${DCAMERA_INCLUDE_DIR}
    ${DCAMERA_COMMON_INCLUDE}
    ${DCAMERA_COMMON_INCLUDE}/constants    # distributed_camera_errno.h 所在目录
    ${DCAMERA_COMMON_INCLUDE}/utils       # dh_log.h 所在目录
    ${DCAMERA_SOURCE_DIR}/services/channel/include  # icamera_channel_listener.h 所在目录
    ${DCAMERA_SOURCE_DIR}/services/channel/include/allconnect  # dcamera_collaboration_manager_capi.h 所在目录
    ${DCAMERA_SERVICE_DIR}/base/include
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcamera
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcameramgr
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcameramgr/dcamerahdf  # dcamerahdf 目录
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcameramgr/dcameradata  # dcamera_source_input.h 所在目录
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcameramgr/dcamerainterface  # icamera_state_listener.h 所在目录
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcameramgr/dcamerastate  # dcamera_source_state_machine.h 所在目录
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcameramgr/dcameracontrol  # dcamera_source_controller.h 所在目录
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcameramgr  # parent directory for subdirs
    ${DCAMERA_SOURCE_DIR}/interfaces/inner_kits/native_cpp/camera_source/include  # idistributed_camera_source.h 所在目录
    ${DCAMERA_SOURCE_DIR}/interfaces/inner_kits/native_cpp/camera_source/include/callback  # idcamera_source_callback.h 所在目录
    ${DCAMERA_SOURCE_DIR}/interfaces/inner_kits/native_cpp/camera_sink/include  # idistributed_camera_sink.h 所在目录
    ${DCAMERA_SOURCE_DIR}/interfaces/inner_kits/native_cpp/camera_sink/include/callback  # idcamera_sink_callback.h 所在目录
    ${DCAMERA_SERVICE_DIR}/sinkservice/include/distributedcamera  # Sink 服务头文件
    ${DCAMERA_SERVICE_DIR}/sinkservice/include/distributedcameramgr  # Sink 管理器头文件
    ${DCAMERA_SERVICE_DIR}/sinkservice/include/distributedcameramgr/interface  # Sink 接口头文件
    ${DCAMERA_SERVICE_DIR}/sinkservice/include/distributedcameramgr/listener  # Sink 监听器头文件
    ${DCAMERA_SERVICE_DIR}/sinkservice/include/distributedcameramgr/callback  # Sink 回调头文件
    ${DCAMERA_SOURCE_DIR}/services/data_process/include/pipeline
    ${DCAMERA_SOURCE_DIR}/services/data_process/include/interfaces
    ${DCAMERA_SOURCE_DIR}/services/data_process/include/utils
    ${DCAMERA_SOURCE_DIR}/services/data_process/include/eventbus
    ${DCAMERA_SOURCE_DIR}/services/cameraservice/sourceservice/include/distributedcameramgr/dcameradata/feedingsmoother/base
    ${DCAMERA_SOURCE_DIR}/services/cameraservice/sourceservice/include/distributedcameramgr/dcameradata/feedingsmoother/derived
    ${DCAMERA_SOURCE_DIR}/services/cameraservice/sourceservice/include/distributedcameramgr/dcameradata/feedingsmoother/utils
    ${DCAMERA_SOURCE_DIR}/services/cameraservice/sourceservice/include/distributedcameramgr/dcameradata/feedingsmoother
    ${DCAMERA_SOURCE_DIR}/services/cameraservice/cameraoperator/handler/include
    ${DCAMERA_SOURCE_DIR}/services/cameraservice/cameraoperator/client/include  # icamera_operator.h 所在目录

    # 源文件所在目录（用于访问同目录的头文件）
    ${DCAMERA_SERVICE_DIR}/base/src
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr

    # 其他 Stub 子目录
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers/v1_1
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers/sys
)

# ========== 源文件列表 ==========

# ========== Sink 服务源文件列表 ==========
set(DCAMERA_SINK_SOURCES
    # ========== Base 基础模块（Sink也需要这些命令类）==========
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_open_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_channel_info_cmd.cpp

    # ========== SinkService 基础服务模块 ==========
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcamera/dcamera_sink_callback_proxy.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcamera/distributed_camera_sink_stub.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcamera/dcamera_sink_hidumper.cpp
    # ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcamera/distributed_camera_sink_service.cpp  # 暂时禁用：依赖太多camera framework

    # ========== SinkService 核心管理模块 ==========
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/dcamera_sink_dev.cpp
    # ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/dcamera_sink_controller.cpp  # 暂时禁用：依赖camera framework
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/dcamera_sink_service_ipc.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/dcamera_sink_access_control.cpp
    # ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/dcamera_sink_output.cpp  # 暂时禁用：可能依赖camera framework
    # ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/dcamera_sink_data_process.cpp  # 暂时禁用：API版本不匹配

    # ========== Listener 监听器模块 ==========
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/listener/dcamera_sink_data_process_listener.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/listener/dcamera_sink_output_channel_listener.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/listener/dcamera_sink_controller_channel_listener.cpp

    # ========== Callback 回调模块 ==========
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/callback/dcamera_sink_controller_state_callback.cpp
    ${DCAMERA_SERVICE_DIR}/sinkservice/src/distributedcameramgr/callback/dcamera_sink_output_result_callback.cpp

    # ========== Common 工具模块（Sink也需要）==========
    ${DCAMERA_SOURCE_DIR}/common/src/utils/anonymous_string.cpp
)

# ========== Source 服务源文件列表 ==========
set(DCAMERA_SOURCE_SOURCES
    # ========== Base 基础模块 ==========
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_capture_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_channel_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_event_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_open_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_sink_frame_info.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_metadata_setting_cmd.cpp

    # ========== SourceService 基础服务模块 ==========
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamera_source_event.cpp
    # ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/dcamera_service_state_listener.cpp  # 暂时禁用：依赖 iav_trans_control_center
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/dcamera_source_callback_proxy.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/distributed_camera_source_stub.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/dcamera_source_hidumper.cpp
    # ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/distributed_camera_source_service.cpp  # 暂时禁用：依赖太多camera framework

    # ========== SourceService 核心管理模块 ==========
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamera_source_dev.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamera_source_service_ipc.cpp

    # ========== State Machine 状态机模块 ==========
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamerastate/dcamera_source_state_machine.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamerastate/dcamera_source_state_factory.cpp
    # ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameracontrol/dcamera_source_controller.cpp  # 暂时禁用：API版本不匹配
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/dcamera_source_input.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/dcamera_stream_data_process.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/dcamera_source_data_process.cpp
    # ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/dcamera_stream_data_process_producer.cpp  # 暂时禁用：NativeBuffer API不匹配
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/dcamera_source_input_channel_listener.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcameradata/dcamera_stream_data_process_pipeline_listener.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamerahdf/dcamera_provider_callback_impl.cpp

    # ========== Channel 通道模块 ==========
    ${DCAMERA_SOURCE_DIR}/services/channel/src/dcamera_channel_source_impl.cpp
    ${DCAMERA_SOURCE_DIR}/services/channel/src/allconnect/distributed_camera_allconnect_manager.cpp

    # ========== Common 工具模块 ==========
    ${DCAMERA_SOURCE_DIR}/common/src/utils/anonymous_string.cpp
    ${DCAMERA_SOURCE_DIR}/common/src/utils/dcamera_utils_tools.cpp
    # ${DCAMERA_SOURCE_DIR}/common/src/utils/dcamera_radar.cpp  # 暂时排除（宏隔离问题）

    # ========== Stub 实现 ==========
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_hisysevent_adapter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/hilog_mock.cpp  # HiLog mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/hitrace_mock.cpp  # HiTrace mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/softbus_mock.cpp  # Softbus mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/ipc_object_stub_mock.cpp  # IPCObjectStub mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/ipc_object_stub_constructor_mock.cpp  # IPCObjectStub 构造函数 mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/peer_holder_mock.cpp  # PeerHolder mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/ipc_skeleton_mock.cpp  # IPCSkeleton mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/iremote_object_mock.cpp  # IRemoteObject mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/message_parcel_mock.cpp  # MessageParcel mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/data_buffer_mock.cpp  # DataBuffer mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_pipeline_source_mock.cpp  # DCameraPipelineSource mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/access_token_kit_mock.cpp  # AccessTokenKit mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_stream_data_process_producer_mock.cpp  # DCameraStreamDataProcessProducer mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/distributed_camera_source_service_mock.cpp  # DistributedCameraSourceService mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/icamera_channel_mock.cpp  # ICameraChannel mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/weak_ref_counter_mock.cpp  # WeakRefCounter mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/broker_registration_impl.cpp  # BrokerRegistration 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_radar_mock.cpp  # DcameraRadar mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_softbus_session_mock.cpp  # DCameraSoftbusSession mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_source_state_mock.cpp  # DCameraSourceState mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_source_controller_mock.cpp  # DCameraSourceController mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_hitrace_mock.cpp  # DcameraHitrace mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/system_ability_manager_client_mock.cpp  # SystemAbilityManagerClient mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_hidumper_mock.cpp  # DcameraHidumper mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/video_config_params_mock.cpp  # VideoConfigParams mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_softbus_adapter_mock.cpp  # DCameraSoftbusAdapter mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_softbus_latency_mock.cpp  # DCameraSoftbusLatency mock 实现
)

# 检查源文件是否存在
set(EXISTING_SOURCES)
foreach(SOURCE_FILE ${DCAMERA_SOURCE_SOURCES})
    if(EXISTS "${SOURCE_FILE}")
        list(APPEND EXISTING_SOURCES "${SOURCE_FILE}")
    else()
        message(STATUS "源文件不存在，跳过: ${SOURCE_FILE}")
    endif()
endforeach()

list(LENGTH EXISTING_SOURCES SOURCE_COUNT)
message(STATUS "找到 ${SOURCE_COUNT} 个 Source 源文件")

# 检查 Sink 源文件是否存在
set(EXISTING_SINK_SOURCES)
foreach(SOURCE_FILE ${DCAMERA_SINK_SOURCES})
    if(EXISTS "${SOURCE_FILE}")
        list(APPEND EXISTING_SINK_SOURCES "${SOURCE_FILE}")
    else()
        message(STATUS "Sink 源文件不存在，跳过: ${SOURCE_FILE}")
    endif()
endforeach()

list(LENGTH EXISTING_SINK_SOURCES SINK_SOURCE_COUNT)
message(STATUS "找到 ${SINK_SOURCE_COUNT} 个 Sink 源文件")

# 编译 cJSON 静态库
add_library(cjson STATIC ${CJSON_DIR}/cJSON.c)
target_include_directories(cjson PUBLIC ${CJSON_INCLUDE_DIR})

# 创建 dcamera_source 动态库
add_library(dcamera_source SHARED
    src/dcamera_source_dll.cpp
    ${EXISTING_SOURCES}
)

# 定义 dcamera_source 的日志宏
# 注意：LOG_CORE 是枚举值，不是宏定义，所以不在这里定义
target_compile_definitions(dcamera_source PRIVATE
    DH_LOG_TAG="dcamerasource"
    LOG_DOMAIN=0xD004150
    HI_LOG_ENABLE=0
)

# 创建 dcamera_sink 动态库
add_library(dcamera_sink SHARED
    src/dcamera_sink_dll.cpp
    ${EXISTING_SINK_SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/hilog_mock.cpp  # HiLog mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/ipc_object_stub_mock.cpp  # IPCObjectStub mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/ipc_object_stub_constructor_mock.cpp  # IPCObjectStub 构造函数 mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/peer_holder_mock.cpp  # PeerHolder mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/ipc_skeleton_mock.cpp  # IPCSkeleton mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/iremote_object_mock.cpp  # IRemoteObject mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/message_parcel_mock.cpp  # MessageParcel mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/broker_registration_impl.cpp  # BrokerRegistration 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/weak_ref_counter_mock.cpp  # WeakRefCounter mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/access_token_kit_mock.cpp  # AccessTokenKit mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/system_ability_manager_client_mock.cpp  # SystemAbilityManagerClient mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_hidumper_mock.cpp  # DcameraHidumper mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_sink_output_impl.cpp  # DCameraSinkOutput stub 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_sink_controller_impl.cpp  # DCameraSinkController stub 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_sink_data_process_mock.cpp  # DCameraSinkDataProcess mock 实现
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/distributed_camera_sink_service_mock.cpp  # DistributedCameraSinkService mock 实现
)

# 定义 dcamera_sink 的日志宏
# 注意：LOG_CORE 是枚举值，不是宏定义，所以不在这里定义
target_compile_definitions(dcamera_sink PRIVATE
    DH_LOG_TAG="dcamerasink"
    LOG_DOMAIN=0xD004151
    HI_LOG_ENABLE=0
)

# 链接库
target_link_libraries(dcamera_source
    PRIVATE
    c++
    cjson
)

target_link_libraries(dcamera_sink
    PRIVATE
    c++
    cjson
)

# 安装
install(TARGETS dcamera_source dcamera_sink
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# 打印配置信息
message(STATUS "")
message(STATUS "==============================================")
message(STATUS "  分布式相机测试工程配置")
message(STATUS "==============================================")
message(STATUS "  项目版本: ${PROJECT_VERSION}")
message(STATUS "  构建类型: ${CMAKE_BUILD_TYPE}")
message(STATUS "  C++ 标准: C++${CMAKE_CXX_STANDARD}")
message(STATUS "  编译器: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "  平台: ${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION}")
message(STATUS "  源码根目录: ${OHOS_DCAMERA_SOURCE_ROOT}")
message(STATUS "  外部依赖目录: ${EXTERNAL_DIR}")
message(STATUS "  源文件数量: ${SOURCE_COUNT}")
message(STATUS "  构建目标:")
message(STATUS "    - libdcamera_source.dylib (Source服务)")
message(STATUS "    - libdcamera_sink.dylib (Sink服务)")
message(STATUS "    - libcjson.a (静态库)")
message(STATUS "==============================================")
message(STATUS "")
