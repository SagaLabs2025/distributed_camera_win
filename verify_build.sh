#!/bin/bash

# 分布式相机构建验证脚本

echo "=========================================="
echo "  分布式相机 macOS 构建验证"
echo "=========================================="
echo ""

# 颜色定义
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# 检查函数
check_file() {
    if [ -f "$1" ]; then
        echo -e "${GREEN}✓${NC} 找到: $1"
        return 0
    else
        echo -e "${RED}✗${NC} 缺失: $1"
        return 1
    fi
}

# 1. 检查构建产物
echo "1. 检查构建产物"
echo "-------------------"
check_file "libdcamera_source.dylib"
SOURCE_EXISTS=$?
check_file "libdcamera_sink.dylib"
SINK_EXISTS=$?
check_file "libcjson.a"
CJSON_EXISTS=$?
echo ""

if [ $SOURCE_EXISTS -ne 0 ] || [ $SINK_EXISTS -ne 0 ] || [ $CJSON_EXISTS -ne 0 ]; then
    echo -e "${RED}错误: 构建产物不完整，请先运行 'make' 进行编译${NC}"
    exit 1
fi

# 2. 检查文件大小
echo "2. 检查文件大小"
echo "-------------------"
ls -lh libdcamera_source.dylib libdcamera_sink.dylib libcjson.a
echo ""

# 3. 检查符号导出
echo "3. 检查符号导出"
echo "-------------------"
echo "Source 库导出的关键符号:"
nm -gU libdcamera_source.dylib | grep -E "GetSourceHardwareHandler" | head -5
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓${NC} Source 库符号导出正常"
else
    echo -e "${RED}✗${NC} Source 库符号导出异常"
fi
echo ""

echo "Sink 库导出的关键符号:"
nm -gU libdcamera_sink.dylib | grep -E "GetSinkHardwareHandler" | head -5
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓${NC} Sink 库符号导出正常"
else
    echo -e "${RED}✗${NC} Sink 库符号导出异常"
fi
echo ""

# 4. 检查库依赖
echo "4. 检查库依赖"
echo "-------------------"
echo "Source 库依赖:"
otool -L libdcamera_source.dylib | grep -v "libdcamera_source.dylib"
echo ""

echo "Sink 库依赖:"
otool -L libdcamera_sink.dylib | grep -v "libdcamera_sink.dylib"
echo ""

# 5. 统计信息
echo "5. 构建统计"
echo "-------------------"
SOURCE_SIZE=$(ls -lh libdcamera_source.dylib | awk '{print $5}')
SINK_SIZE=$(ls -lh libdcamera_sink.dylib | awk '{print $5}')
CJSON_SIZE=$(ls -lh libcjson.a | awk '{print $5}')

echo "libdcamera_source.dylib: $SOURCE_SIZE"
echo "libdcamera_sink.dylib:   $SINK_SIZE"
echo "libcjson.a:              $CJSON_SIZE"
echo ""

SOURCE_SYMBOLS=$(nm -gU libdcamera_source.dylib | wc -l | xargs)
SINK_SYMBOLS=$(nm -gU libdcamera_sink.dylib | wc -l | xargs)

echo "Source 库导出符号数: $SOURCE_SYMBOLS"
echo "Sink 库导出符号数:   $SINK_SYMBOLS"
echo ""

# 6. 架构信息
echo "6. 架构信息"
echo "-------------------"
echo "Source 库架构:"
file libdcamera_source.dylib
echo ""
echo "Sink 库架构:"
file libdcamera_sink.dylib
echo ""

# 7. 最终结果
echo "=========================================="
echo -e "${GREEN}✓ 构建验证完成！${NC}"
echo "=========================================="
echo ""
echo "您可以使用以下命令进行更详细的检查："
echo "  - 查看所有导出符号: nm -gU libdcamera_source.dylib"
echo "  - 查看库依赖:       otool -L libdcamera_source.dylib"
echo "  - 查看库信息:       file libdcamera_source.dylib"
echo ""
