/*****************************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #1         : Theme Park Day Planner
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 08/30/2021 @ 11:59PM
 *****************************************************************************************/

//Pre-processor directives
#include <string>   // For strings
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
using namespace std;

/******************************************************************************************
 *
 * Lab #1: CS1A Review - Theme Day Park Planner
 *
 *
 * ________________________________________________________________________________________
 *
 * This program will help a user plan for a day at the theme park. It will allow planning
 * for 10 kids and determines what each kid will be getting based on the answers entered by
 * the user. Attractions vary depending on certain circumstances. Prices vary depending
 * on kids preferences.
 *
 * ________________________________________________________________________________________
 *
 *
 * INPUT:
 *    kidsName - Temporarily used to hold current kids name.
 *    kidsAge - Temporarily used to hold current kids age.
 *
 *
 * OUTPUT:
 *    attractions - Displays the current kids attractions based on his/her age.
 *    currentMeal - Displays the current kids meals based on his/her preferences.
 *    totalCost - Calculated throughout the program and displayed at the end.
 *    averageKid - Calculated after the 'for' loop and displayed at the end.
 *
 *
 ******************************************************************************************/

int main() {


	//Declared variables for the program header.
		const char PROGRAMMER[20] = "Bryce Berwald";
		const char CLASS[5] = "CS1B";
		const char SECTION[30] = "MW: 7:30PM-10:00PM";
		const int LAB_NUM = 1;
		const char LAB_NAME[30] = "Theme Park Day Planner";

		//Output the program header with variables earlier established.
		cout << left;
		cout << "*******************************************************";
		cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
		cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
		cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
		cout << "\n* Lab #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
		cout << "\n*******************************************************" << endl;
		cout << right;

		//Constants used by the program.
		const float CHEESEBURGER = 3.50;
		const float HAMBURGER = 3.25;
		const float CHEESE_PIZZA = 2.50;
		const float HAPPY_GARDEN = 1.75;

		//Variables used in the program.
		//char kidsName[30];
		string kidsName;
		int kidsAge;
		string attractions;
		string currentMeal;

		//variables used for calculations.
		float totalCost;
		float averageKid;

		//Temporarily used to determine the Y/N questions.
		char answer;

		//Initialize the totalCost to zero.
		totalCost = 0;

		//Give the user a welcome message.
		cout << "\nWelcome to the Theme Park Day Planner! Please have the names of the"
				" kids who will be attending..." << endl;

		//For loop to control program with 10 kid entries.
		for (int i = 1; i < 11; i++) {

			//Current kid number.
			cout << "\nKid #" << i << endl;

			//Gather the current kids name.
			cout << "What\'s your kid\'s name? ";
			//cin.getline(kidsName, 30);
			cin >> kidsName;
			cin.ignore(10000, '\n');

			//Gather the current kids age.
			cout << "How old is the kid? ";
			cin >> kidsAge;

			//Determine the attraction for each kid based on his/her age.
			if (kidsAge < 5) {
				attractions = "Ferris Wheel/Sheep Petting Zoo";
			} else if (kidsAge >= 5 && kidsAge <= 12) {
				attractions = "Tea Cups/Lazer Tag";
				totalCost += 15;
			} else if (kidsAge > 12) {
				attractions = "Roller Coaster/Zip Line";
				totalCost += 20;
			}

			//Vegetarian - YES or NO?  - Ask the user.
			cout << "Vegetarian? (Y/N) ";
			cin >> answer;

			//VEG - YES
			if (tolower(answer) == 'y') {
				//Likes cheese - YES or NO? - Ask the user.
				cout << "Does he/she like cheese? ";
				cin >> answer;
				//CHEESE - YES
				if(tolower(answer) == 'y') {
					currentMeal = "Cheese Pizza";
					totalCost += CHEESE_PIZZA;
				//CHEESE - NO
				} else if (tolower(answer) == 'n') {
					currentMeal = "Happy Garden";
					totalCost += HAPPY_GARDEN;
				}
			//VEG - NO
			} else if (tolower(answer) == 'n') {
				//Likes cheese - YES or NO? - Ask the user.
				cout << "Does he/she like cheese? ";
				cin >> answer;
				//CHEESE - YES
				if(tolower(answer) == 'y') {
					currentMeal = "Cheese Burger";
					totalCost += CHEESEBURGER;
				//CHEESE - NO
				} else if (tolower(answer) == 'n'){
					currentMeal = "Hamburger";
					totalCost += HAMBURGER;
				}
			}

			//Display the current kids information upon completion. (Each kid entry will get displayed)
			cout << "\n" << kidsName << " will be going to the " << attractions << ". Pack a " << currentMeal << " for "
					<< kidsName << "." << endl;

			//clear the buffer
			cin.ignore(1000, '\n');
		}

		//Calculate the average per kid.
		averageKid = (totalCost / 10);

		//Output final results. (Total Cost & Average Per Kid)
		cout << "\n\n\nThe total cost for the day is: " << setw(10) << fixed << setprecision(2) << "$" << right << setw(6) << totalCost;
		cout << "\nThe average cost per kid is: " << setw(12) << fixed << setprecision(2) << "$" <<  right << setw(6) << averageKid;

	return 0;
}
