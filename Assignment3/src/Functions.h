/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #3  : Searching Linked Lists
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/09/2021 @ 11:59PM
 ******************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//Pre-processor directives
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings
#include <ostream>
#include <fstream>
using namespace std;

// Enumerated Types used for the menu options.
enum {
	Exit,                // 0
	OutputEntireList,    // 1
	TitleSearch,         // 2
	GenreSearch,         // 3
	ActorSearch,         // 4
	YearSearch,          // 5
	RatingSearch,        // 6
	Unselected,          // 7

};

// Struct to hold our linked list data.
struct DVD {
	string title;
	string leadActor;
	string supportingActor;
	string genre;
	string alternativeGenre;
	int year;
	int rating;
	string synopis;
	DVD* next;
};

//Prototypes for functions used in the program.

/*************************************************************************
* This is the function prototype for printing the class header to the
* console.
*
* 1 Argument passed by reference -> RETURNS: Nothing
*************************************************************************/
void printHeader(ostream &output);

/*************************************************************************
 *
 *
 *
 *
*************************************************************************/
void PrintRecordHeadingToFile(string outputFileName);

/*************************************************************************
* This is the function prototype for reading in the file names from the
* user. We will need to get an input file name and an output file name
* from the user. The variables will be stored in main.
*
* 2 Arguments passed by reference -> RETURNS: Nothing
*************************************************************************/
void readFileNames(string &inputFileName, string &outputFileName);

/*************************************************************************
* This is the function prototype for creating a linked list. We will use
* the struct type for the function and return the updated head to main.
* This function will get all the data/information from inside our input
* file and store it into the struct pointer variables respectfully.
*
* 2 Arguments passed by value -> RETURNS: head
*************************************************************************/
DVD *CreateLinkedList(string inputFileName, DVD *head);

/*************************************************************************
* This is the function prototype for outputting the linked list contents
* to the console as needed.
*
* 1 Argument passed by value -> RETURNS: Nothing
*************************************************************************/
void OutputList(DVD *head);

/*************************************************************************
* This is the function prototype for printing the menu options to the
* console as needed.
*
* 1  Argument passed by reference -> RETURNS: Nothing
*************************************************************************/
void PrintMenuOptions(int &menuOption);

/*************************************************************************
*
*
*
*
*************************************************************************/
void OutputEntireListContents(string outputFileName, DVD *head);

/*************************************************************************
*
*
*
*
*************************************************************************/
void PerformSearch(int menuOption, string outputFileName, DVD *head);


#endif /* FUNCTIONS_H_ */
