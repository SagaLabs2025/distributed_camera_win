#!/bin/bash

# 分布式相机快速编译脚本

set -e  # 遇到错误立即退出

# 颜色定义
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}=========================================="
echo "  分布式相机 macOS 编译脚本"
echo -e "==========================================${NC}"
echo ""

# 解析命令行参数
CLEAN=0
DEBUG=0
VERBOSE=0
JOBS=8

while [[ $# -gt 0 ]]; do
    case $1 in
        -c|--clean)
            CLEAN=1
            shift
            ;;
        -d|--debug)
            DEBUG=1
            shift
            ;;
        -v|--verbose)
            VERBOSE=1
            shift
            ;;
        -j|--jobs)
            JOBS="$2"
            shift 2
            ;;
        -h|--help)
            echo "用法: $0 [选项]"
            echo ""
            echo "选项:"
            echo "  -c, --clean     清理后重新编译"
            echo "  -d, --debug     Debug 模式编译"
            echo "  -v, --verbose   显示详细编译信息"
            echo "  -j, --jobs N    使用 N 个并行任务（默认: 8）"
            echo "  -h, --help      显示此帮助信息"
            echo ""
            echo "示例:"
            echo "  $0              # 普通编译"
            echo "  $0 -c           # 清理后编译"
            echo "  $0 -d           # Debug 模式"
            echo "  $0 -c -d -j4    # 清理、Debug 模式、4 线程"
            exit 0
            ;;
        *)
            echo -e "${RED}未知选项: $1${NC}"
            echo "使用 -h 或 --help 查看帮助"
            exit 1
            ;;
    esac
done

# 1. 清理（如果需要）
if [ $CLEAN -eq 1 ]; then
    echo -e "${YELLOW}[1/4] 清理构建产物...${NC}"
    make clean 2>/dev/null || true
    rm -f CMakeCache.txt
    echo -e "${GREEN}✓ 清理完成${NC}"
    echo ""
else
    echo -e "${YELLOW}[1/4] 跳过清理${NC}"
    echo ""
fi

# 2. CMake 配置
echo -e "${YELLOW}[2/4] 运行 CMake 配置...${NC}"
if [ $DEBUG -eq 1 ]; then
    echo "  模式: Debug"
    cmake -DCMAKE_BUILD_TYPE=Debug .
else
    echo "  模式: Release"
    cmake -DCMAKE_BUILD_TYPE=Release .
fi

if [ $? -ne 0 ]; then
    echo -e "${RED}✗ CMake 配置失败${NC}"
    exit 1
fi
echo -e "${GREEN}✓ CMake 配置完成${NC}"
echo ""

# 3. 编译
echo -e "${YELLOW}[3/4] 开始编译（使用 $JOBS 个并行任务）...${NC}"
START_TIME=$(date +%s)

if [ $VERBOSE -eq 1 ]; then
    make -j$JOBS
else
    make -j$JOBS 2>&1 | grep -E "^\[|Built target|Linking|Error|error" || make -j$JOBS
fi

if [ $? -ne 0 ]; then
    echo -e "${RED}✗ 编译失败${NC}"
    exit 1
fi

END_TIME=$(date +%s)
ELAPSED=$((END_TIME - START_TIME))
echo -e "${GREEN}✓ 编译完成 (耗时: ${ELAPSED}秒)${NC}"
echo ""

# 4. 验证
echo -e "${YELLOW}[4/4] 验证构建产物...${NC}"

# 检查文件是否存在
if [ ! -f "libdcamera_source.dylib" ]; then
    echo -e "${RED}✗ libdcamera_source.dylib 未生成${NC}"
    exit 1
fi

if [ ! -f "libdcamera_sink.dylib" ]; then
    echo -e "${RED}✗ libdcamera_sink.dylib 未生成${NC}"
    exit 1
fi

if [ ! -f "libcjson.a" ]; then
    echo -e "${RED}✗ libcjson.a 未生成${NC}"
    exit 1
fi

# 显示文件信息
echo "构建产物:"
ls -lh libdcamera_source.dylib libdcamera_sink.dylib libcjson.a | awk '{printf "  %-30s %8s\n", $9, $5}'

# 检查符号
SOURCE_INIT=$(nm -gU libdcamera_source.dylib | grep DCameraSourceInitialize | wc -l | xargs)
SINK_INIT=$(nm -gU libdcamera_sink.dylib | grep DCameraSinkInitialize | wc -l | xargs)

if [ "$SOURCE_INIT" -eq "0" ]; then
    echo -e "${RED}✗ Source 库缺少 DCameraSourceInitialize 符号${NC}"
    exit 1
fi

if [ "$SINK_INIT" -eq "0" ]; then
    echo -e "${RED}✗ Sink 库缺少 DCameraSinkInitialize 符号${NC}"
    exit 1
fi

echo -e "${GREEN}✓ 验证完成${NC}"
echo ""

# 5. 总结
echo -e "${BLUE}=========================================="
echo -e "  ${GREEN}✓ 编译成功！${NC}"
echo -e "${BLUE}==========================================${NC}"
echo ""
echo "构建产物已生成:"
echo "  • libdcamera_source.dylib - Source 服务"
echo "  • libdcamera_sink.dylib   - Sink 服务"
echo "  • libcjson.a              - cJSON 库"
echo ""
echo "下一步:"
echo "  • 运行 ./verify_build.sh 进行详细验证"
echo "  • 查看 BUILD.md 了解更多信息"
echo ""
