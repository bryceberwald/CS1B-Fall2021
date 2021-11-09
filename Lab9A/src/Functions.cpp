/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #9         : Implementing a Queue
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/03/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

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
			cout << "\nQUEUE MENU: ";
			cout << "\n1 – ENQUEUE (Add a person)";
			cout << "\n2 – DEQUEUE (Remove a person)";
			cout << "\n3 – ISEMPTY (Is the queue empty?)";
			cout << "\n4 – FRONT   (Who is in front?)";
			cout << "\n5 – SIZE    (How many people are there?)";
			cout << "\n6 - Clear the Queue";
			cout << "\n0 – to Exit";

			cout << "\nPlease enter a command: ";
			cin >> menuOptionStr;

			cin.ignore(10000, '\n');

			isNumber = ValidateNumber(menuOptionStr);

			if (!isNumber) {
				cout << "\n**** Please input a NUMBER between 0 and 6 ****\n";
			}


		} while(!isNumber);

		menuOption = atoi(menuOptionStr.c_str());

}


/****************************************************************************************
* This function will add linked list items to the end of the list. By doing this we will
* need to find the tail of the linked list. If the list is empty initially then the users
* input will be automated stored in the head, Otherwise in the positions following the head
* known as the tail.
*
* 1 Argument -> RETURNS: Nothing
*****************************************************************************************/
void EnqueueItem(PersonNode *&head){

	PersonNode *perPtr;
	PersonNode *tail;

	perPtr = new PersonNode;

	tail = head;

	// Find the tail
	if (tail != NULL){
		while(tail->next != NULL){
			tail = tail->next;
		}
	}

	cout << "\nWho would you like to add? ";

	cout << "\nEnter name: ";
	getline(cin, perPtr->name);

	cout << "Enter Gender: ";
	cin >> perPtr->gender;

	cout << "Enter Age: ";
	cin >> perPtr->age;

	cin.ignore(10000, '\n');

	if (tail == NULL) {
		head = perPtr;
		perPtr = NULL;
	    delete perPtr;

	} else {
		perPtr->next = NULL;
		tail->next = perPtr;
		tail = perPtr;

		perPtr = NULL;
	    delete perPtr;
	}

}


/****************************************************************************************
* This function will remove linked list items from the front of the list. Reassigning
* the head to the next linked list item. The contents of the dequeued item will be
* displayed to the console.
*
* 1 Argument -> RETURNS: Nothing
*****************************************************************************************/
void DequeueItem(PersonNode *&head) {

	PersonNode *perPtr;
	perPtr = head;

	if (perPtr == NULL) {
		cout << "\nCan't DEQUEUE from an empty list!\n";
	} else {
		head = perPtr->next;

		cout << "\nDEQUEUEING";
		cout << "\nName: " << perPtr->name;
		cout << "\nGender: " << perPtr->gender;
		cout << "\nAge: " << perPtr->age << endl;
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
		cout << "\nYes, the QUEUE is empty.\n";
	} else {
		cout << "\nThe QUEUE is NOT empty.\n";
	}
}


/****************************************************************************************
* This function will look at the front item of the linked list. If the head is equal to
* NULL that means the list is empty and the program will specify so. If the list is not
* empty, the first item in the linked list will be displayed via the console.
*
* 1 Argument -> RETURNS: Nothing
*****************************************************************************************/
void FrontItem(PersonNode *head) {

	PersonNode *ptr;

	ptr = head;

	if (ptr != NULL) {
		cout << "\nThe first person in the queue is: ";
		cout << "\nName: " << ptr->name;
		cout << "\nGender: " << ptr->gender;
		cout << "\nAge: " << ptr->age << endl;
	} else {
		cout << "\nNobody in FRONT, the queue is empty!!\n";
	}

}


/************************************************************************
 * This function counts the number of instances found sequentially. The
 * pointer will be reassigned to next item in the list until the pointer
 * is equivalent to NULL.
 *
 * 2 Arguments -> RETURNS: Integer
************************************************************************/
int QueueInstances(PersonNode *head){

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


/************************************************************************
 * This function will eliminate every item from the linked list. If the
 * list is already empty, only a message to the console will be displayed,
 * otherwise each item will be assigned a next pointer and nullify the
 * current pointer till the end of the list has been reached, we also will
 * nullify the head to ensure an empty list.
 *
 * 1 Argument -> RETURNS: Nothing
************************************************************************/
void ClearTheQueue(PersonNode *&head) {

	PersonNode *perPtr;
	PersonNode *nextPtr;

	perPtr = head;

	if (head == NULL) {
		cout << "\nThe QUEUE is ALREADY clear!\n";
	} else {
		cout << "\nCLEARING...\n";
		while (perPtr != NULL) {
			cout << perPtr->name << endl;
			nextPtr = perPtr->next;
			perPtr = NULL;
			perPtr = nextPtr;

		}
		head = NULL;
		cout << "\nThe queue has been CLEARED!\n";
	}

}

