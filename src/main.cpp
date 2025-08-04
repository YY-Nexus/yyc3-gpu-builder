#include "builder.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <config_path> <output_path>" << std::endl;
        return 1;
    }

    std::string config_path = argv[1];
    std::string output_path = argv[2];

    GpuBuilder builder;

    if (!builder.initialize(config_path)) {
        std::cerr << "Failed to initialize builder" << std::endl;
        return 1;
    }

    if (!builder.build(output_path)) {
        std::cerr << "Build failed" << std::endl;
        return 1;
    }

    std::cout << "Build completed successfully" << std::endl;

    // 输出构建日志
    std::cout << "\nBuild Logs:\n" << std::endl;
    for (const auto& log : builder.get_build_logs()) {
        std::cout << log << std::endl;
    }

    return 0;
}