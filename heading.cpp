/*****************************************************************************
* AUTHOR		: Nisha Davankar
* STUDENT ID	: 1045735
* Assignment #2	: Multi-Dimensional Array - Tic Tac Toe
* CLASS			: CS1B
* SECTION		: M/W: 6:30pm
* DUE DATE		: 10/2/17
*****************************************************************************/

#include "header.h"

/*****************************************************************************
* FUNCTION PrintHeader
*-----------------------------------------------------------------------------
* 	This function receives an output variable, student name, class day/time,
* 		assignment name, assignment type, and assignment/lab # then outputs
* 		the appropriate header
* 		==> returns nothing - This will output the class heading.
*-----------------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need a defined value passed in
* 		out	  : Output variable
* 		stName: Student name
* 		clTime: Class day/time
* 		asName: Assignment Name
* 		asType: Assignment Type
* 		asNum : Assignment Number
*
* POST-CONDITIONS
* 	==> Returns nothing - This function outputs class heading to output file
******************************************************************************/

void PrintHeader(ostream  &out,   // IN/OUT - output file
	string   stName, // IN     - student name to output
	string   clTime, // IN     - class day/time to output
	string   asName, // IN     - assignment name to output
	char     asType, // IN     - assignment type

					 //        - (LAB or ASSIGN)to output
	int      asNum) 	// IN     – assign. number to output
{
	out << left;
	out << "*************************************************\n";
	out << "*  PROGRAMMED BY : " << stName << endl;
	out << "*  " << setw(14) << "CLASS" << ": " << "CS1B" << endl;
	out << "*  " << setw(14) << "SECTION" << ": " << clTime << endl;
	out << "*  ";

	// PROCESSING – This will adjust setws and format appropriately
	// based on if this is a lab ‘L’ or assignment

	if (toupper(asType) == 'L')
	{
		out << "LAB #" << setw(9);
	}
	else
	{
		out << "ASSIGNMENT #" << setw(2);
	}
	out << asNum << ": " << asName << endl;
	out << "*************************************************\n\n";
	out << right;
}
