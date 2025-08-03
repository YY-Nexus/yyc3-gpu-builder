#!/bin/bash

# 确保脚本以非交互方式运行
set -e

# 初始化 Git 仓库
echo "初始化 Git 仓库..."
git init

# 添加所有文件到暂存区
echo "添加文件到暂存区..."
git add .

# 提交代码
echo "提交代码..."
git commit -m "Initial commit with GitHub Actions and Docker setup"

# 创建 main 分支
echo "创建 main 分支..."
git branch -M main

# 提示用户添加远程仓库
cat << EOF

请添加远程仓库并推送代码：

git remote add origin https://github.com/your-username/yyc3-gpu-builder.git
git push -u origin main

EOF

# 提示用户配置 GitHub Secrets 和 Variables
cat << EOF

下一步需要在 GitHub 仓库中配置：
1. 添加变量 DOCKER_USER（Docker Hub 用户名）
2. 添加密钥 DOCKER_PAT（Docker Hub 个人访问令牌）

配置位置：GitHub 仓库 -> Settings -> Secrets and variables -> Actions

EOF

echo "脚本执行完成！请按照上述提示完成剩余步骤。"