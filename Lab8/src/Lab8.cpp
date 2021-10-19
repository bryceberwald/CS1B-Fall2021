/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #8         : Introduction to Pointers
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/20/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/**************************************************************************
 *
 * Lab #8 : Introduction to Pointers
 *
 * ________________________________________________________________________
 *
 * This program only uses THREE variables in total. The FIRST variable is a
 * static integer type variable which gets pointed to by the SECOND variable
 * which is a pointer that is assigned to the address of the static variable.
 * The program will dynamically allocate memory for a new integer pointer
 * that will be used for input, calculations and output. The dynamically
 * allocated pointer will be deleted after used for outputting the sum and
 * product of the users input values. The program will continue to execute
 * until the value of -999 is entered for the first input value.
 * ________________________________________________________________________
 *
 *
 * INPUT:
 *   *valueToCalculate        - Pointer is used for the first input value
 *   *secondValueToCalculate  - Pointer is dynamically allocated and used
 *                              for the second input value.
 *
 *
 * OUTPUT:
     *valueToCalculate        - Pointer used for calculations and displaying results.
 *   *secondValueToCalculate  - Pointer used for calculations and displaying results.
 *
 *
 **************************************************************************/

int main() {

	// Call function to print the class header to the console.
	PrintHeader(cout);

	int valueToCalculate;             // LCV - Static variable that gets pointed to and used as the loop control variable.
	int *valueToCalculatePtr;         // INP/OUT/CALC - Used to point to the static variable. Used for input, calculations & output.
	int *secondValueToCalculatePtr;   // INP/OUT/CALC - Dynamically allocated pointer. Used for input, calculations & output.

	// Assign pointer variable to the address of the static variable.
	valueToCalculatePtr = &valueToCalculate;

	// Default value is set to NULL.
	secondValueToCalculatePtr = NULL;

	// Ask the user for the first integer value.
	cout << "\nInput the first value (enter -999 to exit)? ";
	cin >> *valueToCalculatePtr;

	// Loop until the first integer value is -999.
	while (valueToCalculate != -999) {

		// Dynamically allocate memory for a new integer pointer.
		secondValueToCalculatePtr = new int;

		// Check to ensure newly created pointer is NOT equal to NULL.
		if (secondValueToCalculatePtr != NULL) {

			// Ask the user for the second integer value.
			cout << left << setw(44);
			cout << "Input the second value? ";
			cin >> *secondValueToCalculatePtr;

			// Output the final results to the console.
			cout << "\nThe sum is: " << right << setw(6) << *valueToCalculatePtr + *secondValueToCalculatePtr;
			cout << "\nThe product is: " << *valueToCalculatePtr * *secondValueToCalculatePtr << endl;

		// Check has failed!
		} else {
			cout << "\nOut of memory! Something has gone wrong!" << endl;
		}

		// Reallocate back memory.
		delete secondValueToCalculatePtr;

		// Assign pointer variable to NULL.
		secondValueToCalculatePtr = NULL;

		// Reset the static integer to a value of zero.
		valueToCalculate = 0;

		// Ask the user for the first integer value again.
		cout << "\nInput the first value (enter -999 to exit)? ";
		cin >> *valueToCalculatePtr;

	}

	return 0;
}

/****************************************************************************************
* This function can print to either the console or the output file using ostream type
* with the specified variable being passed by reference.
*****************************************************************************************/
void PrintHeader(ostream &output) {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int LAB_NUM = 8;
	const char LAB_NAME[30] = "Introduction to Pointers";

	// Output the program header to output specified.
	output << left;
	output << "*******************************************************";
	output << "\n* PROGRAMMED BY : " << PROGRAMMER;
	output << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	output << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	output << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	output << "\n*******************************************************" << endl;
	output << right;
}
