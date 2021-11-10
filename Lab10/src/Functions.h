/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #9         : Creating an Ordered List
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/10/21 @ 11:59PM
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

// Enumerated Types used for the menu options.
enum {
	Exit,            // 0
	CreateList,      // 1
	DisplayList,     // 2
	IsEmpty,         // 3
	SearchByName,    // 4
	RemoveNode,      // 5
	ClearList,       // 6
	UnSelected,      // 7
};

struct PersonNode {
	string name;
	char gender;
	int age;
	PersonNode *next;
};

// Prototypes for functions used in the program.

/**********************************************************************************
 *
 *********************************************************************************/
void PrintHeader(ostream &output);

/**********************************************************************************
 *
 *********************************************************************************/
bool ValidateNumber (string menuOptionStr);

/**********************************************************************************
 *
 *********************************************************************************/
void PrintMenuOptions(int &menuOption);

/**********************************************************************************
 *
 *********************************************************************************/
PersonNode *CreateLinkedList(string inputFileName, PersonNode *head);

/**********************************************************************************
 *
 *********************************************************************************/
void DisplayLinkedList(PersonNode *head);


#endif /* FUNCTIONS_H_ */
