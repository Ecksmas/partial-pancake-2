#include "directory_utils.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

// Prompt 2
void listDirectoryContents() {
    std::string path = ".";
    for (const auto& entry : fs::directory_iterator(path)) {
        std::cout << entry.path() << std::endl;
    }
}

// Prompt 2
void navigateDirectories() {
    std::string path;
    std::cout << "Enter directory path: ";
    std::cin >> path;
    if (fs::exists(path) && fs::is_directory(path)) {
        fs::current_path(path);
        std::cout << "Current directory changed to: " << fs::current_path() << std::endl;
    } else {
        std::cout << "Invalid directory path.\n";
    }
}