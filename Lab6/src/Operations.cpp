/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #6         : Structs
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/06/21 @ 11:59PM
 *************************************************************************/

#include "Functions.h"

/*****************************************************************************************
 * This function reads the file names from the user and stores them in inputFileName and
 * outputFileName variables being passed by reference from the main program.
 *****************************************************************************************/
void readFileNames(string &inputFileName, string &outputFileName) {
	cout << setw(40) << left << "What input file would you like to use?";
	getline(cin, inputFileName);

	cout << setw(41) << left << "\nWhat output file would you like to use?";
	getline(cin, outputFileName);
}

/*****************************************************************************************
 * This function will get all the data from the input file and store the values using an
 * array of structs. Each person will have their own struct in the array of structs and
 * will be used by the main program for other functionality. All the data will be gathered
 * from the input file and displayed to the output file.
 *****************************************************************************************/
void getDataFromInputFile(PersonsInformation Person[], const int MAX_VALUES, string inputFileName, string outputFileName) {

	string fullName;
	int ID;
	float balance;

	ifstream inFile;
	inFile.open(inputFileName);

	if (inFile.is_open()) {
		for (int i = 0; i < MAX_VALUES; i++) {
			getline(inFile, fullName);
			Person[i].personsFullName = fullName;

			inFile >> ID;
			Person[i].personsID = ID;

			inFile >> balance;
			Person[i].personsBalance = balance;

			inFile.ignore(10000, '\n');

		}
	}

    inFile.close();

	ofstream oFile;
	oFile.open(outputFileName, ios::app);
	oFile << left;
	oFile << "" << setw(10) << "ID # " << "" << setw(30) << "Name " << "" << setw(40) << "BALANCE DUE" << endl;
	oFile << "" << setw(10) << "-----" << "" << setw(30) << "--------------------" << "" << setw(30) << "-----------" << endl;

    // Write the list of all data entries from the input file to the output file now.
	for (int i = 0; i < MAX_VALUES; i++) {
	    oFile << left << setw(10) << Person[i].personsID
			  << setw(30) << Person[i].personsFullName << "$" << setw(10)
			  << right << setprecision(2) << fixed << Person[i].personsBalance << '\n' << '\n';
	}
    oFile << "\n\n\n";
    oFile.close();
}

/*****************************************************************************************
 * This function will search through the array of structs and compare to see whether the
 * current value is greater than the value before and reassigning if so. The proper index
 * of where the largest balance was found is returned as well.
 *****************************************************************************************/
int findLargestBalance(const PersonsInformation Person[], const int MAX_VALUES) {

	// Variables to be used by sub program.
	float balanceAmount = 0;
	int indexOfBalance = 0;

	//Execute finding the largest balance.
	balanceAmount = Person[0].personsBalance;
	for (int i = 0; i < MAX_VALUES; i++) {
		if (Person[i].personsBalance > balanceAmount) {
			balanceAmount = Person[i].personsBalance;
			indexOfBalance = i;
		}
	}

	// Return index where largest balance was found.
	return indexOfBalance;
}

/*****************************************************************************************
 * This function will loop the the array of structs, adding up all the balances and storing
 * them into a float that will be returned after all the values have been summed up.
 *****************************************************************************************/
float findSumOfBalances(const PersonsInformation Person[], const int MAX_VALUES) {

	//Temporary variable used by this sub program.
	float amount = 0;


	//Execute finding the sum of all balances...
	for (int i = 0; i < MAX_VALUES; i++) {
		amount += Person[i].personsBalance;
	}

	// Return Sum Amount.
	return amount;
}


/*****************************************************************************************
 * This function will perform a sequential search looking through all the person names
 * stored in the array of structs and comparing them to the users input value to search for,
 * if the users input value is found, the proper index will be returned. Otherwise, the
 * array's max value size will returned letting us know that all values have been ran through
 * and nothing was found.
 *****************************************************************************************/
int searchForPerson(const PersonsInformation Person[], const int MAX_VALUES, string& searchedFor) {

	// LCV - Loop Control Variables used by sub program.
	int index = 0;
	bool found = false;

	// Loop goes through the array until a name is found.
	while (index < MAX_VALUES && !found) {
		if (Person[index].personsFullName == searchedFor) {
			found = true;
		} else {
			index++;
		}

	}
	// Return index found.
	return index;
}

