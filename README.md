# C++ Array Operations Program

## Overview
This C++ program reads data from an input file into a one-dimensional array and performs various operations on the array as described in the assignment.

## Table of Contents
- [Instructions](#instructions)
- [Setup](#setup)
- [Visual Studio on Mac](#visual-studio-on-mac)
- [Compilation and Execution](#compilation-and-execution)
- [Usage](#usage)
- [Functions](#functions)
- [Error Handling](#error-handling)
- [Contributing](#contributing)
- [License](#license)
  
## Instructions

### Setup
1. Clone this repository to your local machine.
2. Ensure you have a C++ compiler installed on your system.
3. If you're using Visual Studio on Mac and encounter linker errors, follow the next step.
To run this program, follow these steps:

### Visual Studio on Mac
If you're using Visual Studio on Mac and encounter linker errors, follow these steps:

1. Uncomment the line `#include "functions.cpp"` in the `main.cpp` file.
2. Comment out the line `#include "functions.h"` in the `main.cpp` file.

### Compilation and Execution
1. Clone this repository to your local machine
2. Compile the 'main.cpp' file using a C++ compiler.
```
g++ main.cpp -o program
```
3. Run the compiled executable.
```
./program
```
### Usage
Once the program is running, you will be prompted to enter the filename of the input file containing the data. After reading the data, you can choose from various operations to perform on the array.

### Functions
1. **Check if Integer Exists**
   - `int IntExistOrNo(int array[], int &size, int usernum)` - Checks if a certain integer exists in the array and returns the index where the number is present. Returns -1 if the number is not found.

2. **Modify Integer Value**
   - `int ModifyInt(int array[], int &size, int index_num, int newNum)` - Modifies the value of an integer in the array at the specified index and returns the new value.

3. **Add New Integer**
   - `void AddToEnd(int array[], int &size, int newNum)` - Adds a new integer to the end of the array.

4. **Replace or Remove Integer**
   - `void ReplaceOrRemove(int array[], int &size, int index_num, int choice)` - Replaces the value at the specified index with either 0 or removes the integer altogether from the array.
     
### Error Handling
This program implements error handling using try-catch blocks to handle various exceptions that may occur during execution:

1. **File Opening Error**: If the input file cannot be opened, a `runtime_error` exception is thrown, indicating the failure to open the file.

2. **Memory Allocation Error**: If there is insufficient memory to allocate for the array, a `bad_alloc` exception is thrown, indicating a failure to allocate memory.

3. **Out of Range Error**: If the user attempts to access an index that is out of range, a `out_of_range` exception is thrown, providing a message indicating the index is out of range.

4. **Invalid Argument Error**: If the user provides an invalid choice for replacing or removing an integer, an `invalid_argument` exception is thrown, indicating that the user should choose either 1 or 2.

These exceptions are caught within the program and appropriate error messages are displayed to the user to help identify and resolve the issues.

### Contributing
Contributions are welcome! Please feel free to submit pull requests or open issues for any improvements or fixes.

### License
This project is licensed under the MIT License.

