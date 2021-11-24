/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #12	      : Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/24/21 @ 11:59PM
 *************************************************************************/

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used
#include <ostream>
#include <fstream>

using namespace std;

/**************************************************************************
 * Animal Class
 * 	  This class represents an animal object. This object manages four
 * 	  different attributes (name, type, age, value).
 *************************************************************************/
class Animal
{
    public:
		/******************************************************
		**********   CONSTRUCTOR && DESTRUCTOR    *************
		*******************************************************/

		/******************************************************
		* Animal ();                                          *
		* Constructor; Initialize animal attributes           *
		* Parameters: none                                    *
		* Return: none          						      *
		*******************************************************/
		Animal();

		/******************************************************
		* ~Animal ();                                         *
		* Destructor; Does not perform any specific function  *
		* Parameters: none                                    *
		* Return: none          						      *
		*******************************************************/
		~Animal();


		/******************************************************
		*****************     MUTATORS    *********************
		*******************************************************/


		/******************************************************
		* This is the function prototype for setting the initial
		* animal values of an object instance created with this
		* class.
		*
		* 4 Arguments by reference -> RETURNS: Nothing
		*******************************************************/
		void SetInitialValues(string aName, string aType,
				int aAge, float aValue);

		/******************************************************
		* This is the function prototype for changing the age
		* of an animal object instance created.
		*
		* 1 Argument passed by value -> RETURNS: Nothing
		*******************************************************/
		void ChangeAge(int aAge);

		/******************************************************
		* This is the function prototype for changing the value
		* of an animal object instance created.
		*
		* 1 Argument passed by value -> RETURNS: Nothing
		*******************************************************/
		void ChangeValue(float aValue);


		/******************************************************
		*****************     ACCESSORS    ********************
		*******************************************************/


		/******************************************************
		* This is the function prototype for displaying the
		* animal class object to the console with desired format.
		*
		* No Arguments -> RETURNS: Nothing
		*******************************************************/
		void Display() const;

		/******************************************************
		* This is the function prototype for getting the name
		* of an animal object instance. The name will be returned.
		*
		* No Arguments -> RETURNS: String
		*******************************************************/
		string GetName() const;

		/******************************************************
		* This is the function prototype for getting the type of
		* animal. THe animals type will be returned as a string.
		*
		* No Arguments -> RETURNS: String
		*******************************************************/
		string GetType() const;

		/******************************************************
		* This is the function prototype for getting the age
		* of an animal. The age will be returned as an integer.
		*
		* No Arguments -> RETURN: Integer
		*******************************************************/
		int GetAge() const;

		/******************************************************
		* This is the function prototype for getting the value of
		* an animal class instance. The value will be returned as
		* a floating point value.
		*
		* No Arguments -> RETURNS: Float
		*******************************************************/
		float GetValue() const;

    private:
		string name;     // OUTPUT  - Variable will output to the console when needed.
		string type;     // OUTPUT  - Variable will output to the console when needed.
		int age;         // INP/OUT - User has option to change value. Also, displayed via console.
		float value;     // INP/OUT - User has option to change value. Also, displayed via console.
};

#endif /* ANIMAL_H_ */
