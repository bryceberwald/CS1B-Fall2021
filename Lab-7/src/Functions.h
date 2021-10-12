/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #7         : Testing
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/13/21 @ 11:59PM
 *************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Pre-processor directives
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used
using namespace std;

// Prototypes for functions used in the program.

// Function prototype for printing the class header to the console.
void PrintHeader(ostream &output);

// Function prototype for getting and checking the input values entered by the user.
void GetAndCheckInput(int& numberOfSheep, int& numberOfChocolateBars);

// Function prototype for calculating the amount of chocolate bars per sheep and the amount left over.
void CalculateResults(int& barsLeft, int& counter, int numberOfSheep);

// Function prototype for displaying the results to the console with respect to lab requirements.
void OutputResults(int counter, int barsLeft, int numberOfChocolateBars, int numberOfSheep);


#endif /* FUNCTIONS_H_ */
