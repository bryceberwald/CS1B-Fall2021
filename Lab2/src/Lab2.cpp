/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #2         : Functions - Coin Flip
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 09/08/2021 @ 11:59PM
 *****************************************************************************************/

//Pre-processor directives
#include "Functions.h"

/******************************************************************************************
 *
 * Lab #2: Functions - Coin Flip
 *
 *
 * ________________________________________________________________________________________
 *
 * This program uses four different function in conjunction with the main program. One for
 * gathering data from our user to help us determine a personalized greeting message. One
 * function will randomly generate a number thats either 0 or 1 and return true or false
 * depending on the resulting number. The user will continue to flip the coin by pressing
 * enter over and over again until 3 heads in a row has been reached. In conclusion the
 * program will display some final results with another function.
 *
 *
 * ________________________________________________________________________________________
 *
 *
 * INPUT:
 *    playersName - INPUT from the user. Used to greet the player.
 *    playersGender - INPUT from the user. Used to determine a personalized greeting message.
 *
 *
 *
 * OUTPUT:
 *    totalFlips - OUTPUT to the user via console. Results displayed at the end of the program.
 *    averageHeads - OUTPUT to the user via console. Results displayed as a percentage.
 *
 *
 *
 ******************************************************************************************/

int main() {
	//Declared variables for the program header.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[30] = "MW: 7:30-10:00PM";
	const int LAB_NUM = 2;
	const char LAB_NAME[30] = "Functions - Coin Flip";

	//Output the program header with variables earlier established.
	cout << left;
	cout << "*******************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* Lab #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n*******************************************************" << endl;
	cout << right;

	//Variables used by the main program.
	string playersName;          //INPUT - Name used by the program to greet the user.
	char playersGender;          //INPUT - Gender determines personalized greeting message.

	bool isCoinFlipped;          //Used to determine whether flip is heads or tails with boolean logic.
	bool threeHeads;             //LCV - Loop Control Variable

	int totalHeadsConsecutively; //CALC - Used to determine when 3 heads has been achieved.
	float totalHeadsOverall;     //CALC - Counter used to count all resulting heads.

	float totalFlips;            //CALC - Counter used to count all flips. HEADS or TAILS!
	float averageHeads;          //CALC & OUTPUT - The average number of heads per total flips.

	totalHeadsConsecutively = 0;
	totalHeadsOverall = 0;
	totalFlips = 0;

	threeHeads = false;

	//Generate Random Seed.
	srand(time(NULL));

	//Display a welcome message for the user.
	cout << "\nWelcome to the coin tossing game! Get 3 heads in a row to win... \n";

	//Call function to gather information from our user.
	readInformationFromUser(playersName, playersGender);

	//Determine output message based off of their gender specified.
	if (toupper(playersGender) == 'F'){
		cout << "\nTry to get 3 heads in a row! Good Luck Ms. " << playersName << "!\n";
	} else if (toupper(playersGender) == 'M') {
		cout << "\nTry to get 3 heads in a row! Good Luck Mr. " << playersName << "!\n";
	}

	//Clean the buffer.
	cin.ignore(1000, '\n');

	//Loop to control coin flip game.
	while(!threeHeads) {
		//Give user directions.
		cout << "\nPress <ENTER> to flip the coin.";
		//Clean the buffer.
		cin.ignore(1000, '\n');

		//Call coin flip function and assign the boolean to this variable.
		isCoinFlipped = flipTheCoin();

		//Determine if the function returned true or false.
		if (isCoinFlipped) {
			cout << "HEADS!";
			totalHeadsOverall++;
			totalHeadsConsecutively++;
			totalFlips++;
		} else if (!isCoinFlipped) {
			cout << "TAILS!";
			//reset consecutive counter
			totalHeadsConsecutively = 0;
			totalFlips++;
		}

		//Determine three heads eligibility.
		if (totalHeadsConsecutively == 3) {
			threeHeads = true;
		}

	}

	//Call function to calculate the average heads per total flips.
	averageHeads = calculateAverageHeads(totalHeadsOverall, totalFlips);

	//Call function to display final results to the user.
	displayFinalResults(totalFlips, averageHeads);


	return 0;
}
