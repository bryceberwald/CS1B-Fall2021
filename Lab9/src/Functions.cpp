/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #9         : Implementing a Stack
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/27/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/****************************************************************************************
* This function can print to either the console or the output file using ostream type
* with the specified variable being passed by reference.
*
* 1 Argument -> RETURNS: Nothing
*****************************************************************************************/
void PrintHeader(ostream &output) {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int LAB_NUM = 9;
	const char LAB_NAME[30] = "Implementing a Stack";

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
* This function will validate whether the users input is an integer or a character. If
* the users input is a character, the function will return false, otherwise true.
*
* 1 Argument -> RETURNS: Boolean
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
* This function will print the menu options for the user to make a selection. The menu
* options utilize a few techniques learned through pointers and linked lists. The user
* must select a menu option in the correct range otherwise they will be prompted to change
* their input to become valid.
*
* 1 Argument -> RETURNS: Nothing
*****************************************************************************************/
void PrintMenuOptions(int &menuOption) {

	string menuOptionStr;
	bool isNumber = false;

		do {
			cout << "\nSTACK MENU: ";
			cout << "\n1 – Add a person (PUSH)";
			cout << "\n2 – Remove a person (POP)";
			cout << "\n3 – Is the stack empty? (ISEMPTY)";
			cout << "\n4 – Who is on top? (PEEK)";
			cout << "\n5 – How many people are there? (SIZE)";
			cout << "\n0 – to Exit";

			cout << "\nPlease enter a command: ";
			cin >> menuOptionStr;

			cin.ignore(10000, '\n');

			isNumber = ValidateNumber(menuOptionStr);

			if (!isNumber) {
				cout << "\n**** Please input a NUMBER between 0 and 5 ****\n";
			}


		} while(!isNumber);

		menuOption = atoi(menuOptionStr.c_str());

}


/****************************************************************************************
* This function is designed to push a new element to the front of the linked list. The
* function will gather three different input fields (Name, Gender & Age) respectfully.
* After dynamically creating a new PersonNode, we will add a new list item and reassign
* the pointers in the list for future continuation.
*
* 1 Argument -> RETURNS: head
*****************************************************************************************/
PersonNode *PushItem(PersonNode *head){

	PersonNode *perPtr;

	perPtr = new PersonNode;

	cout << "\nWho would you like to add? ";

	cout << "\nEnter name: ";
	getline(cin, perPtr->name);

	cout << "Enter Gender: ";
	cin >> perPtr->gender;

	cout << "Enter Age: ";
	cin >> perPtr->age;

	cin.ignore(10000, '\n');

    perPtr->next = head;

    head = perPtr;

    delete perPtr;

    return head;
}


/****************************************************************************************
* This function will pop the first item from the linked list unless the list empty, meaning
* that it's equal to NULL. If the list isn't empty, the first item will be popped, updating
* the list and displaying the persons results who is being popped to the console.
*
* 1 Argument -> RETURNS: Nothing
*****************************************************************************************/
void PopItem(PersonNode *&head) {

	PersonNode *perPtr;

	perPtr = head;

	if (perPtr == NULL) {
		cout << "\nCan't POP from an empty stack!\n";
	} else {
		head = perPtr->next;

		cout << "\nPOPPING";
		cout << "\nName: " << perPtr->name;
		cout << "\nGender: " << perPtr->gender;
		cout << "\nAge: " << perPtr->age << endl;
	}
}


/************************************************************************
 * This function counts the number of instances found sequentially. The
 * pointer will be reassigned to next item in the list until the pointer
 * is equivalent to NULL.
 *
 * 2 Arguments -> RETURNS: Integer
************************************************************************/
int StackInstances(PersonNode *head){

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

	return counter;
}


/****************************************************************************************
* This function will peek at the first item in the linked list. If the head is equal to
* NULL that means the list is empty and the program will specify so. If the list is not
* empty, the first item in the linked list will be displayed via the console.
*
* 1 Argument -> RETURNS: Nothing
*****************************************************************************************/
void PeekItem(PersonNode *&head) {

	PersonNode *ptr;

	ptr = head;

	if (ptr != NULL) {
		cout << "\nPEEKING at ";
		cout << "\nName: " << ptr->name;
		cout << "\nGender: " << ptr->gender;
		cout << "\nAge: " << ptr->age << endl;
	} else {
		cout << "\nThere is nobody to PEEK at!!!\n";
	}

}


/****************************************************************************************
* This function will determine if the linked list is empty or not. We will sequentially
* add all the list items until a value of NULL is reached. If the list empty to begin with,
* the loop will be skipped and the counter will be equal to 0, letting us know that the
* list is empty.
*
* 1 Argument -> RETURNS: Nothing
*****************************************************************************************/
void IsListEmpty(PersonNode *head) {

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
		cout << "\nYes, the stack is empty.\n";
	} else {
		cout << "\nThe stack is NOT empty.\n";
	}
}

