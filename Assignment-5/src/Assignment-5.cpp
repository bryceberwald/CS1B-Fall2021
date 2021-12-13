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
 * This program will allow the user to create a linked list from an input file
 * and have the list output to a file in the format discussed in class. A few
 * Movie List class methods will help with the formatting. The program will allow
 * the user to enter the input file name and output file name (or d can be typed
 * for default). Once the file names have been read, if the input file name matches
 * the file name with the data, then the list will be created and will output to
 * the file specified by the user. Two methods from the Movie List class will help
 * accomplish this programs purpose.
 * _____________________________________________________________________________
 *
 * INPUT:
 *   string inputFileName  - User will be allowed to enter the input file name.
 *   string outputFileName - User will be allowed to enter the output file name.
 *
 *
 * OUTPUT:
 *   MovieList movie       - Movie Object will output to a file as specified.
 *
 *
 *
 *******************************************************************************/

int main() {

	MovieList movie;             // MovieList instance created to interact with the class.

	string inputFileName = "";   // INPUT/CALC - Variable used to store the input file name.
	string outputFileName = "";  // INPUT/CALC - Variable used to store the output file name.

	// Call function to print class header to the console.
	PrintHeader(cout);

	// Call function to read file names from the user.
	ReadFileNames(inputFileName, outputFileName);

	// Call movie list class method to create the linked list.
	movie.CreateList(inputFileName);

	// Call movie list class method to output the linked list to a file.
	movie.OutputList(outputFileName);

	return 0;
}

