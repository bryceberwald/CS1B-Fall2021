//============================================================================
// Name        : Functions.h
// Author      : Bryce Berwald
// Version     :
// Copyright   :
// Description :
//============================================================================

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Pre-processor directives
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used
#include <ostream>
#include <fstream>
using namespace std;

// Struct created for doubly linked list.
struct PersonNode {
	string name;
	char gender;
	int age;
	PersonNode *next;
	PersonNode *prev;
};

// Function Prototypes...

/**********************************************************************************
 * This function prototype is for creating a doubly linked list from an input file.
 * Every time a new node is added, it will be documented on the console and the
 * pointers will be reassigned properly. This function will return the updated head
 * containing the linked list after all processes of the function have finished.
 *
 * 2 Arguments passed by value -> RETURNS: Head
 *********************************************************************************/
PersonNode *CreateLinkedList(string inputFileName, PersonNode *head);

/**********************************************************************************
 * This function prototype is for creating an ordered linked list, specifically
 * in alphabetical order. Every time a new node is added, we will loop through
 * contents and arrange pointers as necessary. This function will return the updated
 * head containing the ordered linked list in main.
 *
 * 2 Arguments passed by value -> RETURNS: Head
 *********************************************************************************/
PersonNode *CreateOrderedLinkedList(string inputFileName, PersonNode *head);

/**********************************************************************************
 * This function prototype is for displaying the linked list contents to the console
 * in the format described in class. Only a message will be displayed to the console
 * for an empty list.
 *
 * 1 Argument passed by value -> RETURNS: Nothing
 *********************************************************************************/
void DisplayLinkedList(PersonNode *head);

/**********************************************************************************
 * This function prototype checks to see if the list is empty or not. The head is
 * passed by value and the output message depends on whether or not the list is
 * empty.
 *
 * 1 Argument passed by value -> RETURNS: Nothing
 *********************************************************************************/
void IsLinkedListEmpty(PersonNode *head);

/**********************************************************************************
 * This function prototype lets the user input a name to be searched for. The
 * function will point to next until the search string is found and display the
 * found contents. Otherwise, a message letting the user that the searched name
 * could not be found.
 *
 * 1 Argument passed by value -> RETURNS: Nothing
 *********************************************************************************/
void LinkedListSearch(PersonNode *head);

/**********************************************************************************
 * Function prototype for removing a node from a doubly linked list. This function
 * handles a few specific cases (Removing from the front,middle,tail). Depending
 * on where the node is located, a different procedure may have to be done when
 * removing the node. All nodes removed will be output to the console as they are
 * removed.
 *
 * 1 Argument passed by reference -> RETURNS: Nothing
 *********************************************************************************/
void RemoveNodeFromLinkedList(PersonNode *&head);

/**********************************************************************************
 * Function prototype for the clearing our linked list items. The function will set
 * every item equal to NULL till the end of the list where the head will be set to
 * NULL. Only one parameter is being passed by reference, we need main to have the
 * empty list.
 *
 * 1 Argument passed by reference -> RETURNS: Nothing
 *********************************************************************************/
void ClearLinkedList(PersonNode *&head);





#endif /* FUNCTIONS_H_ */
