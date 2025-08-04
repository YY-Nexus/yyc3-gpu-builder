cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(yyc3-gpu-builder)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加头文件目录
include_directories(include)

# 收集源文件
file(GLOB SOURCES "src/*.cpp")

# 创建可执行文件
add_executable(yyc3-gpu-builder ${SOURCES})

# 如果有额外的库需要链接
# target_link_libraries(yyc3-gpu-builder <library_name>)