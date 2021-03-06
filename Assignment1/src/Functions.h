/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #1  : Functions & Arrays
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 09/17/2021 @ 11:59PM
 *****************************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//Pre-processor directives
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings
#include <ostream>
#include <fstream>
using namespace std;

//Prototypes for functions used in the program.

//Function prototype for printing header to console or file depending on parameter.
void printHeader(ostream &output);

//Function prototype for reading in from the user what file names will be used for the program.
void readFileNames(string &inputFileName, string &outputFileName);

//Function prototype for getting the data from the input file.
void getDataFromInputFile(string personsFullName[], int personsID[], float personsBalance[], const int MAX_VALUES, string inputFileName, string outputFileName);

//Function prototype for printing the record heading.
void printRecordHeadingToFile(string outputFileName);

//Function prototype for retrieving the smallest or largest balance.
int findSmallerOrLargerBalance(const float personsBalance[], const int MAX_VALUES, int menuOptionChosen);

//Function prototype for retrieving the sum or average balance.
float findSumOrAverageBalance(const float personsBalance[], const int MAX_VALUES, int menuOptionChosen);

//Function prototype for searching if a person exists.
int searchForPerson(const string personsFullName[], const int MAX_VALUES);

#endif /* FUNCTIONS_H_ */
