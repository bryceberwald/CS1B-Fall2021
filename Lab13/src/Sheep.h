/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #13	      : Array of Sheep - OOP
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
 *
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
		*
		*******************************************************/
		void SetInitialValues(string sheepName, int sheepAge);


		/******************************************************
		*****************     ACCESSORS    ********************
		*******************************************************/


		/******************************************************
		*
		*******************************************************/
		void GetValues(string &sheepName, int &sheepAge) const;

		/******************************************************
		*
		*******************************************************/
		string GetName() const;

    private:
		string name;
		int age;
};


#endif /* SHEEP_H_ */
