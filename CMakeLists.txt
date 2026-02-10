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
add_definitions(-DDCAMERA_MACOS_MOCK)

# 设置 OpenHarmony 源码根目录
if(NOT DEFINED OHOS_DCAMERA_SOURCE_ROOT)
    set(OHOS_DCAMERA_SOURCE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../distributedhardware_distributed_camera")
    if(NOT EXISTS "${OHOS_DCAMERA_SOURCE_ROOT}")
        message(WARNING "OpenHarmony 源码目录不存在: ${OHOS_DCAMERA_SOURCE_ROOT}")
    endif()
endif()

message(STATUS "OpenHarmony 源码根目录: ${OHOS_DCAMERA_SOURCE_ROOT}")

# 外部依赖目录
set(EXTERNAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external")
set(C_UTILS_INCLUDE_DIR "${EXTERNAL_DIR}/c_utils/base/include")
set(DRIVERS_INTERFACE_DIR "${EXTERNAL_DIR}/drivers_interface")

# 验证外部依赖
if(EXISTS "${C_UTILS_INCLUDE_DIR}")
    message(STATUS "✓ 找到 c_utils: ${C_UTILS_INCLUDE_DIR}")
else()
    message(STATUS "✗ 未找到 c_utils，部分功能可能受限")
endif()

# 源码头文件目录
set(DCAMERA_SOURCE_DIR "${OHOS_DCAMERA_SOURCE_ROOT}")
set(DCAMERA_SERVICE_DIR "${DCAMERA_SOURCE_DIR}/services/cameraservice")
set(DCAMERA_INCLUDE_DIR "${DCAMERA_SOURCE_DIR}/interfaces/innerkits/camera_source_sdk/include")
set(DCAMERA_COMMON_INCLUDE "${DCAMERA_SOURCE_DIR}/common/include")
set(SOFTBUS_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers")

# 包含目录
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/adapters
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/stubs/headers
    ${DCAMERA_INCLUDE_DIR}
    ${DCAMERA_COMMON_INCLUDE}
    ${DCAMERA_SERVICE_DIR}/sourceservice/include
    ${DCAMERA_SERVICE_DIR}/sinkservice/include
    ${DCAMERA_SERVICE_DIR}/base/include
)

# 源文件定义
# 暂时只使用 dylib 入口文件，不包含 OpenHarmony 源码
# 等待 stub 头文件编译通过后再逐步添加源码文件
set(DCAMERA_SOURCE_SOURCES
    # 暂时禁用 OpenHarmony 源码文件
    # ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamera_source_dev.cpp
    # ${DCAMERA_SERVICE_DIR}/sourceservice/src/distributedcameramgr/dcamera_source_handler.cpp
    # ${DCAMERA_SERVICE_DIR}/sourceservice/src/camerasource/dcamera_source_controller.cpp
    # ${DCAMERA_SERVICE_DIR}/sourceservice/src/camerasource/dcamera_source_input.cpp
    # ${DCAMERA_SERVICE_DIR}/sourceservice/src/camerasource/dcamera_source_coordinator.cpp
    # ${DCAMERA_SERVICE_DIR}/sourceservice/src/camerasource/dcamera_state_machine.cpp
    # ${DCAMERA_SERVICE_DIR}/sourceservice/src/camerasource/dcamera_source_callback.cpp
    # ${DCAMERA_SERVICE_DIR}/data_process/src/dcamera_source_data_process.cpp
    # ${DCAMERA_SERVICE_DIR}/data_process/src/dcamera_sink_data_process.cpp
    # ${DCAMERA_SERVICE_DIR}/base/src/dcamera_hdf_event.cpp
    # ${DCAMERA_SERVICE_DIR}/base/src/dcamera_utils_tools.cpp
    # ${DCAMERA_SERVICE_DIR}/base/src/dcamera_channel_info_cmd.cpp
    # ${DCAMERA_SERVICE_DIR}/base/src/dcamera_info_cmd.cpp
    # ${DCAMERA_SERVICE_DIR}/base/src/dcamera_open_info_cmd.cpp
    # ${DCAMERA_SERVICE_DIR}/base/src/dcamera_capture_info_cmd.cpp
    # ${DCAMERA_SERVICE_DIR}/base/src/dcamera_event_cmd.cpp
    # ${DCAMERA_SOURCE_DIR}/common/src/utils/dcamera_buffer.cpp
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

message(STATUS "找到 ${CMAKE_CURRENT_LIST_DIR} 个源文件")

# 创建 dcamera_source 动态库
add_library(dcamera_source SHARED
    src/dcamera_source_dll.cpp
    ${EXISTING_SOURCES}
)

# 创建 dcamera_sink 动态库
add_library(dcamera_sink SHARED
    src/dcamera_sink_dll.cpp
)

# 链接库
target_link_libraries(dcamera_source
    PRIVATE
    c++
    c++
)

target_link_libraries(dcamera_sink
    PRIVATE
    c++
)

# 安装
install(TARGETS dcamera_source dcamera_sink
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# 打印配置信息
message(STATUS "===============================================")
message(STATUS "  分布式相机测试工程配置")
message(STATUS "===============================================")
message(STATUS "  构建类型: ${CMAKE_BUILD_TYPE}")
message(STATUS "  C++ 标准: ${CMAKE_CXX_STANDARD}")
message(STATUS "  源码根目录: ${OHOS_DCAMERA_SOURCE_ROOT}")
message(STATUS "  源文件数量: ${CMAKE_CURRENT_LIST_DIR}")
message(STATUS "===============================================")
