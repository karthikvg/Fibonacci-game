#include<stdio.h>
#include<stdlib.h>
#include "making.h"
#pragma warning(disable:4996)
void playGame()
{
	/*this function givens an option to choose the board dimensions*/
	char ch;
	while (true)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\t\t\t\t1.2X2 Game\n\n\t\t\t\t2.4X4 Game\n");
		ch = getchar();
		fflush(stdin);
		if (ch == '1')
		{
			system("cls");
			createGame(2, 2);
			break;
		}
		else if (ch == '2')
		{
			system("cls");
			createGame(4, 4);
			break;
		}
	}
}
void rePlay()
{
	/*reloads the last saved game*/
	system("cls");
	reload();
	//loadGame();
	//system("pause");
}
void LeaderBoard()
{
	/*displays the leader board by calling showLeaderBoard*/
	system("cls");
	//getchar();
	showLeaderBoard();
	system("pause");
}
int main()
{
	/*initial page on the console*/
	while (1)
	{
		char ch;
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t\t\t\t1.PlayGame\n\n\t\t\t\t\t\t\t2.RePlay\n\n\t\t\t\t\t\t\t3.ShowLeaderBoard\n\n\t\t\t\t\t\t\t0.exit\n\n\n");
		ch = getchar();
		fflush(stdin);
		if (ch == '1')
		{
			playGame();
		}
		else if (ch == '2')
		{
			rePlay();
		}
		else if (ch == '3')
		{
			LeaderBoard();
		}
		else if (ch == '0')
			break;
	}
	return 0;
}
