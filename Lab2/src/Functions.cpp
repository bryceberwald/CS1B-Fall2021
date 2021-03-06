/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #7         : Functions - Coin Flip
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 09/08/2021 @ 11:59PM
 *****************************************************************************************/

//Pre-processor directives
#include "Functions.h"

/**************************************************************************
 * This function reads information from the user by passing two variables
 * in by reference.
 **************************************************************************/
void readInformationFromUser(string &name, char &gender){

	cout << "\nWhat is your name? ";
	getline(cin, name);

	cout << "\nWhat is your gender (M/F)? ";
	cin >> gender;

}

/**************************************************************************
 * This function will generate a random number thats either 0 or 1. Depending
 * on the result, this function will return a boolean. True or False.
 **************************************************************************/
bool flipTheCoin() {

	int randomNumber = rand() % 2;

	if (randomNumber == 0) {
		return false;
	} else if (randomNumber == 1) {
		return true;
	}
}

/**************************************************************************
 * This function  calculates the average heads per heads divided by the
 * total number of flips.
 **************************************************************************/
float calculateAverageHeads(float heads, float totalFlips) {
	float average;

	average = heads / totalFlips;

	return average;
}

/**************************************************************************
 * This function  will display the results to the console after 3 heads
 * from the user has been achieved.
 **************************************************************************/
void displayFinalResults(float totalFlips, float averageHeads) {

	cout << "\n\n\nIt took you " << totalFlips << " tosses to get 3 heads in a row." << endl;
	cout << "On Average you flipped heads " << fixed << setprecision(0) << (averageHeads * 100) << "% of the time.";

}



