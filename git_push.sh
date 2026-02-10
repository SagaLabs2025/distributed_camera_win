#!/bin/bash
# GitHub Push Helper - 使用 Personal Access Token 推送代码

set -e

echo "========================================"
echo "  GitHub 代码推送助手"
echo "========================================"
echo ""
echo "请按以下步骤操作："
echo ""
echo "1. 创建 GitHub Personal Access Token:"
echo "   - 访问: https://github.com/settings/tokens"
echo "   - 点击 'Generate new token' -> 'Generate new token (classic)'"
echo "   - 勾选 'repo' 权限"
echo "   - 点击 'Generate token'"
echo "   - 复制生成的 token（以 ghp_ 开头）"
echo ""
echo "2. 将 token 粘贴到下面:"
echo ""
read -p "GitHub Token: " TOKEN

if [ -z "$TOKEN" ]; then
    echo "错误: Token 不能为空"
    exit 1
fi

# 检查 token 格式
if [[ ! $TOKEN =~ ^ghp_ ]]; then
    echo "警告: Token 格式可能不正确（应该以 ghp_ 开头）"
    read -p "是否继续? (y/n): " CONFIRM
    if [ "$CONFIRM" != "y" ]; then
        exit 1
    fi
fi

# 设置远程 URL（带 token）
echo ""
echo "正在配置 Git 远程仓库..."
git remote set-url origin "https://${TOKEN}@github.com/SagaLabs2025/distributed_camera_win.git"

# 推送代码
echo ""
echo "正在推送代码到 GitHub..."
git push -u origin main

# 恢复原始 URL（移除 token）
echo ""
echo "推送完成！正在恢复远程 URL..."
git remote set-url origin "https://github.com/SagaLabs2025/distributed_camera_win.git"

echo ""
echo "✓ 代码已成功推送到 GitHub!"
echo "  仓库地址: https://github.com/SagaLabs2025/distributed_camera_win"
