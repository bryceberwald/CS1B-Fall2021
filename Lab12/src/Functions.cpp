/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #12	      : Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/24/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/*************************************************************************
* This function can print to either the console or an output file using
* ostream type with the specified variable being passed by reference.
*
* 1 Argument passed by reference -> RETURNS: Nothing
*************************************************************************/
void PrintHeader(ostream &output) {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int LAB_NUM = 12;
	const char LAB_NAME[40] = "Introduction to OOP";

	// Output the program header to output specified.
	output << left;
	output << "*******************************************************";
	output << "\n* PROGRAMMED BY : " << PROGRAMMER;
	output << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	output << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	output << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
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


/**************************************************************************
* This function will display one of two menu options in our program. One
* of the parameters will be a boolean which will be used to determine which
* menu option to display. A boolean is used for this purpose since we have
* only two menu options for selection.
*
* 2 Arguments passed, 1 by reference, 1 by value -> RETURNS: Nothing
**************************************************************************/
void PrintMenuOptions(int &menuOption, bool init) {

	string menuOptionStr;     // INPUT - User will enter a value to be stored.
	bool isNumber = false;    // CALC  - Determine's if input is a valid number.

	if(init) {
		do {
			cout << "\nMENU OPTIONS: ";
			cout << "\n1 - Initialize Animals";
			cout << "\n2 - Change Age";
			cout << "\n3 - Change Value";
			cout << "\n4 - Display";
			cout << "\n0 – Exit";

			cout << "\nEnter selection: ";
			cin >> menuOptionStr;

			cin.ignore(10000, '\n');

			// Call function to check input validity.
			isNumber = ValidateNumber(menuOptionStr);

			if (!isNumber) {
				cout << "\n**** Please input a NUMBER between 0 and 4 ****\n";
			}

		} while(!isNumber);

		// Convert the numerical string to an integer.
		menuOption = atoi(menuOptionStr.c_str());
	} else {
		do {
			cout << "\nMENU OPTIONS: ";
			cout << "\n1 - Initialize Animals";
			cout << "\n0 – Exit";

			cout << "\nEnter selection: ";
			cin >> menuOptionStr;

			cin.ignore(10000, '\n');

			// Call function to check input validity.
			isNumber = ValidateNumber(menuOptionStr);

			if (!isNumber) {
				cout << "\n**** Please input a NUMBER between 0 and 1 ****\n";
			}

		} while(!isNumber);

		// Convert the numerical string to an integer.
		menuOption = atoi(menuOptionStr.c_str());
	}

}

