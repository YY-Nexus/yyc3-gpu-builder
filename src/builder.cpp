#include "builder.h"
#include <fstream>
#include <iostream>
#include <sstream>

GpuBuilder::GpuBuilder() : is_initialized_(false) {
    build_logs_.push_back("GpuBuilder initialized");
}

GpuBuilder::~GpuBuilder() {
    if (is_initialized_) {
        build_logs_.push_back("GpuBuilder cleaned up");
    }
}

bool GpuBuilder::initialize(const std::string& config_path) {
    build_logs_.push_back("Initializing GpuBuilder");

    if (!load_config(config_path)) {
        build_logs_.push_back("Failed to load config");
        return false;
    }

    if (!validate_config()) {
        build_logs_.push_back("Config validation failed");
        return false;
    }

    is_initialized_ = true;
    build_logs_.push_back("GpuBuilder initialized successfully");
    return true;
}

bool GpuBuilder::build(const std::string& output_path) {
    if (!is_initialized_) {
        build_logs_.push_back("Error: Not initialized");
        return false;
    }

    build_logs_.push_back("Starting build process");

    if (!compile_sources()) {
        build_logs_.push_back("Compilation failed");
        return false;
    }

    if (!link_libraries()) {
        build_logs_.push_back("Linking failed");
        return false;
    }

    if (!package_output(output_path)) {
        build_logs_.push_back("Packaging failed");
        return false;
    }

    build_logs_.push_back("Build completed successfully");
    return true;
}

std::vector<std::string> GpuBuilder::get_build_logs() const {
    return build_logs_;
}

bool GpuBuilder::load_config(const std::string& config_path) {
    std::ifstream file(config_path);
    if (!file.is_open()) {
        return false;
    }

    config_file_ = config_path;
    build_logs_.push_back("Config loaded: " + config_path);
    return true;
}

bool GpuBuilder::validate_config() {
    // 实际项目中这里应该有更复杂的配置验证逻辑
    build_logs_.push_back("Config validated");
    return true;
}

bool GpuBuilder::compile_sources() {
    // 模拟编译过程
    build_logs_.push_back("Compiling sources");
    return true;
}

bool GpuBuilder::link_libraries() {
    // 模拟链接过程
    build_logs_.push_back("Linking libraries");
    return true;
}

bool GpuBuilder::package_output(const std::string& output_path) {
    // 模拟打包过程
    build_logs_.push_back("Packaging output to: " + output_path);
    return true;
}