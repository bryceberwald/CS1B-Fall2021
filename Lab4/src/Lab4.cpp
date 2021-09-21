/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #4         : Introduction to Arrays
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 9/22/21 @ 11:59PM
 *****************************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/******************************************************************************************
 *
 * Lab #4 : Introduction to Arrays
 *
 * ________________________________________________________________________________________
 *
 * This program will gather a total of ten names from the user and then store them in an
 * array. After the ten names have been stored, the program will continually ask the user
 * who they would like to search for until the user types "done". After each search, the
 * user will be given output with the number of instances found of the ten name in our
 * array.
 * ________________________________________________________________________________________
 *
 *
 * INPUT:
 *    allPersons[]         - Data entered by user will be stored in array.
 *    nameEnterdByUser     - Used to temporarily hold input until stored in array.
 *    searchedByUser       - Used to search through array contents.
 *
 *
 * OUTPUT:
 *    searchedByUser       - Variable is reused, displaying searched name to console.
 *    personsFound         - Variable is reused, displaying # of names found in array.
 *
 ******************************************************************************************/

int main() {

	const int ARRAY_SIZE = 10;         // CONST - used to set array lengths and know size.
	string allPersons[ARRAY_SIZE];     // INPUT - Array for all names entered by the user.
	string nameEnteredByUser;          // INPUT - Used to temporarily hold the input data from the user.
	string searchedByUser;             // INPUT/OUTPUT - Search name determined by user & displayed via console.
	bool stillSearching = true;        // LCV - Used to determine whether the user wants to remain searching or not.
	int personsFound = 0;              // CALC/OUTPUT - Holds number of names found, reused & reset upon new search.

	// Declared variables to be used for outputting class header.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int LAB_NUM = 4;
	const char ASSIGNMENT_NAME[25] = "Introduction to Arrays";

	// Print the class header to the console.
	cout << left;
	cout << "*******************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << ASSIGNMENT_NAME;
	cout << "\n*******************************************************" << endl;
	cout << right << endl;

	// Loop to get 10 names from the user.
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << "Enter name #" << i + 1 << ": ";
		getline(cin, nameEnteredByUser);
		allPersons[i] = nameEnteredByUser;
	}

	// Loop continues until user specifies with "done".
	while (stillSearching) {

		// Get search data from the user.
		cout << "\nWho do you want to search for (enter done to exit)? ";
		cin >> searchedByUser;

		// Check to see if user wants to terminate the program.
		if (searchedByUser == "done") {

			stillSearching = false;
			cout << "\nThank you for using my program!";

		} else {

			// Loop to find number of instances found in the array.
			for (int i = 0; i < ARRAY_SIZE; i++) {

				if (searchedByUser == allPersons[i]) {
					personsFound += 1;
				}

			}

			// Specialized message for zero entries found.
			if (personsFound == 0) {
				cout << searchedByUser << "'s name does not exist in this list." << endl;
			// Specialized message for one entry found.
			} else if (personsFound == 1) {
				cout << "There is one instance of the name " << searchedByUser << "." << endl;
			// Message that displays number of instances found.
			} else {
				cout << "There are " << personsFound << " instances of the name "  << searchedByUser << "." << endl;
			}

		}

		// Reset variable to zero.
		personsFound = 0;
	}

	return 0;
}
