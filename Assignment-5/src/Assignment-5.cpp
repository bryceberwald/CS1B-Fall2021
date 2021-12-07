/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #5  : DVD Movie List - Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/15/2021 @ 11:59PM
 ******************************************************************************/

#include "MovieList.h"
#include "StackList.h"
#include "Functions.h"

/******************************************************************************
 *
 * Assignment #5: CS1B - DVD Movie List - Introduction to OOP
 *
 * ____________________________________________________________________________
 *
 *
 * Description goes here...
 *
 *
 *
 *
 *
 * _____________________________________________________________________________
 *
 * INPUT:
 *
 *
 *
 * OUTPUT:
 *
 *
 *
 *******************************************************************************/

int main() {

	MovieList movie;

	int menuOptionSelected = UnSelected;
	bool inSession = true;

	stringstream createString;
	string comboStr;

	string inputFileName = "";
	string outputFileName = "";

	// Call function to print class header to the console.
	PrintHeader(cout);

	// Call function to read file names from user.
	ReadFileNames(inputFileName, outputFileName);

	while(inSession){

		// Call function to print menu options to the console.
		PrintMenuOptions(menuOptionSelected);

		switch(menuOptionSelected){
			case Exit:
				// Code for terminating the program.
				inSession = false;
				break;
			case CreateList:
				// Code for creating linked list.
				movie.CreateList(inputFileName);
				break;
			case OutputList:
				// Code for outputting the list to a file.
				movie.OutputList(outputFileName);
				break;
			default:
				// Create a string for the invalid number entry.
				createString << "The number " << menuOptionSelected << " is an invalid entry.";
				comboStr = createString.str();

				// Error Checking!!!
				cout << endl << left << setw(7);
				cout << "****"  << setw(38) << comboStr;
				cout << right << setw(7) << "****";

				cout << endl << left << setw(7);
				cout << "****"  << "Please choose a number between 0 and 2";
				cout << right << setw(7) << "****" << endl;

				// Reset string and stringstream variables to empty strings.
				comboStr = "";
				createString.str("");
				break;
		}
	}
	return 0;
}

