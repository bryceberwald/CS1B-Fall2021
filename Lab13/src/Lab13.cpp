/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #13	      : Array of Sheep - OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/01/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"
#include "FarmList.h"

/******************************************************************************
 *
 * Lab #13: CS1B - Array of Sheep - OOP
 *
 * ____________________________________________________________________________
 *
 * This program will allow a user to select from a range of menu options. The
 * user will be able to add a sheep class object into a list contained within
 * the FarmList class object which was created to hold all objects concerning
 * a farm, but for this lab purpose, only a list of sheep objects will be used.
 * The sheep objects will be appended to the end of a list. Different
 * manipulations may be done to the list through the menu options. At any time
 * enter 0 to terminate the program.
 * _____________________________________________________________________________
 *
 * INPUT:
 *   menuOptionSelected - User will input a value to choose a menu option.
 *	 newSheep           - User will input values for a new sheep to be added.
 *	 Farm               - User's input values will be stored in the Farm class.
 *
 *
 * OUTPUT:
 *   menuOptionSelected - User's menu option selections displayed to console as needed.
 *   newSheep           - User's chosen sheep values will be displayed to console as needed.
 *   sheep              - Sheep values will be displayed to console as needed.
 *   sheepName          - Sheep values will be displayed to console as needed.
 *   sheepAge           - Sheep values will be displayed to console as needed.
 *   SizeOfList         - Variable will be returned and displayed as needed.
 *   comboStr           - Variable gets displayed to console when input values are out of range.
 *
 *
 *******************************************************************************/

int main() {

	FarmList Farm;             // INP/OUT/CALC - Instance of the FarmList class is created for the program to use.
	Sheep newSheep;            // INP/OUT      - A sheep object is created for whenever new sheep are added to the list.
	Sheep sheep;               // OUT/CALC     - A sheep object is created for returning values from a sheep object itself.

	string sheepName;          // OUT/CALC     - Value's get returned by reference and displayed to the console.
	int sheepAge;              // OUT/CALC     - Value's get returned by reference and displayed to the console.
	int SizeOfList;            // OUT/CALC     - Value's get returned by reference and displayed to the console.

	stringstream createString; // CALC         - This variable is used to create a string for error checking input.
	string comboStr;           // OUT          - This variable is assigned the created string value to be displayed.

	bool inSession = true;     // LCV          - Used to determine the duration of the program.

	int menuOptionSelected;    // INP/OUT      - User selects menu options will this variable.

	menuOptionSelected = UnSelected;

	// Call function to print class header to the console.
	PrintHeader(cout);

	while(inSession){

		// Call function to display menu options.
		PrintMenuOptions(menuOptionSelected);

		switch(menuOptionSelected){
			case Exit:
				// Code for terminating the program.
				inSession = false;
				break;
			case AddSheep:
				// Code for adding a sheep.
				Farm.AddSheep(newSheep);
				break;
			case OutputFirstSheep:
				// Code for outputting the first sheep.

				if(Farm.TotalSheep() > 0){

					// Get the first sheep from the sheep array in FarmList class.
					sheep = Farm.GetFirstSheep();
					sheep.GetValues(sheepName, sheepAge);

					// Display Results to the console.
					cout << endl << left;
					cout << setw(15) << "Name" << "AGE" << endl;
					cout << right;
					cout << setfill('-') << setw(15) << " " << setw(4) << " " << setfill(' ');

					cout << endl << left;
					cout << setw(16) << sheepName << sheepAge << endl;

					cout << "\nIs at the front of the list.\n";
				} else {
					cout << "\nNobody is in the front - the list is empty!\n";
				}

				// Reset temporary variables.
				sheepName = "";
				sheepAge = 0;

				break;
			case FindSheep:
				// Code for finding a sheep.

				if(Farm.TotalSheep() > 0){
					cout << "\nWho are you looking for? ";
					getline(cin, sheepName);

					sheep = Farm.FindSheep(sheepName);

					if (sheep.GetName() != ""){
						sheep.GetValues(sheepName, sheepAge);

						cout << endl << left;
						cout << setw(15) << "Name" << "AGE" << endl;
						cout << right;
						cout << setfill('-') << setw(15) << " " << setw(4) << " " << setfill(' ');

						cout << endl << left;
						cout << setw(16) << sheepName << sheepAge << endl;

						cout << "\nHas been found.\n";


					} else {
						cout << "\nNo sheep was found!\n";
					}
				} else {
					cout << "\nThere are no sheep to be found!\n";
				}

				break;
			case ListSize:
				// Code for getting the list size.
				SizeOfList = Farm.TotalSheep();

				if(SizeOfList == 0){
					cout << "\nThe list is empty!\n";
				} else if (SizeOfList == 1){
					cout << "\nThere is one sheep in the list.\n";
				} else {
					cout << "\nThere are " << SizeOfList << " sheep in the list.\n";
				}
				break;
			case OutputList:
				// Code for outputting the list contents.
				Farm.DisplaySheepTable();
				break;
			case ClearList:
				// Code for clearing the list contents.
				Farm.ClearList();

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
				cout << "****"  << "Please choose a number between 0 and 6";
				cout << right << setw(7) << "****" << endl;

				// Reset string and stringstream variables to empty strings.
				comboStr = "";
				createString.str("");
				break;
		}
	}


	return 0;
}
