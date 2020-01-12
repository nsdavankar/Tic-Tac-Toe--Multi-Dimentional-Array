/*****************************************************************************
* AUTHOR		: Nisha Davankar
* STUDENT ID	: 1045735
* Assignment #2	: Multi-Dimensional Array - Tic Tac Toe
* CLASS			: CS1B
* SECTION		: M/W: 6:30pm
* DUE DATE		: 9/27/17
*****************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <cctype>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>	
using namespace std;

const int ROW = 3;
const int COL = 3;

/*****************************************************************************
* FUNCTION PrintHeader
*-----------------------------------------------------------------------------
* 	This function receives an output variable, student name, class day/time,
* 		assignment name, assignment type, and assignment/lab # then outputs
* 		the appropriate header
* 		==> returns nothing - This will output the class heading.
*-----------------------------------------------------------------------------
******************************************************************************/
void PrintHeader(ostream  &out, string stName, string clTime, string asName, char asType, int asNum);

/******************************************************************************
* OutputInstruct
* This function outputs instructions to the users. There are no input
* or output parameters for this function as it only displays text to
* the screen.
*
* RETURNS: nothing
* à Displays the instructions to the user
*****************************************************************************/
void OutputInstruct();

/******************************************************************************
* InitBoard
* This function initializes each spot in the board to a space ' '.
*
* RETURNS: Board initialized with all spaces
*****************************************************************************/
void InitBoard(char boardAr[][COL]);

/******************************************************************************
* DisplayBoard
* This function outputs the tic tac toe board including the tokens
* played in the proper format (as described below).
*
*       1        2       3
*    [1][1] | [1][2] | [1][3]
*           |        |
* 1         |        |
*           |        |
*    --------------------------
*    [2][1] | [2][2] | [2][3]
*           |        |
* 2         |        |
*           |        |
*    --------------------------
*    [3][1] | [3][2] | [3][3]
*           |        |
* 3         |        |
*           |        |
*
* RETURNS: nothing
*  outputs the current state of the board
*****************************************************************************/
void DisplayBoard(const char boardAr[][COL]);

/******************************************************************************
* GetPlayers
* This function prompts the user and gets the input for the players’ names.
* playerX will always contain the name of the player that is using the X token.
* playerO will always contain the name of the player that is using the O token.
*
* RETURNS: the players names through the variables playerX and playerO.
*****************************************************************************/
void GetPlayers(string& playerX, string& playerO);

/******************************************************************************
* GetAndCheckInp
* This function prompts the user and gets the input for the token.
* allows then the function checks whether the input is within the
* bounds of the array and if the spot is taken. if not the function
* places the token in the spot
*
* RETURNS: nothing
*****************************************************************************/
void GetAndCheckInp(char boardAr[][COL], char token, string playerX, string playerO);

/******************************************************************************
* GetAndCheckInp
* This function prompts the user and gets the input for the token.
* allows then the function checks whether the input is within the
* bounds of the array and if the spot is taken. if not the function
* places the token in the spot. And this function allows the computer
* to play and then computer places its token in the array.
*
* RETURNS: nothing
*****************************************************************************/
void GetAndCheckInpcomp(char boardAr[][COL], char token, string playerX);

/******************************************************************************
* SwitchToken
* This function switches the active player.
* It takes in a parameter representing the current player's token
* as a character value (either an X or an O) and returns the opposite.
* For example, if this function receives an X it returns an 0. If it
* receives and O it returns and X.
*
* RETURNS: the token opposite of the one in which it receives.
*****************************************************************************/
char SwitchToken(char token);

/******************************************************************************
* CheckWin
* This function checks to see if either player has run. Once it is
* possible for a win condition to exist, this should run after each a
* player makes a play.
*
* RETURNS the character value of the player that won or a value that
* indicates a tie.
*****************************************************************************/
char CheckWin(const char boardAr[][COL]);

/******************************************************************************
* OutputWinner
* This function receives as input a character indicating which player won
* or if the game was a tie and outputs an appropriate message. This function
* does not return anything as it simply outputs the appropriate message to
* the screen.
*
* RETURNS: nothing
* à Displays the winner’s name
*****************************************************************************/
void OutputWinner(char whoWon, // IN - represents the winner or a value
							   // indicating a tied game.
	string playerX, // OUT - player X’s name
	string playerO); // OUT - player O’x name 

#endif /* HEADER_H_ */