#include <iostream>
#include "functions.h"
using namespace std;

// Functions to check if certain integer exists in the array 
// if number is present, return index where number is present
int IntExistOrNo(int array [], int &size, int usernum){
    for (int i = 0; i < size; ++i){
        if (array[i] == usernum){
            return i;
        }
    }

    return -1;
}

// Function that can modify the vlaue of an integer when called w/ index of the integer in array
// return the new value and old value back to the user
int ModifyInt(int array[], int &size, int index_num, int newNum){
    array[index_num] = newNum;
    /*for (int i = 0; i < size; ++i){
    if (array[i] == array[index_num]){
        array[index_num] = newNum;
    }*/
    return newNum;
}


// Function that adds a new integer to the end of the array
void AddToEnd(int array[], int &size, int newNum){
    array[size] = newNum;
    size++;
}

// Function which takes an index of an array and replaces value with either 0
// or removes the integer altogether  
void ReplaceOrRemove(int array [], int &size, int index_num, int choice){
    if (choice == 1){
        array[index_num] = 0;
    }
    else if (choice == 2){
        // Shift elements
        for (int i = index_num; i < size - 1; ++i){
            array[i] = array[i + 1];
        }
        // Decrease the size of the array as one element is removed
        size--;
    }
}
