/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #5         : Binary Search
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 9/29/21 @ 11:59PM
 *****************************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

// Pre-processor directives
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used
using namespace std;

// Prototypes for functions used in the program.

/*******************************************************************************
 * Function prototype for outputting the array contents to the console.
 * Code for the function is written in the output.cpp file.
 ******************************************************************************/
void outputArrayContents(const int intArray[], const int ARRAY_SIZE);

/*******************************************************************************
 * Function prototype for doing a sequential search with the array contents.
 * Code for the function is written in the search.cpp file.
 ******************************************************************************/
int sequentialSearch(const int intArray[], const int ARRAY_SIZE, int integerSearchedFor);

/*******************************************************************************
 * Function prototype for sorting the array with an insertion sort method.
 * Code for the function is written in the sort.cpp file.
 ******************************************************************************/
void insertionSorting(int intArray[], const int ARRAY_SIZE);

/*******************************************************************************
 * Function prototype for searching the array with the binary search approach.
 * Code for the function is written in the search.cpp file.
 ******************************************************************************/
int binarySearch(const int intArray[], const int ARRAY_SIZE, int integerSearchedFor);


#endif /* FUNCTIONS_H_ */
