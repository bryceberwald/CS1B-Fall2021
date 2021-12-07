/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #5  : DVD Movie List - Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/15/2021 @ 11:59PM
 ******************************************************************************/

#include "Functions.h"

/*****************************************************************************
* This function will print the class header to the console.
*
* 1 Argument passed by reference -> RETURNS: Nothing
******************************************************************************/
void PrintHeader(ostream &output) {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int ASSIGNMENT_NUM = 5;
	const char ASSIGNMENT_NAME[50] = "DVD Movie List - Intro to OOP";

	// Output the program header to output specified.
	output << left;
	output << "*******************************************************";
	output << "\n* PROGRAMMED BY : " << PROGRAMMER;
	output << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	output << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	output << "\n* ASSIGNMENT #" << setw(2) << ASSIGNMENT_NUM << ": " << ASSIGNMENT_NAME;
	output << "\n*******************************************************" << endl;
	output << right << endl;
}


/*******************************************************************************
 * This function will get input from the user, collecting the input file name
 * and the output file name and storing the string values in main since they
 * are being passed by reference. If the user selects d for default for either
 * of these two input questions, a default string file name will be provided.
 *
 * 2 Arguments passed by reference -> RETURNS: Nothing
 *******************************************************************************/
void ReadFileNames(string &inputFileName, string &outputFileName) {

	cout << setw(40) << left << "Which input file would you like to use(type d for default file)? ";
	cin >> inputFileName;

	if (inputFileName == "d" || inputFileName == "D"){
		inputFileName = "inFile.txt";
	}

	cout << setw(41) << left << "\nWhich output file would you like to use(type d for default file)? ";
	cin >> outputFileName;

	if (outputFileName == "d" || outputFileName == "D"){
		outputFileName = "OFile.txt";
	}

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

		cout << "\nMENU OPTIONS ";
		cout << "\n1 - Create List";
		cout << "\n2 – Output List";
		cout << "\n0 – Exit";

		cout << "\nEnter a command: ";
		cin >> menuOptionStr;

		cin.ignore(10000, '\n');

		// Call function to check if input is a number.
		numberValid = ValidateNumber(menuOptionStr);

		if(!numberValid) {
			cout << endl << right << setfill('*') << setw(7);
			cout << " "  << "Please input a NUMBER between 0 and 2";
			cout << left << setw(7) << " " << setfill(' ') << endl;
		}

		} while(!numberValid);

		// Convert string into integer.
		menuOption = atoi(menuOptionStr.c_str());
}




