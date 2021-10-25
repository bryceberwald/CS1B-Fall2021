/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #9         : Implementing a Stack
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/27/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

int main() {

	// Call function to print the class header.
	PrintHeader(cout);

	bool inSession = true;
	int menuOptionSelected = UnSelected;    // equals 6 - Out of Range for the menu options...

	PersonNode *head;
    //PersonNode *perPtr;

    head = NULL;

	// Call function to print menu options for the user.
	PrintMenuOptions(menuOptionSelected);

	// Loop until users specifies otherwise.
	while(inSession) {

		switch(menuOptionSelected){
		    case Exit:
		    	// Code for terminating the program.
		    	inSession = false;
		    	break;

			case Push:
				// Code for Pushing to the front of the linked list.
				head = PushItem(head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;

			case Pop:
				// Call function to pop the first item in the linked list.
				PopItem(head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;

			case IsEmpty:
				// Code for checking if linked list is empty.
				IsListEmpty(head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;

			case Peek:
				// Code for returning the front item of the linked list.
				PeekItem(head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;

			case Size:
				// Code for finding the total size of the linked list.
				int stackCounter;
			    stackCounter = StackInstances(head);

			    if (stackCounter > 1) {
			    	cout << "\nThere are " << stackCounter << " people on the stack.\n";
			    } else if (stackCounter == 1) {
			    	cout << "\nThere is one person on the stack.\n";
			    } else if (stackCounter == 0) {
			    	cout << "\nNobody is on the stack!\n";
			    } else {
			    	cout << "\nERROR while checking size of linked list.\n";
			    }

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;

			default:
				// Error check to make sure menu option chosen is in range.
				cout << "\n**** The number" << menuOptionSelected << "is an invalid entry ****";
                cout << "\n**** Please input a number between 0 and 5 ****\n";

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;

		}

	}

	return 0;
}
