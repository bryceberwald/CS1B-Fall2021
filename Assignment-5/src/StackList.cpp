/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #5  : DVD Movie List - Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/15/2021 @ 11:59PM
 ******************************************************************************/

#include "StackList.h"

/**************************************************************************
 * Stack List class constructor will initiate the head to NULL and the
 * stack count to a value of zero.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
StackList::StackList(){

	// Initialize class attributes.
	head = NULL;
	stackCount = 0;

}


/**************************************************************************
 * Stack List class destructor is currently left as a template as it is not
 * being used for this assignment.
 *
 * No Arguments -> RETURNS: Nothing
 *************************************************************************/
StackList::~StackList(){

}


/**************************************************************************
 * Stack List class mutator method for pushing a new linked list item to
 * the front of the linked list. The function will check if head is equal
 * to NULL and append to the front of the linked list properly.
 *
 * 1 Argument passed by value -> RETURNS: Nothing
 *************************************************************************/
void StackList::Push(DVDNode newDVD){

	DVDNode *dvdPtr;        // Pointer used to created a new DVD Node.
	dvdPtr = new DVDNode;

	if(head == NULL){
		dvdPtr->title = newDVD.title;
		dvdPtr->leadActor = newDVD.leadActor;
		dvdPtr->supportingActor = newDVD.supportingActor;
		dvdPtr->genre = newDVD.genre;
		dvdPtr->alternativeGenre = newDVD.alternativeGenre;
		dvdPtr->year = newDVD.year;
		dvdPtr->rating = newDVD.rating;
		dvdPtr->synopis = newDVD.synopis;

		head = dvdPtr;
		dvdPtr->next = NULL;

	} else {

		dvdPtr->title = newDVD.title;
		dvdPtr->leadActor = newDVD.leadActor;
		dvdPtr->supportingActor = newDVD.supportingActor;
		dvdPtr->genre = newDVD.genre;
		dvdPtr->alternativeGenre = newDVD.alternativeGenre;
		dvdPtr->year = newDVD.year;
		dvdPtr->rating = newDVD.rating;
		dvdPtr->synopis = newDVD.synopis;

	    dvdPtr->next = head;

	    head = dvdPtr;

	}

    stackCount++;
}


/**************************************************************************
 * Stack List class mutator method for popping a linked list item from
 * the front of the list. A  DVDNode will be assigned all of the values of
 * the popped node for returning.
 *
 * No Arguments -> RETURNS: DVDNode
 *************************************************************************/
DVDNode StackList::Pop(){
	DVDNode frontDVD;  // Pointer used to return popped DVD Node.

	frontDVD.title = head->title;
	frontDVD.leadActor = head->leadActor;
	frontDVD.supportingActor = head->supportingActor;
	frontDVD.genre = head->genre;
	frontDVD.alternativeGenre = head->alternativeGenre;
	frontDVD.year = head->year;
	frontDVD.rating = head->rating;
	frontDVD.synopis = head->synopis;

	// Check if head is equal to null.
	if(head != NULL){
		head = head->next;
		stackCount--;
	}

	return frontDVD;
}


/**************************************************************************
 * Stack List class accessor method for determining if the linked list is
 * empty or not. The stack counter variable will be used to solve this issue,
 * returning a boolean for an answer.
 *
 * No Arguments -> RETURNS: Boolean
 *************************************************************************/
bool StackList::IsEmpty() const {
	if(stackCount == 0){
		return true;
	} else {
		return false;
	}
}


/**************************************************************************
 * Stack List class accessor method for peeking at the front most item of
 * the linked list. A DVD Node will be created and assigned all the front
 * items values to be returned.
 *
 * No Arguments -> RETURNS: DVDNode
 *************************************************************************/
DVDNode StackList::Peek() const {
	DVDNode frontDVD;

	frontDVD.title = head->title;
	frontDVD.leadActor = head->leadActor;
	frontDVD.supportingActor = head->supportingActor;
	frontDVD.genre = head->genre;
	frontDVD.alternativeGenre = head->alternativeGenre;
	frontDVD.year = head->year;
	frontDVD.rating = head->rating;
	frontDVD.synopis = head->synopis;

	return frontDVD;
}


/**************************************************************************
 * Stack List class accessor method for getting and returning the size
 * of the linked list.
 *
 * No Arguments -> RETURNS: Integer
 *************************************************************************/
int StackList::Size() const {
	return stackCount;
}

