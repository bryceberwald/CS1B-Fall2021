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

// enum type for menu option
enum menu {
	Exit,        // 0
	CreateList,  // 1
	OutputList,  // 2
	UnSelected,  // 3
};

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

/**********************************************************************************
 * Function prototype for checking whether input is a valid number or not. This
 * function will take a string as a parameter and returns a boolean as a way to
 * verify the number.
 *
 * 1 Argument passed by value -> RETURNS: Boolean
 *********************************************************************************/
bool ValidateNumber (string menuOptionStr);

/*********************************************************************************
* Function prototype for printing the menu options to the console as needed. This
* function will use the ValidateNumber() function to ensure a user has entered a
* number.
*
* 1 Argument passed by reference -> RETURNS: Nothing
**********************************************************************************/
void PrintMenuOptions(int &menuOption);


#endif /* FUNCTIONS_H_ */
