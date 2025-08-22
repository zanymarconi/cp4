#ifndef IO_REDIRECT_H
#define IO_REDIRECT_H

#include <filesystem>

void redirect_input_output(const char* source_file) {
    // Redirect standard input and output to files
    std::filesystem::path path = source_file;
    std::string input_file = path.stem().string() + ".in";
    freopen(input_file.c_str(), "r", stdin);
    
    std::string output_file = path.stem().string() + ".out";
    freopen(output_file.c_str(), "w", stdout);
}

#endif // IO_REDIRECT_H