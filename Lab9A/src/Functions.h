/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #9         : Implementing a Queue
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/03/21 @ 11:59PM
 *************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Pre-processor directives
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used
#include <ostream>
using namespace std;

// Enumerated Types used for the menu options.
enum {
	Exit,            // 0
	Enqueue,         // 1
	Dequeue,         // 2
	IsEmpty,         // 3
	Front,           // 4
	Size,            // 5
	ClearQueue,      // 6
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
 * Function prototype for printing the class header to the console with one
 * parameter being passed by reference to determine where we want to output to the
 * console or an output file. In the case of this program we will be outputting to
 * the console.
 *
 * 1 Argument -> RETURNS: Nothing
 *********************************************************************************/
void PrintHeader(ostream &output);

/**********************************************************************************
 * This function prototype determines whether or not the users input is a number.
 * One parameter is passed by value, returning a boolean. This function is used
 * inside of the PrintMenuOptions() function for error checking.
 *
 * 1 Argument -> RETURNS: Boolean
 *********************************************************************************/
bool ValidateNumber (string menuOptionStr);

/**********************************************************************************
 * Function prototype for printing menu options with one parameter passed by
 * reference. Nothing is returned by this function by the variable being passed by
 * reference to the function will be updated in main as well.
 *
 * 1 Argument -> RETURNS: Nothing
 *********************************************************************************/
void PrintMenuOptions(int &menuOption);

/**********************************************************************************
 * Function prototype for adding linked list items to the end of the list. One
 * parameter is being passed by reference to keep the variable updated in main.
 *
 * 1 Argument -> RETURNS: Nothing
 *********************************************************************************/
void EnqueueItem(PersonNode *&head);

/**********************************************************************************
 * Function prototype for removing linked list items from the front of the list.
 * Only one parameter is being passed by reference to keep our head updated in the
 * main program.
 *
 * 1 Argument -> RETURNS: Nothing
 *********************************************************************************/
void DequeueItem(PersonNode *&head);

/**********************************************************************************
 * This function prototype checks to see if the list is empty or not. The head is
 * passed by value and the output message depends on whether or not the list is
 * empty.
 *
 * 1 Argument -> RETURNS: Nothing
 *********************************************************************************/
void IsListEmpty(PersonNode *head);

/**********************************************************************************
 * This function prototype for looking at the first item in the linked list, unless
 * it's empty initially of course. The console will display the data from the first
 * node in the linked list for our user.
 *
 * 1 Argument -> RETURNS: Nothing
 *********************************************************************************/
void FrontItem(PersonNode *head);

/**********************************************************************************
 * Function prototype for calculating the size of the linked list. The head of the
 * linked list is being passed by value and the number of items in the linked list
 * is being returned as an integer.
 *
 * 1 Argument -> RETURNS: Integer
 *********************************************************************************/
int QueueInstances(PersonNode *head);

/**********************************************************************************
 * Function prototype for the clearing our linked list items. The function will set
 * every item equal to NULL till the end of the list where the head will be set to
 * NULL. Only one parameter is being passed by reference, we need main to have the
 * empty list.
 *
 * 1 Argument -> RETURNS: Nothing
 *********************************************************************************/
void ClearTheQueue(PersonNode *&head);


#endif /* FUNCTIONS_H_ */
