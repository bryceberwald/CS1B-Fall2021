/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #13	      : Linked Lists of Sheep - OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/01/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"
#include "FarmList.h"

/******************************************************************************
 *
 * Lab #13: CS1B - Linked Lists of Sheep - OOP
 *
 * ____________________________________________________________________________
 *
 *
 *
 *
 *
 *
 *
 *
 * _____________________________________________________________________________
 *
 * INPUT:
 *
 *
 *
 *
 * OUTPUT:
 *
 *
 *
 *
 *******************************************************************************/

int main() {

	FarmList Farm;
	Sheep newSheep;
	Sheep sheep;

	string sheepName;
	int sheepAge;
	int SizeOfList;

	stringstream createString;
	string comboStr;

	bool inSession = true;

	int menuOptionSelected = UnSelected;

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
