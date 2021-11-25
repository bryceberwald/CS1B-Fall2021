/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #4  : Accessing Recursion Performance
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/30/2021 @ 11:59PM
 ******************************************************************************/

#include "Functions.h"

/*****************************************************************************
* This function will print the class header to the console or an output file.
* The parameter specifies which output stream to use. For this assignment, this
* function will be printing to the console only.
*
* 1 Argument passed by reference -> RETURNS: Nothing
******************************************************************************/
void PrintHeader(ostream &output) {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int ASSIGNMENT_NUM = 4;
	const char ASSIGNMENT_NAME[40] = "Accessing Recusion Performance";

	// Output the program header to output specified.
	output << left;
	output << "*******************************************************";
	output << "\n* PROGRAMMED BY : " << PROGRAMMER;
	output << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	output << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	output << "\n* ASSIGNMENT #" << setw(2) << ASSIGNMENT_NUM << ": " << ASSIGNMENT_NAME;
	output << "\n*******************************************************" << endl;
	output << right;
}


/*************************************************************************
* This function will validate whether the users input is an integer or a
* character. If the users input is a character, the function will return
* false, otherwise true.
*
* 1 Argument passed by value -> RETURNS: Boolean
**************************************************************************/
bool ValidateNumber (string menuOptionStr) {

   bool isValid;   // CALC - Determine's validity to be returned.

   for (int i = 0; i < menuOptionStr.length(); i++)
	   if (isdigit(menuOptionStr[i]) == false){
		   isValid = false;
	   } else {
		   isValid = true;
	   }

   return isValid;
}


/************************************************************************
 * This function will print the menu options to the console as needed.
 * We will gather a menu option as input which will be stored in main
 * since the variable is being passed by reference. This function will
 * also check to ensure a number is being used for input.
 *
 * 1 Argument passed by reference -> RETURNS: Nothing
************************************************************************/
void PrintMenuOptions(int &menuOption) {

	bool numberValid;      // LCV/CALC - Used to check if input is a valid number.
	string menuOptionStr;  // INP/CALC - User inputs a string that's calculated if it's a number.

	do {

		cout << "\nMENU OPTIONS: \n";
		cout << "\n1 - Calculate and Display Factorial of a Number";
		cout << "\n2 – Calculate and Display Fibonacci Series of a Number";
		cout << "\n3 – Compare Performance for Factorial Implementations";
		cout << "\n4 – Compare Performance for Fibonacci Series Implementations";
		cout << "\n0 – Exit";

		cout << "\nEnter an option (0 to exit): ";
		cin >> menuOptionStr;

		cin.ignore(10000, '\n');

		// Call function to check if input is a number.
		numberValid = ValidateNumber(menuOptionStr);

		if(!numberValid) {
			cout << endl << right << setfill('*') << setw(7);
			cout << " "  << "Please input a NUMBER between 0 and 4";
			cout << left << setw(7) << " " << setfill(' ') << endl;
		}

		} while(!numberValid);

		// Convert string into integer.
		menuOption = atoi(menuOptionStr.c_str());
}


/************************************************************************
*
************************************************************************/
int CalculateFactorialRecursively(int number){

	int factorialNumber;   // CALC - Product is stored in variable, eventually returned.
	int decrementedNumber; // CALC - Variable stores number minus one.

	decrementedNumber = number - 1;

	if (number == 0){
		factorialNumber = 1;
	} else {

		// Call factorial recursive function to return an integer.
		factorialNumber = number * CalculateFactorialRecursively(decrementedNumber);

	}

	// Return the resulting factorial number.
	return factorialNumber;
}


/************************************************************************
*
************************************************************************/
int CalculateFactorialIteratively(int number){

	int factorialNumber;  // CALC - Number factorial is stored in this variable.

	if (number == 0){
		factorialNumber = 1;
	} else {
		factorialNumber = 1;

		// Find the factorial using iteration.
		for(int i = 1; i <= number; i++){
			factorialNumber = factorialNumber * i;
		}
	}

	// Return the resulting factorial number.
	return factorialNumber;
}


/************************************************************************
*
************************************************************************/
int CalculateFibonacciRecursively(int number){

	int fibonacciNumber;   // CALC - Used for calculating the final fibonacci number.

	// Check if the input value is 0 or 1.
    if (number == 0 || number == 1) {
        return number;
    }

    // Call functions recursively and add the resulting values.
    fibonacciNumber = CalculateFibonacciRecursively(number - 1);
    fibonacciNumber += CalculateFibonacciRecursively(number - 2);

    // Return the final fibonacci number.
    return fibonacciNumber;

}


/************************************************************************
*
************************************************************************/
int CalculateFibonacciIteratively(int number){

	int beforePrevNumber;   // CALC - Holds the value of number minus 2.
	int prevNumber;         // CALC - Holds the value of number minus 1.
	int currentNumber;      // CALC - Holds actual value of number variable being passed.

	// Initialize variables with values needed.
	prevNumber = 0;
	currentNumber = 1;

	// Check if either default values were entered.
	if(number == 0 || number == 1){
		return number;
	}

	// Find the fibonacci number using iteration.
	for (int i = 0; i < number-1; i++){

		// Reassign variables.
		beforePrevNumber = prevNumber;
		prevNumber = currentNumber;

		// Calculate the current fibonacci number in the series.
		currentNumber = beforePrevNumber + prevNumber;
	}

	// Return the final fibonacci number.
	return currentNumber;
}

