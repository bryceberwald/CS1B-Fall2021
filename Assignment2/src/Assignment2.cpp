/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #2  : Multi-Dimensional Array (Tic Tac Toe)
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/07/2021 @ 11:59PM
 ******************************************************************************/

#include "Functions.h"

/******************************************************************************************
 *
 * Assignment #2: CS1B - Multi-Dimensional Array (Tic Tac Toe)
 *
 *
 * ________________________________________________________________________________________
 *
 *
 * Description goes here...
 *
 * ________________________________________________________________________________________
 *
 * INPUT:
 *
 *
 *
 *
 * OUTPUT:
 *
 *
 *
 *
 ******************************************************************************************/

int main() {


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


	char boardAr[ROW_SIZE][COL_SIZE];

	string playerX = "Player X";
	string playerO = "Player O";
	char playerChosen = 'X';

	int menuOptionChosen = 7;
	bool inSession = false;

	char token = 'X';
	char checkWin = 'N';


	while (menuOptionChosen != 0) {
		//Print menu options to the console for the user.
		cout << "\nMENU OPTIONS" << endl << endl;
		cout << "---------------------------------------" << endl;
		cout << "Type \"1\" to Set Player Names." << endl;
		cout << "Type \"2\" to Play in Two Player Mode." << endl;
		cout << "Type \"3\" to Play in One Player Mode." << endl;
		cout << "Type \"0\" to Exit" << endl;
		cout << "---------------------------------------" << endl;
		cout << "Please enter an option (0 to exit): ";

		cin >> menuOptionChosen;
		cin.ignore(10000, '\n');

		switch(menuOptionChosen) {
		case 0:
			//Exits the program...
			cout << "\nTerminating now!!!" << endl;
			break;
		case 1:
			GetPlayers(playerX, playerO);
			break;
		case 2:
			//Code for Two Player Mode
			InitBoard(boardAr);
			DisplayBoard(boardAr);
			inSession = true;
			while (inSession) {
				GetAndCheckInp(boardAr, token, playerX, playerO);
				DisplayBoard(boardAr);
				token = SwitchToken(token);
				checkWin = CheckWin(boardAr);
				if(checkWin == 'X') {
					inSession = false;
				} else if (checkWin == 'O') {
					inSession = false;
				} else if (checkWin == 'T') {
					inSession = false;
				} else if (checkWin == 'N') {
					inSession = true;
				}
			}
			OutputWinner(checkWin, playerX, playerO);
			checkWin = 'N';
			token = 'X';
			break;
		case 3:
			//Code for One Player Mode
			cout << "\nTo play as " << playerX << " type 'X' or to play as " << playerO << " type 'O': ";
			cin >> playerChosen;
			InitBoard(boardAr);
			DisplayBoard(boardAr);
			if (playerChosen == 'X') {
				token = 'X';
			} else if (playerChosen == 'O') {
				token = 'O';
			}
			inSession = true;
			while (inSession) {
				GetAndCheckInp(boardAr, token, playerX, playerO);
				DisplayBoard(boardAr);
			}

			break;
		default:
			cout << "\nERROR WHILE SELECTING MENU OPTIONS.";
			break;

		}
	}



	return 0;
}
