/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #13	      : Linked Lists of Sheep - OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/01/21 @ 11:59PM
 *************************************************************************/

#ifndef SHEEP_H_
#define SHEEP_H_

#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used

using namespace std;

/**************************************************************************
 * Sheep Class
 * This is the class object that will hold the properties containing sheep.
 * Using the constructor, destructor, 1 mutator method, and a couple
 * accessor methods, with 2 private attributes.
 *************************************************************************/
class Sheep
{
    public:
		/******************************************************
		**********   CONSTRUCTOR && DESTRUCTOR    *************
		*******************************************************/

		/******************************************************
		* Sheep ();                                          *
		* Constructor; Initialize sheep attributes           *
		* Parameters: none                                    *
		* Return: none          						      *
		*******************************************************/
		Sheep();

		/******************************************************
		* ~Sheep ();                                         *
		* Destructor; Does not perform any specific function  *
		* Parameters: none                                    *
		* Return: none          						      *
		*******************************************************/
		~Sheep();


		/******************************************************
		*****************     MUTATORS    *********************
		*******************************************************/


		/******************************************************
		* Function prototype for setting the initial values of
		* a sheep object.
		*
		* 2 Arguments passed by value -> RETURNS: Nothing
		*******************************************************/
		void SetInitialValues(string sheepName, int sheepAge);


		/******************************************************
		*****************     ACCESSORS    ********************
		*******************************************************/


		/******************************************************
		* Function prototype for getting the values of a sheep
		* class object and returning the values by reference.
		*
		* 2 Arguments passed by reference -> RETURNS: Nothing
		*******************************************************/
		void GetValues(string &sheepName, int &sheepAge) const;

		/******************************************************
		* Function prototype for getting the private name
		* attribute to be returned as a string to the called
		* function.
		*
		* No Arguments passed -> RETURNS: String
		*******************************************************/
		string GetName() const;

    private:
		string name;  //INP/OUT - User will add a sheep object, & displayed as necessary.
		int age;      //INP/OUT - User will add a sheep object, & displayed as necessary.
};



#endif /* SHEEP_H_ */
