/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #12	      : Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/24/21 @ 11:59PM
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

enum {
	Exit,                // 0
	InitializeAnimals,   // 1
	ChangeAge,           // 2
	ChangeValue,         // 3
	Display,             // 4
	Unselected,          // 5
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
 *
 *********************************************************************************/
bool ValidateNumber (string menuOptionStr);

/**********************************************************************************
 *
 *********************************************************************************/
void PrintMenuOptions(int &menuOption, bool init);



#endif /* FUNCTIONS_H_ */
