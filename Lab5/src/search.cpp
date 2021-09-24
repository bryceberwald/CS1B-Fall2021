/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #5         : Binary Search
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 9/29/21 @ 11:59PM
 *****************************************************************************************/

#include "functions.h"

/*******************************************************************************
 * This function performs a sequential search, looping through each array
 * contents individually to see if we have a match. If we do have a match in
 * our array, the function will return the proper index. If no value was found
 * for the value being searched for then the default value is set to negative
 * one as the return value.
 ******************************************************************************/
int sequentialSearch(const int intArray[], const int ARRAY_SIZE, int integerSearchedFor) {

	int foundIndex = -1;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (intArray[i] == integerSearchedFor) {
			foundIndex = i;
		}
	}

	return foundIndex;
}

/*******************************************************************************
 * This function performs a binary search, using a while loop to cut the array
 * contents in half continually until the number is found or not found. If the
 * middle index holds the desired value, the while loop will terminate, if not
 * the top and bottom values will be reassigned to reassign the middle,
 * searching through the contents once more.
 ******************************************************************************/
int binarySearch(const int intArray[], const int ARRAY_SIZE, int integerSearchedFor) {

	int bottom;
	int middle;
	int top;
	int foundIndex = -1;

	bottom = 0;
	middle = 0;
	top = ARRAY_SIZE -1;



	bool found = false;

	while(!found && bottom <= top) {
		middle = (bottom + top) / 2;

		if (intArray[middle] == integerSearchedFor) {
			found = true;
			foundIndex = middle;
		} else {
			if (intArray[middle] < integerSearchedFor) {
				bottom = middle + 1;
			} else {
				top = middle - 1;
			}
		}
	}

	return foundIndex;
}
