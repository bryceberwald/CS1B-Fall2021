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
#include <sstream>
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

/*********************************************************************************
* This is the function prototype for printing the class header to the
* console.
*
* 1 Argument passed by reference -> RETURNS: Nothing
**********************************************************************************/
void printHeader(ostream &output);

/**********************************************************************************
 * This function prototype determines whether or not the users input is a number.
 * One parameter is passed by value, returning a boolean. This function is used
 * inside of the PrintMenuOptions() function for error checking.
 *
 * 1 Argument passed by value -> RETURNS: Boolean
 *********************************************************************************/
bool ValidateNumber (string number);

/**********************************************************************************
 * This function prototype is for the algorithm to implement lines not overflowing
 * in words for our title search portion of the program. This function helps to
 * ensure cleaner readability by taking in one string as a parameter and adding
 * new lines as needed.
 *
 * 1 Argument passed by value -> RETURNS: String
 *********************************************************************************/
string WordWrapping(string newStr);

/**********************************************************************************
* This is the function prototype for reading in the file names from the
* user. We will need to get an input file name and an output file name
* from the user. The variables will be stored in main.
*
* 2 Arguments passed by reference -> RETURNS: Nothing
**********************************************************************************/
void readFileNames(string &inputFileName, string &outputFileName);

/*********************************************************************************
* This is the function prototype for creating a linked list. We will use
* the struct type for the function and return the updated head to main.
* This function will get all the data/information from inside our input
* file and store it into the struct pointer variables respectfully.
*
* 2 Arguments passed by value -> RETURNS: Updated Head
*********************************************************************************/
DVD *CreateLinkedList(string inputFileName, DVD *head);

/*********************************************************************************
* This is the function prototype for printing the menu options to the
* console as needed.
*
* 1  Argument passed by reference -> RETURNS: Nothing
*********************************************************************************/
void PrintMenuOptions(int &menuOption);

/********************************************************************************
* This is the function prototype for outputting the entire linked list
* to an output file as needed. Two parameters are passed, one for the
* output files name, another for the head of the linked list.
*
* 2 Arguments passed by value -> RETURNS: Nothing
*********************************************************************************/
void OutputEntireListContents(string outputFileName, DVD *head);

/*********************************************************************************
* This is the function prototype for handing the searching portion of the
* program. This function will be used for ALL the searching aspects. This
* function uses menuOption being passed by value to know which search
* operation to conduct.
*
* 3 Arguments passed by value -> RETURNS: Nothing
*********************************************************************************/
void PerformSearch(int menuOption, string outputFileName, DVD *head);


#endif /* FUNCTIONS_H_ */
