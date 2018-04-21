#include<stdio.h>
#include<stdlib.h>
#include "making.h"
#pragma warning(disable:4996)
game stacks[700];
int n = 0;
void copyUp(game* board)
{
	int n = board->counter;
	stacks[n].counter = board->counter;
	stacks[n].n = board->n;
	for (int i = 0; board->name[i]; i++)
	{
		stacks[n].name[i] = board->name[i];
		stacks[n].name[i + 1] = '\0';
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			stacks[n].a[i][j] = board->a[i][j];
		}
	}
}
void pushing(game* board)
{
	if (n == 699)
		return;
	else
	{
		copyUp(board);
		n++;
	}
}
void timeTravel(game* board)
{
	int n = board->counter;
	board->counter = stacks[n - 1].counter;
	//board->counter = n - 1;
	for (int i = 0; stacks[n-1].name[i]; i++)
	{
		board->name[i] = stacks[n-1].name[i];
		board->name[i + 1] = '\0';
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			board->a[i][j]=stacks[n-1].a[i][j];
		}
	}
}
void poping(game* board)
{
	if (board->counter == 0)
		return;
	else
	{
		timeTravel(board);
		n--;
	}
}
void clearing()
{
	n = 0;
}