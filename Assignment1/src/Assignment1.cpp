/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #1  : Functions & Arrays
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 09/17/2021 @ 11:59PM
 *****************************************************************************************/

#include "Functions.h"

/******************************************************************************************
 *
 * Assignment #1: CS1B - Functions & Arrays
 *
 *
 * ________________________________________________________________________________________
 *
 * This program will allow the user to input a inputFileName and outputFileName, that
 * will be used throughout the program to store data determined by the user. This program
 * will read all the data from the predetermined input file name and output to the output
 * file as needed. There will be menu options for display and the program will use a
 * multitude of functions to help with the issues we have and to also have a code base
 * that's more organized.
 *
 * ________________________________________________________________________________________
 *
 * INPUT:
 *    inputFileName      - User inputs the file name needed.
 *    outputFileName     - User inputs the file name specified.
 *    menuOptionChosen   - User inputs a selection for the menu options.
 *
 *
 * OUTPUT:
 *    personsFullName[]  - Array used for output during certain time frames of the program.
 *    personsID          - Array used for output during certain time frames of the program.
 *    personsBalance     - Array used for output during certain time frames of the program.
 *
 *
 ******************************************************************************************/

int main() {

	//system("clear");

	string inputFileName;                  // INPUT - User determines variable value for input file.
	string outputFileName;                 // INPUT - User determines variable value for output file.

	int menuOptionChosen = 7;              // INPUT from the user, setting initial value out of bounds.

	int calculatedIndex;                   // CALC - Variable assigned to calling functions return value. (Smaller or Larger balance)
	float calculatedResult;                // CALC - Variable assigned to calling functions return value. (Sum or Average)
	int foundPersonIndex;                  // CALC - Variable assigns index of person found, or not found.

	const int MAX_VALUES = 10;             // CONST - used to set array lengths and know size.

	string personsFullName[MAX_VALUES];    // INPUT/OUTPUT - Array for all persons names from the input file.
	int personsID[MAX_VALUES];             // INPUT/OUTPUT - Array for all persons ID #s from the input file.
	float personsBalance[MAX_VALUES];      // INP/OUT/CALC - Array for all persons balances from the input file.

	//Function prints header to the console.
	printHeader(cout);

	//Function reads file names from the user.
	readFileNames(inputFileName, outputFileName);

	ofstream oFile;
	oFile.open(outputFileName, ios::app);
	//Function prints header to the output file.
	printHeader(oFile);
	oFile.close();

	//Function gathers data from the input file.
	getDataFromInputFile(personsFullName, personsID, personsBalance, MAX_VALUES, inputFileName, outputFileName);

	while (menuOptionChosen != 0) {
		//Print menu options to the console for the user.
		cout << "\nMENU OPTIONS" << endl << endl;
		cout << "1 - Find the larger balance" << endl;
		cout << "2 - Find the smaller balance" << endl;
		cout << "3 - Obtain the sum of all balances" << endl;
		cout << "4 - Obtain the average of all balances" << endl;
		cout << "5 - Find person" << endl;
		cout << "0 - Exit" << endl;
		cout << "Enter an option (0 to exit): ";

		cin >> menuOptionChosen;
		cin.ignore(10000, '\n');

		ofstream oFile;
		oFile.open(outputFileName, ios::app);

		switch(menuOptionChosen) {
			case 0:
				//Exits the program...
				cout << "\nTerminating now!!!" << endl;
				oFile.close();
				break;
			case 1:
				//Find the larger balance...
				cout << "\nFinding the larger balance..." << endl;

				if(oFile.is_open()) {
					calculatedIndex = findSmallerOrLargerBalance(personsBalance, MAX_VALUES, menuOptionChosen);
					oFile << left;
					oFile << "\nThe largest balance is: " << endl;
					printRecordHeadingToFile(outputFileName);
				    oFile << left << setw(10)
				    		<< personsID[calculatedIndex] << setw(29) << personsFullName[calculatedIndex]
							<< " " << setw(4) << "$" << right << setprecision(2)
							<< fixed << personsBalance[calculatedIndex] << '\n' << '\n';
				}
				break;
			case 2:
				//Find the smaller balance...
				cout << "\nFinding the smaller balance..." << endl;

				if(oFile.is_open()) {
					calculatedIndex = findSmallerOrLargerBalance(personsBalance, MAX_VALUES, menuOptionChosen);
					oFile << left;
					oFile << "\nThe smallest balance is: " << endl;
					printRecordHeadingToFile(outputFileName);
					oFile << left << setw(10)
							<< personsID[calculatedIndex] << setw(29) << personsFullName[calculatedIndex]
							<< " " << setw(6) << "$" << right << setprecision(2)
							<< fixed << personsBalance[calculatedIndex] << '\n' << '\n';
				}
				break;
			case 3:
				//Obtain the sum of all balances...
				cout << "\nObtaining the sum of all balances..." << endl;

				if(oFile.is_open()) {
					calculatedResult = findSumOrAverageBalance(personsBalance, MAX_VALUES, menuOptionChosen);
					oFile << left;
					oFile << "\nThe sum of all persons balances: " << endl;
					oFile << setw(5) << "$" << right << calculatedResult << "\n\n";
				}

				break;
			case 4:
				//Obtain the average of all balances...
				cout << "\nObtaining the average of all balances..." << endl;

				if(oFile.is_open()) {
					calculatedResult = findSumOrAverageBalance(personsBalance, MAX_VALUES, menuOptionChosen);
					oFile << left;
					oFile << "\nThe average of all persons balances: " << endl;
					oFile << setw(6) << "$" << right << setprecision(2)
						  << fixed << calculatedResult << "\n\n";
				}
				break;
			case 5:
				//Find person...
				foundPersonIndex = searchForPerson(personsFullName, MAX_VALUES);

				if (foundPersonIndex < MAX_VALUES) {
					cout << "Person Found." << endl;
					if(oFile.is_open()) {
						oFile << left;
						oFile << "\nSearch Name: " << endl;
						printRecordHeadingToFile(outputFileName);
					    oFile << left << setw(10) << personsID[foundPersonIndex]
							  << setw(30) << personsFullName[foundPersonIndex] << "$" << setw(10)
							  << right << setprecision(2) << fixed << personsBalance[foundPersonIndex] << '\n' << '\n';
					}
				} else {
					cout << "Person was not found." << endl;
				}
				break;
			default:
				//Error checking for menu options not specified.
				cout << "\nPlease choose a valid menu option." << endl;
				break;
		}
	}
	return 0;
}
