/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #3         : Functions - GCD
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 9/15/21 @ 11:59PM
 *****************************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Pre-processor directives
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used
#include <ostream>  // For stream interchangeability
#include <fstream>  // For Files
#include <sstream>  // For ostringstream
using namespace std;

// Prototypes for functions used in the program.

// Function prototype for printing header to console or file using ostream to determine where to output.
void printHeader(ostream &output);

// Function prototype for printing header to console or file using ostringstream to return a string.
string printHeaderTwo();

// Function prototype for reading in two integers from the user.
void getIntegersFromUser(int &firstIntegerFromUser, int &secondIntegerFromUser);

// Function prototype for calculating the GCD from the users input.
int calculateGCD(int firstInteger, int secondInteger);

// Function prototype for displaying GCD results to the output file.
void sendResultsToFile(int firstInteger, int secondInteger, int currentGCD, string outputFileName);

#endif /* FUNCTIONS_H_ */
