/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #5  : DVD Movie List - Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/15/2021 @ 11:59PM
 ******************************************************************************/

#include "StackList.h"
#include "MovieList.h"

/**************************************************************************
 * Movie List constructor method doesn't have a purpose for this
 * assignment. Currently left for template purposes.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
MovieList::MovieList(){

}


/**************************************************************************
 * Movie List destructor method doesn't have a purpose for this
 * assignment. Currently left for template purposes.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
MovieList::~MovieList(){

}


/**************************************************************************
 * Movie List class mutator method will create a linked list with the
 * input file being passed as a parameter. A method from the Stack List
 * class will help push the item to the front of the list.
 *
 * 1 Argument passed by value -> RETURNS: Nothing
 *************************************************************************/
void MovieList::CreateList(string inputFileName){

	DVDNode dvd;                // DVD Node created and assigned input file variables to be stored.
	ifstream inFile;            // Variable used to interact with the input file.
	inFile.open(inputFileName);

	if (inFile.is_open()) {
		while (inFile) {
			getline(inFile, dvd.title);
			getline(inFile, dvd.leadActor);
			getline(inFile, dvd.supportingActor);
			getline(inFile, dvd.genre);
			getline(inFile, dvd.alternativeGenre);

			inFile >> dvd.year;
			inFile >> dvd.rating;

			inFile.ignore(10000, '\n');

			getline(inFile, dvd.synopis);

			inFile.ignore(10000, '\n');

			// Call Stack List class method to push item to linked list.
			Push(dvd);
		}
	}
}


/**************************************************************************
 * Movie List class mutator method will output all twenty of the linked
 * list items to the output file name being passed as a parameter. The list
 * will continually be popped from until the head is equal to NULL, meaning
 * the end has been reached.
 *
 * 1 Argument passed by value -> RETURNS: Nothing
 *************************************************************************/
void MovieList::OutputList(string outputFileName){

	DVDNode poppedDVD;     // DVD Node created to assign popped node values for returning.

	ofstream oFile;
	oFile.open(outputFileName, ios::app);

	PrintHeader(oFile);

	while (head != NULL){

		// Call Stack List class method to pop a linked list item from the front.
		poppedDVD = Pop();

		oFile << left;
		oFile << setfill('*') << setw(75) << "*" << setfill(' ') << endl;
		oFile << "Movie #: " << setw(9) << 20-Size() << "Title: " << TruncatedTitle(poppedDVD.title) << endl;
		oFile << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
		oFile << "Year: " << setw(12) << poppedDVD.year << "Rating: " << poppedDVD.rating << endl;
		oFile << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
		oFile << setw(18) << "Leading Actor: " << setw(30) << poppedDVD.leadActor << "Genre 1: " << poppedDVD.genre << endl;
		oFile << setw(16) << "Supporting Actor: " << setw(30) << poppedDVD.leadActor << "Genre 2: " << poppedDVD.alternativeGenre << endl;
		oFile << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
		oFile << "PLOT: " << endl;
		oFile << WordWrap(poppedDVD.synopis) << endl;
		oFile << setfill('*') << setw(75) << "*" << setfill(' ') << "\n\n\n\n";
	}
}


/**************************************************************************
 * Movie List class method for ensuring that the synopsis doesn't over run
 * the length to stay within. The synopsis will be passed as a parameter
 * and the properly wrapped string will be returned.
 *
 * 1 Argument passed by value -> RETURNS: String
 *************************************************************************/
string MovieList::WordWrap(string synopsis) const{

	const int MAX_CHARACTERS_PER_LINE = 75;  // Max characters per line of synopsis.

	ostringstream newString;                 // Variable used to append wrapped synopsis strings to.
	string word = "";                        // CALC - Used to hold word characters.
	string line = "";                        // CALC - Used to hold line characters.

	for(int i = 0; i < synopsis.length(); i++){
		if(synopsis[i] != ' '){
			word = word + synopsis[i];
		} else {
			if(line.length() + word.length() > MAX_CHARACTERS_PER_LINE){
				newString << line << endl;
				line = "";
			}
			line = line + word + ' ';
			word = "";
		}
	}
	newString << line;

	if(line.length() + word.length() > MAX_CHARACTERS_PER_LINE){
		newString << endl;
	}

	newString << word;
	return newString.str();
}


/**************************************************************************
 * Movie List class method for checking the titles length and returning an
 * updated title with a few dots to allow the user to know that the title
 * is actually of a longer length.
 *
 * 1 Argument passed by value -> RETURNS: String
 *************************************************************************/
string MovieList::TruncatedTitle(string title) const{
	const int MAX_TITLE_CHARACTERS = 50;   // Max characters allowed in title length.

	if(title.length() > MAX_TITLE_CHARACTERS){
		title = title.substr(0, MAX_TITLE_CHARACTERS - 3) + "...";
	}
	return title;
}


/**************************************************************************
 * Movie List class method for outputting the class header to the output
 * file before displaying all the movies from the linked list.
 *
 * 1 Argument passed by reference -> RETURNS: Nothing
 *************************************************************************/
void MovieList::PrintHeader(ostream &output) const {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int ASSIGNMENT_NUM = 5;
	const char ASSIGNMENT_NAME[50] = "DVD Movie List - Intro to OOP";

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

