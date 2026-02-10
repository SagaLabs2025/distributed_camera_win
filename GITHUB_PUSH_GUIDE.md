# GitHub 代码推送指南

## 方法 1：使用推送脚本（推荐）

```bash
./git_push.sh
```

脚本会引导您：
1. 创建 GitHub Personal Access Token
2. 输入 token
3. 自动推送代码

## 方法 2：手动配置

### 步骤 1：创建 Personal Access Token

1. 访问：https://github.com/settings/tokens
2. 点击 "Generate new token" → "Generate new token (classic)"
3. 设置：
   - **Note**: `distributed_camera_push`
   - **Expiration**: 选择过期时间（或选择 No expiration）
   - **勾选权限**: `repo` (Full control of private repositories)
4. 点击 "Generate token"
5. **重要**：复制生成的 token（格式：`ghp_xxxxxxxxxxxx`）

### 步骤 2：推送代码

```bash
# 替换 YOUR_TOKEN 为您复制的 token
git push https://YOUR_TOKEN@github.com/SagaLabs2025/distributed_camera_win.git main
```

**示例**：
```bash
git push https://ghp_abc123def456xyz789@github.com/SagaLabs2025/distributed_camera_win.git main
```

### 步骤 3：清除历史记录（可选）

如果命令保存在 shell 历史中：
```bash
# 编辑历史记录，删除包含 token 的行
history -d <历史号>

# 或者清除整个历史
history -c
```

## 方法 3：使用 SSH Key（长期推荐）

### 生成 SSH Key

```bash
# 生成新的 SSH key
ssh-keygen -t ed25519 -C "your_email@example.com"

# 或者使用 RSA
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```

### 添加到 GitHub

1. 复制公钥：
```bash
cat ~/.ssh/id_ed25519.pub
# 或
cat ~/.ssh/id_rsa.pub
```

2. 添加到 GitHub：
   - 访问：https://github.com/settings/keys
   - 点击 "New SSH key"
   - 粘贴公钥内容
   - 点击 "Add SSH key"

### 切换到 SSH URL

```bash
# 查看当前远程 URL
git remote -v

# 切换到 SSH URL
git remote set-url origin git@github.com:SagaLabs2025/distributed_camera_win.git

# 推送代码
git push -u origin main
```

## 验证推送成功

访问：https://github.com/SagaLabs2025/distributed_camera_win

您应该能看到：
- 4 个提交记录
- 所有源代码文件
- 完整的项目结构

## 常见问题

### Q: Token 失效了怎么办？
A: 重新生成 token，然后使用新 token 推送

### Q: 推送失败提示权限不足？
A: 检查 token 是否有 `repo` 权限

### Q: 忘记保存 token？
A: 需要重新生成，GitHub 只显示一次

### Q: 想避免每次输入 token？
A: 使用方法 3 配置 SSH key

---

**推荐方案**：
- **临时使用**：方法 1（脚本）或方法 2（手动）
- **长期使用**：方法 3（SSH Key）
