# partial-pancake-2
This is a partial turn in for a course in my vocational school

// Prompt 6
# File Organization Tool

## Overview
The File Organization Tool is a C++ application with a Text User Interface (TUI) that allows users to manage files and directories. The tool provides functionalities such as listing directory contents, navigating directories, renaming files, batch renaming with regex, sorting files, filtering files, copying/moving files, and deleting files.

## Features
1. **List Directory Contents**: Display files and folders in the current directory.
2. **Navigate Directories**: Change the current directory (e.g., cd functionality) and provide navigation shortcuts like `..` (parent directory).
3. **Rename Files**: Rename all files in a directory to a uniform format and append custom extensions to filenames.
4. **Batch Rename with Regex**: Apply regex patterns to rename files partially (e.g., search and replace text in filenames).
5. **File Sorting**: Sort files by name, size, date modified, or type.
6. **File Filtering**: Filter files displayed based on patterns or extensions.
7. **Copy/Move Files**: Copy or move files between directories.
8. **Delete Files**: Delete selected files (with a confirmation prompt).

## Requirements
- CMake 3.10 or higher
- C++17 compatible compiler
- Visual Studio Code (optional, for development)

## Building the Project
1. **Clone the repository**:
    ```sh
    git clone <repository-url>
    cd <repository-directory>
    ```

2. **Create a build directory**:
    ```sh
    mkdir build
    cd build
    ```

3. **Run CMake to configure the project**:
    ```sh
    cmake ..
    ```

4. **Build the project**:
    ```sh
    cmake --build .
    ```

## Running the Application
1. **Navigate to the build directory**:
    ```sh
    cd build
    ```

2. **Run the executable**:
    ```sh
    ./FileOrganizationTool
    ```

## Usage
1. **List Directory Contents**: 
    - Select option 1 to display files and folders in the current directory.
    - Example: 
      ```
      Enter your choice: 1
      ```

2. **Navigate Directories**: 
    - Select option 2 and enter the path to change the current directory.
    - Example: 
      ```
      Enter your choice: 2
      Enter directory path: test
      ```
    - To navigate to the parent directory:
      ```
      Enter directory path: ..
      ```

3. **Rename Files**: 
    - Select option 3 and follow the prompts to rename files in a directory.
    - You will be asked to enter the directory path and the new base name for the files.
    - Example: 
      ```
      Enter your choice: 3
      Enter directory path: test
      Enter new base name for files: newname
      ```

4. **Batch Rename with Regex**: 
    - Select option 4 and follow the prompts to apply regex patterns to rename files.
    - You will be asked to enter the directory path, the regex pattern, and the replacement text.
    - Example: 
      ```
      Enter your choice: 4
      Enter directory path: test
      Enter regex pattern: oldname
      Enter replacement text: newname
      ```

5. **File Sorting**: 
    - Select option 5 and choose the sorting criteria.
    - You will be asked to enter the directory path and the sorting criteria (1 for Name, 2 for Size, 3 for Date Modified, 4 for Type).
    - Example: 
      ```
      Enter your choice: 5
      Enter directory path: test
      Sort by: 1. Name 2. Size 3. Date Modified 4. Type
      Enter your choice: 1
      ```

6. **File Filtering**: 
    - Select option 6 and enter the file extension to filter files.
    - You will be asked to enter the directory path and the file extension.
    - Example: 
      ```
      Enter your choice: 6
      Enter directory path: test
      Enter file extension to filter (e.g., .txt): .txt
      ```

7. **Copy/Move Files**: 
    - Select option 7 and follow the prompts to copy or move files between directories.
    - You will be asked to enter the source directory path, the destination directory path, and whether you want to copy (1) or move (2) the files.
    - Example: 
      ```
      Enter your choice: 7
      Enter source directory path: test
      Enter destination directory path: test2
      Do you want to copy (1) or move (2) files? 1
      ```

8. **Delete Files**: 
    - Select option 8 and confirm to delete files in a directory.
    - You will be asked to enter the directory path and confirm the deletion.
    - Example: 
      ```
      Enter your choice: 8
      Enter directory path: test
      Are you sure you want to delete all files in this directory? (y/n): y
      ```

9. **Exit**: 
    - Select option 9 to exit the application.
    - Example: 
      ```
      Enter your choice: 9
      ```

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request for any enhancements or bug fixes.