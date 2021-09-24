/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #5         : Binary Search
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 9/29/21 @ 11:59PM
 *****************************************************************************************/

#include "functions.h"

/********************************************************************************
 * This function will sort our array numerically through the insertion algorithm.
 * This algorithm is designed to rearrange the order of numbers from less than
 * to greater than, left to right, replacing the desired array contents.
 ********************************************************************************/
void insertionSorting(int intArray[], const int ARRAY_SIZE) {

	cout << "\n\nPerforming Insertion Sort!" << endl;

	int temp;
	int j;

	for(int i = 1; i < ARRAY_SIZE - 1; i++ ) {

		temp = intArray[i];
		j = i - 1;

		while(j >= 0 && intArray[j] > temp) {
			intArray[j+1] = intArray[j];
			j = j - 1;
		}

		intArray[j+1] = temp;
	}

}
