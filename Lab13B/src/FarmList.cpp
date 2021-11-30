/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #13	      : Linked Lists of Sheep - OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/01/21 @ 11:59PM
 *************************************************************************/

#include "FarmList.h"

/**************************************************************************
 *
 *************************************************************************/
FarmList::FarmList(){

	head = NULL;
	sheepCount = 0;

}


/**************************************************************************
 *
 *************************************************************************/
FarmList::~FarmList(){

}


/**************************************************************************
 *
 *************************************************************************/
void FarmList::AddSheep(Sheep newSheep){

	SheepNode *sheepPtr;
	SheepNode *tail;

	tail = head;

	sheepPtr = new SheepNode;

	string name;
	int age;

	// Find the tail
	if (tail != NULL){
		while(tail->next != NULL){
			tail = tail->next;
		}
	}

	cout << "\nSheep Name: ";
	getline(cin, name);

	do {
		cout << "Sheep Age: ";
		cin >> age;

		if(age > 9){
			cout << "Sheep can not be more than 9 years old...\n";
		}

		if(age < 0){
			cout << "Sheep have to be at least 0 years old...\n";
		}

	} while(age < 0 || age > 9);

	cin.ignore(10000, '\n');

	newSheep.SetInitialValues(name, age);

	sheepPtr->currentSheep = newSheep;

	if (tail == NULL) {
		head = sheepPtr;
		sheepPtr = NULL;
	    delete sheepPtr;

	} else {
		sheepPtr->next = NULL;
		tail->next = sheepPtr;
		tail = sheepPtr;

		sheepPtr = NULL;
	    delete sheepPtr;
	}

	cout << "\nThe Sheep...";
	cout << "\nSheep Name: " << name;
	cout << "\nSheep Age: " << age;
	cout << "\nHas been added!\n";

	sheepCount++;

}


/**************************************************************************
 *
 *************************************************************************/
void FarmList::ClearList(){

	SheepNode *sheepPtr;
	SheepNode *nextPtr;

	sheepPtr = head;

	if (head == NULL) {
		cout << "\nThe list is empty!\n";
	} else {
		cout << "\nThe list has been cleared.\n";
		while (sheepPtr != NULL) {
			nextPtr = sheepPtr->next;
			sheepPtr = NULL;
			sheepPtr = nextPtr;

		}
		head = NULL;
		sheepCount = 0;
	}

}


/**************************************************************************
 *
 *************************************************************************/
Sheep FarmList::FindSheep(string sheepName) const {

		SheepNode *sheepPtr;
		sheepPtr = head;

		Sheep foundSheep;

		bool found = false;

		// Loop until the end of list and also while hasn't been found.
		while(sheepPtr != NULL && !found){

			if(sheepPtr->currentSheep.GetName() == sheepName) {
				found = true;
				foundSheep = sheepPtr->currentSheep;
			} else {
				sheepPtr = sheepPtr->next;
				found = false;
			}
		}
	return foundSheep;
}


/**************************************************************************
 *
 *************************************************************************/
Sheep FarmList::GetFirstSheep() const {
	SheepNode *sheepPtr;

	sheepPtr = head;

	if (sheepPtr != NULL) {
		return sheepPtr->currentSheep;
	} else {
		cout << "\nNobody is in the front - the list is empty!\n";
		return sheepPtr->currentSheep;
	}
}


/**************************************************************************
 *
 *************************************************************************/
int FarmList::TotalSheep() const {
	return sheepCount;
}


/**************************************************************************
 *
 *************************************************************************/
void FarmList::DisplaySheepTable() const {

	SheepNode *sheepPtr;
	sheepPtr = head;

	Sheep showSheep;
	string name;
	int age;

	if(sheepCount > 0){
		cout << endl << left;
		cout << setw(15) << "Name" << "AGE" << endl;
		cout << right;
		cout << setfill('-') << setw(15) << " " << setw(4) << " " << setfill(' ');

		cout << endl << left;

		while(sheepPtr != NULL){
			sheepPtr->currentSheep.GetValues(name, age);
			cout << setw(16) << name << age << endl;

			sheepPtr = sheepPtr->next;
		}

		if(sheepCount == 1){
			cout << "\nThere is one sheep in the list.\n";
		} else {
			cout << "\nThere are " << sheepCount << " sheep in the list!\n";
		}

	} else {
		cout << "\nThe list is empty!\n";
	}

}

