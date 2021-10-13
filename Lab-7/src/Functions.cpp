/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #7         : Testing
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/13/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/****************************************************************************************
* This function can print to either the console or the output file using ostream type
* with the specified variable being passed by reference.
*****************************************************************************************/
void PrintHeader(ostream &output) {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int LAB_NUM = 7;
	const char LAB_NAME[10] = "Testing";

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

/**************************************************************************
 * This function will allow the user to enter a number of sheep/chocolate
 * bars. The values must be greater than zero and the number of sheep must
 * be greater than the number of chocolate bars since every sheep has to
 * eat the same amount of chocolate bars as the others, unless the number
 * of chocolate bars is zero, allowing all sheep to consume 0 chocolate
 * bars and leaving 0 left over at the same time.
 *************************************************************************/
void GetAndCheckInput(int& numberOfSheep, int& numberOfChocolateBars) {

	bool validInput = false;    // LCV - Used to validate the input from our user.

	do {

		// Ask the user for # of sheep
		cout << "\nHow many sheep are there? ";
		cin >> numberOfSheep;

		// Ask the user for # of chocolate bars
		cout << "\nHow many chocolate bars? ";
		cin >> numberOfChocolateBars;

		// Check for either value being less than zero. (NEGATIVE)
		if (numberOfSheep < 0 || numberOfChocolateBars < 0) {

			// Sheep Value is NEGATIVE
			if (numberOfSheep < 0 && numberOfChocolateBars < 0) {

				// Display feedback message.
				cout << "\nThere can not be negative sheep/chocolate bar values. Try again.\n";
				validInput = false;

			// Chocolate Bar Value is NEGATIVE
			} else if (numberOfSheep < 0) {
				cout << "\nThere can not be a negative sheep value. Try again!\n";
				validInput = false;
			} else if (numberOfChocolateBars < 0) {


				// Display feedback message.
				cout << "\nThere can not be negative chocolate bars. Try again!\n";
				validInput = false;

			} else {

				// Display feedback message.
				cout << "\nThere can not be negative sheep or chocolate bar values. Try again!\n";
				validInput = false;

			}

		// Is # of sheep larger than # of chocolate bars and chocolate bars isn't zero???
		} else if (numberOfSheep > numberOfChocolateBars && numberOfChocolateBars != 0) {

			// Display feedback message.
			cout << "\nSheep must all receive the same amount of chocolate bars.";
			cout << "\nPlease choose at least as many sheep as chocolate bars or zero for all. Try again!\n";
			validInput = false;

		// INPUT IS VALID
		} else {

			validInput = true;
		}

	} while(!validInput);

}

/**************************************************************************
 * This function will calculate the number of chocolate bars each sheep
 * will be allowed to have with a maximum of four per sheep. Leaving the
 * rest of the chocolate bars as the remainder.
 *************************************************************************/
void CalculateResults(int& barsLeft, int& counter, int numberOfSheep) {

	const int MAX_BARS = 4;          // CONST - Used as maximum value of chocolate bars per sheep.
	bool stillCalculating = true;    // LCV - Used to determine the length of the loop.

	while(counter < MAX_BARS && stillCalculating) {

		// Values of less than or equal to zero can skip calculations.
		if (barsLeft <= 0 || numberOfSheep <= 0) {
			stillCalculating = false;
		} else {

			// Chocolate bars left based on # of sheep.
			barsLeft = barsLeft - numberOfSheep;

			// Chocolate bars leftover is POSITIVE
			if (barsLeft >= 0) {
				stillCalculating = true;
				counter++;
			// Chocolate bars leftover is NEGATIVE
			} else {
				barsLeft = barsLeft + numberOfSheep;
				stillCalculating = false;
			}

		}

	}

}

/**************************************************************************
 * This function will display the results to the console depending on the
 * resulting values.
 *************************************************************************/
void OutputResults(int counter, int barsLeft, int numberOfChocolateBars, int numberOfSheep) {

	if (counter > 0 && numberOfChocolateBars != 0) {
		cout << "\nEach sheep will eat " << counter
			 << " chocolate bars each. Leaving " << barsLeft << " left over.";
	} else if ((counter == 0 && numberOfChocolateBars == 0) && numberOfSheep > 0) {
		cout << "\nAll " << numberOfSheep << " sheep will have " << barsLeft << " chocolate bars. Leaving " << barsLeft << " left over.";
	} else {
		cout << "\nNo sheep will eat any chocolate bars. Leaving " << barsLeft << " left over.";
	}

}


