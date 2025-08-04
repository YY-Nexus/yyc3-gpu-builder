#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include <vector>

class GpuBuilder {
public:
    GpuBuilder();
    ~GpuBuilder();

    // 初始化构建器
    bool initialize(const std::string& config_path);

    // 构建 GPU 项目
    bool build(const std::string& output_path);

    // 获取构建日志
    std::vector<std::string> get_build_logs() const;

private:
    bool load_config(const std::string& config_path);
    bool validate_config();
    bool compile_sources();
    bool link_libraries();
    bool package_output(const std::string& output_path);

    std::string config_file_;
    std::vector<std::string> build_logs_;
    bool is_initialized_;
};

#endif // BUILDER_H