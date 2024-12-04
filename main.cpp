#include <iostream>
#include "directory_utils.h"
#include "file_utils.h"

// Prompt 2
void showMenu() {
    std::cout << "1. List Directory Contents\n";
    std::cout << "2. Navigate Directories\n";
    std::cout << "3. Rename Files\n";
    std::cout << "4. Batch Rename with Regex\n";
    std::cout << "5. File Sorting\n";
    std::cout << "6. File Filtering\n";
    std::cout << "7. Copy/Move Files\n";
    std::cout << "8. Delete Files\n";
    std::cout << "9. Exit\n";
}

int main() {

    // Prompt 2
  int choice;
    do {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 9.\n";
            continue;
        }

        switch (choice) {
            case 1:
                listDirectoryContents();
                break;
            case 2:
                navigateDirectories();
                break;
            case 3:
                renameFiles();
                break;
            case 4:
                batchRenameWithRegex();
                break;
            case 5:
                fileSorting();
                break;
            case 6:
                fileFiltering();
                break;
            case 7:
                copyMoveFiles();
                break;
            case 8:
                deleteFiles();
                break;
            case 9:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 9.\n";
        }
    } while (choice != 9);

    return 0;
}