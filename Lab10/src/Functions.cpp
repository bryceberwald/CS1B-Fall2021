/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #9         : Creating an Ordered List
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/10/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/*************************************************************************
* This function will validate whether the users input is an integer or a
* character. If the users input is a character, the function will return
* false, otherwise true.
*
* 1 Argument -> RETURNS: Boolean
**************************************************************************/
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


/**************************************************************************
* This function will print the menu options for the user to make a selection.
* The menu options utilize a few techniques learned through pointers and
* linked lists. The user must select a menu option in the correct range
* otherwise they will be prompted to change their input to become valid.
*
* 1 Argument -> RETURNS: Nothing
**************************************************************************/
void PrintMenuOptions(int &menuOption) {

	string menuOptionStr;     // INPUT - User will enter a value to be stored.
	bool isNumber = false;    // CALC  - Determine's if input is a valid number.

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

			// Call function to check input validity.
			isNumber = ValidateNumber(menuOptionStr);

			if (!isNumber) {
				cout << "\n**** Please input a NUMBER between 0 and 6 ****\n";
			}


		} while(!isNumber);

		// Convert the numerical string to an integer.
		menuOption = atoi(menuOptionStr.c_str());

}


/******************************************************************************
 * This function will create an ordered doubly linked list. Every time a new
 * node is being added, a searchPtr will be assigned the value of head to
 * figure out the placement of the node based on sequencing all of the nodes in
 * an alphabetically manner. A special case will be handled for a head thats null
 * or a node in the first position that needs to be rearranged.
 *
 * 2 Arguments -> RETURNS: Head
 ******************************************************************************/
PersonNode *CreateOrderedLinkedList(string inputFileName, PersonNode *head) {

	PersonNode *perPtr;      // Pointer used to handle new data input.
	PersonNode *searchPtr;   // Pointer used as a clone for the head for searching.

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

			// Adding to the head
			if(head == NULL || head->name > perPtr->name){
				perPtr->next = head;
				perPtr->prev = NULL;
				if (head != NULL){
					head->prev = perPtr;
				}
				head = perPtr;
				perPtr = NULL;
			// Adding to the middle/end
			} else {
				searchPtr = head;
				bool found= false;
				while (searchPtr->next != NULL && !found){
					// Compare searched pointers with current pointer.
					if (searchPtr->next->name > perPtr->name){
						found = true;
				    } else {
				    	searchPtr = searchPtr->next;
				    }
				}
			    perPtr->next = searchPtr->next;
			    perPtr->prev = searchPtr;

			    // For adding to the tail.
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
 * This function will display the linked list contents to the console in the
 * format specified in class. If the head is NULL, a message will be displayed
 * instead of nodes. Otherwise all the nodes in the current linked list will be
 * displayed to the console.
 *
 * 1 Argument -> RETURNS: Nothing
 ******************************************************************************/
void DisplayLinkedList(PersonNode *head){

    PersonNode *perPtr;   // Pointer used to display of linked list nodes.
    perPtr = head;

    int counter = 1;      // CALC/OUT - Incremented and displayed next to each node.

    // Check if list is empty.
    if (head == NULL){
    	cout << "\nCan't display an empty list\n";
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

	PersonNode *ptr; // Pointer used to count linked list nodes.
	int counter;     // CALC - Used to count how many nodes are in list.

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
* This function is for letting a user input a name to be searched for in the
* linked list and display its contents when or if it has been found. If no
* linked list name of the searched string contain matches, then a message
* saying the name was not found will be displayed.
*
* 1 Argument -> RETURNS: Nothing
****************************************************************************/
void LinkedListSearch(PersonNode *head){

	PersonNode *perPtr;  // Pointer used to search for a name in list.
	string searchName;   // INP/CALC - Users input used for comparisons.
	bool found = false;  // LCV - Used to shorten the loop when found.

	perPtr = head;

	if(head == NULL){
		cout << "\nCan't search an empty list\n";
	} else {
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

}


/****************************************************************************
* This function will remove a node from a doubly linked list. The function
* will ask the user what name they would like to remove from the list, then
* loop through the pointed struct until a name is found. Found nodes will be
* removed differently depending on the nodes location. After the removal, the
* updated head thats passed by reference will be updated.
*
* 1 Argument -> RETURNS: Nothing
*****************************************************************************/
void RemoveNodeFromLinkedList(PersonNode *&head){

	string searchName;   // INP/CALC - Users input used for comparisons.
	bool found = false;  // LCV - Used to shorten the loop when found.

	PersonNode *perPtr;  // Pointer used as the starting point of list.
	PersonNode *tail;    // Pointer used as ending point of list.

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

		cout << "\nSearching For " << searchName << "...";

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
			cout << "\nRemoving " << perPtr->name << "!\n";

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
			cout << "\nI'm sorry, \"" << searchName << "\" was NOT found!" << endl;
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

	PersonNode *perPtr;  // Pointer used as the starting point of the list.
	PersonNode *nextPtr; // Pointer temporarily holds perPtr before nullifying.

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



