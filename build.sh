#!/bin/bash
# 分布式相机测试工程一键构建脚本

set -e

# 颜色输出
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}  分布式相机测试工程构建脚本${NC}"
echo -e "${GREEN}========================================${NC}"

# 清理构建
if [ "$1" == "--clean" ]; then
    echo -e "${YELLOW}清理构建目录...${NC}"
    rm -rf build
fi

# 创建构建目录
echo -e "${YELLOW}创建构建目录...${NC}"
mkdir -p build
cd build

# 运行 CMake
echo -e "${YELLOW}配置项目...${NC}"
cmake -DCMAKE_BUILD_TYPE=Debug ..

# 编译
echo -e "${YELLOW}编译项目...${NC}"
make -j$(sysctl -n hw.ncpu)

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}  构建完成！${NC}"
echo -e "${GREEN}========================================${NC}"
echo -e "输出文件:"
ls -lh *.dylib 2>/dev/null || echo "  未找到动态库文件"
