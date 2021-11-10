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
*
*
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
*
*
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
*
*
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
 *
 *
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


			cout << "\nAdding : " << perPtr->name;

			perPtr->next = head;
			perPtr->prev = NULL;

			if (head != NULL){
				head->prev = perPtr;
			}

			head = perPtr;
			perPtr = NULL;
			perPtr = new PersonNode;
		}
		delete perPtr;
		cout << endl;
	}

    return head;
}


/******************************************************************************
 *
 *
 *
 *
 ******************************************************************************/
void DisplayLinkedList(PersonNode *head){

    PersonNode *perPtr;
    perPtr = head;

    int counter = 1;

    if (head == NULL){
    	cout << "\nYes, the list is empty.\n";
    } else {

        cout << left << endl;
        cout << setw(3) << " " << setw(5) << "#" << setw(24) << "NAME" << setw(9) << "GENDER" << "AGE\n";
        cout << right;
        cout << setfill('-') << setw(8) << "-  " << setw(23) << "- " << setw(9) << "- " << setw(6) << "-\n";
        cout << setfill(' ');
        cout << left;

        while(perPtr != NULL) {

            cout << setw(3) << " " << setw(5) << counter << setw(26) << perPtr->name << setw(7)
        		 << perPtr->gender << perPtr->age << endl;

            perPtr = perPtr->next;

            counter++;
        }

    }

}


/****************************************************************************************
*
*
*
*
*****************************************************************************************/
void IsLinkedListEmpty(PersonNode *head) {

	PersonNode *ptr;
	int counter;

	ptr = head;
	counter = 0;

	while(ptr != NULL){

		if(ptr != NULL){
			counter++;
		}

		ptr = ptr->next;
	}

	if (counter == 0) {
		cout << "\nYes, the list is empty.\n";
	} else {
		cout << "\nNo, The list is NOT empty.\n";
	}
}


/****************************************************************************************
*
*
*
*
*****************************************************************************************/
void LinkedListSearch(PersonNode *head){

	PersonNode *perPtr;
	perPtr = head;
	string searchName;
	bool found = false;

	cout << "\nWho would you like to search for? ";
	getline(cin, searchName);

	cout << "\nSearching For " << searchName << "...\n";

	while(perPtr != NULL && !found){

		if(perPtr->name == searchName){
			found = true;
		} else {
			perPtr = perPtr->next;
		}

	}

	if (found){
		cout << "\nName: " << perPtr->name;
		cout << "\nGender: " << perPtr->gender;
		cout << "\nAge: " << perPtr->age << endl;
	} else {
		cout << "I'm sorry, \"" << searchName << "\" was NOT found!" << endl;
	}

}


/****************************************************************************************
*
*
*
*
*****************************************************************************************/
void RemoveNodeFromLinkedList(PersonNode *&head){

	string searchName;
	bool found = false;

	PersonNode *perPtr;
	PersonNode *tail;
	perPtr = head;

	// Find the tail.
	tail = head;
	if (tail != NULL){
		while(tail->next != NULL){
			tail = tail->next;
		}
	}

	if(head == NULL){
		cout << "\nCan't remove from an empty list!\n";
	} else {

		// Ask the user which node is being removed.
		cout << "\nWho would you like to remove? ";
		getline(cin, searchName);

		cout << "\nSearching For " << searchName << "...\n";

		// Loop until found or end of linked list has been reached.
		while(perPtr != NULL && !found){

			if(perPtr->name == searchName){
				found = true;
			} else {
				perPtr = perPtr->next;
			}

		}

		// Check if search name was found.
		if (found){
			cout << "\nName: " << perPtr->name;
			cout << "\nGender: " << perPtr->gender;
			cout << "\nAge: " << perPtr->age << endl;

			// Reassign pointer variables and delete node.
			if (perPtr->prev == NULL){
				// Removing from the front.
				perPtr = head;
				perPtr->next->prev = NULL;
				head = perPtr->next;
				delete perPtr;
				perPtr = NULL;
			} else if(perPtr->next == NULL) {
				// removing from the tail.
				perPtr = tail;
				perPtr->prev->next = NULL;
				tail = perPtr->prev;
				delete perPtr;
				perPtr = NULL;
			} else {
				// Removing from the middle.
				perPtr->next->prev = perPtr->prev;
				perPtr->prev->next = perPtr->next;
				delete perPtr;
				perPtr = NULL;
			}

		} else {
			cout << "I'm sorry, \"" << searchName << "\" was NOT found!" << endl;
		}

	}
}


/************************************************************************
 *
 *
 *
 *
************************************************************************/
void ClearLinkedList(PersonNode *&head) {

	PersonNode *perPtr;
	PersonNode *nextPtr;

	perPtr = head;

	if (head == NULL) {
		cout << "\nThe list has been cleared!\n";
	} else {
		cout << "\nCLEARING LIST:";
		while (perPtr != NULL) {
			cout << "\nRemoving " << perPtr->name << "!";
			nextPtr = perPtr->next;
			perPtr = NULL;
			perPtr = nextPtr;
		}
		cout << "\n\nThe list has been cleared!\n";
		head = NULL;
	}

}



