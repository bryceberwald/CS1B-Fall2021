/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #6         : Structs
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/06/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/**************************************************************************
 *
 * Lab #6 : Structs
 *
 * ________________________________________________________________________
 *
 * This program is designed to practice the learned concept of how to use
 * structs instead of parallel arrays. Similar to Assignment #1, this program
 * will ask the user to enter an input and output file name. The data from
 * the input file will be stored into the array of structs respectfully.
 * The program will calculate the largest balance, the sum of all balances,
 * and allow the user to search for a person until the keyword "done" is
 * typed.
 * ________________________________________________________________________
 *
 *
 * INPUT:
 *    inputFileName  - User inputs the file name needed.
 *    outputFileName - User inputs the file name specified.
 *
 *
 *
 * OUTPUT:
 *    *** All output is being done via output file ***
 *
 *    Person[] - Content from the array of structs is being displayed as
 *    needed to the output file specified.
 *
 *
 **************************************************************************/

int main() {

	string inputFileName;                  // INPUT - User determines variable value for input file.
	string outputFileName;                 // INPUT - User determines variable value for output file.
	string searchedFor;                    // INPUT - User determines who why would like to search for.

	const int MAX_VALUES = 10;             // CONST - used to set array lengths and know size.

	int largestBalanceReturnedIndex;       // CALC - Variable assigned to calling functions return value. (Larger balance)
	float sumOfBalancesreturned;           // CALC - Variable assigned to calling functions return value. (Sum of balances)
	int foundPersonIndex;                  // CALC - Variable assigns index of person found, or not found.
	float totalFoundPersonsBalance = 0;    // CALC/OUTPUT - Calculated and printed to output file.

	//Function prints header to the console.
	printHeader(cout);

	//Function reads file names from the user.
	readFileNames(inputFileName, outputFileName);

	// Initialize the output file variable.
	ofstream oFile;

	// Open the output file.
	oFile.open(outputFileName, ios::app);

	//Function prints header to the output file.
	printHeader(oFile);

	// Create an array of structs.
	PersonsInformation Person[MAX_VALUES];

	// Function retrieves all the data from the input file and stores into struct created.
	getDataFromInputFile(Person, MAX_VALUES, inputFileName, outputFileName);

	// Check to see if file is open.
	if(oFile.is_open()) {
		// Call Function to find largest value and store into variable.
		largestBalanceReturnedIndex = findLargestBalance(Person, MAX_VALUES);
		oFile << left;
		oFile << "\nThe largest balance is: " << endl;
		printRecordHeadingToFile(outputFileName);
	    oFile << left << setw(10)
	    		<< Person[largestBalanceReturnedIndex].personsID << setw(29) << Person[largestBalanceReturnedIndex].personsFullName
				<< " " << setw(4) << "$" << right << setprecision(2)
				<< fixed << Person[largestBalanceReturnedIndex].personsBalance << '\n' << '\n';
	}

	// Close output file.
	oFile.close();

	// Reopen output file.
	oFile.open(outputFileName, ios::app);

	// Check to see if file is open.
	if(oFile.is_open()) {
		// Call Function to find sum of all balances and store the returned sum into variable.
		sumOfBalancesreturned = findSumOfBalances(Person, MAX_VALUES);
		oFile << left;
		oFile << "\nThe sum of all persons balances: " << endl;
		oFile << setw(5) << "$" << right << sumOfBalancesreturned << "\n\n";
	}

	// Close File.
	oFile.close();

	// Reopen File with appending to it.
	oFile.open(outputFileName, ios::app);

	// Ask user input search question before the loop.
    cout << "\nWho do you want to search for (enter done to exit): ";
    getline(cin, searchedFor);

    // Print to output file - Search persons header
	oFile << "\nSearch Names: " << endl;
	printRecordHeadingToFile(outputFileName);

    // Loop until keyword 'done' is typed by the user.
    while (searchedFor != "done") {

    	// Call function to find person and store the returned index into this variable.
    	foundPersonIndex = searchForPerson(Person, MAX_VALUES, searchedFor);

    	if (foundPersonIndex < MAX_VALUES) {
    		cout << "Person Found." << endl;
    		if(oFile.is_open()) {
    			oFile << left;
    			oFile << left << setw(10) << Person[foundPersonIndex].personsID
    				<< setw(30) << Person[foundPersonIndex].personsFullName << "$" << setw(10)
    				<< right << setprecision(2) << fixed << Person[foundPersonIndex].personsBalance << '\n' << '\n';
    		}
    	} else {
    		cout << "Person was not found." << endl;
    	}

    	// Totaling for all persons found balances.
    	totalFoundPersonsBalance += Person[foundPersonIndex].personsBalance;

    	// Ask user input search question before re entering the loop.
        cout << "\nWho do you want to search for (enter done to exit): ";
        getline(cin, searchedFor);
    }

    // Print total balance of found persons to the output file.
    oFile << right << setw(42) << "Total Balance Due: $ " << setw(9)<< totalFoundPersonsBalance;
    oFile.close();

    // Termination Message.
    cout << "\nThank you for using my program!";

	return 0;
}
