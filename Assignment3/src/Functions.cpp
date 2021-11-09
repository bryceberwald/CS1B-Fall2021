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
*
* 1 Argument passed by reference -> RETURNS: Nothing
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


/****************************************************************************************
* This function will take in a string and determine if it's a number or not. The function
* will loop though the length of the string and count every time a non number is made
* known. If any non numbers are counted, then the string is not a number and will return
* false. The function will also check if the first index is a dash representing a possible
* negative number, which the count will decrement by one if so.
*
* 1 Argument passed by value -> RETURNS: Nothing
*****************************************************************************************/
bool ValidateNumber (string number) {

   bool isValid;
   int counter = 0;

   for (int i = 0; i < number.length(); i++){
	   if (isdigit(number[i]) == false){
		   counter++;
	   }
   }

   // Adjust counter for negative numbers.
   if(number[0] == '-'){
	   counter--;
   }

   if(counter == 0) {
	   isValid = true;
   } else {
	   isValid = false;
   }

   return isValid;
}


/****************************************************************************************
* This function will take in a string as a parameter and ensure that it says within
* bounds of our title searching function necessities. We don't want our synopsis to run
* all on one line. Therefore, when the line gets to an exceeding length and a blank space
* is the current indexes value, a new line will be inserted into a new string that will be
* returned as a whole to the calling function.
*
* 1 Argument passed by value -> RETURNS: String
*****************************************************************************************/
string WordWrapping(string newStr){

	ostringstream output;      // CALC/OUT - Used for words to be appended to and returned.
	string character;          // CALC     - Used to append letters to the ostringstream output variable.

	const int MAX_LENGTH = 65; // CALC - Used to determine the exceeding length of the line.
	int counter = 0;           // CALC - Used to count how many characters have been added to a line.

	for(int i = 0; i < newStr.length(); i++){
		character = newStr[i];

		if ((counter > MAX_LENGTH) && character == " ") {
			output << endl;
			counter = 0;
		} else {
			output << character;
		}
		counter++;
	}
	return output.str();
}


/*******************************************************************************
 * This function will get input from the user, collecting the input file name
 * and the output file name and storing the string values in main since they
 * are being passed by reference. If the user selects d for default for either
 * of these two input questions, a default string file name will be provided.
 *
 * 2 Arguments passed by reference -> RETURNS: Nothing
 *******************************************************************************/
void readFileNames(string &inputFileName, string &outputFileName) {

	cout << setw(40) << left << "Which input file would you like to use(type d for default file)? ";
	cin >> inputFileName;

	if (inputFileName == "d" || inputFileName == "D"){
		inputFileName = "inputFile.txt";
	}

	cout << setw(41) << left << "\nWhich output file would you like to use(type d for default file)? ";
	cin >> outputFileName;

	if (outputFileName == "d" || outputFileName == "D"){
		outputFileName = "OFile.txt";
	}

}


/******************************************************************************
 * This function will create a linked list with all the data inside the input
 * file. A pointer will be created dynamically allowing us to continually add
 * data into our struct DVD type fields until the input file has no more data
 * to be stored. After all the data from the input file has been stored, we will
 * delete the pointer we dynamically created to eliminate the possibility of a
 * memory leak and return the head to main.
 *
 * 2 Arguments passed by value -> RETURNS: Head
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
    return head;
}


/************************************************************************
 * This function will print the menu options to the console as needed.
 * We will gather a menu option as input which will be stored in main
 * since the variable is being passed by reference. This function will
 * also check to ensure a number is being used for input.
 *
 * 1 Argument passed by reference -> RETURNS: Nothing
************************************************************************/
void PrintMenuOptions(int &menuOption) {

	bool numberValid;      // LCV/CALC - Used to check if input is a valid number.
	string menuOptionStr;  // INP/CALC - User inputs a string that's calculated if it's a number.

	do {

		cout << "\nDVD MENU OPTIONS: \n";
		cout << "\n1 - Output Entire List";
		cout << "\n2 - Title Search";
		cout << "\n3 - Genre Search";
		cout << "\n4 - Actor Search";
		cout << "\n5 - Year Search";
		cout << "\n6 - Rating Search (0-9)";
		cout << "\n0 – Exit";

		cout << "\nEnter an option (0 to exit): ";
		cin >> menuOptionStr;

		cin.ignore(10000, '\n');

		numberValid = ValidateNumber(menuOptionStr);

		if(!numberValid) {
			cout << "\n**** Please input a NUMBER between 0 and 6 ****\n";
		}

	} while(!numberValid);

	menuOption = atoi(menuOptionStr.c_str());

}


/************************************************************************
 * This function will output the entire linked list to an output file as
 * needed. The function will start with the head and go through the entire
 * linked list until the pointer equates to NULL.
 *
 * 2 Arguments passed by value -> RETURNS: Nothing
************************************************************************/
void OutputEntireListContents(string outputFileName, DVD *head) {

	// Initialize variable for the output file.
	ofstream oFile;

	// Open output file and append to it.
	oFile.open(outputFileName, ios::app);

	// Create a pointer to be used by sub program.
	DVD *perPtr;
	perPtr = head;

	int counter = 1;  // CALC/OUT - Used for calculations and output to the file.

	oFile << "COMPLETE MOVIE LISTING";
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

	cout << "\nListing all movies!\n";

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
	oFile << "\n\n\n";
	oFile.close();
}


/************************************************************************
 * This function is in charge of handing the searching aspect of the
 * program. The function takes in 3 different parameters, one of the
 * parameters passed is the menuOption which will be used for determining
 * which search is to be done by this function. The title search has unique
 * qualities compared to the other searching cases.
 *
 * 3 Arguments passed by value -> RETURNS: Nothing
************************************************************************/
void PerformSearch(int menuOption, string outputFileName, DVD *head){

	// Initialize variable for the output file.
	ofstream oFile;

	// Open output file and append to it.
	oFile.open(outputFileName, ios::app);

	// Create a pointer to be used by sub program.
	DVD *perPtr;
	perPtr = head;

	string searchString;         // INPUT      - Used will enter a value to be stored.
	int searchInteger;           // INPUT/CALC - User will enter a value, or used or parsing.

	bool isValidNumber = false;  // CALC     - Used to determine if the users input is a valid number.
	bool found = false;          // LCV      - Used to control the length of the search when item is found.
	int counter = 0;             // CALC/OUT - Used for calculations and output to the file.

	switch(menuOption){

		case TitleSearch:

			// Ask the user which title they would like to search for.
			cout << "\nWhich title are you looking for? ";
			getline(cin, searchString);

			cout << "\nSearching for the title " << searchString << endl;

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
				cout << "Found the movie " << perPtr->title << "!\n\n";

				// CODE FOR OUTPUTTING TO FILE
				oFile << left;
				oFile << setfill('*') << setw(75) << "*" << setfill(' ') << endl;
				oFile << "Title: " << perPtr->title << endl;
				oFile << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
				oFile << "Year: " << setw(12) << perPtr->year << "Rating: " <<perPtr->rating << endl;
				oFile << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
				oFile << setw(18) << "Leading Actor: " << setw(30) << perPtr->leadActor << "Genre 1: " << perPtr->genre << endl;
				oFile << setw(16) << "Supporting Actor: " << setw(30) << perPtr->leadActor << "Genre 2: " << perPtr->alternativeGenre << endl;
				oFile << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
				oFile << "PLOT: " << endl;
				oFile << WordWrapping(perPtr->synopis) << endl;
				oFile << setfill('*') << setw(75) << "*" << setfill(' ') << "\n\n\n\n";
				// END OF CODE


			} else {
				cout << "Sorry, the movie \"" << searchString << "\" was not found.\n\n";
			}

			// Reset the head back to the original value.
			perPtr = head;

			break;

		case GenreSearch:

			// Ask the user which genre they would like to search for.
			cout << "\nWhich genre are you looking for? ";
			getline(cin, searchString);

			cout << "\nSearching for the genre " << searchString << endl;

			// Output heading to file for genre searches being performed.
			oFile << "Search by genre for " << searchString << " found: ";
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
				cout << "Sorry, no movies for the genre, " << searchString << " were found.\n\n";
				oFile << "NOTHING WAS FOUND DURING THE SEARCH.\n\n\n\n";
			} else {
				cout << "Found " << counter << " movies for the genre " << searchString << "!\n\n";
				oFile << "\n\n\n";
			}

			// Reset counter variable.
			counter = 0;

			// Reset the head back to the original value.
			perPtr = head;

			break;

		case ActorSearch:
			// Code for Actor Searches

			// Ask the user which actor they would like to search for.
			cout << "\nWhich actor are you looking for? ";
			getline(cin, searchString);

			cout << "\nSearching for the actor " << searchString << endl;

			// Output heading to file for actor searches being performed.
			oFile << "Search by actor for " << searchString << " found: ";
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

				if (searchString == perPtr->leadActor || searchString == perPtr->supportingActor){

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

			// Check how many instances of the searched actor were found.
			if (counter == 0) {
				cout << "Sorry, no movies for the actor, " << searchString << " were found.\n\n";
				oFile << "NOTHING WAS FOUND DURING THE SEARCH.\n\n\n\n";
			} else {
				cout << "Found " << counter << " movies for the actor " << searchString << "!\n\n";
				oFile << "\n\n\n";
			}

			// Reset counter variable.
			counter = 0;

			// Reset the head back to the original value.
			perPtr = head;

			break;
		case YearSearch:
			// Code for Year Searches

			do {
				// Ask the user which year they would like to search for.
				cout << "\nWhich year are you looking for? ";
				getline(cin, searchString);

				// Check if input is a valid number.
				isValidNumber = ValidateNumber(searchString);

				if(!isValidNumber) {
					cout << "\n**** Please input a NUMBER between 1878 and 3000 *****\n";
				} else {
					searchInteger = atoi(searchString.c_str());
				}

				// Output a message if not within desired range.
				if((searchInteger < 1878 || searchInteger > 3000) && isValidNumber) {
					cout << "\n**** The number " << searchInteger << " is an invalid entry            *****";
					cout << "\n**** Please input a number between 1878 and 3000 *****\n";
				}

			} while(searchInteger < 1878 || searchInteger > 3000 || !isValidNumber);

			cout << "\nSearching for the year " << searchInteger << endl;

			// Output heading to file for year searches being performed.
			oFile << "Search by year for " << searchInteger << " found: ";
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

				if (searchInteger == perPtr->year){

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

			// Check how many instances of the searched year was found.
			if (counter == 0) {
				cout << "Sorry, no movies for the year, " << searchInteger << " were found.\n\n";
				oFile << "NOTHING WAS FOUND DURING THE SEARCH.\n\n\n\n";
			} else {
				cout << "Found " << counter << " movies for the year " << searchInteger << "!\n\n";
				oFile << "\n\n\n";
			}

			// Reset counter variable.
			counter = 0;

			// Reset the head back to the original value.
			perPtr = head;

			break;
		case RatingSearch:
			// Code for Rating Searches

			do {
				// Ask the user which rating they would like to search for.
				cout << "\nWhich rating are you looking for? ";
				getline(cin, searchString);

				// Check if input is a valid number.
				isValidNumber = ValidateNumber(searchString);

				if(!isValidNumber) {
					cout << "\n**** Please input a NUMBER between 0 and 9 *****\n";
				} else {
					searchInteger = atoi(searchString.c_str());
				}

				// Output a message if not within desired range.
				if((searchInteger < 0 || searchInteger > 9) && isValidNumber) {
					cout << "\n**** The number " << searchInteger << " is an invalid entry            *****";
					cout << "\n**** Please input a number between 0 and 9 *****\n";
				}

			} while(searchInteger < 0 || searchInteger > 9 || !isValidNumber);

			cout << "\nSearching for the rating " << searchInteger << endl;

			// Output heading to file for rating searches being performed.
			oFile << "Search by rating for " << searchInteger << " found: ";
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

				if (searchInteger == perPtr->rating){

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

			// Check how many instances of the searched rating was found.
			if (counter == 0) {
				cout << "Sorry, no movies for the rating, " << searchInteger << " were found.\n\n";
				oFile << "NOTHING WAS FOUND DURING THE SEARCH.\n\n\n\n";
			} else {
				cout << "Found " << counter << " movies for the rating " << searchInteger << "!\n\n";
				oFile << "\n\n\n";
			}

			// Reset counter variable.
			counter = 0;

			// Reset the head back to the original value.
			perPtr = head;

			break;
		default:
			// Error Checking!
			cout << "\nSomething went wrong in switch statement!!!";
			break;

	}

}


