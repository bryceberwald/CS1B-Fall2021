/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #3  : Searching Linked Lists
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/09/2021 @ 11:59PM
 ******************************************************************************/

#include "Functions.h"

/*****************************************************************************
* This function will print the class header to the console.
******************************************************************************/
void printHeader(ostream &output) {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int ASSIGNMENT_NUM = 3;
	const char ASSIGNMENT_NAME[30] = "Searching Linked Lists";

	// Output the program header to output specified.
	output << left;
	output << "*******************************************************";
	output << "\n* PROGRAMMED BY : " << PROGRAMMER;
	output << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	output << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	output << "\n* ASSIGNMENT #" << setw(2) << ASSIGNMENT_NUM << ": " << ASSIGNMENT_NAME;
	output << "\n*******************************************************" << endl;
	output << right << endl;
}


/*******************************************************************************
 * This function will get input from the user, collecting the input file name
 * and the output file name and storing the string values in main since they
 * are being passed by reference.
 *******************************************************************************/
void readFileNames(string &inputFileName, string &outputFileName) {
	cout << setw(40) << left << "What input file would you like to use?";
	cin >> inputFileName;

	cout << setw(41) << left << "\nWhat output file would you like to use?";
	cin >> outputFileName;
}


/******************************************************************************
 * This function will create a linked list with all the data inside the input
 * file. A pointer will be created dynamically allowing us to continually add
 * data into our struct DVD type fields until the input file has no more data
 * to be stored. After all the data from the input file has been stored, we will
 * delete the pointer we dynamically created to eliminate the possibility of a
 * memory leak and return the head to main.
 ******************************************************************************/
DVD *CreateLinkedList(string inputFileName, DVD *head) {

	DVD *perPtr;
	perPtr = new DVD;

	ifstream inFile;
	inFile.open(inputFileName);

	if (inFile.is_open()) {
		while (inFile && perPtr != NULL) {

			getline(inFile, perPtr->title);
			getline(inFile, perPtr->leadActor);
			getline(inFile, perPtr->supportingActor);
			getline(inFile, perPtr->genre);
			getline(inFile, perPtr->alternativeGenre);

			inFile >> perPtr->year;
			inFile >> perPtr->rating;

			inFile.ignore(10000, '\n');

			getline(inFile, perPtr->synopis);

			inFile.ignore(10000, '\n');

			perPtr->next = head;
			head = perPtr;
			perPtr = new DVD;
		}
		delete perPtr;
	}
    inFile.close();
    return head;
}


/************************************************************************
 * This function will output the linked list in reversed format. Only
 * keeping track of the head and pointing to next until the pointer
 * equates to NULL.
************************************************************************/
void OutputList(DVD *head) {

    DVD *perPtr;
    perPtr = head;

    while(perPtr != NULL) {
        cout << "\nTitle: " << perPtr->title;
        cout << "\nLead Actor/Actress: " << perPtr->leadActor;
        cout << "\nSupporting Actor: " << perPtr->supportingActor;
        cout << "\nGenre: " << perPtr->genre;
        cout << "\nAlternative Genre: " << perPtr->alternativeGenre;
        cout << "\nYear: " << perPtr->year;
        cout << "\nRating: " << perPtr->rating;
        cout << "\nDescription: " << perPtr->synopis;

        perPtr = perPtr->next;
    }
}


/************************************************************************
 * This function will print the menu options to the console as needed.
 * We will gather a menu option as input which will be stored in main
 * since the variable is being passed by reference.
************************************************************************/
void PrintMenuOptions(int &menuOption) {

	cout << "\nDVD MENU OPTIONS: \n";
	cout << "\n1 - Output Entire List";
	cout << "\n2 - Title Search";
	cout << "\n3 - Genre Search";
	cout << "\n4 - Actor Search";
	cout << "\n5 - Year Search";
	cout << "\n6 - Rating Search (0-9)";
	cout << "\n0 – Exit";

	cout << "\nEnter an option (0 to exit):";
	cin >> menuOption;

	cin.ignore(10000, '\n');
}




