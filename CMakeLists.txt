cmake_minimum_required(VERSION 3.20)
project(distributed_camera_test VERSION 1.0.0 LANGUAGES C CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置编译选项
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-parameter")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -DNDEBUG")
endif()

# 定义平台宏
add_definitions(-D__APPLE__)
add_definitions(-D__MACOS__)
add_definitions(-DHI_LOG_ENABLE=0)
add_definitions(-DDCAMERA_LOCAL_TEST)  # 分布式相机本地模拟测试

# 设置 OpenHarmony 源码根目录
if(NOT DEFINED OHOS_DCAMERA_SOURCE_ROOT)
    set(OHOS_DCAMERA_SOURCE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../distributedhardware_distributed_camera")
    if(NOT EXISTS "${OHOS_DCAMERA_SOURCE_ROOT}")
        message(WARNING "OpenHarmony 源码目录不存在: ${OHOS_DCAMERA_SOURCE_ROOT}")
    endif()
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
if(EXISTS "${C_UTILS_INCLUDE_DIR}")
    message(STATUS "✓ 找到 c_utils: ${C_UTILS_INCLUDE_DIR}")
else()
    message(STATUS "✗ 未找到 c_utils，部分功能可能受限")
endif()

if(EXISTS "${CJSON_INCLUDE_DIR}/cJSON.h")
    message(STATUS "✓ 找到 cJSON: ${CJSON_INCLUDE_DIR}")
else()
    message(STATUS "✗ 未找到 cJSON")
endif()

if(EXISTS "${DH_FWK_INCLUDE_DIR}")
    message(STATUS "✓ 找到 distributed_hardware_fwk: ${DH_FWK_INCLUDE_DIR}")
else()
    message(STATUS "✗ 未找到 distributed_hardware_fwk")
endif()

# 源码头文件目录
set(DCAMERA_SOURCE_DIR "${OHOS_DCAMERA_SOURCE_ROOT}")
set(DCAMERA_INCLUDE_DIR "${DCAMERA_SOURCE_DIR}/interfaces/innerkits/camera_source_sdk/include")
set(DCAMERA_COMMON_INCLUDE "${DCAMERA_SOURCE_DIR}/common/include")
set(SOFTBUS_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers")

# 正确的源文件路径（相对于 OHOS_DCAMERA_SOURCE_ROOT）
set(DCAMERA_SERVICE_DIR "${DCAMERA_SOURCE_DIR}/services/cameraservice")

# 包含目录
# 注意：stubs/headers 优先级最高，用于提供简化的 mock 实现
# external 头文件用于引用真实的类型定义
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/adapters
    ${CMAKE_SOURCE_DIR}/include

    # Stub 头文件（优先级最高 - 提供简化的 mock 和适配器）
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers
    ${CMAKE_SOURCE_DIR}/stubs/headers
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers/v1_1
    ${CMAKE_SOURCE_DIR}/stubs/headers/v1_1
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers/meta
    ${CMAKE_SOURCE_DIR}/stubs/headers/meta
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers/buffer
    ${CMAKE_SOURCE_DIR}/stubs/headers/buffer
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers/hitrace
    ${CMAKE_SOURCE_DIR}/stubs/headers/hitrace
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers/ipc
    ${CMAKE_SOURCE_DIR}/stubs/headers/ipc

    # External 依赖头文件（用于类型定义）
    ${C_UTILS_INCLUDE_DIR}
    ${IPC_CORE_INCLUDE}
    ${SAFWK_INCLUDE}
    ${DH_FWK_UTILS_INCLUDE}
    ${EXTERNAL_DIR}/communication_ipc/interfaces/innerkits/ipc_core/include
    ${EXTERNAL_DIR}/security_access_token/interfaces/innerkits/accesstoken/include
    ${EXTERNAL_DIR}/multimedia_av_codec/interfaces/inner_api/native
    ${EXTERNAL_DIR}/distributedhardware_distributed_hardware_fwk/common/utils/include

    # OpenHarmony 源码头文件
    ${CJSON_INCLUDE_DIR}
    ${DCAMERA_INCLUDE_DIR}
    ${DCAMERA_COMMON_INCLUDE}
    ${DCAMERA_COMMON_INCLUDE}/constants    # distributed_camera_errno.h 所在目录
    ${DCAMERA_COMMON_INCLUDE}/utils       # dh_log.h 所在目录
    ${DCAMERA_SOURCE_DIR}/services/channel/include  # icamera_channel_listener.h 所在目录
    ${DCAMERA_SERVICE_DIR}/base/include
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcamera
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcameramgr
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcameramgr/dcamerahdf
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcameramgr/dcamerainterface
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcameramgr/dcamerastate
    ${DCAMERA_SERVICE_DIR}/sourceservice/include/distributedcameramgr/dcameracontrol
    ${DCAMERA_SOURCE_DIR}/interfaces/inner_kits/native_cpp/camera_source/include
    ${DCAMERA_SOURCE_DIR}/interfaces/inner_kits/native_cpp/camera_source/include/callback
    ${EXTERNAL_DIR}/drivers_interface_distributed_camera/v1_1
)

# 源文件定义 - 逐步添加源文件
set(DCAMERA_SOURCE_SOURCES
    # ========== Base 工具模块 ==========
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_capture_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_channel_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_event_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_open_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_sink_frame_info.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_metadata_setting_cmd.cpp

    # ========== SourceService 基础服务模块 ==========
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamera_source_event.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/dcamera_service_state_listener.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/dcamera_source_callback_proxy.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/distributed_camera_source_service.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/distributed_camera_source_stub.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcamera/dcamera_source_hidumper.cpp

    # ========== SourceService 核心管理模块 ==========
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamera_source_dev.cpp
    ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamera_source_service_ipc.cpp

    # ========== Common 工具模块 ==========
    ${DCAMERA_SOURCE_DIR}/common/src/utils/anonymous_string.cpp
    # ${DCAMERA_SOURCE_DIR}/common/src/utils/dcamera_radar.cpp  # 暂时排除（宏隔离问题）

    # ========== Stub 实现 ==========
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/src/dcamera_hisysevent_adapter.cpp
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
message(STATUS "找到 ${SOURCE_COUNT} 个源文件")

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
message(STATUS "==============================================")
message(STATUS "  分布式相机测试工程配置")
message(STATUS "==============================================")
message(STATUS "  构建类型: ${CMAKE_BUILD_TYPE}")
message(STATUS "  C++ 标准: ${CMAKE_CXX_STANDARD}")
message(STATUS "  源码根目录: ${OHOS_DCAMERA_SOURCE_ROOT}")
message(STATUS "  源文件数量: ${SOURCE_COUNT}")
message(STATUS "==============================================")
