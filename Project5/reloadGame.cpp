#include<stdio.h>
#include<stdlib.h>
#include "making.h"
#pragma warning(disable:4996)
game* readPrevData()
{
	game* temp = (game*)malloc(sizeof(game));
	FILE* fp = fopen("savedGame.txt", "r");
	int n;
	fscanf(fp, "%d", &n);
	if (n == 2 || n == 4)
	{
		temp->n = n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fscanf(fp, "%d", &(temp->a[i][j]));
			}
		}
	}
	else
		return NULL;
	fscanf(fp,"%s%d", &(temp->name),&(temp->counter));
	return temp;
}
bool isFibonacci(int x)
{
	int fibonacci[] = {
		0, 1, 1, 2, 3, 5, 8, 13,
		21, 34, 55, 89, 144,
		233, 377, 610, 987, 1597,
		2584, 4181, 6765, 10946,
		17711, 28657, 46368, 75025,
		121393, 196418, 317811,
		514229, 832040, 1346269,
		2178309, 3524578
	};
	for (int i = 0; i < 33; i++)
	{
		if (x == fibonacci[i])
			return true;
	}
	return false;
}
bool verifying(game* board)
{
	if (board == NULL||board->n>4||board->n<2||board->n==3||board->counter<0||board->name==NULL)
		return false;
	int n = board->n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (!isFibonacci(board->a[i][j]))
			{
				return false;
			}
		}
	}
	return true;
}
void reload()
{
	game* board = readPrevData();
	if (board == NULL || !verifying(board))
	{
		printf("error no saved game found or someone changed the content in the file ;)\n");
	}
	play(board);
}