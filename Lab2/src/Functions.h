/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #7         : Functions - Coin Flip
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 09/08/2021 @ 11:59PM
 *****************************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//Pre-processor directives
#include <string>   // For strings
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <stdlib.h> // For srand & rand
#include <time.h>   // For Time
using namespace std;

//Prototypes for functions used in the program.

//This functions prototype is for reading the information in from the user. (name/gender)
void readInformationFromUser(string &name, char &gender);

//This function prototype is for the coin flip.
bool flipTheCoin();

//This function prototype is for calculating the average of heads per total flips.
float calculateAverageHeads(float heads, float totalFlips);

//This function prototype is for displaying the final results after getting 3 heads from the user.
void displayFinalResults(float totalFlips, float averageHeads);


#endif /* FUNCTIONS_H_ */
