//============================================================================
// Name        : LinkedLists.cpp
// Author      : Bryce Berwald
// Version     :
// Copyright   :
// Description :
//============================================================================

#include "Functions.h"


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
PersonNode *CreateOrderedLinkedList(string inputFileName, PersonNode *head) {

	PersonNode *perPtr;
	PersonNode *searchPtr;

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

			if(head == NULL || head->name > perPtr->name){
				perPtr->next = head;
				perPtr->prev = NULL;
				if (head != NULL){
					head->prev = perPtr;
				}

				head = perPtr;
				perPtr = NULL;


			} else {
				searchPtr = head;
				bool found= false;
				while (searchPtr->next != NULL && !found){

					if (searchPtr->next->name > perPtr->name){
						found = true;
				    } else {
				    	searchPtr = searchPtr->next;
				    }

				}
			    perPtr->next = searchPtr->next;
			    perPtr->prev = searchPtr;

			    if(searchPtr->next != NULL){
			    	searchPtr->next->prev = perPtr;
			    }

			    searchPtr->next = perPtr;
			    perPtr = NULL;
				searchPtr = NULL;
			}
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


/******************************************************************************
* This function will determine if the linked list is empty or not. We will
* sequentially add all the list items until a value of NULL is reached. If the
* list empty to begin with, the loop will be skipped and the counter will be
* equal to 0, letting us know that the list is empty.
*
* 1 Argument -> RETURNS: Nothing
*******************************************************************************/
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


/****************************************************************************
*
*
*
*
****************************************************************************/
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


/****************************************************************************
*
*
*
*
*****************************************************************************/
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
 * This function will eliminate every item from the linked list. If the
 * list is already empty, only a message to the console will be displayed,
 * otherwise each item will be assigned a next pointer and nullify the
 * current pointer till the end of the list has been reached, we also will
 * nullify the head to ensure an empty list.
 *
 * 1 Argument -> RETURNS: Nothing
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


