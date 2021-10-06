/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #6         : Structs
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/06/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/****************************************************************************************
* This function can print to either the console or the output file using ostream type
* with the specified variable being passed by reference.
*****************************************************************************************/
void printHeader(ostream &output) {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int LAB_NUM = 6;
	const char LAB_NAME[10] = "Structs";

	// Output the program header to output specified.
	output << left;
	output << "*******************************************************";
	output << "\n* PROGRAMMED BY : " << PROGRAMMER;
	output << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	output << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	output << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	output << "\n*******************************************************" << endl;
	output << right << endl;
}

/*****************************************************************************************
 * This function will print the record heading to the output file as needed.
 *****************************************************************************************/
void printRecordHeadingToFile(string outputFileName) {

	ofstream oFile;
	oFile.open(outputFileName, ios::app);

	oFile << left;
	oFile << "" << setw(10) << "ID # " << "" << setw(30) << "Name " << "" << setw(40) << "BALANCE DUE" << endl;
	oFile << "" << setw(10) << "-----" << "" << setw(30) << "--------------------" << "" << setw(30) << "-----------" << endl;

	oFile.close();

}




