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
#include <cstdlib>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;

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
* Function prototype for printing the class header to either a file or the console.
*
* 1 Argument passed by reference -> RETURNS: Nothing
**********************************************************************************/
void PrintHeader(ostream &output);

/**********************************************************************************
 * Function prototype for checking whether input is a valid number or not. This
 * function will take a string as a parameter and returns a boolean as a way to
 * verify the number.
 *
 * 1 Argument passed by value -> RETURNS: Boolean
 *********************************************************************************/
bool ValidateNumber (string menuOptionStr);

/*********************************************************************************
* Function prototype for printing the menu options to the console as needed. This
* function will use the ValidateNumber() function to ensure a user has entered a
* number.
*
* 1 Argument passed by reference -> RETURNS: Nothing
**********************************************************************************/
void PrintMenuOptions(int &menuOption);

/*********************************************************************************
* Function prototype for calculating the factorial of a number using recursion.
* This function will call itself till a resulting value is found to be returned.
*
* 1 Argument passed by value -> RETURNS: Integer
**********************************************************************************/
int CalculateFactorialRecursively(int number);

/*********************************************************************************
* Function prototype for calculating the factorial of a number using iteration.
* This function will loop until the resulting value has been found.
*
* 1 Argument passed by value -> RETURNS: Integer
**********************************************************************************/
int CalculateFactorialIteratively(int number);

/*********************************************************************************
* Function prototype for calculating the fibonacci series of a number using
* recursion. This function will continually call itself until a resulting series
* has been found.
*
* 1 Argument passed by value -> RETURNS: Integer
**********************************************************************************/
int CalculateFibonacciRecursively(int number);

/*********************************************************************************
* Function prototype for calculating the fibonacci series of a number using
* iteration as the method of choice. This function will iterate or loop until the
* resulting value's of the fibonacci series have been found.
*
* 1 Argument passed by value -> RETURNS: Integer
**********************************************************************************/
int CalculateFibonacciIteratively(int number);

#endif /* FUNCTIONS_H_ */
