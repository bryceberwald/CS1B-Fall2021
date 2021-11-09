/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #9         : Implementing a Queue
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/03/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/**************************************************************************
 *
 * Lab #9A : Implementing a Queue
 *
 * ________________________________________________________________________
 *
 * This program will use a linked list to store the data using a menu option
 * for different manipulations to be done using queue operations. The queue
 * calls for a few functions that are needed to be carried out. Enqueue will
 * add new list items to the end of the linked list. Dequeue will remove the
 * first item in the linked list. IsEmpty, Front and Size will return the
 * appropriate information concerning the queue. Finally, ClearTheQueue will
 * remove every item from the queue displaying to the console removed items
 * as they are being removed. This program ultimately serves as a template
 * for a basic implementation of a queue.
 * ________________________________________________________________________
 *
 *
 * INPUT:
 *    menuOptionSelected - User inputs this value when selecting a menu option.
 *    perPtr->name       - User will enqueue a new name into the linked list.
 *    perPtr->gender     - User will enqueue a new gender into the linked list.
 *    perPtr->age        - User will enqueue a new age into the linked list.
 *
 *
 *
 * OUTPUT:
 *    menuOptionSelected - Displayed to console whenever the number is out of range.
 *    perPtr->name       - Displayed to the console under certain menu options.
 *    perPtr->gender     - Displayed to the console under certain menu options.
 *    perPtr->age        - Displayed to the console under certain menu options.
 *    queueCounter       - Displayed to the console when 'Size' option is selected.
 *
 *
 *
 **************************************************************************/

int main() {

	// Call function to print class header to the console.
	PrintHeader(cout);

	bool inSession = true;                  // LCV   - Used to determine the length of the program.
	int menuOptionSelected = UnSelected;    // INPUT - Used to select specific menu options. Unselected = 7, Which is out of range!

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
		    	inSession = false;
		    	break;
			case Enqueue:
				// Call function to add to the rear of linked list.
				EnqueueItem(head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case Dequeue:
				// Call function to remove from the front of linked list.
				DequeueItem(head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case IsEmpty:
				// Call function to see if linked list is empty.
				IsListEmpty(head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case Front:
				// Call function to get the first item of linked list.
				FrontItem(head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case Size:
				int queueCounter;   // CALC/OUT - Used to determine linked list size.

				// Call function to get the total size in the queue.
			    queueCounter = QueueInstances(head);

			    // MORE than ONE person in the queue display message.
			    if (queueCounter > 1) {
			    	cout << "\nThere are " << queueCounter << " people in the queue.\n";
			    // Only ONE person is on the queue display message.
			    } else if (queueCounter == 1) {
			    	cout << "\nThere is one person on the queue.\n";
			    // NOBODY is in queue display message.
			    } else if (queueCounter == 0) {
			    	cout << "\nNobody is in the queue!\n";
			    // Error Checking!!!
			    } else {
			    	cout << "\nERROR while checking size of linked list.\n";
			    }

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case ClearQueue:
				// Code for clearing the queue.
				ClearTheQueue(head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			default:
				// Error check to make sure menu option chosen is in range.
				cout << "\n**** The number " << menuOptionSelected << " is an invalid entry ****";
                cout << "\n**** Please input a number between 0 and 6 ****\n";

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
		}

	}

	return 0;
}
