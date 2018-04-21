#include<stdio.h>
#include<stdlib.h>
#include "making.h"
#pragma warning(disable:4996)
game* create(int n)
{
	/*creates a new game with default values*/

	game* newGame = (game*)malloc(sizeof(game));
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			newGame->a[i][j] = 0;
	newGame->counter = 0;
	newGame->n = n;
	printf("enter your name:\n");
	scanf("%s", newGame->name);
	return newGame;
}
void showBoard(game* temp)
{
	/*shows the board to the center of screen*/
	printf("\n\n\n\n\n");
	int n = temp->n;
	for (int i = 0; i<n; i++)
	{
		printf("\t\t\t\t");
		for (int j = 0; j<n; j++)
		{
			printf("%6d ", temp->a[i][j]);
		}
		printf("\t\t\t\t\t\n\n");
	}
	printf("\n\n\n\n\n\n\n\t%s\t\t\t\t\t\t\t\t\t%d\n\n", temp->name, temp->counter);
}
bool checkValue(game* board, int value)
{
	/*for given n*n board it will verify if given value is present in the board or not*/
	int n = board->n;
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			if (board->a[i][j] == value)
				return true;
	return false;
}
int valueAt(game* board, int i, int j)
{
	/*returns the value at board->a[i][j] if i,j are valid else it returns -1 */
	int n = board->n;
	if (i<0 || j<0 || i >= n || j >= n)
		return -1;
	return board->a[i][j];
}
bool verifyMerge(game* board, int x, int y)
{
	/*verifies if the current piece can perform merge with any of its four neighbours*/
	int value = getPrevFibo(board->a[x][y]);
	int nextValue = getNextFibo(board->a[x][y]);
	int dx[] = { -1, 0, 1, 0 };//flood fill
	int dy[] = { 0, 1, 0, -1 };//flood fill
	for (int i = 0; i<4; i++)
	{
		if (value == valueAt(board, x + dx[i], y + dy[i])||nextValue==valueAt(board,x+dx[i],y+dy[i]))
			return true;
	}
	return false;
}
bool isGameEnded(game* board)
{
	/*verifies if the game ended or not it 
	 *please refer the doc of project to know 
	 *about how the game can be ended for various boards*/
	int n = board->n;
	if (checkValue(board, 2 * (n*n) == 8 ? 21 : 2178309))
		return true;
	if (checkValue(board, 0))
		return false;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (verifyMerge(board, i, j))
				return false;
		}
	}
	return true;
}
void increment(game* board, int movement)
{
	/*no of valide movements can be counted*/
	board->counter += movement;
}
bool isBoardFull(game* board)
{
	/*verifies is the current board is full occupied or not*/
	int n = board->n;
	int limit = n*n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board->a[i][j] == 0)
				limit--;
	return limit == n*n;//if there are no zeros return false;
}
void getNewElementsToBoard(game* board)
{
	/*used to fill a random unoccupied slot of the board*/
	if (isBoardFull(board))
		return;
	int n = board->n;
	int mod = n*n;
	while (true)
	{
		int randomValue = (rand()) % (mod);
		int x = randomValue / n;
		int y = randomValue % n;
		if (board->a[x][y] == 0)
		{
			board->a[x][y] = 1;
			return;
		}
	}
}
void play(game* board)
{
	/*this function works on users command to play the game*/
	char choice;
	int movement = 1;
	while (!isGameEnded(board))
	{
		system("cls");
		showBoard(board);
		choice = getchar();
		fflush(stdin);
		movement = 0;
		save(board);
		if (choice == 'a' || choice == 'A')
		{
			movement=playLeft(board);
			increment(board, movement);
		}
		else if (choice == 's' || choice == 'S')
		{
			movement = playDown(board);
			increment(board, movement);
		}
		else if (choice == 'd' || choice == 'D')
		{
			movement = playRight(board);
			increment(board, movement);
		}
		else if (choice == 'w' || choice == 'W')
		{
			movement = playUp(board);
			increment(board, movement);
		}
		else if (choice == 'q' || choice == 'Q')
		{
			poping(board);
		}
		else if (choice == 'e' || choice == 'E')
		{
			preview(board);
		}
		if (movement == 1)
		{
			getNewElementsToBoard(board);
		}
		pushing(board);
		save(board);
	}
	system("cls");
	showBoard(board);
	int n = board->n;
	if (checkValue(board, 2 * (n*n) == 8 ? 21 : 2178309))
	{
		writeIntoFile(board);
		printf("Great you completed in %d moves :D\n\n\n",board->counter);
	}
	else
	{
		printf("You Lost the Game :(\n\n\n");
	}
	system("pause");
	system("cls");
}
void createGame(int x, int y)
{
	/*this function is used to create the game*/
	game* newGame = create(x);
	system("cls");
	getNewElementsToBoard(newGame);
	getNewElementsToBoard(newGame);
	//system("pause");
	play(newGame);
}
