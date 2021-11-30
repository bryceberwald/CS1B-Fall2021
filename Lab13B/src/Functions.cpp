/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #13	      : Linked Lists of Sheep - OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/01/21 @ 11:59PM
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
	const int LAB_NUM = 13;
	const char LAB_NAME[60] = "Linked Lists of Sheep - OOP";

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

		cout << endl << right << setfill('*');
		cout << setw(38) << " ";

		cout << endl << setfill(' ') << left << setw(2);
		cout << "*"  << "WELCOME TO THE SHEEP LIST MANAGER";
		cout << right << setw(2) << "*" << endl;
		cout << setfill('*') << setw(38) << " " << setfill(' ') << endl;

		cout << "\nSHEEP LIST MANAGER ";
		cout << "\n1 - Add Sheep";
		cout << "\n2 – Output 1st Sheep";
		cout << "\n3 – Find Sheep";
		cout << "\n4 – List Size";
		cout << "\n5 – Output List";
		cout << "\n6 – Clear List";
		cout << "\n0 – Exit";

		cout << "\nEnter a command: ";
		cin >> menuOptionStr;

		cin.ignore(10000, '\n');

		// Call function to check if input is a number.
		numberValid = ValidateNumber(menuOptionStr);

		if(!numberValid) {
			cout << endl << right << setfill('*') << setw(7);
			cout << " "  << "Please input a NUMBER between 0 and 7";
			cout << left << setw(7) << " " << setfill(' ') << endl;
		}

		} while(!numberValid);

		// Convert string into integer.
		menuOption = atoi(menuOptionStr.c_str());
}

