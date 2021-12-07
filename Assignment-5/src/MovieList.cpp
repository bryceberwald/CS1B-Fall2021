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

			Stack.Push(dvd);

		}
	}

	// Output size of linked list for testing purposes.
	cout << Stack.Size();

}


/**************************************************************************
 *
 *************************************************************************/
void MovieList::OutputList(string outputFileName){

	DVDNode peekDVD;
	DVDNode poppedDVD;

	for(int i = 0; i < Stack.Size(); i++){
		peekDVD = Stack.Peek();

		cout << peekDVD.title << peekDVD.leadActor << peekDVD.supportingActor << peekDVD.genre << peekDVD.alternativeGenre
		     << peekDVD.year << peekDVD.rating << peekDVD.synopis;

		poppedDVD = Stack.Pop();

	}

}


/**************************************************************************
 *
 *************************************************************************/
string MovieList::WorpWarp(string plot) const{

	// Return a empty string for now...
	return "";
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
