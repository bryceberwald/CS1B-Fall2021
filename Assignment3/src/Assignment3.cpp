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
 * ________________________________________________________________________________________
 *
 * This program will read in a bunch of movies from the input file. The user will have the
 * ability to choose from a menu of options. The menu will allow the user to display the
 * entire movie list contents to the output file, as well as search for a movie through a
 * variety of different methods. The user will be able to search a movie by title, genre,
 * actor, year or rating. The numerical amount found will be displayed to the console but
 * the resulting values will be displayed in the output file. The user has the ability to
 * terminate the program at any time by pressing zero.
 * ________________________________________________________________________________________
 *
 * INPUT:
 *   menuOptionSelected - User will input a value for a menu option.
 *   inputFileName      - User has the option to input a file name.
 *   outputFileName     - User has the option to input a file name.
 *
 * OUTPUT:
 *	 DVD *perPtr - Displayed to console and/or file as needed.
 *	 counter     - Displayed to console and/or file as needed.
 *
 *
 ******************************************************************************************/

int main() {

	// Call function to print class header to the console.
	printHeader(cout);

	string inputFileName;                // INPUT - User determines variable value for input file.
	string outputFileName;               // INPUT - User determines variable value for output file.

	int menuOptionSelected = Unselected; // INPUT - Used to select specific menu options. Unselected = 7, Which is out of range!
	bool inSession = true;               // LCV   - Used to determine the length of the program.

	// Create pointer that will used as the head.
	DVD *head;

	// Initialize the linked list to empty.
	head = NULL;

	// Call function to get input and output file names from the user.
	readFileNames(inputFileName, outputFileName);

	ofstream oFile;
	oFile.open(outputFileName, ios::app);

	// Call function to print class header to file.
	printHeader(oFile);

	// Call function to create a linked list and return the new head.
	head = CreateLinkedList(inputFileName, head);

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

				// Call function to output all of linked list contents.
				OutputEntireListContents(outputFileName, head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case TitleSearch:
				// Code for searching for a title in the linked list.

				// Call function to perform a title search.
				PerformSearch(menuOptionSelected, outputFileName, head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case GenreSearch:
				// Code for searching for a genre in the linked list.

				// Call function to perform a genre search.
				PerformSearch(menuOptionSelected, outputFileName, head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case ActorSearch:
				// Code for searching for an actor in the linked list.

				// Call function to perform a genre search.
				PerformSearch(menuOptionSelected, outputFileName, head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case YearSearch:
				// Code for searching for a year in the linked list.

				// Call function to perform a genre search.
				PerformSearch(menuOptionSelected, outputFileName, head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			case RatingSearch:
				// Code for searching for a rating in the linked list.

				// Call function to perform a genre search.
				PerformSearch(menuOptionSelected, outputFileName, head);

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
			default:
				// Error Checking!!!
				cout << "\n**** The number " << menuOptionSelected << " is an invalid entry  *****";
				cout << "\n**** Please input a number between 0 and 6 *****\n";

				// Call function to redisplay menu options.
				PrintMenuOptions(menuOptionSelected);
				break;
		}


	}
	oFile.close();

	return 0;
}
