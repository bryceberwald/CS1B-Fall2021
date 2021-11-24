/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #12	      : Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/24/21 @ 11:59PM
 *************************************************************************/

#include "Animal.h"

/**************************************************************************
 * This is the constructor method for the animal class instance. As for
 * this lab, the constructor is left empty.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
Animal::Animal(){


}


/**************************************************************************
 * This is the destructor method for the animal class instance. As for
 * this lab, the destructor method will be left empty.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
Animal::~Animal(){

}


/**************************************************************************
 * This is a mutator method within the animal class instance. This function
 * will set the initial values of the animal object created in main when
 * the user specifies to initialize animal objects.
 *
 * 4 Arguments passed by value -> RETURNS: Nothing
 *************************************************************************/
void Animal::SetInitialValues (string aName, string aType, int aAge, float aValue){

	name = aName;

	type = aType;

	age = aAge;

	value = aValue;

}


/**************************************************************************
 * This is a mutator method within the animal class instance. This function
 * will change the age of an animal when the user selects the option to do
 * so.
 *
 * 1 Argument passed by value -> RETURNS: Nothing
 *************************************************************************/
void Animal::ChangeAge (int aAge){

	age = aAge;

}


/**************************************************************************
 * This is a mutator method within the animal class instance. This function
 * will change the value of the value attribute inside the animal class.
 *
 * 1 Argument passed by value -> RETURNS: Nothing
 *************************************************************************/
void Animal::ChangeValue (float aValue){

	value = aValue;

}


/**************************************************************************
 * This is a accessor method within the animal class instance. This function
 * will display all four attributes within the animal class object to the
 * console with the format discussed in class.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
void Animal::Display() const {

	cout << setw(11) << type << setw(14) << name << setw(7) << age
		 << fixed << setprecision(2) << value << endl;

}


/**************************************************************************
 * This is a accessor method within the animal class instance. This function
 * will access the name attribute to be returned to main.
 *
 * No Arguments -> RETURNS: String
 *************************************************************************/
string Animal::GetName () const {

	return name;

}


/**************************************************************************
 * This is a accessor method within the animal class instance. This function
 * will access the private type attribute to be returned to main by this
 * function.
 *
 * No Arguments -> RETURNS: String
 *************************************************************************/
string Animal::GetType () const {

	return type;

}


/**************************************************************************
 * This is a accessor method within the animal class instance. This function
 * will access the private age attribute within animal class to be returned
 * to main.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
int Animal::GetAge () const {

	return age;

}


/**************************************************************************
 * This is a accessor method within the animal class instance. This function
 * will access the private value attribute in the animal class to be returned
 * to main.
 *
 * No Arguments -> RETURNS: Float
 *************************************************************************/
float Animal::GetValue () const {

	return value;

}

