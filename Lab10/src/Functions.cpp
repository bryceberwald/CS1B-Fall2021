/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #9         : Creating an Ordered List
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/10/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/****************************************************************************************
*
*****************************************************************************************/
void PrintHeader(ostream &output) {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int LAB_NUM = 10;
	const char LAB_NAME[30] = "Creating an Ordered List";

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


/****************************************************************************************
*
*****************************************************************************************/
bool ValidateNumber (string menuOptionStr) {

   bool isValid;

   for (int i = 0; i < menuOptionStr.length(); i++)
	   if (isdigit(menuOptionStr[i]) == false){
		   isValid = false;
	   } else {
		   isValid = true;
	   }

   return isValid;
}


/****************************************************************************************
*
*****************************************************************************************/
void PrintMenuOptions(int &menuOption) {

	string menuOptionStr;
	bool isNumber = false;

		do {
			cout << "\nLIST MENU: ";
			cout << "\n1 – Create List";
			cout << "\n2 – Display List";
			cout << "\n3 - Is the list empty?";
			cout << "\n4 - Search by name";
			cout << "\n5 - Remove Node";
			cout << "\n6 - Clear List";
			cout << "\n0 – to Exit";

			cout << "\nEnter a command (0 to exit): ";
			cin >> menuOptionStr;

			cin.ignore(10000, '\n');

			isNumber = ValidateNumber(menuOptionStr);

			if (!isNumber) {
				cout << "\n**** Please input a NUMBER between 0 and 6 ****\n";
			}


		} while(!isNumber);

		menuOption = atoi(menuOptionStr.c_str());

}


/******************************************************************************
 *
 ******************************************************************************/
PersonNode *CreateLinkedList(string inputFileName, PersonNode *head) {

	PersonNode *perPtr;
	perPtr = new PersonNode;

	ifstream inFile;
	inFile.open(inputFileName);

	if (inFile.is_open()) {
		while (inFile && perPtr != NULL) {

			getline(inFile, perPtr->name);
			inFile.get(perPtr->gender);
			inFile >> perPtr->age;

			inFile.ignore(10000, '\n');
			inFile.ignore(10000, '\n');


			perPtr->next = head;
			head = perPtr;
			perPtr = new PersonNode;
		}
		delete perPtr;
	}
    return head;
}


/******************************************************************************
 *
 ******************************************************************************/
void DisplayLinkedList(PersonNode *head){

    PersonNode *perPtr;

    perPtr = head;

    while(perPtr != NULL) {
        cout << "\nName: " << perPtr->name;
        cout << "\nGender: " << perPtr->gender;
        cout << "\nAge: " << perPtr->age << endl;

        perPtr = perPtr->next;
    }

}






