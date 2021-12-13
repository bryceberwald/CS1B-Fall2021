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

// Struct created for DVDNode type.
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
 * This is the class definition for the Stack List class. This class has
 * two protected attributes along with mutator and accessor methods to
 * manipulate the linked list.
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
		* StackList Class method prototype for pushing a new DVD
		* node to the linked list. A DVDNode type is passed as a
		* parameter to add to the front of the list.
		*
		* 1 Argument passed by value -> RETURNS: Nothing
		*******************************************************/
		void Push(DVDNode newDVD);

		/******************************************************
		* StackList Class method prototype for popping a linked
		* list item from the front of the list. The popped
		* DVDNode type will be returned as well.
		*
		* No Arguments -> RETURNS: DVDNode
		*******************************************************/
		DVDNode Pop();

		/******************************************************
		*****************     ACCESSORS    ********************
		*******************************************************/

		/******************************************************
		* StackList Class method prototype for checking whether
		* the linked list is empty or not. A boolean type will
		* be returned for determination if list is empty.
		*
		* No Arguments -> RETURNS: Boolean
		*******************************************************/
		bool IsEmpty() const;

		/******************************************************
		* StackList Class method prototype for peeking at the
		* front most item of the linked list. The front item
		* will be returned as a DVDNode type.
		*
		* No Arguments -> RETURNS: DVDNode
		*******************************************************/
		DVDNode Peek() const;

		/******************************************************
		* StackList Class method prototype for getting the size
		* of the linked list to be returned.
		*
		* No Arguments -> RETURNS: Integer
		*******************************************************/
		int Size() const;

    protected:
		DVDNode *head;    // Pointer created for the head of the linked list.
		int stackCount;   // Integer created for counting number of items in linked list.

    private:
		// None!
};

#endif /* STACKLIST_H_ */
