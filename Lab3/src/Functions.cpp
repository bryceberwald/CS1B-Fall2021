/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #3         : Functions - GCD
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 9/15/21 @ 11:59PM
 *****************************************************************************************/

#include "Functions.h";

/****************************************************************************************
* This function can print to either the console or the output file using ostream type
* with the specified variable being passed by reference.
*****************************************************************************************/
void printHeader(ostream &output) {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int LAB_NUM = 3;
	const char ASSIGNMENT_NAME[20] = "Functions - GCD";

	// Output the program header to output specified.
	output << left;
	output << "*******************************************************";
	output << "\n* PROGRAMMED BY : " << PROGRAMMER;
	output << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	output << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	output << "\n* LAB #" << setw(9) << LAB_NUM << ": " << ASSIGNMENT_NAME;
	output << "\n*******************************************************" << endl;
	output << right << endl;
}

/****************************************************************************************
* This function will return the class header as a string using ostringstream to be used
* for output for the console or output file.
*****************************************************************************************/
string printHeaderTwo() {

	ostringstream output;

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int LAB_NUM = 3;
	const char ASSIGNMENT_NAME[20] = "Functions - GCD";

	// Output the program header to output specified.
	output << left;
	output << "*******************************************************";
	output << "\n* PROGRAMMED BY : " << PROGRAMMER;
	output << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	output << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	output << "\n* LAB #" << setw(9) << LAB_NUM << ": " << ASSIGNMENT_NAME;
	output << "\n*******************************************************" << endl;
	output << right << endl;

	return output.str();
}

/****************************************************************************************
* This function will gather the essential data that we need to make sure this program
* operates. The function will take in two integers that are being passed by reference
* in this function, that way we will be able to use the variable data in our main
* program.
*****************************************************************************************/
void getIntegersFromUser(int &firstIntegerFromUser, int &secondIntegerFromUser) {
	cout << left << setw(28);
	cout << "\nEnter the first integer: ";
	cin >> firstIntegerFromUser;

	cout << setw(28);
	cout << "\nEnter the second integer: ";
	cin >> secondIntegerFromUser;
}

/****************************************************************************************
* This function will calculate the greatest common divisor by using two parameters, one
* for each integer chosen by the user, returning the GCD as the result.
*****************************************************************************************/
int calculateGCD(int firstInteger, int secondInteger) {

	int largestValue = firstInteger;      // Variable from user is reassigned to a variable by this function.
	int smallestValue = secondInteger;    // Variable from user is reassigned to a variable by this function.
	int greatestCommonDivisor;            // Used to hold and return the desired GCD result.

	// Check if the second Integer equates to zero.
	if (secondInteger == 0) {
		greatestCommonDivisor = firstInteger;
	// Check if the second number from the user is larger than the first, if so reassign variables.
	} else if (smallestValue > largestValue) {
		smallestValue = firstInteger;
		largestValue = secondInteger;
        // Start the process of calculating the GCD.
		int remainder = largestValue % smallestValue;
		while (remainder != 0) {
			largestValue = smallestValue;
			smallestValue = remainder;
			remainder = largestValue % smallestValue;
		}
		greatestCommonDivisor = smallestValue;
	} else {
		// Start the process of calculating the GCD.
		int remainder = largestValue % smallestValue;
		while (remainder != 0) {
			largestValue = smallestValue;
			smallestValue = remainder;
			remainder = largestValue % smallestValue;
		}
		greatestCommonDivisor = smallestValue;
	}

	return greatestCommonDivisor;

}

/****************************************************************************************
* This function will display our resulting GCD's to our output file. This function has
* four different variables being passed in as well. We need both integers for display
* purposes, and the current GCD, as well as the output file name.
*****************************************************************************************/
void sendResultsToFile(int firstInteger, int secondInteger, int currentGCD, string outputFileName) {

	// Initialize & open file stream.
	ofstream oFile;
	oFile.open(outputFileName, ios::app);

	// Output the results to the output file.
	oFile << "\nThe GCD for " << firstInteger << " & "
		  << secondInteger << " = " << currentGCD;

	// Close file stream.
	oFile.close();
}

