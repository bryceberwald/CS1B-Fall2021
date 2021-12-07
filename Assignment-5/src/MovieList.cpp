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
 *
 *************************************************************************/
MovieList::MovieList(){

}


/**************************************************************************
 *
 *************************************************************************/
MovieList::~MovieList(){

}


/**************************************************************************
 *
 *************************************************************************/
void MovieList::CreateList(string inputFileName){

	DVDNode dvd;

	ifstream inFile;
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

			Push(dvd);
		}
	}
}


/**************************************************************************
 *
 *************************************************************************/
void MovieList::OutputList(string outputFileName){

	DVDNode poppedDVD;

	ofstream oFile;
	oFile.open(outputFileName, ios::app);

	PrintHeader(oFile);

	while (head != NULL){
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
 *
 *************************************************************************/
string MovieList::WordWrap(string plot) const{

	const int MAX_CHARACTERS_PER_LINE = 75;

	ostringstream newString;
	string word = "";
	string line = "";

	for(int i = 0; i < plot.length(); i++){
		if(plot[i] != ' '){
			word = word + plot[i];
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
 *
 *************************************************************************/
string MovieList::TruncatedTitle(string title) const{
	const int MAX_TITLE_CHARACTERS = 50;

	if(title.length() > MAX_TITLE_CHARACTERS){
		title = title.substr(0, MAX_TITLE_CHARACTERS - 3) + "...";
	}
	return title;
}


/**************************************************************************
 *
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

