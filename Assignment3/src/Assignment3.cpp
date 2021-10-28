/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #3  : Searching Linked Lists
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/09/2021 @ 11:59PM
 ******************************************************************************/

#include "Functions.h"

/******************************************************************************************
 *
 * Assignment #3: CS1B - Searching Linked Lists
 *
 *
 * ________________________________________________________________________________________
 *
 *
 * Description goes here...
 *
 *
 * ________________________________________________________________________________________
 *
 * INPUT:
 *
 *
 *
 * OUTPUT:
 *
 *
 *
 ******************************************************************************************/

int main() {

	// Call function to print class header to the console.
	printHeader(cout);

	string inputFileName;     // INPUT - User determines variable value for input file.
	string outputFileName;    // INPUT - User determines variable value for output file.

	int menuOptionSelected = Unselected;
	bool inSession = true;

	// Create pointer that will used as the head.
	DVD *head;

	// Initialize the linked list to empty.
	head = NULL;

	// Call function to get input and output file names from the user.
	readFileNames(inputFileName, outputFileName);

	// Call function to create a linked list and return the new head.
	head = CreateLinkedList(inputFileName, head);

	// Call function to output linked list for testing purposes.
	OutputList(head);

	// Call function to display menu options.
	PrintMenuOptions(menuOptionSelected);

	// Loop until user specifies otherwise.
	while(inSession) {

		switch(menuOptionSelected){
			case Exit:
				// Code for terminating the program
				inSession = false;
				break;
			case OutputEntireList:
				// Code for outputting entire linked list.

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case TitleSearch:
				// Code for searching for a title in the linked list.

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case GenreSearch:
				// Code for searching for a genre in the linked list.

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case ActorSearch:
				// Code for searching for an actor in the linked list.

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case YearSearch:
				// Code for searching for a year in the linked list.

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case RatingSearch:
				// Code for searching for a rating in the linked list.

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			default:
				// Error Checking!!!
				cout << "\nPlease Choose a Valid Menu Option.\n";

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
		}
	}

	return 0;
}
