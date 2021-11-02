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


/************************************************************************
 *
************************************************************************/
void PrintRecordHeadingToFile(string outputFileName) {

	ofstream oFile;
	oFile.open(outputFileName, ios::app);

	oFile << left;

	oFile << "\nMOVIE # " << setw(49) << " TITLE" << "YEAR " << "RATING  "
		  << setw(18) << "GENRE" << setw(18) << "ALT GENRE" << setw(20) << "LEAD ACTOR"
		  << "SUPPORTING ACTOR";

	oFile << "\n------- ";
	oFile << "------------------------------------------------ ";
	oFile << "---- ";
	oFile << "------ ";
	oFile << "----------------- ";
	oFile << "----------------- ";
	oFile << "------------------- ";
	oFile << "-------------------\n";

	//oFile.close();
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
    //inFile.close();
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

//        cout << perPtr->title << perPtr->leadActor << perPtr->supportingActor
//        	 << perPtr->genre << perPtr->alternativeGenre << perPtr->year
//			 << perPtr->rating << perPtr-> synopis;

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

	cout << "\nEnter an option (0 to exit): ";
	cin >> menuOption;

	cin.ignore(10000, '\n');
}


/************************************************************************
 *
 *
 *
************************************************************************/
void OutputEntireListContents(string outputFileName, DVD *head) {

	ofstream oFile;
	oFile.open(outputFileName, ios::app);

	oFile << "\nCOMPLETE MOVIE LISTING";

	oFile << left;

	oFile << "\nMOVIE # " << setw(49) << " TITLE" << "YEAR " << "RATING  "
		  << setw(18) << "GENRE" << setw(18) << "ALT GENRE" << setw(20) << "LEAD ACTOR"
		  << "SUPPORTING ACTOR";

	oFile << "\n------- ";
	oFile << "------------------------------------------------ ";
	oFile << "---- ";
	oFile << "------ ";
	oFile << "----------------- ";
	oFile << "----------------- ";
	oFile << "------------------- ";
	oFile << "-------------------\n";

	DVD *perPtr;

	perPtr = head;

	int counter = 1;

	while(perPtr != NULL) {

		oFile << left << "   ";
		oFile << setw(7) << counter;
		oFile << setw(47) << perPtr->title;
		oFile << setw(8) << perPtr->year;
		oFile << setw(6) << perPtr->rating;
		oFile << setw(18) << perPtr->genre;
		oFile << setw(18) << perPtr->alternativeGenre;
		oFile << setw(20) << perPtr->leadActor;
		oFile << setw(22) << perPtr->supportingActor << endl;

		perPtr = perPtr->next;

		counter++;
	}

	oFile.close();
}


/************************************************************************
 *
 *
 *
************************************************************************/
void PerformSearch(int menuOption, string outputFileName, DVD *head){

	ofstream oFile;
	oFile.open(outputFileName, ios::app);

	DVD *perPtr;

	string searchString;

	//int searchInteger;

	bool found = false;
	int counter = 0;

	perPtr = head;

	switch(menuOption){

		case TitleSearch:

			// Ask the user which title they would like to search for.
			cout << "\nWhich title are you looking for? ";
			getline(cin, searchString);

			// Loop until the end of list and also while hasn't been found.
			while(perPtr != NULL && !found){

				if(perPtr->title == searchString) {
					found = true;
				} else {
					perPtr = perPtr->next;
					found = false;
				}
			}

			// Check if movie searched was found.
			if (found) {
				cout << "Found the movie " << perPtr->title << endl;

				// CODE FOR OUTPUTTING TO FILE


				// END OF CODE


			} else {
				cout << "Sorry, the movie \"" << searchString << "\" was not found.\n";
			}

			// Reset the head back to the original value.
			perPtr = head;

			break;

		case GenreSearch:

			// Ask the user which genre they would like to seach for.
			cout << "\nWhich genre are you looking for? ";
			getline(cin, searchString);

			// Output heading to file for genre searches being performed.
			oFile << "\nSearch by genre for " << searchString << " found: ";
			oFile << left;
			oFile << "\nMOVIE # " << setw(49) << " TITLE" << "YEAR " << "RATING  "
				  << setw(18) << "GENRE" << setw(18) << "ALT GENRE" << setw(20) << "LEAD ACTOR"
				  << "SUPPORTING ACTOR";
			oFile << "\n------- ";
			oFile << "------------------------------------------------ ";
			oFile << "---- ";
			oFile << "------ ";
			oFile << "----------------- ";
			oFile << "----------------- ";
			oFile << "------------------- ";
			oFile << "-------------------\n";

			// Loop until the end of the linked list.
			while(perPtr != NULL){

				if (searchString == perPtr->genre || searchString == perPtr->alternativeGenre){

					oFile << left << "   ";
					oFile << setw(7) << counter+1;
					oFile << setw(47) << perPtr->title;
					oFile << setw(8) << perPtr->year;
					oFile << setw(6) << perPtr->rating;
					oFile << setw(18) << perPtr->genre;
					oFile << setw(18) << perPtr->alternativeGenre;
					oFile << setw(20) << perPtr->leadActor;
					oFile << setw(22) << perPtr->supportingActor << endl;

					counter++;
				}

				perPtr = perPtr->next;
			}

			// Check how many instances of the searched genre were found.
			if (counter == 0) {
				cout << "Sorry, no movies for the genre, " << searchString << " were found.\n";
				oFile << "NOTHING WAS FOUND DURING THE SEARCH.\n\n";
			} else {
				cout << "Found " << counter << " movies for the genre " << searchString << "!\n";
			}

			// Reset counter variable.
			counter = 0;

			// Reset the head back to the original value.
			perPtr = head;

			break;

		case ActorSearch:
			// Code for Actor Searches
			break;
		case YearSearch:
			// Code for Year Searches
			break;
		case RatingSearch:
			// Code for Rating Searches
			break;
		default:
			// Error Checking!
			break;

	}

}


