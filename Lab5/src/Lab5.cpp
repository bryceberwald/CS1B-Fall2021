/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #5         : Binary Search
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 9/29/21 @ 11:59PM
 *****************************************************************************************/

#include "functions.h"

/******************************************************************************************
 *
 * Lab #5 : Binary Search
 *
 * ________________________________________________________________________________________
 *
 * This program will use an array with known values already preset. First, the program will
 * output the original array contents to the console followed by a sequential search that
 * allows the user to get a returned index from the sequential search function. After four
 * sequential searches, the array will be sorted through the insertion method learned in
 * class. After the numbers have been numerically ordered, a binary search will occur
 * four times as well, also returning the proper index in which the search item was found
 * or not found.
 * ________________________________________________________________________________________
 *
 *
 * INPUT:
 *	 integerSearchedFor  - Variable entered by user/reused by user to search array contents.
 *
 *
 * OUTPUT:
 *   intArray[]          - Array contents will be used for display via console.
 *   integerSearchedFor  - Number entered by user will be used for display purposes.
 *
 ******************************************************************************************/

int main() {

	const int ARRAY_SIZE = 8;                                  // CONST - Used to set array length and know size.
	int intArray[ARRAY_SIZE] = {4, 1, 7, 12, 8, 13, 9, 21};    // CALC/OUTPUT - Used for searching, sorting, & displaying to console.
	int integerSearchedFor;                                    // INPUT/CALC/OUTPUT - Used for searching array and displaying results.

	// Declared variables to be used for outputting class header.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int LAB_NUM = 5;
	const char ASSIGNMENT_NAME[25] = "Binary Search";

	// Print the class header to the console.
	cout << left;
	cout << "*******************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << ASSIGNMENT_NAME;
	cout << "\n*******************************************************" << endl;
	cout << right;

	// Display original array contents to the console.
	outputArrayContents(intArray, ARRAY_SIZE);

	// Loops four times for the sequential search.
	for (int i = 0; i < 4; i++) {

		int returnedIndex;

		// What integer does the user want to search for?
		cout << "\n\nEnter an integer to search for: ";
		cin >> integerSearchedFor;

		// Returned value gets stored in this variable.
		returnedIndex = sequentialSearch(intArray, ARRAY_SIZE, integerSearchedFor);

		if (returnedIndex >= 0) {
			cout << "The integer " << integerSearchedFor << " was found in index #" << returnedIndex << ".";
		} else {
			cout << "The integer " << integerSearchedFor << " was not found!";
		}
	}

	// Call function to sort array with insertion method.
	insertionSorting(intArray, ARRAY_SIZE);

	// Display sorted array contents to the console.
	outputArrayContents(intArray, ARRAY_SIZE);

	// Loops four times for the binary search.
	for (int i = 0; i < 4; i++) {

		int returnedIndex;

		// What integer does the user want to search for?
		cout << "\n\nEnter an integer to search for: ";
		cin >> integerSearchedFor;

		// Returned value gets stored in this variable.
		returnedIndex =  binarySearch(intArray, ARRAY_SIZE, integerSearchedFor);

		if (returnedIndex >= 0) {
			cout << "The integer " << integerSearchedFor << " was found in index #" << returnedIndex << ".";
		} else {
			cout << "The integer " << integerSearchedFor << " was not found!";
		}
	}

	return 0;
}
