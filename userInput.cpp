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
* OutputInstruct
* This function outputs instructions to the users. There are no input
* or output parameters for this function as it only displays text to
* the screen.
*
* RETURNS: nothing
* à Displays the instructions to the user
*****************************************************************************/
void OutputInstruct()
{
	cout << "Instructions:" << endl
		<< "Select an option from the menu" << endl
		<< "Option a: exits" << endl
		<< "Option b: allows the user to enter the names of the two players" << endl
		<< "Option c: allows two players to play tic tac toe" << endl
		<< "Option d: allows one player to play tic tac toe aginst the computer" << endl << endl;
}


/******************************************************************************
* InitBoard
* This function initializes each spot in the board to a space ' '.
*
* PRE-CONDITIONS:
*	The following need a defined value passed in
*		char boardAr[][3]	:tic tac toe board array
*
* POST-CONDITIONS:
*	RETURNS: Board initialized with all spaces
*****************************************************************************/
void InitBoard(char boardAr[][COL]) // OUT - tic tac toe board
{
	int rowCount; //IN- array row number
	int colCount; //IN- array column number

	for (rowCount = 0; rowCount < ROW; rowCount++)
	{
		for (colCount = 0; colCount < COL; colCount++)
		{
			boardAr[rowCount][colCount] = ' ';
		}
	}
}

/******************************************************************************
* DisplayBoard
* This function outputs the tic tac toe board including the tokens
* played in the proper format (as described below).
*
* PRE-CONDITIONS:
*	The following need a defined value passed in
*		char boardAr[][3]	:tic tac toe board array
*
* POST-CONDITIONS:
*	RETURNS: Board initialized with all spaces
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
*****************************************************************************/
void DisplayBoard(const char boardAr[][COL])// IN - tic tac toe board
{
	system("cls");

	int i;
	int j;

	cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";

	for (i = 0; i < ROW; i++)
	{
		cout << setw(7) << "[" << i + 1 << "][1] | " << "[" << i + 1;
		cout << "][2] | " << "[" << i + 1 << "][3]" << endl;
		cout << setw(14) << "|" << setw(9) << "|" << endl;
		for (j = 0; j < COL; j++)
		{
			switch (j)
			{
			case 0: cout << i + 1 << setw(9) << boardAr[i][j];
				cout << setw(4) << "|";
				break;
			case 1: cout << setw(4) << boardAr[i][j];
				cout << setw(5) << "|";
				break;
			case 2: cout << setw(4) << boardAr[i][j] << endl;
				break;
			default: cout << "ERROR!\n\n";
			}
		}
		cout << setw(14) << "|" << setw(10) << "|\n";

		if (i != 2)
		{
			cout << setw(32) << "--------------------------\n";
		}
	}
	cout << endl << endl;
}

/******************************************************************************
* GetPlayers
* This function prompts the user and gets the input for the players’ names,
* playerX will always contain the name of the player that is using the X token,
* playerO will always contain the name of the player that is using the O token.
*
* PRE-CONDITIONS:
*	The following need a defined value passed in
*		playerX	:player X’s name
*		playerO :player O’s name
*
* POST-CONDITIONS:
*	RETURNS: the players names through the variables playerX and playerO.
*****************************************************************************/
void GetPlayers(string& playerX, // OUT - player X’s name
				string& playerO) // OUT - player O’x name 
{
	cout << "Player 1 - Enter your name: " << endl;
	cin.ignore(1000, '\n');
	getline(cin, playerX);

	cout << "Player 2-Enter your name: " << endl;
	getline(cin, playerO);
}

/******************************************************************************
* GetAndCheckInp
* This function prompts the user and gets the input for the token.
* allows then the function checks whether the input is within the
* bounds of the array and if the spot is taken. if not the function
* places the token in the spot
*
* PRE-CONDITIONS:
*	The following need a defined value passed in
*		char boardAr[][3]: tic tac toe board array
*		char token: The token that is currently playing
*		playerX	:player X’s name
*		playerO :player O’s name
*
* POST-CONDITIONS:
*	RETURNS: nothing
*****************************************************************************/
void GetAndCheckInp(char boardAr[][COL], // IN - tic tac toe board array
					char token, //IN- The token that is currently playing
					string playerX, //IN - player X’s name 
					string playerO)//IN - player X’s name
{
	int row;
	int col;
	bool valid;

	valid = false;
	do
	{
		if (token == 'X')
		{
			cout << endl << playerX << "'s turn, what is your play?";
			cin >> row >> col;
		}
		else if (token == 'O')
		{
			cout << endl << playerO << "'s turn, what is your play?";
			cin >> row >> col;
		}

		row--;
		col--;

		if (row > ROW || row < 0)
		{
			cout << "Invalid row\n";
		}
		else if (col > COL || col < 0)
		{
			cout << "Invalid column\n";
		}
		else if (boardAr[row][col] != ' ')
		{
			cout << "That spot is taken\n";
		}
		else
		{
			valid = true;
		}
	} while (!valid);

	boardAr[row][col] = token;
	cin.ignore(1000, '\n');
}

/******************************************************************************
* GetAndCheckInp
* This function prompts the user and gets the input for the token.
* allows then the function checks whether the input is within the
* bounds of the array and if the spot is taken. if not the function
* places the token in the spot. And this function allows the computer
* to play and then computer places its token in the array.
*
* PRE-CONDITIONS:
*	The following need a defined value passed in
*		char boardAr[][3]: tic tac toe board array
*		char token: The token that is currently playing
*		playerX	:player X’s name
*		playerO :player O’s name
*
* POST-CONDITIONS:
*	RETURNS: nothing
*****************************************************************************/
void GetAndCheckInpcomp(char boardAr[][COL], // IN - tic tac toe board array
	char token, //IN- The token that is currently playing
	string playerX) //IN - player X’s name 

{
	int row; // IN- the number of the row input by user
	int col; //IN - the number of the column input by user
	bool valid;

	valid = false;
	do
	{
		if (token == 'X')
		{
			cout << endl << playerX << "'s turn! what is your play?";
			cin >> row >> col;
		}
		else if (token == 'O')
		{
			srand(time(NULL));
			cout << "Computer's turn!, what is your play?";
			row = rand() % 3 + 1;
			col = rand() % 3 + 1;
			cout << row << endl;
			cout << col << endl;
		}

		row--;
		col--;

		if (row > 3 || row < 0)
		{
			cout << "Invalid row\n";
		}
		else if (col > 3 || col < 0)
		{
			cout << "Invalid column\n";
		}
		else if (boardAr[row][col] != ' ')
		{
			cout << "That spot is taken\n";
		}
		else
		{
			valid = true;
		}
	} while (!valid);

	boardAr[row][col] = token;
	cin.ignore(1000, '\n');
}

/******************************************************************************
* SwitchToken
* This function switches the active player.
* It takes in a parameter representing the current player's token
* as a character value (either an X or an O) and returns the opposite.
* For example, if this function receives an X it returns an 0. If it
* receives and O it returns and X.
*
PRE-CONDITIONS:
*	The following need a defined value passed in
*		char token: The token that is currently playing
*
* POST-CONDITIONS:
*	RETURNS: the token opposite of the one in which it receives.
*****************************************************************************/
char SwitchToken(char token) // IN - current player’s token ('X' or 'O')
{

	if (token == 'X')
	{
		token = 'O';
	}
	else
		token = 'X';


	return token;
}

/******************************************************************************
* CheckWin
* This function checks to see if either player has run. Once it is
* possible for a win condition to exist, this should run after each a
* player makes a play.
*
* PRE-CONDITIONS:
*	The following need a defined value passed in
*		char boardAr[][3]	:tic tac toe board array
*
* POST-CONDITIONS:
*	RETURNS the character value of the player that won or a value that
*	indicates a tie.
*****************************************************************************/
char CheckWin(const char boardAr[][COL]) // IN - tic tac toe board
{
	int countX; // OUT- count for how many places in the array are X
	int countO; // OUT- count for how many places in the array are O
	int countT; // OUT- count if a row had no spaces
	char winner; // OUT- winner of the game
	int j;

	countX = 0;
	countO = 0;
	countT = 0;
	j = 0;

	for (int i = 0; i < ROW; i++)
	{

		if (boardAr[i][j] == 'X')
		{
			countX++;
		}
		else if (boardAr[i][j] == 'O')
		{
			countO++;
		}
	}

	if (countX == 3)
	{
		winner = 'A';
		return winner;
	}
	else if (countO == 3)
	{
		winner = 'B';
		return winner;
	}
	else
	{
		countX = 0;
		countO = 0;
	}

	for (int i = 0; i < ROW; i++)
	{

		if (boardAr[i][j + 1] == 'X')
		{
			countX++;
		}
		else if (boardAr[i][j + 1] == 'O')
		{
			countO++;
		}
	}

	if (countX == 3)
	{
		winner = 'A';
		return winner;
	}
	else if (countO == 3)
	{
		winner = 'B';
		return winner;
	}
	else
	{
		countX = 0;
		countO = 0;
	}

	for (int i = 0; i < ROW; i++)
	{

		if (boardAr[i][j + 2] == 'X')
		{
			countX++;
		}
		else if (boardAr[i][j + 2] == 'O')
		{
			countO++;
		}
	}

	if (countX == 3)
	{
		winner = 'A';
		return winner;
	}
	else if (countO == 3)
	{
		winner = 'B';
		return winner;
	}
	else
	{
		countX = 0;
		countO = 0;
	}

	for (int i = 0; i < COL; i++)
	{
		if (boardAr[j][i] == 'X')
		{
			countX++;
		}
		else if (boardAr[j][i] == 'O')
		{
			countO++;
		}
	}

	if (countX == 3)
	{
		winner = 'A';
		return winner;
	}
	else if (countO == 3)
	{
		winner = 'B';
		return winner;
	}
	else
	{
		countX = 0;
		countO = 0;
	}

	for (int i = 0; i < COL; i++)
	{
		if (boardAr[j + 1][i] == 'X')
		{
			countX++;
		}
		else if (boardAr[j + 1][i] == 'O')
		{
			countO++;
		}
	}

	if (countX == 3)
	{
		winner = 'A';
		return winner;
	}
	else if (countO == 3)
	{
		winner = 'B';
		return winner;
	}
	else
	{
		countX = 0;
		countO = 0;
	}

	for (int i = 0; i < COL; i++)
	{
		if (boardAr[j + 2][i] == 'X')
		{
			countX++;
		}
		else if (boardAr[j + 2][i] == 'O')
		{
			countO++;
		}
	}

	if (countX == 3)
	{
		winner = 'A';
		return winner;
	}
	else if (countO == 3)
	{
		winner = 'B';
		return winner;
	}
	else
	{
		countX = 0;
		countO = 0;
	}

	if (boardAr[0][0] == 'X' && boardAr[1][1] == 'X' && boardAr[2][2] == 'X'
		|| boardAr[0][2] == 'X' && boardAr[1][1] == 'X' && boardAr[2][0] == 'X')
	{
		countX = 3;
	}
	else if (boardAr[0][0] == 'O' && boardAr[1][1] == 'O' && boardAr[2][2] == 'O'
		|| boardAr[0][2] == 'O' && boardAr[1][1] == 'O' && boardAr[2][0] == 'O')
	{
		countO = 3;
	}

	if (countX == 3)
	{
		winner = 'A';
		return winner;
	}
	else if (countO == 3)
	{
		winner = 'B';
		return winner;
	}

	for (int i = 0; i < ROW; i++)
	{
		{
			if (boardAr[i][j] != ' ' && boardAr[i][j + 1] != ' ' && boardAr[i][j + 2] != ' ')
			{
				countT++;
			}
		}
	}

	if (countT == 3)
	{
		winner = 'T';
		return winner;
	}

	winner = 'N';
	return winner;
}


/******************************************************************************
* OutputWinner
* This function receives as input a character indicating which player won
* or if the game was a tie and outputs an appropriate message. This function
* does not return anything as it simply outputs the appropriate message to
* the screen.

* PRE-CONDITIONS:
*	The following need a defined value passed in
*		char whowon: The token that won the game
*		playerX: player X’s name
*		playerO: player O’x name
*
* POST-CONDITIONS:
*	RETURNS: nothing
* à Displays the winner’s name
*****************************************************************************/
void OutputWinner(char whoWon, // IN - represents the winner or a value
							   // indicating a tied game.
	string playerX, // OUT - player X’s name
	string playerO) // OUT - player O’x name 
{
	if (whoWon == 'A')
	{
		cout << "The winner is " << playerX << endl << endl;
	}
	else if (whoWon == 'B')
	{
		cout << "The winner is " << playerO << endl << endl;
	}
	else if (whoWon == 'T')
	{
		cout << "Its a tie!\n\n";
	}
}