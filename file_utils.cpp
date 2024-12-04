#include "file_utils.h"
#include <iostream>
#include <filesystem>
#include <regex>

namespace fs = std::filesystem;

// Prompt 2
void renameFiles()
{
    // Prompt 4
    std::string path;
    std::string newName;
    std::cout << "Enter directory path: ";
    std::cin >> path;
    std::cout << "Enter new base name for files: ";
    std::cin >> newName;

    int counter = 1;
    for (const auto &entry : fs::directory_iterator(path))
    {
        if (fs::is_regular_file(entry.status()))
        {
            std::string extension = entry.path().extension().string();
            std::string newFileName = newName + std::to_string(counter++) + extension;
            fs::rename(entry.path(), entry.path().parent_path() / newFileName);
        }
    }
}

// Prompt 2
void batchRenameWithRegex()
{
    // Prompt 4
    std::string path;
    std::string pattern;
    std::string replacement;
    std::cout << "Enter directory path: ";
    std::cin >> path;
    std::cout << "Enter regex pattern: ";
    std::cin >> pattern;
    std::cout << "Enter replacement text: ";
    std::cin >> replacement;

    std::regex re(pattern);
    for (const auto &entry : fs::directory_iterator(path))
    {
        if (fs::is_regular_file(entry.status()))
        {
            std::string oldName = entry.path().filename().string();
            std::string newName = std::regex_replace(oldName, re, replacement);
            fs::rename(entry.path(), entry.path().parent_path() / newName);
        }
    }
}

// Prompt 2
void fileSorting()
{
    // Prompt 4
    std::string path;
    std::cout << "Enter directory path: ";
    std::cin >> path;

    std::vector<fs::directory_entry> entries;
    for (const auto &entry : fs::directory_iterator(path))
    {
        entries.push_back(entry);
    }

    std::cout << "Sort by: 1. Name 2. Size 3. Date Modified 4. Type\n";
    int choice;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::sort(entries.begin(), entries.end(), [](const fs::directory_entry &a, const fs::directory_entry &b)
                  { return a.path().filename() < b.path().filename(); });
        break;
    case 2:
        std::sort(entries.begin(), entries.end(), [](const fs::directory_entry &a, const fs::directory_entry &b)
                  { return fs::file_size(a) < fs::file_size(b); });
        break;
    case 3:
        std::sort(entries.begin(), entries.end(), [](const fs::directory_entry &a, const fs::directory_entry &b)
                  { return fs::last_write_time(a) < fs::last_write_time(b); });
        break;
    case 4:
        std::sort(entries.begin(), entries.end(), [](const fs::directory_entry &a, const fs::directory_entry &b)
                  { return a.path().extension() < b.path().extension(); });
        break;
    default:
        std::cout << "Invalid choice.\n";
        return;
    }

    for (const auto &entry : entries)
    {
        std::cout << entry.path() << std::endl;
    }
}

// Prompt 2
void fileFiltering()
{
    // Prompt 4
    std::string path;
    std::string pattern;
    std::cout << "Enter directory path: ";
    std::cin >> path;
    std::cout << "Enter file extension to filter (e.g., .txt): ";
    std::cin >> pattern;

    for (const auto &entry : fs::directory_iterator(path))
    {
        if (fs::is_regular_file(entry.status()) && entry.path().extension() == pattern)
        {
            std::cout << entry.path() << std::endl;
        }
    }
}

// Prompt 2
void copyMoveFiles()
{
    // Prompt 4
    std::string sourcePath;
    std::string destinationPath;
    std::cout << "Enter source directory path: ";
    std::cin >> sourcePath;
    std::cout << "Enter destination directory path: ";
    std::cin >> destinationPath;

    std::cout << "Do you want to copy (1) or move (2) files? ";
    int choice;
    std::cin >> choice;

    for (const auto &entry : fs::directory_iterator(sourcePath))
    {
        if (fs::is_regular_file(entry.status()))
        {
            fs::path dest = destinationPath / entry.path().filename();
            if (choice == 1)
            {
                fs::copy(entry.path(), dest);
            }
            else if (choice == 2)
            {
                fs::rename(entry.path(), dest);
            }
            else
            {
                std::cout << "Invalid choice.\n";
                return;
            }
        }
    }
}

// Prompt 2
void deleteFiles()
{
    // Prompt 4
    std::string path;
    std::cout << "Enter directory path: ";
    std::cin >> path;

    std::cout << "Are you sure you want to delete all files in this directory? (y/n): ";
    char confirmation;
    std::cin >> confirmation;

    if (confirmation == 'y' || confirmation == 'Y')
    {
        for (const auto &entry : fs::directory_iterator(path))
        {
            if (fs::is_regular_file(entry.status()))
            {
                fs::remove(entry.path());
            }
        }
        std::cout << "Files deleted.\n";
    }
    else
    {
        std::cout << "Operation cancelled.\n";
    }
}