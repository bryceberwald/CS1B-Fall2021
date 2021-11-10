/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #9         : Creating an Ordered List
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/10/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/**************************************************************************
 *
 * Lab #10 : Creating an Ordered List
 *
 * ________________________________________________________________________
 *
 * This program will allow the user to select from a menu of options. Each
 * menu option allows for manipulations on a doubly linked list. The user
 * has the ability to create a linked list from a text file with the text
 * file being in that specific format. When all the nodes have been added
 * into the doubly linked list, the program will redisplay the menu options
 * for new manipulations to be done. Remember, only certain parts of the
 * program will occur when the list is NOT empty, meaning there are still
 * nodes in the linked list.
 * ________________________________________________________________________
 *
 *
 * INPUT:
 *	  menuOptionSelected - User will input a value for a menu option.
 *
 * OUTPUT:
 *	  PersonNode *head   - Passed to functions that output data to console.
 *
 **************************************************************************/

int main() {

	// Create pointer that will used as the head.
	PersonNode *head;

	// Initialize the linked list to empty.
	head = NULL;

	string inputFileName = "inputFile.txt"; // String holds input file name.

	int menuOptionSelected = UnSelected;    // INP/CALC - Users input used for menu selections.
	bool inSession = true;                  // LCV      - Variable controls the length of program

	// Call function to display class header to the console.
	PrintHeader(cout);

	// Call function to display menu options to the console.
	PrintMenuOptions(menuOptionSelected);

	while (inSession){

		switch(menuOptionSelected){
			case Exit:
				// Code for terminating the program.
				inSession = false;
				break;
			case CreateList:
				// Call function to create an ordered linked list.
				head = CreateOrderedLinkedList(inputFileName, head);

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
			case DisplayList:
				// Call function to display linked list.
				DisplayLinkedList(head);

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
			case IsEmpty:
				// Call function to determine if linked list is empty.
				IsLinkedListEmpty(head);

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
			case SearchByName:
				// Call function to search linked list by name.
				LinkedListSearch(head);

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
			case RemoveNode:
				// Call function to remove a node from linked list.
				RemoveNodeFromLinkedList(head);

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
			case ClearList:
				// Call function to delete all nodes in linked list.
				ClearLinkedList(head);

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
			default:
				// Error checking users input.
				cout << "\n**** The number " << menuOptionSelected << " is an invalid entry     ****";
				cout << "\n**** Please input a number between 0 and 6 ****\n";

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
		}
	}
	return 0;
}
