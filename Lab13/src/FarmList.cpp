/**************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Lab #13	      : Array's and Linked Lists of Sheep - OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/01/21 @ 11:59PM
 *************************************************************************/

#include "FarmList.h"

/**************************************************************************
 *
 *************************************************************************/
FarmList::FarmList(){

	sheepCount = 0;

}


/**************************************************************************
 *
 *************************************************************************/
FarmList::~FarmList(){

}


/**************************************************************************
 *
 *************************************************************************/
void FarmList::AddSheep(Sheep newSheep){

	string name;
	int age;

	cout << "\nSheep Name: ";
	getline(cin, name);

	cout << "Sheep Age: ";
	cin >> age;

	cin.ignore(10000, '\n');

	newSheep.SetInitialValues(name, age);

	if(sheepCount < AR_SIZE){
		farmArray[sheepCount] = newSheep;
		sheepCount++;
		cout << "\nThe Sheep...";
		cout << "\nSheep Name: " << name;
		cout << "\nSheep Age: " << age;
		cout << "\nHas been added!\n";
	} else {
		cout << "\nThe Array is FULL.\n";
	}

}


/**************************************************************************
 *
 *************************************************************************/
void FarmList::ClearList(){

	for (int i = 0; i < sheepCount; i++){
		farmArray[i].SetInitialValues("", 0);
	}

	if(sheepCount > 0){
		cout << "\nThe list has been cleared!\n";
	} else {
		cout << "\nThe list is empty!\n";
	}

	sheepCount = 0;
}


/**************************************************************************
 *
 *************************************************************************/
Sheep FarmList::FindSheep(string sheepName) const {

	Sheep newSheep;
	string name;
	int age;

	bool found = false;
	int index = 0;

	while(index < sheepCount && !found){

		if(farmArray[index].GetName() == sheepName){
			farmArray[index].GetValues(name, age);
			newSheep.SetInitialValues(name, age);
			found = true;
		} else {
			found = false;
		}

		index++;
	}

	return newSheep;
}


/**************************************************************************
 *
 *************************************************************************/
Sheep FarmList::GetFirstSheep() const {
	return farmArray[0];
}


/**************************************************************************
 *
 *************************************************************************/
int FarmList::TotalSheep() const {
	return sheepCount;
}


/**************************************************************************
 *
 *************************************************************************/
void FarmList::DisplaySheepTable() const {

	Sheep showSheep;

	string name;
	int age;

	if(sheepCount > 0){
		cout << endl << left;
		cout << setw(15) << "Name" << "AGE" << endl;
		cout << right;
		cout << setfill('-') << setw(15) << " " << setw(4) << " " << setfill(' ');

		cout << endl << left;

		for (int i = 0; i < sheepCount; i++){
			farmArray[i].GetValues(name, age);
			cout << setw(15) << name << age << endl;
		}

		if(sheepCount == 1){
			cout << "\nThere is one sheep in the list.\n";
		} else {
			cout << "\nThere are " << sheepCount << " sheep in the list!\n";
		}

	} else {
		cout << "\nThe list is empty!\n";
	}

}

