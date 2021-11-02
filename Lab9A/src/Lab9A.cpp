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
 *
 * Description goes here...
 *
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

	// Call function to print class header to the console.
	PrintHeader(cout);

	bool inSession = true;                  // LCV   - Used to determine the length of the program.
	int menuOptionSelected = UnSelected;    // INPUT - Used to select specific menu options. Unselected = 7, Which is out of range!

	// Create a pointer to a new PersonNode.
	PersonNode *head;

	PersonNode *tail;

	tail = NULL;

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
				// Call function to enqueue to the linked list.
				EnqueueItem(head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case Dequeue:
				// Call function to remove last item from linked list.
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
				// Call function to look at the front most item.
				FrontItem(head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case Size:
				int queueCounter;
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
