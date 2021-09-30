/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #2  : Multi-Dimensional Array (Tic Tac Toe)
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/07/2021 @ 11:59PM
 ******************************************************************************/

#include "Functions.h"

/******************************************************************************
 *
 ******************************************************************************/
void OutputInstruct() {

}


/*******************************************************************************
 * This function will initialize every position on the game board to a blank
 * space using two for loops.
 ******************************************************************************/
void InitBoard(char boardAr[][3], const int ROW_SIZE, const int COL_SIZE) {

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
	cout << "\nWhat's the name of Player X? ";
	getline(cin, playerX);
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
	//cout << endl;
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
void GetAndCheckInp(char boardAr[ROW_SIZE][COL_SIZE], char token, string playerX, string playerO) {

	int rowSelected;
	int colSelected;
	bool valid = false;

	do {

		if (token == 'X') {
			cout << "\n" << playerX << "'s turn! What's your play? ";
			cin >> rowSelected >> colSelected;

			if (rowSelected < 1 || rowSelected > 3 || colSelected < 1 || colSelected > 3) {

				cout << "Please make sure your row and column values are between 1 & 3.\n";
				valid = false;

			} else {

				if(boardAr[rowSelected-1][colSelected-1] == ' ') {
					boardAr[rowSelected-1][colSelected-1] = 'X';
					valid = true;
				} else if (boardAr[rowSelected-1][colSelected-1] == 'X' || boardAr[rowSelected-1][colSelected-1] == 'O'){
					cout << "Please choose an option that hasn't already been taken.\n";
					valid = false;
				}

			}


		} else if (token == 'O') {
			cout << "\n" << playerO << "'s turn! What's your play? ";
			cin >> rowSelected >> colSelected;

			if (rowSelected < 1 || rowSelected > 3 || colSelected < 1 || colSelected > 3) {

				cout << "Please make sure your row and column values are between 1 & 3.\n";
				valid = false;

			} else {

				if(boardAr[rowSelected-1][colSelected-1] == ' ') {
					boardAr[rowSelected-1][colSelected-1] = 'O';
					valid = true;
				} else if (boardAr[rowSelected-1][colSelected-1] == 'X' || boardAr[rowSelected-1][colSelected-1] == 'O'){
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
*
******************************************************************************/
char CheckWin(const char boardAr[][3]) {



}


/******************************************************************************
*
******************************************************************************/
void OutputWinner(char whoWon, string playerX, string playerO) {



}



