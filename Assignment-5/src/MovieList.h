/******************************************************************************
 * AUTHOR         : BRYCE BERWALD
 * Assignment #5  : DVD Movie List - Introduction to OOP
 * CLASS          : CS1B
 * SECTION        : MW 7:30-10:00PM
 * DUE DATE       : 12/15/2021 @ 11:59PM
 ******************************************************************************/

#ifndef MOVIELIST_H_
#define MOVIELIST_H_

#include "StackList.h"
#include <iostream> // For input & output
#include <iomanip>  // For manipulating the input & output
#include <string>   // For strings to be used
#include <fstream>

using namespace std;

/**************************************************************************
 * MovieList Class
 *************************************************************************/
class MovieList:public StackList
{
    public:
		/******************************************************
		**********   CONSTRUCTOR && DESTRUCTOR    *************
		*******************************************************/

		/******************************************************
		 * MovieList ();
		 * Constructor; Initialize movie list attributes
		 * Parameters: none
		 * Return: none
		 *******************************************************/
		MovieList();

		/******************************************************
		* ~MovieList ();                                      *
		* Destructor; Does not perform any specific function  *
		* Parameters: none                                    *
		* Return: none
		*******************************************************/
		~MovieList();


		/******************************************************
		*****************     MUTATORS    *********************
		*******************************************************/


		/******************************************************
		*
		*******************************************************/
		void CreateList(string inputFileName);

		/******************************************************
		*
		*******************************************************/
		void OutputList(string outputFileName);


    private:

		/******************************************************
		*****************     ACCESSORS    ********************
		*******************************************************/


		/******************************************************
		*
		*******************************************************/
		string WorpWarp(string plot) const;

		/******************************************************
		*
		*******************************************************/
		void PrintHeader(ostream &output) const;

		StackList Stack; // Created Instance of the class StackList to be used.
};

#endif /* MOVIELIST_H_ */
