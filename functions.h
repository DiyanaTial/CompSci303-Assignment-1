#ifndef MYHEADER_H
#define MYHEADER_H
#include <iostream>

using namespace std;

// Function to check if certain integer exists in the array 
// if number is present, return index where number is present
int IntExistOrNo(int array [], int &size, int usernum);

// Function that can modify the vlaue of an integer when called w/ index of the integer in array
// return the new value and old value back to the user
int ModifyInt(int array [], int &size, int index_num, int newNum);

// Function that adds a new integer to the end of the array
void AddToEnd(int array [], int &size, int newNum);

// Function which takes an index of an array and replaces value with either 0
// or removes the integer altogether  
void ReplaceOrRemove(int array [], int &size, int index_num, int choice);

#endif
