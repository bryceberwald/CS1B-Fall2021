/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #5  : DVD Movie List - Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/15/2021 @ 11:59PM
 ******************************************************************************/

#include "StackList.h"

/**************************************************************************
 *
 *************************************************************************/
StackList::StackList(){

	head = NULL;
	stackCount = 0;

}


/**************************************************************************
 *
 *************************************************************************/
StackList::~StackList(){

}


/**************************************************************************
 *
 *************************************************************************/
void StackList::Push(DVDNode newDVD){

	DVDNode *dvdPtr;
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
 *
 *************************************************************************/
DVDNode StackList::Pop(){
	DVDNode frontDVD;

	frontDVD.title = head->title;
	frontDVD.leadActor = head->leadActor;
	frontDVD.supportingActor = head->supportingActor;
	frontDVD.genre = head->genre;
	frontDVD.alternativeGenre = head->alternativeGenre;
	frontDVD.year = head->year;
	frontDVD.rating = head->rating;
	frontDVD.synopis = head->synopis;

	if(head != NULL){
		head = head->next;
		stackCount--;
	}

	return frontDVD;
}


/**************************************************************************
 *
 *************************************************************************/
bool StackList::IsEmpty() const {
	if(stackCount == 0){
		return true;
	} else {
		return false;
	}
}


/**************************************************************************
 *
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
 *
 *************************************************************************/
int StackList::Size() const {
	return stackCount;
}

