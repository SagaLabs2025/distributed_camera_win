#!/bin/bash
# 外部依赖一键下载脚本

set -e

# 颜色输出
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

EXTERNAL_DIR="$(pwd)/external"

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}  外部依赖下载脚本${NC}"
echo -e "${GREEN}========================================${NC}"

# 创建外部依赖目录
mkdir -p "${EXTERNAL_DIR}"

# 下载 c_utils
if [ ! -d "${EXTERNAL_DIR}/c_utils" ] || [ "$1" == "--force" ]; then
    echo -e "${YELLOW}下载 c_utils...${NC}"
    cd "${EXTERNAL_DIR}"
    rm -rf c_utils
    git clone https://gitcode.com/openharmony/commonlibrary_c_utils.git c_utils
    echo -e "${GREEN}✓ c_utils 下载完成${NC}"
else
    echo -e "${GREEN}✓ c_utils 已存在${NC}"
fi

# 下载 drivers_interface
if [ ! -d "${EXTERNAL_DIR}/drivers_interface" ] || [ "$1" == "--force" ]; then
    echo -e "${YELLOW}下载 drivers_interface...${NC}"
    cd "${EXTERNAL_DIR}"
    rm -rf drivers_interface
    git clone https://gitcode.com/openharmony/drivers_interface.git drivers_interface
    echo -e "${GREEN}✓ drivers_interface 下载完成${NC}"
else
    echo -e "${GREEN}✓ drivers_interface 已存在${NC}"
fi

echo -e "${GREEN}========================================${NC}"
echo -e "${GREEN}  外部依赖下载完成！${NC}"
echo -e "${GREEN}========================================${NC}"
