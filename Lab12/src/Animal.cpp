/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #12	      : Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 11/24/21 @ 11:59PM
 *************************************************************************/

#include "Animal.h"

/**************************************************************************
 *
 *************************************************************************/
Animal::Animal(){


}


/**************************************************************************
 *
 *************************************************************************/
Animal::~Animal(){

}


/**************************************************************************
 *
 *************************************************************************/
void Animal::SetInitialValues (string aName, string aType, int aAge, float aValue){

	name = aName;

	type = aType;

	age = aAge;

	value = aValue;

}


/**************************************************************************
 *
 *************************************************************************/
void Animal::ChangeAge (int aAge){

	age = aAge;

}


/**************************************************************************
 *
 *************************************************************************/
void Animal::ChangeValue (float aValue){

	value = aValue;

}


/**************************************************************************
 *
 *************************************************************************/
void Animal::Display() const {

	cout << setw(11) << type << setw(14) << name << setw(7) << age
		 << fixed << setprecision(2) << value << endl;

}


/**************************************************************************
 *
 *************************************************************************/
string Animal::GetName () const {

	return name;

}


/**************************************************************************
 *
 *************************************************************************/
string Animal::GetType () const {

	return type;

}


/**************************************************************************
 *
 *************************************************************************/
int Animal::GetAge () const {

	return age;

}


/**************************************************************************
 *
 *************************************************************************/
float Animal::GetValue () const {

	return value;

}



