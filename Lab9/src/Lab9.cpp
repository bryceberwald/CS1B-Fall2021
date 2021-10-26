/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #9         : Implementing a Stack
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/27/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/**************************************************************************
 *
 * Lab #9 : Implementing a Stack
 *
 * ________________________________________________________________________
 *
 * This program creates a stack using a linked list. The program will start
 * off by initializing the linked list head to null, meaning the list is
 * empty. The program will display a variety of menu options for the
 * user to select from. The user will be able to add persons (PUSH) to the
 * front of the linked list. The user will also be allowed to POP a user from
 * the front of the list. The user can check the size of the list and even if
 * it's empty. Specialized error check messages are also utilized giving the
 * user a more friendly experience cluing them in on keen details of what is
 * really going on behind the scenes.
 * ________________________________________________________________________
 *
 *
 * INPUT:
 *    menuOptionSelected - User inputs this value when selecting a menu option.
 *    perPtr->name       - User inputs a new name when pushing into the linked list.
 *    perPtr->gender     - User inputs a new gender when pushing into the linked list.
 *    perPtr->age        - User inputs a new age when pushing into the linked list.
 *
 *
 *
 * OUTPUT:
 *    menuOptionSelected - Displayed to console whenever the number is out of range.
 *    perPtr->name       - Displayed to the console under certain menu options.
 *    perPtr->gender     - Displayed to the console under certain menu options.
 *    perPtr->age        - Displayed to the console under certain menu options.
 *    stackCounter       - Displayed to the console when 'Size' option is selected.
 *
 *
 *
 **************************************************************************/

int main() {

	// Call function to print the class header.
	PrintHeader(cout);

	bool inSession = true;                  // LCV   - Used to determine the length of the program.
	int menuOptionSelected = UnSelected;    // INPUT - Used to select specific menu options. Unselected = 6, Which is out of range!

	// Create a pointer to a new PersonNode.
	PersonNode *head;

	// Initialize the head to NULL.
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

				int stackCounter;                      // Variable used to hold the number of instances.
			    stackCounter = StackInstances(head);   // Called Function returns # of items into variable.

			    // MORE than ONE person on the stack display message.
			    if (stackCounter > 1) {
			    	cout << "\nThere are " << stackCounter << " people on the stack.\n";
			    // Only ONE person is on the stack display message.
			    } else if (stackCounter == 1) {
			    	cout << "\nThere is one person on the stack.\n";
			    // NOBODY is on the stack display message.
			    } else if (stackCounter == 0) {
			    	cout << "\nNobody is on the stack!\n";
			    // Error Checking!!!
			    } else {
			    	cout << "\nERROR while checking size of linked list.\n";
			    }

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;

			default:
				// Error check to make sure menu option chosen is in range.
				cout << "\n**** The number " << menuOptionSelected << " is an invalid entry ****";
                cout << "\n**** Please input a number between 0 and 5 ****\n";

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
		}

	}

	return 0;
}
