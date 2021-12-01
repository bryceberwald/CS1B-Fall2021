/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #13	      : Linked Lists of Sheep - OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/01/21 @ 11:59PM
 *************************************************************************/

#include "FarmList.h"

/**************************************************************************
 * This function will initialize our private sheep counter attribute to the
 * value of zero since no sheep have been added to our list yet.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
FarmList::FarmList(){

	head = NULL;
	sheepCount = 0;

}


/**************************************************************************
 * This function is for the destructor, for this assignment we will not be
 * adding anything to it. Leaving this as a template basis.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
FarmList::~FarmList(){

}


/**************************************************************************
 * This is the function prototype for adding a sheep to the end of a list.
 * We will gather input values for a sheep object from the user which in
 * turn will be appended to the list.
 *
 * 1 Argument passed by value -> RETURNS: Nothing
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
 * This function will clear the entire list contents. If the list contents
 * have already been cleared, a message concerning that will be displayed.
 *
 * No Arguments -> RETURNS: Nothing
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
 * This function will find a sheep object by its name in the list and
 * return the sheep when found. If no sheep was found, an empty sheep will
 * be returned for the calling function to know that, no sheep was found.
 *
 * 1 Argument passed by value -> RETURNS: Sheep
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
 * This function will get the first sheep from the list to be returned to
 * the calling function.
 *
 * No Arguments -> RETURNS: Sheep
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
 * This function will get the total number of sheep from the farm list
 * class attribute to be returned to the calling function.
 *
 * No Arguments -> RETURNS: Integer
 *************************************************************************/
int FarmList::TotalSheep() const {
	return sheepCount;
}


/**************************************************************************
 * This function will display the entire list contents to the console in
 * the format specified in class. If no sheep are currently held in the list,
 * a message concerning that will be displayed.
 *
 * No Arguments -> RETURNS: Nothing
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

