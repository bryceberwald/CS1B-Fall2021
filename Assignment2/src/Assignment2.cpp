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
 * This program will allow the user to play a game of tic-tac-toe. The User will be
 * displayed a menu of options for selection. One of the options will allow the user to
 * change player names from their default values of 'Player X' and 'Player O'. The following
 * two options will allow the user to choose whether they want to play in two or one player
 * mode. The last menu option will allow the user to terminate the program with a '0' input
 * entry. The Player who wins will be displayed to the console as needed.
 *
 * ________________________________________________________________________________________
 *
 * INPUT:
 *   boardAr[]        - User selection determines values in this multi-dimensional array.
 *   playerX          - User can input a value for this variable, changing it's default value.
 *   playerO          - User can input a value for this variable, changing it's default value.
 *   token            - One player mode allows the user to choose which player they want to use.
 *   menuOptionChosen - User selects a menu option from the preset list displayed to the console.
 *
 *
 * OUTPUT:
 *   boardAr[]  - Array is used for outputting the game board to the console as need.
 *   playerX    - String is used for displaying player's name/default value as needed.
 *   playerO    - String is used for displaying player's name/default value as needed.
 *   token      - Char is displayed to the game board as needed.
 *
 *
 ******************************************************************************************/

int main() {

	char boardAr[ROW_SIZE][COL_SIZE];      // INP/OUT - Multi-Dimensional Array for the tic-tac-toe board.
	string playerX = "Player X";           // INP/OUT - Input to reset the default value & displayed as needed.
	string playerO = "Player O";           // INP/OUT - Input to reset the default value & displayed as needed.
	char token = 'X';                      // INP/OUT - Player Token Value is set to initial value of X.

	char playerChosen = 'X';               // INPUT - Used to determine which player for one player mode is playing.
	int menuOptionChosen = 7;              // INPUT - Get from the user, setting initial value out of bounds.

	bool inSession = false;                // LCV   - Used to control the game loop.
	bool playerValid = false;              // LCV   - Used to check input of player chosen for one player mode.

	char checkWin = 'N';                   // CALC  - Returned Char that's used for calculations of a win or not.

	// Generate Random Seed.
	srand(time(NULL));

	//Function prints the class header to the console.
	PrintClassHeader();

	// Function outputs instructions for the user.
	OutputInstruct();

	// Loop controls main program.
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
			// Exits the program...
			cout << "\nTerminating now!!!" << endl;
			break;
		case 1:
			// Function returns the player names by reference.
			GetPlayers(playerX, playerO);
			break;
		case 2:
			// Code for Two Player Mode

			//Initialize the game board.
			InitBoard(boardAr);

			// Display the game board to the console.
			DisplayBoard(boardAr);

			inSession = true;
			// Loop until game is finished.
			while (inSession) {

				// Get & Check Input
				GetAndCheckInp(boardAr, token, playerX, playerO);

				// Redisplay Game Board
				DisplayBoard(boardAr);

				// Switch Player Token
				token = SwitchToken(token);

				// Check For a Win.
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
			// Output the winner to the console.
			OutputWinner(checkWin, playerX, playerO);

			// Reset Variables.
			checkWin = 'N';
			token = 'X';
			break;
		case 3:
			//Code for One Player Mode

			// Input check for player specified to play one player game.
			do {

				// Ask the user which player they would like to be.
				cout << "\nTo play as " << playerX << " type 'X' or to play as " << playerO << " type 'O': ";
				cin >> playerChosen;

				// Reassign the input variable to the upper case version of itself.
				playerChosen = toupper(playerChosen);

				if (playerChosen == 'X' || playerChosen == 'O') {
					playerValid = true;
				} else {
					cout << "Please Choose a Valid Option.\n";
					playerValid = false;
				}

			} while (!playerValid);

			// Initialize game board.
			InitBoard(boardAr);

			// Display game board to the console.
			DisplayBoard(boardAr);

			// Determine the player's token and assign it to the variable 'token'.
			if (playerChosen == 'X') {
				token = 'X';
			} else if (playerChosen == 'O') {
				token = 'O';
			}

			inSession = true;

			// Loop until the game is finished.
			while (inSession) {

				// Get & Check Input.
				GetAndCheckInp(boardAr, token, playerX, playerO);

				// Redisplay Game Board.
				DisplayBoard(boardAr);

				// Check to see if there's a winner.
				checkWin = CheckWin(boardAr);
				if(checkWin == 'X') {
					inSession = false;
				} else if (checkWin == 'O') {
					inSession = false;
				} else if (checkWin == 'T') {
					inSession = false;
				} else if (checkWin == 'N') {
					inSession = true;

					// Algorithm for an attack against the user.
					token = SwitchToken(token);   // Switches token for the computer
					bool isRandomPositionAvailable = false;

					// Loop while random position generated is already taken or not in bounds.
					while (!isRandomPositionAvailable) {

						// Generate Random Row Value
						int randRow = rand() % 3;

						// Generate Random Column Value
						int randColumn = rand() % 3;

						// Determine if position is empty or not.
						if (boardAr[randRow][randColumn] == ' ') {
							boardAr[randRow][randColumn] = token;
							isRandomPositionAvailable = true;
						}
					}

					// Switches token back for the user.
					token = SwitchToken(token);

					// Redisplay board after computer's move.
					DisplayBoard(boardAr);

				}

				// Check to see if there's a winner.
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

			// Output who the winner is.
			if (checkWin == token) {
				cout << "\nCongratulations! You have beat the computer!\n";
			} else if (checkWin == 'T') {
				cout << "\nThere was a tie. Better luck next time!\n";
			} else if (checkWin == 'N') {
				cout << "";
			} else {
				cout << "\nThe computer won. Better luck next time!\n";
			}

			// Reset variables
			playerValid = false;
			checkWin = 'N';
			token = 'X';

			break;
		default:
			cout << "\nERROR WHILE SELECTING MENU OPTIONS.";
			break;

		}
	}

	return 0;
}
