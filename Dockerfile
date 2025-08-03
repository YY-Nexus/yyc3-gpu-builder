# 使用官方 Ubuntu 镜像作为基础
FROM ubuntu:22.04

# 设置非交互式安装以避免卡住
ENV DEBIAN_FRONTEND=noninteractive

# 更新包列表并安装必要的依赖
RUN apt-get update && apt-get install -y \n    build-essential \n    cmake \n    git \n    && rm -rf /var/lib/apt/lists/*

# 设置工作目录
WORKDIR /app

# 复制项目文件（假设存在源代码）
COPY . .

# 构建项目
RUN mkdir -p build && cd build && cmake .. && make

# 设置默认命令
CMD ["/app/build/your-app-name"]