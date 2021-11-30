/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #13	      : Linked Lists of Sheep - OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/01/21 @ 11:59PM
 *************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Pre-processor directives
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used
#include <ostream>
#include <sstream>

using namespace std;

// Enumerated Types used for the menu options.
enum {
	Exit,              // 0
	AddSheep,          // 1
	OutputFirstSheep,  // 2
	FindSheep,         // 3
	ListSize,          // 4
	OutputList,        // 5
	ClearList,         // 6
	UnSelected,        // 7
};

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
