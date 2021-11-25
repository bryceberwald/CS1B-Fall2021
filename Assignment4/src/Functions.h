/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #4  : Accessing Recursion Performance
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/30/2021 @ 11:59PM
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

// Created enum types for menu options.
enum {
	Exit,                // 0
	CalculateFactorial,  // 1
	CalculateFibonacci,  // 2
	CompareFactorial,    // 3
	CompareFibonacci,    // 4
	UnSelected,          // 5
};

//Prototypes for functions used in the program.

/*********************************************************************************
* This is the function prototype for printing the class header to the
* console.
*
* 1 Argument passed by reference -> RETURNS: Nothing
**********************************************************************************/
void PrintHeader(ostream &output);

/**********************************************************************************
 * Function prototype for checking whether input is a valid number or not. This
 * function will take a string as a parameter and returns a boolean.
 *
 * 1 Argument passed by value -> RETURNS: Boolean
 *********************************************************************************/
bool ValidateNumber (string menuOptionStr);

/*********************************************************************************
*
**********************************************************************************/
void PrintMenuOptions(int &menuOption);

/*********************************************************************************
*
**********************************************************************************/
int CalculateFactorialRecursively(int number);

/*********************************************************************************
*
**********************************************************************************/
int CalculateFactorialIteratively(int number);

/*********************************************************************************
*
**********************************************************************************/
int CalculateFibonacciRecursively(int n);

/*********************************************************************************
*
**********************************************************************************/
int CalculateFibonacciIteratively(int number);



#endif /* FUNCTIONS_H_ */
