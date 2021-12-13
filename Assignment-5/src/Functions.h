/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #5  : DVD Movie List - Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/15/2021 @ 11:59PM
 ******************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//Pre-processor directives
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings
#include <ostream>
#include <sstream>
#include <fstream>
using namespace std;

//Prototypes for functions used in the program.

/*********************************************************************************
* This is the function prototype for printing the class header to the
* console.
*
* 1 Argument passed by reference -> RETURNS: Nothing
**********************************************************************************/
void PrintHeader(ostream &output);

/**********************************************************************************
* This is the function prototype for reading in the file names from the
* user. We will need to get an input file name and an output file name
* from the user. The variables will be stored in main.
*
* 2 Arguments passed by reference -> RETURNS: Nothing
**********************************************************************************/
void ReadFileNames(string &inputFileName, string &outputFileName);


#endif /* FUNCTIONS_H_ */
