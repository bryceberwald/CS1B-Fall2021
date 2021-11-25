/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #4  : Accessing Recursion Performance
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/30/2021 @ 11:59PM
 ******************************************************************************/

#include "Functions.h"

/******************************************************************************
 *
 * Assignment #4: CS1B - Accessing Recursion Performance
 *
 * ____________________________________________________________________________
 *
 *
 * Description goes here...
 *
 *
 *
 *
 * _____________________________________________________________________________
 *
 * INPUT:
 *
 *
 * OUTPUT:
 *
 *
 *******************************************************************************/

int main() {

	// Call function to display class header the console.
	PrintHeader(cout);

	// Variable & Constant Declarations.
	bool inSession;
	bool isNumber;

	string inputString;
	int inputInteger;

	int menuOptionSelected;

	stringstream createString;
	string comboStr;

	int fibonacci;

	// Assign variables initial values.
	inSession = true;
	menuOptionSelected = UnSelected;

	while(inSession){

		// Call function to display menu options.
		PrintMenuOptions(menuOptionSelected);

		switch(menuOptionSelected){
			case Exit:
				// Code for terminating the program.
				inSession = false;
				break;
			case CalculateFactorial:
				// Code for calculating & displaying factorial using recursive method.

				do {

					cout << "\nEnter a number: ";
					cin >> inputString;
					cin.ignore(10000, '\n');

					isNumber = ValidateNumber(inputString);

					if(!isNumber) {
						cout << endl << right << setfill('*') << setw(7);
						cout << " "  << "Please Enter a NUMBER.";
						cout << left << setw(7) << " " << setfill(' ') << endl;
					}

				} while(!isNumber);

				inputInteger = atoi(inputString.c_str());

				cout << "\nThe Factorial of " << inputInteger << " is: " << CalculateFactorialRecursively(inputInteger) << endl;

				break;
			case CalculateFibonacci:
				// Code for calculating & displaying fibonacci series using recursive method.

				do {

					cout << "\nEnter a number: ";
					cin >> inputString;
					cin.ignore(10000, '\n');

					isNumber = ValidateNumber(inputString);

					if(!isNumber) {
						cout << endl << right << setfill('*') << setw(7);
						cout << " "  << "Please Enter a NUMBER.";
						cout << left << setw(7) << " " << setfill(' ') << endl;
					}

				} while(!isNumber);

				inputInteger = atoi(inputString.c_str());

				// Output the final fibonacci series in ascending order.
				cout << "\nThe Final Fibonacci Series of " << inputInteger << " is: ";
				for (int i = 0; i <= inputInteger; i++){
					fibonacci = CalculateFibonacciRecursively(i);
					cout << fibonacci << " ";
				}
				cout << endl;

				break;
			case CompareFactorial:
				// Code for comparing performance of factorial calculation using recursion & iteration.
				break;
			case CompareFibonacci:
				// Code for comparing performance of fibonacci calculation using recursion & iteration.
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
				cout << "****"  << "Please choose a number between 0 and 4";
				cout << right << setw(7) << "****" << endl;

				// Reset string and stringstream variables to empty strings.
				comboStr = "";
				createString.str("");

				break;
		}
	}

	return 0;
}








