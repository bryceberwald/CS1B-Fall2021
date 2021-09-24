/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #5         : Binary Search
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 9/29/21 @ 11:59PM
 *****************************************************************************************/

#include "functions.h"

/*******************************************************************************
 * This function is designed to output the array contents to the console as
 * needed. Nothing is returned, but the console gets output of each index's
 * value.
 ******************************************************************************/
void outputArrayContents(const int intArray[], const int ARRAY_SIZE) {

	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << "\nIndex #" << i << ": " << intArray[i];
	}
}

