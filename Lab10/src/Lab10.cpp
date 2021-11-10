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
 * Description goes here...
 *
 *
 *
 * ________________________________________________________________________
 *
 *
 * INPUT:
 *
 *
 *
 *
 * OUTPUT:
 *
 *
 *
 *
 **************************************************************************/

int main() {

	// Create pointer that will used as the head.
	PersonNode *head;

	// Initialize the linked list to empty.
	head = NULL;

	string inputFileName = "inputFile.txt";

	int menuOptionSelected = UnSelected;
	bool inSession = true;

	PrintHeader(cout);

	// Call function to display menu options to the console.
	PrintMenuOptions(menuOptionSelected);

	while (inSession){
		switch(menuOptionSelected){
			case Exit:
				// Code for terminating the program
				inSession = false;
				break;
			case CreateList:
				// Code for creating an ordered list.

				head = CreateLinkedList(inputFileName, head);

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
			case DisplayList:
				// Code for displaying ordered linked list.

				DisplayLinkedList(head);

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
			case IsEmpty:
				// Code for indicating if the list is empty.

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
			case SearchByName:
				// Code for searching by name.

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
			case RemoveNode:
				// Code for removing a node from linked list.

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
			case ClearList:
				// Code for deleting all nodes in linked list.

				// Call function to display menu options to the console.
				PrintMenuOptions(menuOptionSelected);
				break;
			default:
				// Error Checking!!!
				cout << "\nSomething went wrong in switch statement!\n";
				break;
		}
	}


	return 0;
}
