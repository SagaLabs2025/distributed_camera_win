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
set(CJSON_DIR "${EXTERNAL_DIR}/cJSON")
set(CJSON_INCLUDE_DIR "${CJSON_DIR}")

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

# 源码头文件目录
set(DCAMERA_SOURCE_DIR "${OHOS_DCAMERA_SOURCE_ROOT}")
set(DCAMERA_SERVICE_DIR "${DCAMERA_SOURCE_DIR}/services/cameraservice")
set(DCAMERA_INCLUDE_DIR "${DCAMERA_SOURCE_DIR}/interfaces/innerkits/camera_source_sdk/include")
set(DCAMERA_COMMON_INCLUDE "${DCAMERA_SOURCE_DIR}/common/include")
set(SOFTBUS_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers")

# 包含目录
# 注意：源码头文件路径必须在stub之前，优先使用源码定义
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/adapters
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/stubs/headers
    ${CMAKE_SOURCE_DIR}/stubs/headers
    ${CJSON_INCLUDE_DIR}
    ${DCAMERA_INCLUDE_DIR}
    ${DCAMERA_COMMON_INCLUDE}
    ${DCAMERA_SERVICE_DIR}/sourceservice/include
    ${DCAMERA_SERVICE_DIR}/sinkservice/include
    ${DCAMERA_SERVICE_DIR}/base/include
)

# 源文件定义
# 阶段 1: Base 工具（7个文件）
set(DCAMERA_SOURCE_SOURCES
    # Base 工具 - 阶段 1
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_capture_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_channel_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_event_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_open_info_cmd.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_sink_frame_info.cpp
    ${DCAMERA_SERVICE_DIR}/base/src/dcamera_metadata_setting_cmd.cpp
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

# 创建 dcamera_sink 动态库
add_library(dcamera_sink SHARED
    src/dcamera_sink_dll.cpp
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
message(STATUS "===============================================")
message(STATUS "  分布式相机测试工程配置")
message(STATUS "===============================================")
message(STATUS "  构建类型: ${CMAKE_BUILD_TYPE}")
message(STATUS "  C++ 标准: ${CMAKE_CXX_STANDARD}")
message(STATUS "  源码根目录: ${OHOS_DCAMERA_SOURCE_ROOT}")
message(STATUS "  源文件数量: ${SOURCE_COUNT}")
message(STATUS "===============================================")
