/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #13	      : Array of Sheep - OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/01/21 @ 11:59PM
 *************************************************************************/

#ifndef FARMLIST_H_
#define FARMLIST_H_

#include "Sheep.h"
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used

using namespace std;

// Constant Declarations.
const int AR_SIZE = 50;

/**************************************************************************
 * FarmList Class
 * This is the farm class object. This class will allow us to use the sheep
 * class object to be contained within this class. We will append sheep to
 * a list as needed.
 *************************************************************************/
class FarmList
{
    public:
		/******************************************************
		**********   CONSTRUCTOR && DESTRUCTOR    *************
		*******************************************************/

		/******************************************************
		* FarmList ();
		* Constructor; Initialize farm list attributes
		* Parameters: none
		* Return: none
		*******************************************************/
		FarmList();

		/******************************************************
		* ~FarmList ();                                       *
		* Destructor; Does not perform any specific function  *
		* Parameters: none                                    *
		* Return: none
		*******************************************************/
		~FarmList();


		/******************************************************
		*****************     MUTATORS    *********************
		*******************************************************/


		/******************************************************
		* Function prototype for adding a new sheep the farm
		* list class. This is a mutator method within the public
		* side of the farm list class object.
		*
		* 1 Argument passed by value -> RETURNS: Nothing
		*******************************************************/
		void AddSheep(Sheep newSheep);

		/******************************************************
		* This is the function prototype for clearing the
		* entire list contents.
		*
		* No Arguments -> RETURNS: Nothing
		*******************************************************/
		void ClearList();


		/******************************************************
		*****************     ACCESSORS    ********************
		*******************************************************/


		/******************************************************
		* This is the function prototype for finding a sheep
		* class object by it's name attribute.
		*
		* 1 Argument passed by value -> RETURNS: Nothing
		*******************************************************/
		Sheep FindSheep(string sheepName) const;

		/******************************************************
		* This is the function prototype for getting the first
		* sheep class object in the list created. The sheep
		* object will then be returned.
		*
		* No Arguments -> RETURNS: Sheep
		*******************************************************/
		Sheep GetFirstSheep() const;

		/******************************************************
		* This is the function prototype for getting the total
		* number of sheep which is returned to the calling
		* function.
		*
		* No Arguments -> RETURNS: Integer
		*******************************************************/
		int TotalSheep() const;

		/******************************************************
		* This is the function prototype for displaying all
		* the sheep in the format specified in class.
		*
		* No Arguments -> RETURNS: Nothing
		*******************************************************/
		void DisplaySheepTable() const;

    private:
		Sheep farmArray[AR_SIZE];   // INP/OUT  - Array gets appended to & contents displayed as needed.
		int sheepCount;             // OUT/CALC - Variable gets incremented as sheep objects are added.
};


#endif /* FARMLIST_H_ */
