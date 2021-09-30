/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #2  : Multi-Dimensional Array (Tic Tac Toe)
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 10/07/2021 @ 11:59PM
 ******************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int ROW_SIZE = 3;
const int COL_SIZE = 3;

/******************************************************************************
 * OutputInstruct
 *     This function outputs instructions to the users.  There are no input
 *     or output parameters for this function as it only displays text to
 *     the screen.
 *
 * RETURNS: nothing
 * -> Displays the instructions to the user
 ******************************************************************************/
void OutputInstruct();

/*******************************************************************************
 * InitBoard
 *     This function initializes each spot in the board to a space ' '.
 *
 * RETURNS: Board initialized with all spaces
 ******************************************************************************/
void InitBoard(char boardAr[][3], const int ROW_SIZE, const int COL_SIZE);

/*******************************************************************************
* DisplayBoard
*     This function outputs the tic tac toe board including the tokens
*     played in the proper format (as described below).
*
*			 1         2       3
*		   [1][1] | [1][2] | [1][3]
*			      |        |
*	1		      |        |
*			      |        |
*		  --------------------------
*		   [2][1] | [2][2] | [2][3]
*		   		  |        |
*	2		      |        |
*			      |        |
*          --------------------------
*          [3][1] | [3][2] | [3][3]
*		   		  |        |
*	3		      |        |
*			      |        |
*
* RETURNS: nothing
* -> outputs the current state of the board
********************************************************************************/
void DisplayBoard(const char boardAr[][3]); // IN -tic tac toe board

/********************************************************************************
 * GetPlayers
 *     This function prompts the user and gets the input for the players’ names.
 *     playerX will always contain the name of the player that is using the X token.
 *     playerO will always contain the name of the player that is using the O token.
 *
 * RETURNS: the players names through the variables playerX and playerO.
 ********************************************************************************/
void GetPlayers(string& playerX,  //OUT -player X’s name
		        string& playerO); //OUT -player O’x name

// As this was written in class -you need to document this
void GetAndCheckInp(char boardAr[ROW_SIZE][COL_SIZE], char token, string playerX, string playerO);

/******************************************************************************
 * SwitchToken
 *    This function switches the active player.
 *    It takes in a parameter representing the current player's token
 *    as a character value (either an X or an O) and returns the opposite.
 *    For example, if this function receives an X it returns an 0. If it
 *    receives and O it returns and X.
 *
 * RETURNS: the token opposite of the one in which it receives.
 *****************************************************************************/
char SwitchToken(char token);  // IN -current player’s token ('X' or 'O')

/*******************************************************************************
 * CheckWin
 *     This function checks to see if either player has run. Once it is
 *     possible for a win condition to exist, this should run after each a
 *     player makes a play.
 *
 * RETURNS the character value of the player that won or a value that
 *     indicates a tie.
 *******************************************************************************/
char CheckWin(const char boardAr[][3]); // IN -tic tac toe board

/******************************************************************************
 * OutputWinner
 *     This function receives as input a character indicating which player won
 *     or if the game was a tie and outputs an appropriate message. This function
 *     does not return anything as it simply outputs the appropriate message to
 *     the screen.
 *
 * RETURNS: nothing
 * -> Displays the winner’s name
 ******************************************************************************/
void OutputWinner(char whoWon,     // IN  -represents the winner or a value
		                           //     indicating a tied game.
		          string playerX,  //OUT -player X’s name
				  string playerO); //OUT -player O’x name

#endif /* FUNCTIONS_H_ */


