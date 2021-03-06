/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #1  : Functions & Arrays
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 09/17/2021 @ 11:59PM
 *****************************************************************************************/

#include "Functions.h"

/****************************************************************************************
* This function can print to either the console or the output file using ostream type
* with the specified variable being passed by reference.
*****************************************************************************************/
void printHeader(ostream &output) {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int ASSIGNMENT_NUM = 1;
	const char ASSIGNMENT_NAME[20] = "Functions & Arrays";

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

/*****************************************************************************************
 * This function reads the file names from the user and stores them in inputFileName and
 * outputFileName variables being passed by reference from the main program.
 *****************************************************************************************/
void readFileNames(string &inputFileName, string &outputFileName) {
	cout << setw(40) << left << "What input file would you like to use?";
	cin >> inputFileName;

	cout << setw(41) << left << "\nWhat output file would you like to use?";
	cin >> outputFileName;
}

/*****************************************************************************************
 * This function uses the input file name specified by the user to extract the ID #s,
 * names and balances into 3 parallel arrays to be used by the main program.
 *****************************************************************************************/
void getDataFromInputFile(string personsFullName[], int personsID[], float personsBalance[], const int MAX_VALUES, string inputFileName, string outputFileName) {

	string fullName;
	int ID;
	float balance;

	ifstream inFile;
	inFile.open(inputFileName);

	if (inFile.is_open()) {
		for (int i = 0; i < MAX_VALUES; i++) {
			getline(inFile, fullName);
			personsFullName[i] = fullName;

			inFile >> ID;
			personsID[i] = ID;

			inFile >> balance;
			personsBalance[i] = balance;

			inFile.ignore(10000, '\n');

		}
	}

    inFile.close();

	ofstream oFile;
	oFile.open(outputFileName, ios::app);
	oFile << left;
	oFile << "" << setw(10) << "ID # " << "" << setw(30) << "Name " << "" << setw(40) << "BALANCE DUE" << endl;
	oFile << "" << setw(10) << "-----" << "" << setw(30) << "--------------------" << "" << setw(30) << "-----------" << endl;

    // Write the list of all data entries from the input file to the output file now.
	for (int i = 0; i < MAX_VALUES; i++) {
	    oFile << left << setw(10) << personsID[i]
			  << setw(30) << personsFullName[i] << "$" << setw(10)
			  << right << setprecision(2) << fixed << personsBalance[i] << '\n' << '\n';
	}
    oFile << "\n\n\n";
    oFile.close();
}

/*****************************************************************************************
 * This function will print the record heading to the output file as needed.
 *****************************************************************************************/
void printRecordHeadingToFile(string outputFileName) {

	ofstream oFile;
	oFile.open(outputFileName, ios::app);

	oFile << left;
	oFile << "" << setw(10) << "ID # " << "" << setw(30) << "Name " << "" << setw(40) << "BALANCE DUE" << endl;
	oFile << "" << setw(10) << "-----" << "" << setw(30) << "--------------------" << "" << setw(30) << "-----------" << endl;

	oFile.close();

}

/*****************************************************************************************
 * This function will find the smallest or largest balance depending on the users
 * selection from the menu options. Function returns index needed to the main program.
 *****************************************************************************************/
int findSmallerOrLargerBalance(const float personsBalance[], const int MAX_VALUES, int menuOptionChosen) {

	float balanceAmount = 0;

	int indexOfBalance = 0;

	switch(menuOptionChosen) {
		case 1:
			//Execute finding the largest balance.
			balanceAmount = personsBalance[0];
			for (int i = 0; i < MAX_VALUES; i++) {
				if (personsBalance[i] > balanceAmount) {
					balanceAmount = personsBalance[i];
					indexOfBalance = i;
				}
			}
			break;
		case 2:
			//Execute finding the smallest balance.
			balanceAmount = personsBalance[0];
			for (int i = 0; i < MAX_VALUES; i++) {
				if (personsBalance[i] < balanceAmount) {
					balanceAmount = personsBalance[i];
					indexOfBalance = i;
				}
			}
			break;
		default:
			//Error Check, because something must have gone wrong!
			cout << "\nSomething went wrong..." << endl;
			break;
	}
	return indexOfBalance;
}

/*****************************************************************************************
 * This function will find the sum or average of all balances depending on the users
 * selection from the menu options. Function returns a floating point number.
 *****************************************************************************************/
float findSumOrAverageBalance(const float personsBalance[], const int MAX_VALUES, int menuOptionChosen) {

	//Temporary variable used by this sub program.
	float amount = 0;

	switch(menuOptionChosen) {
		case 3:
			//Execute finding the sum of all balances...
			for (int i = 0; i < MAX_VALUES; i++) {
				amount += personsBalance[i];
			}
			break;
		case 4:
			//Execute finding the average of all balances...
			for (int i = 0; i < MAX_VALUES; i++) {
				amount += personsBalance[i];
			}
			amount = amount / MAX_VALUES;
			break;
		default:
			//Error Check, because something must have gone wrong!
			cout << "\nSomething went wrong..." << endl;
			break;
	}
	return amount;
}

/*****************************************************************************************
 * This function will search for a person in the personsFullName array and returns the
 * proper index for the person found.
 *****************************************************************************************/
int searchForPerson(const string personsFullName[], const int MAX_VALUES) {

	// Initialize variable for user input by sub program.
	string searchedFor;

	// Finding Person - Need INPUT from the user.
	cout << "\nWho do you wish to search for? ";
	getline(cin, searchedFor);

	// LCV - Loop Control Variables used by sub program.
	int index = 0;
	bool found = false;

	// Loop goes through the array until a name is found.
	while (index < MAX_VALUES && !found) {
		if (personsFullName[index] == searchedFor) {
			found = true;
		} else {
			index++;
		}

	}
	return index;
}




