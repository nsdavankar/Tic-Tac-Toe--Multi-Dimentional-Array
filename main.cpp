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
* Multi-Dimensional Array
*----------------------------------------------------------------------------
* This program will allow the user to to chose if they want to play a two player 
* tic tac toe game or one player tic tac toe game. The user will enter where they
* would like to place the token and the program will end when there is a winner.
*----------------------------------------------------------------------------
* INPUT:
*	char boardAr[3][3]: The multi dimentional array of the tic tac toe
*	choice	:The option selected on the menu
*   playerX :Name of player with token X	
*	playerO :Name of player with token O
*	token	:The token that is currently playing
*
*  OUTPUT:
*   winner  :The winner of the tic tac toe game
*****************************************************************************/
int main()
{
	/*****************************************************************************
	* FUNCTION PrintHeader
	*-----------------------------------------------------------------------------
	* 	This function receives an output variable, student name, class day/time,
	* 		assignment name, assignment type, and assignment/lab # then outputs
	* 		the appropriate header
	* 		==> returns nothing - This will output the class heading.
	*-----------------------------------------------------------------------------
	******************************************************************************/
	PrintHeader(cout, "Nisha Davankar", "M/W: 6:30pm",
		"Multi-Dimensional Array", 'A', 5);

	/*****************************************************************************
	* OutputInstruct
	* This function outputs instructions to the users. There are no input
	* or output parameters for this function as it only displays text to
	* the screen.
	*****************************************************************************/
	OutputInstruct();

	string playerX; //Name of player with token X
	string playerO; //Name of player with token O
	char choice; //The option selected on the menu
	char token; //The token that is currently playing
	char winner; //The winner of the tic tac toe game

	//DATA TABLE
	token = 'X';
	playerX = 'X';
	playerO = 'O';

	char boardAr[ROW][COL];
	do {
		cout << "a. Exit" << endl
			<< "b. Set Player Names" << endl
			<< "c. Play in Two Player Mode" << endl
			<< "d. Play in One Player Mode" << endl;
		cin >> choice;
		{
			/******************************************************************************
			* InitBoard
			* This function initializes each spot in the board to a space ' '.
			*****************************************************************************/
			InitBoard(boardAr);


			if (toupper(choice) == 'B')
			{
				/******************************************************************************
				* GetPlayers
				* This function prompts the user and gets the input for the players’ names,
				* playerX will always contain the name of the player that is using the X token,
				* playerO will always contain the name of the player that is using the O token.
				*****************************************************************************/
				GetPlayers(playerX, playerO);
			}

			else if (toupper(choice) == 'C' || toupper(choice) == 'D')
			{
				/******************************************************************************
				* DisplayBoard
				* This function outputs the tic tac toe board including the tokens
				* played in the proper format (as described below).
				*****************************************************************************/
				DisplayBoard(boardAr);

				do
				{
					if (toupper(choice) == 'C')
					{
						/******************************************************************************
						* GetAndCheckInp
						* This function prompts the user and gets the input for the token.
						* allows then the function checks whether the input is within the
						* bounds of the array and if the spot is taken. if not the function
						* places the token in the spot
						*****************************************************************************/
						GetAndCheckInp(boardAr, token, playerX, playerO);
					}
					else if (toupper(choice) == 'D')
					{
						/******************************************************************************
						* GetAndCheckInp
						* This function prompts the user and gets the input for the token.
						* allows then the function checks whether the input is within the
						* bounds of the array and if the spot is taken. if not the function
						* places the token in the spot. And this function allows the computer
						* to play and then computer places its token in the array.
						*****************************************************************************/
						GetAndCheckInpcomp(boardAr, token, playerX);
					}
					/******************************************************************************
					* SwitchToken
					* This function switches the active player.
					* It takes in a parameter representing the current player's token
					* as a character value (either an X or an O) and returns the opposite.
					* For example, if this function receives an X it returns an 0. If it
					* receives and O it returns and X.
					******************************************************************************/
					SwitchToken(token);
					token = SwitchToken(token);

					/******************************************************************************
					* DisplayBoard
					* This function outputs the tic tac toe board including the tokens
					* played in the proper format (as described below).
					*****************************************************************************/
					DisplayBoard(boardAr);

					/******************************************************************************
					* CheckWin
					* This function checks to see if either player has run. Once it is
					* possible for a win condition to exist, this should run after each a
					* player makes a play.
					*******************************************************************************/
					winner = CheckWin(boardAr);

				} while (winner == 'N');

				/******************************************************************************
				* OutputWinner
				* This function receives as input a character indicating which player won
				* or if the game was a tie and outputs an appropriate message. This function
				* does not return anything as it simply outputs the appropriate message to
				* the screen.
				******************************************************************************/
				OutputWinner(winner, playerX, playerO);

				/******************************************************************************
				* InitBoard
				* This function initializes each spot in the board to a space ' '.
				*****************************************************************************/
				InitBoard(boardAr);
				token = 'O';
			}
		}
	} while (toupper(choice) != 'A');

	return 0;
}