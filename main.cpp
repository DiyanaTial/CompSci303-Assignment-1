#include <iostream>
#include <fstream>
#include "functions.cpp" // I am using MacBook and Visual Studio on Mac needs this include "functions.cpp" to run the code or it gives me linker error.
// Please uncomment #include "functions.h" for code to run and comment out #include "functions.cpp".
//#include "functions.h" 
using namespace std;

int main() {
    int i;
    // Create CONST initial size
    const int INITIALSIZE = 100;
    int size = 0;

    // dynamically allocate initial array
    int* array = new int[INITIALSIZE];
    int counter = 0;

    // Read input file, add try block in case file can't open
    ifstream inFile;
    try {
        inFile.open("A1input.txt");

        if (!inFile.is_open()) {
            throw runtime_error("Failed to open A1input.txt");
        }

        // Error handling and reading file
        while (inFile >> array[counter]) {
            // Increment counter
            counter++;

            if (counter == size) {
                int newSize = size * 2;
                int* newArray = new int[newSize];

                // Copy elements to new array
                for (int i = 0; i < size; i++) {
                    newArray[i] = array[i];
                }
                // Deallocate memory of old array
                delete[] array;
                array = newArray;
                size = newSize;
            }
        }

        // Output array elements
        /*for (int i = 0; i < counter; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;*/

        // Menu-based program using switch and case
        int userChoice = 7;
        while (userChoice != 0) {
            cout << "What would you like to do with your array?\n1. Check if integer exists in array\n2. Modify integer in array\n3. Add new integer to array\n4. Replace or Remove Integer\n5. View array\nEnter 0 to Quit\n--> ";
            cin >> userChoice;
            cout << endl;
            switch (userChoice) {
                case 1: { // Check if integer exists in array
                    try {
                        int userNum;
                        cout << "What number would you like to check if it exists in the array? ";
                        cin >> userNum;
                        cout << endl;
                        int index = IntExistOrNo(array, counter, userNum);
                        if (index != -1) {
                            cout << "Your number was found at index " << index << " in the array!" << endl << endl;
                        } 
                        else {
                            cout << "The number " << userNum << " was not found in the array." << endl << endl;
                        }
                    } catch (const out_of_range &e) {
                        cout << e.what() << endl;
                    }
                    break;
                }
                case 2: { // Modify integer in array
                    try {
                        int indexNum;
                        int newNum;
                        cout << "Please enter index number to modify: ";
                        cin >> indexNum;
                        cout << endl;
                        if (indexNum < 0 || indexNum >= counter) {
                            throw out_of_range("Index out of range");
                        }

                        int origNum = array[indexNum]; // Get the original number to be modified
                        cout << "The number at index " << indexNum << " is " << origNum << endl;
                        cout << "What number would you like to change this to? ";
                        cin >> newNum;
                        cout << endl;

                        ModifyInt(array, counter, indexNum, newNum);
                        cout << "The old number at index " << indexNum << " was " << origNum << "\nThe new number at index " << indexNum << " is " << newNum << endl << endl;
                    } 
                    catch (const out_of_range &e) {
                        cout << e.what() << endl;
                    }
                    break;
                }
                case 3: { // Add new integer to array
                    try {
                        int newNum;
                        cout << "Enter the new integer to add to array: ";
                        cin >> newNum;
                        cout << endl;
                        AddToEnd(array, counter, newNum);
                        cout << "New integer is added to the array." << endl << endl;
                    } 
                    catch (const bad_alloc &e) {
                        cout << "Failed to allocate memory for the new integer." << endl;
                    }
                    break;
                }
                case 4: { // Replace or Remove Integer
                    try {
                        int indexNum;
                        int userChoice;
                        cout << "Please enter index number to modify: ";
                        cin >> indexNum;
                        cout << endl;
                        if (indexNum < 0 || indexNum >= counter) {
                            throw out_of_range("Index out of range");
                        }

                        cout << "The number at index " << indexNum << " is " << array[indexNum] << endl;
                        cout << "Would you like to:\n1. replace the value with 0\n2. remove the integer? -> ";
                        cin >> userChoice;
                        cout << endl;

                        if (!(userChoice == 1 || userChoice == 2)) {
                            throw invalid_argument("Please choose 1 or 2");
                        }

                        ReplaceOrRemove(array, counter, indexNum, userChoice);
                    } 
                    
                    catch (const out_of_range &e) {
                        cout << e.what() << endl;
                    } 
                    catch (const invalid_argument &e) {
                        cout << e.what() << endl;
                    }
                    break;
                }
                case 5: { // output array elements
                    for (int i = 0; i < counter; ++i) {
                        cout << array[i] << " ";
                    }
                    cout << endl << endl;
                }
            }
        }
        // Close the file
        inFile.close();
    } 
    // catch all exceptions
    catch (const runtime_error &e) {
        cout << e.what() << endl;
    } 
    catch (const bad_alloc &e) {
        cout << "Failed to allocate memory for the array." << endl;
    } 
    catch (...) {
        cout << "An unexpected error occurred." << endl;
    }

    // Deallocate memory of dynamic array
    delete[] array;

    return 0;
}
