/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #13	      : Array's and Linked Lists of Sheep - OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/01/21 @ 11:59PM
 *************************************************************************/

#include "Sheep.h"

/**************************************************************************
 *
 *************************************************************************/
Sheep::Sheep(){

	name = "";
	age = 0;

}


/**************************************************************************
 *
 *************************************************************************/
Sheep::~Sheep(){

}


/**************************************************************************
 *
 *************************************************************************/
void Sheep::SetInitialValues(string sheepName, int sheepAge){

	name = sheepName;
	age = sheepAge;

}


/**************************************************************************
 *
 *************************************************************************/
void Sheep::GetValues(string &sheepName, int &sheepAge) const {

	sheepName = name;
	sheepAge = age;

}


/**************************************************************************
 *
 *************************************************************************/
string Sheep::GetName() const {

	return name;

}
