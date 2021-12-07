/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #5  : DVD Movie List - Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/15/2021 @ 11:59PM
 ******************************************************************************/

#ifndef STACKLIST_H_
#define STACKLIST_H_

#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used

using namespace std;

struct DVDNode {
	string title;
	string leadActor;
	string supportingActor;
	string genre;
	string alternativeGenre;
	int year;
	int rating;
	string synopis;
	DVDNode *next;
};

/**************************************************************************
 * StackList Class
 *************************************************************************/
class StackList
{
    public:
		/******************************************************
		**********   CONSTRUCTOR && DESTRUCTOR    *************
		*******************************************************/

		/******************************************************
		 * StackList ();
		 * Constructor; Initialize stack list attributes
		 * Parameters: none
		 * Return: none
		 *******************************************************/
		StackList();

		/******************************************************
		* ~StackList ();                                       *
		* Destructor; Does not perform any specific function  *
		* Parameters: none                                    *
		* Return: none
		*******************************************************/
		~StackList();


		/******************************************************
		*****************     MUTATORS    *********************
		*******************************************************/


		/******************************************************
		*
		*******************************************************/
		void Push(DVDNode newDVD);

		/******************************************************
		*
		*******************************************************/
		DVDNode Pop();


		/******************************************************
		*****************     ACCESSORS    ********************
		*******************************************************/


		/******************************************************
		*
		*******************************************************/
		bool IsEmpty() const;

		/******************************************************
		*
		*******************************************************/
		DVDNode Peek() const;

		/******************************************************
		*
		*******************************************************/
		int Size() const;


    protected:
		DVDNode *head;
		int stackCount;

    private:
		// None!
};

#endif /* STACKLIST_H_ */
