/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #13	      : Linked Lists of Sheep - OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/01/21 @ 11:59PM
 *************************************************************************/

#include "Sheep.h"

/**************************************************************************
 * This function is the constructor of the sheep class object. The goal of
 * the constructor is to initialize the sheep class object with empty values.
 * Meaning a empty string for the name and a 0 for no age as a basis.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
Sheep::Sheep(){

	name = "";
	age = 0;

}


/**************************************************************************
 * This function is the destructor of the sheep class object. As of this
 * lab, we will not be utilizing the destructor and am only leaving this
 * function for a template basis.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
Sheep::~Sheep(){

}


/**************************************************************************
 * This function will set the initial values of the sheep classes object
 * attributes equal to the parameters passed to the function.
 *
 * 2 Arguments passed by value -> RETURNS: Nothing
 *************************************************************************/
void Sheep::SetInitialValues(string sheepName, int sheepAge){

	name = sheepName;
	age = sheepAge;

}


/**************************************************************************
 * This function prototype is for getting the private sheep attributes and
 * and returning those values by reference when using this sheep accessor
 * method.
 *
 * 2 Arguments passed by reference -> RETURNS: Nothing
 *************************************************************************/
void Sheep::GetValues(string &sheepName, int &sheepAge) const {

	sheepName = name;
	sheepAge = age;

}


/**************************************************************************
 * This is the function for getting the name attribute from the sheep class
 * object and returning that value to the called function.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
string Sheep::GetName() const {

	return name;

}

