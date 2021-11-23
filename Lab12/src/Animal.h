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

class Animal
{
    public:
		//Animal();
		//~Animal();

		void SetInitialValues(string aName, string aType, int aAge, float aValue);
		void ChangeAge(int aAge);
		void ChangeValue(float aValue);

		void Display() const;
		string GetName() const;
		string GetType() const;
		int GetAge() const;
		float GetValue() const;

    private:
		string name;
		string type;
		int age;
		float value;
};

#endif /* ANIMAL_H_ */
