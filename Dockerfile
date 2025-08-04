# 使用官方 Ubuntu 镜像作为基础
FROM ubuntu:22.04

# 设置非交互式安装以避免卡住
ENV DEBIAN_FRONTEND=noninteractive

# 更新包列表并安装必要的依赖（固定版本）
RUN apt-get update && apt-get install -y build-essential=12.9 cmake=3.22.1-1ubuntu1.22.04.1 git=1:2.34.1-1ubuntu1.10 && rm -rf /var/lib/apt/lists/*

# 设置工作目录
WORKDIR /app

# 复制必要的项目文件
COPY CMakeLists.txt .
COPY src/ ./src/
COPY include/ ./include/

# 构建项目
RUN mkdir -p build && cd build && cmake .. && make

# 创建非 root 用户
RUN useradd -m appuser
USER appuser

# 设置默认命令
CMD ["/app/build/yyc3-gpu-builder"]