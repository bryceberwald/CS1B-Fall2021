/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #11	      : Introduction to Recursion - GCD
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/17/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/**************************************************************************
 *
 * Lab #11 : Introduction to Recursion - GCD
 *
 * ________________________________________________________________________
 *
 * This program is an extended implementation of Lab #3 using recursion to
 * solve the GCD problem we are solving instead of an iterating with a loop.
 * This program uses only a couple different functions. One for getting the
 * integers as input from the user, another function for calculating the GCD
 * recursively and finally a function to print the class header to the console
 * or output file as needed. The programs runs a predetermined number of 4
 * times as specified in class.
 * ________________________________________________________________________
 *
 * INPUT:
 *    firstInt  - User enters a integer value to be stored in this variable.
 *    secondInt - User enters a integer value to be stored in this variable.
 *
 * OUTPUT:
 *    firstInt  - Variable is used for calculations before the output.
 *    secondInt - Variable is used for calculations before the output.
 *    GCD       - Variable is returned by CalculateGCD() function for output.
 *
 **************************************************************************/

int main() {

	int firstInt;           // IN/OUT/CALC - Used as the first integer value entered by the user for calculations.
	int secondInt;          // IN/OUT/CALC - Used as the second integer value entered by user for calculations.
	int GCD = 0;            // OUT/CALC    - Initialized and set to zero, changes after calculations.

	// Initialize an output file variable to use in our program.
	ofstream oFile;

	// Open the output file with it being appended to.
	oFile.open("OFile.txt", ios::app);

	// Call function to print the class header to file.
	PrintHeader(oFile);

	// Call function to print the class header to console.
	PrintHeader(cout);

	for (int i = 0; i < 4; i++){

		// Call function to get two integers from the user.
		GetInputFromUser(firstInt, secondInt);

		// Call function to calculate the GCD recursively.
		GCD = CalculateGCD(firstInt, secondInt);

		// Display the resulting GCD to the console.
		oFile << "\nThe GCD of " << firstInt << " & " << secondInt << " is: " << GCD << endl;

	}

	// Display termination messages to the console and output file.
	cout << "\nThank you for using my GCD calculator!\n";
	oFile << "\nProgram has terminated! All results are displayed...\n";

	// Close output file.
	oFile.close();

	return 0;
}
