/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #11	      : Introduction to Recursion - GCD
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/17/21 @ 11:59PM
 *************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Pre-processor directives
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used
#include <ostream>
#include <fstream>
using namespace std;

// Prototypes for functions used in the program.

/**********************************************************************************
 * Function prototype for printing the class header to the console with one
 * parameter being passed by reference to determine where we want to output to the
 * console or an output file. In the case of this program we will be outputting to
 * the console.
 *
 * 1 Argument passed by reference -> RETURNS: Nothing
 *********************************************************************************/
void PrintHeader(ostream &output);

/**********************************************************************************
 * Function prototype for getting two integers from the user of the program. We
 * will be passing variables by reference, so they can be used in main by other
 * functions in this program.
 *
 * 2 Argument passed by reference -> RETURNS: Nothing
 *********************************************************************************/
void GetInputFromUser(int &firstInteger, int &secondInteger);

/**********************************************************************************
 * Function prototype for calculating the GCD recursively. This function will
 * continue to call itself within the function until a remainder of zero is found,
 * letting us know we have found our desired GCD, which will then be returned by
 * the function to main for outputting reasons.
 *
 * 2 Argument passed by value -> RETURNS: Integer
 *********************************************************************************/
int CalculateGCD(int firstInteger, int secondInteger);


#endif /* FUNCTIONS_H_ */
