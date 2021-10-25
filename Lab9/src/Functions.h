/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #9         : Implementing a Stack
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/27/21 @ 11:59PM
 *************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Pre-processor directives
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used
using namespace std;

// Enumerated Types
enum {
	Exit,            // 0
	Push,            // 1
	Pop,             // 2
	IsEmpty,         // 3
	Peek,            // 4
	Size,            // 5
	UnSelected,      // 6
};

// Struct Definitions
struct PersonNode {
    string name;
    char gender;
    int age;
    PersonNode *next;
};


// Prototypes for functions used in the program.

/**********************************************************************************
 * Function prototype for printing the class header to the console with one
 * parameter being passed by reference to determine where we want to output to the
 * console or an output file. In the case of this program we will be outputting to
 * the console.
 *********************************************************************************/
void PrintHeader(ostream &output);

/**********************************************************************************
 * Function prototype for printing menu options with one parameter passed by
 * reference. Nothing is returned by this function by the variable being passed by
 * reference to the function will be updated in main as well.
 *********************************************************************************/
void PrintMenuOptions(int &menuOption);

/**********************************************************************************
 * Function prototype for pushing a new item into a linked list. One parameter is
 * being passed by value and is returned to the main program to have the updated
 * head of our linked list.
 *********************************************************************************/
PersonNode *PushItem(PersonNode *head);

/**********************************************************************************
 * Function prototype for popping an item from the front of the linked list. The
 * head of the linked list is being passed by reference to update the linked
 * list in main.
 *********************************************************************************/
void PopItem(PersonNode *&head);

/**********************************************************************************
 * Function prototype for calculating the size of the linked list. The head of the
 * linked list is being passed by value and the number of items in the linked list
 * is being returned as an integer.
 *********************************************************************************/
int StackInstances(PersonNode *head);

/**********************************************************************************
 * This function prototype for looking at the first item in the linked list, unless
 * it's empty initially of course. The console will display the data from the first
 * node in the linked list for our user.
 *********************************************************************************/
void PeekItem(PersonNode *&head);

/**********************************************************************************
 * This function checks to see if the list is empty or not. The head is passed by
 * value and the output message depends on whether or not the list is empty.
 *********************************************************************************/
void IsListEmpty(PersonNode *head);


#endif /* FUNCTIONS_H_ */
