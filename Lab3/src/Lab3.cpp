/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #3         : Functions - GCD
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 9/15/21 @ 11:59PM
 *****************************************************************************************/

#include "Functions.h";

/******************************************************************************************
 *
 * Lab #3: Functions - GCD
 *
 * ________________________________________________________________________________________
 *
 * This program will use a combination of five functions to best assist myself through
 * breaking up code into smaller segments. This program will run a number of times, with
 * this program running four times for test cases. After each set of integers is typed
 * by the user, a GCD will be calculated and displayed in the output file according
 * to the lab directions. Also, two sets of class headers will output to the console and
 * output file using two different approaches and differing libraries.
 * ________________________________________________________________________________________
 *
 *
 * INPUT:
 *    firstIntegerFromUser      - User inputs this integer to be used for calculations.
 *    secondIntegerFromUser     - User inputs this integer to be used for calculations.
 *
 *
 * OUTPUT:
 *    currentGCD                - Variable used to hold the current GCD before a new set
 *                                of integers is required, displaying output in a file.
 *
 ******************************************************************************************/

int main() {

	string outputFileName = "OFile.txt";    // Predetermined output file name.

	int firstIntegerFromUser;               // INPUT/OUTPUT - Determined by user & used for display purposes.
	int secondIntegerFromUser;              // INPUT/OUTPUT - Determined by user & used for display purposes.
	int currentGCD;                         // CALC/OUTPUT - The GCD is returned and assigned to this variable.

	// Print the header to the console.
	printHeader(cout);

	// Print the string being returned by this function to the console.
	cout << printHeaderTwo();

	// Initialize & open file stream.
	ofstream oFile;
	oFile.open(outputFileName, ios::app);

	// Function prints header to the output file.
	printHeader(oFile);

	// Prints the returned string to the output file.
	oFile << printHeaderTwo();

	// Close file stream.
	oFile.close();

	for (int i = 0; i < 4; i++) {

		// Call function to read in two integers from the user.
		getIntegersFromUser(firstIntegerFromUser, secondIntegerFromUser);

		// Call function to calculate GCD and assign return value to currentGCD.
		currentGCD = calculateGCD(firstIntegerFromUser, secondIntegerFromUser);

		// Call function to output the resulting GCD to the output file.
		sendResultsToFile(firstIntegerFromUser, secondIntegerFromUser, currentGCD, outputFileName);

	}

	cout << "\n\nThank you for using my GCD calculator!";

	return 0;
}
