/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #6         : Structs
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/06/21 @ 11:59PM
 *************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Pre-processor directives
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used
#include <ostream>
#include <fstream>
using namespace std;

// Struct for holding each individual from the input file.
struct PersonsInformation {
	string personsFullName;
	int personsID;
	float personsBalance;
};

// Prototypes for functions used in the program.

// Function prototype for printing header to console or file depending on parameter.
void printHeader(ostream &output);

// Function prototype for reading in from the user what file names will be used for the program.
void readFileNames(string &inputFileName, string &outputFileName);

// Function prototype for getting the data from the input file.
void getDataFromInputFile(PersonsInformation Person[], const int MAX_VALUES, string inputFileName, string outputFileName);

// Function prototype for printing the record heading as needed.
void printRecordHeadingToFile(string outputFileName);

// Function prototype for finding the largest balance and returning the proper index.
int findLargestBalance(const PersonsInformation Person[], const int MAX_VALUES);

// Function prototype for finding the sum of balances from the array of structs.
float findSumOfBalances(const PersonsInformation Person[], const int MAX_VALUES);

// Function prototype for searching for a persons name and returning the proper index.
int searchForPerson(const PersonsInformation Person[], const int MAX_VALUES, string& searchedFor);


#endif /* FUNCTIONS_H_ */
