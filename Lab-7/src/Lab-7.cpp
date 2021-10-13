/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #7         : Testing
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/13/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/**************************************************************************
 *
 * Lab #7 : Testing
 *
 * ________________________________________________________________________
 *
 *
 * Description goes here...
 *
 *
 * ________________________________________________________________________
 *
 *
 * INPUT:
 *
 *
 *
 * OUTPUT:
 *
 *
 **************************************************************************/

int main() {

	int numberOfChocolateBars = 0;     // INPUT       - User determines this value
	int numberOfSheep = 0;             // INPUT/CALC  - User determine this value and is used for calculating results.

	int barsLeft = 0;                  // CALC/OUTPUT - Initial total amount is assigned to this variable for further estimations.
	int counter = 0;                   // CALC/OUTPUT - Used to calculate the amount of chocolate bars per sheep. (Max of 4)

	// Call function to print the class header to the console.
	PrintHeader(cout);

	// Test stub # 1
	cout << "\nTest Stub for GetAndCheckInput() Function: ";
	cout << "\nThe number of sheep prior to the function call is: " << numberOfSheep;
	cout << "\nThe number of chocolate bars prior to the function call is: " << numberOfChocolateBars << endl;

	// Call function to get and check the input values from the user.
	GetAndCheckInput(numberOfSheep, numberOfChocolateBars);

	// Test driver # 1
	cout << "\nTest Driver for GetAndCheckInput() Function: ";
	cout << "\nThe number of sheep returned is: " << numberOfSheep;
	cout << "\nThe number of chocolate bars returned is: " << numberOfChocolateBars << endl;

	// Assign the initial value of bars left to the total number of bars.
	barsLeft = numberOfChocolateBars;

	// Test stub # 2
	cout << "\nTest Stub for CalculateResults() Function: ";
	cout << "\nThe number of chocolate bars per sheep prior to function call is : " << counter;
	cout << "\nThe number of chocolate bars remaining prior to function call is : " << barsLeft << endl;

	// Call function to calculate the number of bars each sheep will eat and the remainder.
	CalculateResults(barsLeft, counter, numberOfSheep);

	// Test driver # 2
	cout << "\nTest Driver for CalculateResults() Function: ";
	cout << "\nThe number of chocolate bars per sheep returned is: " << counter;
	cout << "\nThe number of chocolate bars remaining returned is: " << barsLeft << endl;

	// Call function to display the results via the console.
	OutputResults(counter, barsLeft, numberOfChocolateBars, numberOfSheep);

	// Test driver # 3
	cout << "\n\nTest Driver for OutputResults() Function: ";
	cout << "\nNo values are returned by this function.";

	return 0;
}
