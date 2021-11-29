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
 * This program will allow a user to calculate the factorial and fibonacci
 * series of a number from a few different menu option selections. The first two
 * menu options will calculate the numbers using only recursive methods. The
 * resulting value's will get displayed to the console as they are found. The
 * last two menu options available for selection (option 3 or option 4) will
 * calculate the resulting values using recursion and iteration with separate
 * functions that will be used with a time comparison library to get the seconds
 * measured of the time each function takes. 0 - to Exit at any time!!!
 * _____________________________________________________________________________
 *
 * INPUT:
 *	 inputString        - Variable used to store users input value.
 *
 *
 * OUTPUT:
 * 	 seconds            - Calculated & displayed after time comparisons are done.
 * 	 comboStr           - Displayed to the console when error checking.
 * 	 menuOptionSelected - Displayed when users input is a number & out of range.
 * 	 fibonacci          - Displayed after calculations have been done.
 * 	 factorial          - Displayed after calculations have been done.
 *
 *
 *******************************************************************************/

int main() {

	// Variable & Constant Declarations.

	high_resolution_clock::time_point t1;    // CALC     - Starting time value used for calculations.
	high_resolution_clock::time_point t2;    // CALC     - Ending time value used for calculations.

	long long duration;                      // CALC     - Number of microseconds for execution.

	float seconds = 0.0;                     // CALC/OUT - Number of seconds for execution, displayed to console as needed.

	const float TIME_CONVERSION = 1000000.0; // CALC     - Used to convert microseconds into seconds.
	const int NUMBER_OF_CALLS = 10000;       // CALC     - Used to iterate function calls for time comparisons.

	bool inSession = true;                   // LCV      - Used to control the duration of the program.
	bool isNumber;                           // CALC     - Used to determine if user's input is a actual number.

	stringstream createString;               // CALC     - Used to create a string when error checking.
	string inputString;                      // INP/CALC - User will input a value, which is used for number checking as well.
	string comboStr;                         // CALC/OUT - Used to convert the string stream into a string for output.

	int inputInteger;                        // CALC     - Used for user's input when the string value is verified to be a number.
	int menuOptionSelected = UnSelected;     // CALC/OUT - Used to determine which menu option is being accessed, being displayed if needed.
	int fibonacci;                           // CALC/OUT - Variable holds the factorial of a number to be displayed as needed.
	int factorial;                           // CALC/OUT - Variable holds the fibonacci series of a number to be displayed as needed.

	// Call function to display class header the console.
	PrintHeader(cout);

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
					// Ask the user for a number.
					cout << "\nEnter a number: ";
					cin >> inputString;
					cin.ignore(10000, '\n');

					// Check if users input is a actual number.
					isNumber = ValidateNumber(inputString);

					if(!isNumber) {
						cout << endl << right << setfill('*') << setw(7);
						cout << " "  << "Please Enter a NUMBER.";
						cout << left << setw(7) << " " << setfill(' ') << endl;
					}

				} while(!isNumber);

				// Convert string input to integer.
				inputInteger = atoi(inputString.c_str());

				// Call function to calculate factorial recursively.
				factorial = CalculateFactorialRecursively(inputInteger);

				// Display calculations being done to the console.
				cout << endl;
				for(int i = inputInteger; i > 0; i--){
					if(i == 1){
						cout << "1 = ";
					} else {
						cout << i << "x";
					}
				}
				cout << factorial;
				cout << "\nThe Factorial of " << inputInteger << " is: " << CalculateFactorialRecursively(inputInteger) << endl;

				break;
			case CalculateFibonacci:
				// Code for calculating & displaying fibonacci series using recursive method.
				do {

					// Ask user for a number.
					cout << "\nEnter a number: ";
					cin >> inputString;
					cin.ignore(10000, '\n');

					// Check if users input is a actual number.
					isNumber = ValidateNumber(inputString);

					if(!isNumber) {
						cout << endl << right << setfill('*') << setw(7);
						cout << " "  << "Please Enter a NUMBER.";
						cout << left << setw(7) << " " << setfill(' ') << endl;
					}

				} while(!isNumber);

				// Convert string input to an integer.
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

				cout << "\nRecursive Implementation: \n";
				t1 = high_resolution_clock::now();

				// Call factorial function using recursion.
				for (int i = 0; i < NUMBER_OF_CALLS; i++){
					factorial = CalculateFactorialRecursively(inputInteger);
				}
				cout << factorial;
				t2 = high_resolution_clock::now();

				duration = duration_cast<microseconds>(t2 - t1).count();

				// Convert microseconds into seconds.
				seconds = duration / TIME_CONVERSION;

				cout << "\nIt took the program " << seconds << " seconds to execute.\n";

				cout << "\nIterative Implementation: \n";
				t1 = high_resolution_clock::now();

				// Call factorial function using iteration.
				for (int i = 0; i < NUMBER_OF_CALLS; i++){
					factorial = CalculateFactorialIteratively(inputInteger);
				}
				cout << factorial;
				t2 = high_resolution_clock::now();

				duration = duration_cast<microseconds>(t2 - t1).count();

				// Convert microseconds into seconds.
				seconds = duration / TIME_CONVERSION;

				cout << "\nIt took the program " << seconds << " seconds to execute.\n";

				break;
			case CompareFibonacci:
				// Code for comparing performance of fibonacci calculation using recursion & iteration.
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

				cout << "\nRecursive Implementation:";
				t1 = high_resolution_clock::now();

				// Call function using recursion.
				for (int i = 0; i < NUMBER_OF_CALLS; i++){
					fibonacci = CalculateFibonacciRecursively(inputInteger);
				}
				cout << "\nCalculating the time of Fibonacci Series using recursion!";
				t2 = high_resolution_clock::now();

				duration = duration_cast<microseconds>(t2 - t1).count();

				// Convert microseconds into seconds.
				seconds = duration / TIME_CONVERSION;

				cout << "\nIt took the program " << seconds << " seconds to execute.\n";

				cout << "\nIterative Implementation:";
				t1 = high_resolution_clock::now();

				// Call function using iteration.
				for(int i = 0; i < NUMBER_OF_CALLS; i++){
					fibonacci = CalculateFibonacciIteratively(inputInteger);
				}
				cout << "\nCalculating the time of Fibonacci Series using iteration!";
				t2 = high_resolution_clock::now();

				duration = duration_cast<microseconds>(t2 - t1).count();

				// Convert microseconds into seconds.
				seconds = duration / TIME_CONVERSION;

				cout << "\nIt took the program " << seconds << " seconds to execute.\n";

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

