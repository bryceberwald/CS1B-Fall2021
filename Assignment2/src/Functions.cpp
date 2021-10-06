/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #2  : Multi-Dimensional Array (Tic Tac Toe)
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/07/2021 @ 11:59PM
 ******************************************************************************/

#include "Functions.h"

void PrintClassHeader() {

	// Declared variables for the program header to be used by this function.
	const char PROGRAMMER[20] = "Bryce Berwald";
	const char CLASS[5] = "CS1B";
	const char SECTION[25] = "MW: 7:30PM-10:00PM";
	const int ASSIGNMENT_NUM = 2;
	const char ASSIGNMENT_NAME[30] = "Tic Tac Toe Game";

	// Output the program header to output specified.
	cout << left;
	cout << "*******************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* ASSIGNMENT #" << setw(2) << ASSIGNMENT_NUM << ": " << ASSIGNMENT_NAME;
	cout << "\n*******************************************************" << endl;
	cout << right << endl;

}

/******************************************************************************
 * This function will display instructions for the user on how to use the
 * program. How to make a menu option selection is explained, as well as some
 * functionality aspects that will make the user's gaming experience more at
 * ease.
 ******************************************************************************/
void OutputInstruct() {

	cout << "\nInstructions for the user:";
	cout << "\n------------------------------------------";
	cout << "\nTo change the default player names, select the first menu option below by typing\n";
	cout << "the number 1 for that menu option to be selected. By default player X will be used\n";
	cout << "as the first player to make a move in two player mode. To play in two player mode\n";
	cout << "you can type the number 2 like shown in the menu options. Finally, to play in one\n";
	cout << "player mode type 3 like shown in the menu options. One player mode will ask you to\n";
	cout << "specify which player you'd like to use. The options available are either X or O. To\n";
	cout << "change the player names, navigate to the setting player names menu option like stated\n";
	cout << "before by typing 1 as the menu option. Don't want to play or tired of playing? Type\n";
	cout << "0 and the tic-tac-toe program will be terminated. GOOD LUCK!!!" << endl;
}


/*******************************************************************************
 * This function will initialize every position on the game board to a blank
 * space using two for loops.
 ******************************************************************************/
void InitBoard(char boardAr[][3]) {

	int i;
	int k;

	for (i = 0; i < ROW_SIZE; i++) {
		for (k = 0; k < COL_SIZE; k++) {
			boardAr[i][k] = ' ';
		}
	}
}


/********************************************************************************
* This function will ask the user for the names of Player X and Player O. These
* variables are being passed by reference to this function, so the values will
* be stored in the main program.
********************************************************************************/
void GetPlayers(string& playerX, string& playerO) {

	// Who will be player X?
	cout << "\nWhat's the name of Player X? ";
	getline(cin, playerX);

	// Who will be player O?
	cout << "\nWhat's the name of Player O? ";
	getline(cin, playerO);
}


/******************************************************************************
* This function has been provided to display the game board to the console.
* This function will display a 3 by 3 tic-tac-toe board with each position
* also displaying the coordinates of that position. This function also has the
* multi-dimensional array contents stored within, with an initial value of
* a blank space.
******************************************************************************/
void DisplayBoard(const char boardAr[][3])
{
	int i;
	int j;
	cout << "\n";
	cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";
	for (i = 0; i < 3; i++)
	{
		cout << setw(7) << "[" << i+1 << "][1] | " << "[" << i+1;
		cout << "][2] | " << "[" << i+1 << "][3]" << endl;
		cout << setw(14) << "|" << setw(9) << "|" << endl;

		for (j = 0; j < 3; j++)
		{
			switch(j)
			{
				case 0: cout << i + 1 << setw(9) << boardAr[i][j];
	 					cout << setw(4) << "|";
	 					break;
				case 1: cout << setw(4) << boardAr[i][j];
				 		cout << setw(5) << "|";
				 		break;
				case 2: cout << setw(4) << boardAr[i][j] << endl;
						break;
				default: cout <<"ERROR!\n\n";
			}
		}

		cout << setw(14)<< "|" << setw(10) << "|\n";

		if (i != 2)
		{
			cout << setw(32) << "--------------------------\n";
		}
	}
}


/******************************************************************************
* This function will ask the user where they would like to make their next
* move. After the users input, an input check will be performed. Firstly,
* a check will be done to make sure the position chosen is within range. If
* the values picked by the user are within range, a check will be done to
* ensure that spot hasn't already been taken. If the values selected are within
* range and the position chosen is open, then the user's token will be placed
* in the multi-dimensional array. Otherwise the user will bhe prompted to
* re-do their input.
******************************************************************************/
void GetAndCheckInp(char boardAr[][3], char token, string playerX, string playerO) {

	int rowSelected;     // INPUT - User's input row value
	int colSelected;     // INPUT - User's input column value
	bool valid = false;  // LCV   - Determines if user's input is available and in bounds.

	do {

		// Player X's turn executed here.
		if (token == 'X') {

			// Get input from the user.
			cout << "\n" << playerX << "'s turn! What's your play? ";
			cin >> rowSelected >> colSelected;

			// Check for input values being in bounds of the array.
			if (rowSelected < 1 || rowSelected > 3 || colSelected < 1 || colSelected > 3) {

				// Display correction message.
				cout << "Please make sure your row and column values are between 1 & 3.\n";
				valid = false;

			} else {

				// Check if input values are available for selection.
				if(boardAr[rowSelected-1][colSelected-1] == ' ') {

					// Empty spot gets assigned to player X.
					boardAr[rowSelected-1][colSelected-1] = 'X';
					valid = true;

				} else if (boardAr[rowSelected-1][colSelected-1] == 'X' || boardAr[rowSelected-1][colSelected-1] == 'O'){

					// Display correction message.
					cout << "Please choose an option that hasn't already been taken.\n";
					valid = false;
				}

			}

		// Player O's turn executed here.
		} else if (token == 'O') {

			// Get input from the user.
			cout << "\n" << playerO << "'s turn! What's your play? ";
			cin >> rowSelected >> colSelected;

			// Check for input values being in bounds of the array.
			if (rowSelected < 1 || rowSelected > 3 || colSelected < 1 || colSelected > 3) {

				// Display correction message
				cout << "Please make sure your row and column values are between 1 & 3.\n";
				valid = false;

			} else {

				// Check if input values are available for selection.
				if(boardAr[rowSelected-1][colSelected-1] == ' ') {

					// Empty spot gets assigned to player O.
					boardAr[rowSelected-1][colSelected-1] = 'O';
					valid = true;

				} else if (boardAr[rowSelected-1][colSelected-1] == 'X' || boardAr[rowSelected-1][colSelected-1] == 'O'){

					// Display correction message.
					cout << "Please choose an option that hasn't already been taken.\n";
					valid = false;
				}

			}

		}


	} while(!valid);

}


/******************************************************************************
* This function will take in the current token as a parameter and return the
* opposite token to the main program.
******************************************************************************/
char SwitchToken(char token) {

	char returnedToken = ' ';

	if (token == 'X') {
		returnedToken = 'O';
	} else if (token == 'O') {
		returnedToken = 'X';
	}

	return returnedToken;
}


/******************************************************************************
* This function will check whether a player has won the game or not. The
* function will check all columns and all rows to see if there is three values
* in a row. Also, this function will check for diagonal three in a rows as well.
* If no player has three in a row and all spots are taken, a check for a tie
* will be done as well to ensure everything is okay. The appropriate char will
* be returned too.
******************************************************************************/
char CheckWin(const char boardAr[][3]) {

	// Variables used by sub program.
	int boardCounter = 0;
	char returnedChar = 'N';

	// Check if columns have three in a row.
	for (int i = 0; i < COL_SIZE; i++) {

		if(boardAr[0][i] == 'X' && boardAr[1][i] == 'X' && boardAr[2][i] == 'X') {
			returnedChar = 'X';
		}

		if (boardAr[0][i] == 'O' && boardAr[1][i] == 'O' && boardAr[2][i] == 'O') {
			returnedChar = 'O';
		}
	}

	// Check if rows have three in a row.
	for (int i = 0; i < ROW_SIZE; i++) {

		if(boardAr[i][0] == 'X' && boardAr[i][1] == 'X' && boardAr[i][2] == 'X') {
			returnedChar = 'X';
		}

		if (boardAr[i][0] == 'O' && boardAr[i][1] == 'O' && boardAr[i][2] == 'O') {
			returnedChar = 'O';
		}
	}

	// Check for diagonal three in a row.
	if (boardAr[0][0] == 'X' && boardAr[1][1] == 'X' && boardAr[2][2] == 'X') {
		returnedChar = 'X';
	}
	if (boardAr[0][2] == 'X' && boardAr[1][1] == 'X' && boardAr[2][0] == 'X') {
		returnedChar = 'X';
	}
	if (boardAr[0][0] == 'O' && boardAr[1][1] == 'O' && boardAr[2][2] == 'O') {
		returnedChar = 'O';
	}
	if (boardAr[0][2] == 'O' && boardAr[1][1] == 'O' && boardAr[2][0] == 'O') {
		returnedChar = 'O';
	}

	// Check if there is a tie
	for (int i = 0; i < ROW_SIZE; i++) {
		for (int k = 0; k < COL_SIZE; k++) {
			if (boardAr[i][k] != ' ') {
				boardCounter++;
			}
		}
	}
	if (boardCounter == 9 && returnedChar == 'N') {
		returnedChar = 'T';
	}

	return returnedChar;
}


/******************************************************************************
* This function will only execute after a player has won the game or a tie has
* occurred. After a resolution to the game is determined, the appropriate
* winner/no winner will be displayed to the console.
******************************************************************************/
void OutputWinner(char whoWon, string playerX, string playerO) {

	switch(whoWon) {
		case 'X':
			cout << "\nCongratulations " << playerX << "! You have just won the game!!!\n";
			break;
		case 'O':
			cout << "\nCongratulations " << playerO << "! You have just won the game!!!\n";
			break;
		case 'T':
			cout << "\nNo Winner! Better luck next time...\n";
			break;
		default:
			cout << "\nError while outputting winner.\n";
			break;
	}

}



