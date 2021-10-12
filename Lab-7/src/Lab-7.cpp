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

	// Call function to get and check the input values from the user.
	GetAndCheckInput(numberOfSheep, numberOfChocolateBars);

	// Assign the initial value of bars left to the total number of bars.
	barsLeft = numberOfChocolateBars;

	// Call function to calculate the number of bars each sheep will eat and the remainder.
	CalculateResults(barsLeft, counter, numberOfSheep);

	// Call function to display the results via the console.
	OutputResults(counter, barsLeft, numberOfChocolateBars, numberOfSheep);

	return 0;
}
