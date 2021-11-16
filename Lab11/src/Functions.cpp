/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #11	      : Introduction to Recursion - GCD
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/17/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/*************************************************************************
* This function can print to either the console or the output file using
* ostream type with the specified variable being passed by reference.
*
* 1 Argument passed by reference -> RETURNS: Nothing
*************************************************************************/
void PrintHeader(ostream &output) {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int LAB_NUM = 11;
	const char LAB_NAME[40] = "Introduction to Recursion - GCD";

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


/****************************************************************************************
* This function will gather the essential data that we need to make sure this program
* operates. The function will take in two integers that are being passed by reference
* in this function, that way we will be able to use the variable data in our main
* program.
*
* 2 Arguments passed by reference -> RETURNS: Nothing
*****************************************************************************************/
void GetInputFromUser(int &firstInteger, int &secondInteger) {

	cout << left << setw(28);
	cout << "\nEnter the first integer: ";
	cin >> firstInteger;

	cout << setw(27);
	cout << "Enter the second integer: ";
	cin >> secondInteger;

}


/****************************************************************************************
* This function will calculate our GCD recursively. The function is called within itself
* however many times is needed for a remainder of zero, giving the desired GCD. Once the
* GCD has been found, the resulting value will be returned to main.
*
* 2 Arguments passed by value -> RETURNS: Nothing
*****************************************************************************************/
int CalculateGCD(int firstInteger, int secondInteger){

	int GCD;          // CALC/OUT - Used for calculations by this function and returned to main for output.
	int remainder;    // CALC     - Used for calculating remainder each time function is recursively called.

	// Arrange order if the second integer is largest.
	if(secondInteger > firstInteger){
		GCD = CalculateGCD(secondInteger, firstInteger);
	}

    // Check for number initially set to zero.
	if (secondInteger == 0){
		remainder = 0;
	} else {
		// Start calculating the GCD recursively.
		remainder = firstInteger % secondInteger;
		firstInteger = secondInteger;
		secondInteger = remainder;
	}

	// GCD found.
	if (remainder == 0){
		GCD = firstInteger;
	// GCD not found.
	} else {
		GCD = CalculateGCD(firstInteger, secondInteger);
	}

	return GCD;
}


