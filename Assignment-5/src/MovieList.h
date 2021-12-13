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
#include <sstream>
#include <ostream>

using namespace std;

/**************************************************************************
 * MovieList Class
 * This is the class definition for the Movie List class. This class will
 * allow for creating a linked list which will output to a file in the format
 * discussed in class. The class will use a couple accessor methods and
 * mutator methods to accomplish the task at hand.
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
		* This is the Movie List class method prototype for
		* creating a linked list from the input file passed as
		* a parameter.
		*
		* 1 Argument passed by value -> RETURNS: Nothing
		*******************************************************/
		void CreateList(string inputFileName);

		/******************************************************
		* This is the Movie List class method prototype for
		* outputting a linked list to the output file name passed
		* as a parameter.
		*
		* 1 Argument passed by value -> RETURNS: Nothing
		*******************************************************/
		void OutputList(string outputFileName);

    private:

		/******************************************************
		*****************     ACCESSORS    ********************
		*******************************************************/

		/******************************************************
		* This is the Movie List class method prototype for
		* making sure the movie synopsis stays within a certain
		* length.
		*
		* 1 Argument passed by value -> RETURNS: String
		*******************************************************/
		string WordWrap (string synopsis) const;

		/******************************************************
		* This is the Movie List class method prototype for
		* making sure the title length doesn't run over creating
		* an ugly user view.
		*
		* 1 Argument passed by value -> RETURNS: String
		*******************************************************/
		string TruncatedTitle(string title) const;

		/******************************************************
		* This is the Movie List class method prototype for
		* printing the class header to the output file.
		*
		* 1 Argument passed by reference -> RETURNS: Nothing
		*******************************************************/
		void PrintHeader(ostream &output) const;
};

#endif /* MOVIELIST_H_ */
