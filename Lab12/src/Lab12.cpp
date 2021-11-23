/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #12	      : Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/24/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"
#include "Animal.h"

/**************************************************************************
 *
 * Lab #12 : Introduction to Object Oriented Programming
 *
 * ________________________________________________________________________
 *
 *
 * Description goes here...
 *
 *
 *
 * ________________________________________________________________________
 *
 * INPUT:
 *
 *
 *
 * OUTPUT:
 *
 *
 *
 **************************************************************************/

int main() {

	Animal Fluffy, Maa, Babe;

	// Call function to print class header to the console.
	PrintHeader(cout);

	int menuOptionSelected = Unselected;

	bool isInitialized = false;
	bool inSession = true;

	string currentName = "";

	char reInitialize = 'N';

	int changeOptionInt;
	string changeOptionStr;

	bool isNumber;

	int newAge;

	float newValue;

	while(inSession){

		if (isInitialized){
			// Menu Options for animals already initialized.

			// Call function to display menu options to the console.
			PrintMenuOptions(menuOptionSelected, isInitialized);

			switch(menuOptionSelected){

				case Exit:
					// Code for terminating the program.
					inSession = false;

					break;
				case InitializeAnimals:
					// Code for initializing the animals.
					cout << "\nAre you sure you want to reinitialize (Y/N)? ";
					cin.get(reInitialize);
					cin.ignore(10000, '\n');

					if (reInitialize == 'Y' || reInitialize == 'y'){
						cout << "\nInitializing Fluffy, Maa, & Babe...\n";

						Fluffy.SetInitialValues("Fluffy", "Sheep", 1, 15000.00);
						Maa.SetInitialValues("Maa", "Sheep", 3, 16520.35);
						Babe.SetInitialValues("Babe", "Pig", 2, 10240.67);
					}
					reInitialize = 'N';

					break;
				case ChangeAge:
					// Code for changing the age of an animal.
					cout << "\nCHANGE AGE: ";
					cout << "\n1 - " << Fluffy.GetName();
					cout << "\n2 - " << Maa.GetName();
					cout << "\n3 - " << Babe.GetName();

					cout << "\nSelect the animal you'd like to change: ";
					cin >> changeOptionStr;

					cin.ignore(10000, '\n');

					// Call function to check input validity.
					isNumber = ValidateNumber(changeOptionStr);

					if (!isNumber) {
						cout << "\n**** Please enter a valid number. ****\n";
					} else {
						// Convert the numerical string to an integer.
						changeOptionInt = atoi(changeOptionStr.c_str());

						switch(changeOptionInt){
							case 1:
								cout << "\nNEW AGE: ";
								cin >> newAge;
								Fluffy.ChangeAge(newAge);
								cout << "\nChanging " << Fluffy.GetName() << "'s age to " << newAge << " ...\n";
								break;
							case 2:
								cout << "\nNEW AGE: ";
								cin >> newAge;
								Maa.ChangeAge(newAge);
								cout << "\nChanging " << Maa.GetName() << "'s age to " << newAge << " ...\n";
								break;
							case 3:
								cout << "\nNEW AGE: ";
								cin >> newAge;
								Babe.ChangeAge(newAge);
								cout << "\nChanging " << Babe.GetName() << "'s age to " << newAge << " ...\n";
								break;
							default:
								cout << "\n**** The number " << changeOptionInt << " is an invalid entry ****\n";
								break;
						}
					}

					break;
				case ChangeValue:
					// Code for changing the value of an animal.

					do {

						cout << "\nCHANGE VALUE: ";
						cout << "\n1 - " << Fluffy.GetName();
						cout << "\n2 - " << Maa.GetName();
						cout << "\n3 - " << Babe.GetName();

						cout << "\nSelect the animal you'd like to change: ";
						cin >> changeOptionStr;

						cin.ignore(10000, '\n');

						// Call function to check input validity.
						isNumber = ValidateNumber(changeOptionStr);

						// Convert the numerical string to an integer.
						changeOptionInt = atoi(changeOptionStr.c_str());

						if(!isNumber){
							cout << "\n**** Please Enter a Valid NUMBER. ****\n";
						}

						if(isNumber){
							if(changeOptionInt < 1 || changeOptionInt > 3){
								cout << "\n**** The number " << changeOptionInt << " is an invalid entry ****";
								cout << "\n**** Please input a number between 0 and 3 ****\n";
							}
						}


					}while((changeOptionInt < 1 || changeOptionInt > 3) || !isNumber);

					switch(changeOptionInt){
						case 1:
							cout << "\nNEW VALUE: ";
							cin >> newValue;
							Fluffy.ChangeValue(newValue);
							cout << "\nChanging " << Fluffy.GetName() << "'s value to " << newValue << " ...\n";
							break;
						case 2:
							cout << "\nNEW VALUE: ";
							cin >> newValue;
							Maa.ChangeValue(newValue);
							cout << "\nChanging " << Maa.GetName() << "'s value to " << newValue << " ...\n";
							break;
						case 3:
							cout << "\nNEW VALUE: ";
							cin >> newValue;
							Babe.ChangeValue(newValue);
							cout << "\nChanging " << Babe.GetName() << "'s value to " << newValue << " ...\n";
							break;
						default:
							cout << "\n**** The number " << changeOptionInt << " is an invalid entry ****\n";
							break;
					}

					break;
				case Display:
					// Code for displaying the animals contents.
					cout << endl << left << setw(11);
					cout << "ANIMAL" << setw(14) << "NAME" << setw(7) << "AGE" << "VALUE" << endl;

					cout << right;
					cout << setfill('-') << setw(11) << " " << setw(14) << " "
						 << setw(4) << " " << setw(12) << " " << endl;

					cout << left << setfill(' ');

					Fluffy.Display();
					Maa.Display();
					Babe.Display();

					break;
				default:
					// Error checking!!!
					cout << "\n**** The number " << menuOptionSelected << " is an invalid entry ****";
					cout << "\n**** Please input a number between 0 and 4 ****\n";
					break;
			}

		} else {
			// Menu Options before animals have been initialized.

			PrintMenuOptions(menuOptionSelected, isInitialized);

			if (menuOptionSelected == 0){
				inSession = false;
			} else if (menuOptionSelected == 1){
				inSession = true;

				Fluffy.SetInitialValues("Fluffy", "Sheep", 1, 15000.00);
				Maa.SetInitialValues("Maa", "Sheep", 3, 16520.35);
				Babe.SetInitialValues("Babe", "Pig", 2, 10240.67);

				cout << "\nInitializing Fluffy, Maa, & Babe...\n";

				isInitialized = true;
			} else {
				cout << "\n**** The number " << menuOptionSelected << " is an invalid entry ****";
				cout << "\n**** Please input a number between 0 and 1 ****\n";

				inSession = true;
				isInitialized = false;
			}
		}
	}
	return 0;
}
