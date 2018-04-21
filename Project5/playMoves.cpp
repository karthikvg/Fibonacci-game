#include<stdio.h>
#include<stdlib.h>
#include "making.h"
#pragma warning(disable:4996)
int upFlush(game* board);
int downFlush(game* board);
int leftFlush(game* board);
int rightFlush(game* board);
int getPrevFibo(int value)
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
	for (int i = 2; i<35; i++)
	{
		if (value == fibonacci[i])
			return fibonacci[i - 1];
	}
	return 0;
}
int getNextFibo(int value)
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
	for (int i = 2; i<35; i++)
	{
		if (value == fibonacci[i])
			return fibonacci[i + 1];
	}
	return 0;
}
int playLeft(game* board)
{
	int valid = 0;
	int n = board->n;
	valid=leftFlush(board); leftFlush(board); leftFlush(board); leftFlush(board);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (board->a[i][j] != 0)
			{
				if (board->a[i][j] == getPrevFibo(board->a[i][j + 1]) || board->a[i][j] == getNextFibo(board->a[i][j + 1]))
				{
					board->a[i][j] += board->a[i][j + 1];
					board->a[i][j + 1] = 0;
					valid = 1;
				}
			}
		}
	}
	leftFlush(board); leftFlush(board); leftFlush(board); leftFlush(board);
	return valid;
}
int playRight(game* board)
{

	int valid = 0;
	int n = board->n;
	valid=rightFlush(board); rightFlush(board); rightFlush(board); rightFlush(board);
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > 0; j--)
		{
			if (board->a[i][j] != 0)
			{
				if (board->a[i][j] == getPrevFibo(board->a[i][j - 1]) || board->a[i][j] == getNextFibo(board->a[i][j - 1]))
				{
					board->a[i][j] += board->a[i][j - 1];
					board->a[i][j - 1] = 0;
					valid = 1;
				}
			}
		}
	}
	rightFlush(board); rightFlush(board); rightFlush(board); rightFlush(board);
	return valid;
}
int playUp(game* board)
{
	int valid = 0;
	int n = board->n;
	valid=upFlush(board); upFlush(board);	upFlush(board); upFlush(board);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board->a[i][j] != 0)
			{
				if (board->a[i][j] == getPrevFibo(board->a[i + 1][j]) || board->a[i][j] == getNextFibo(board->a[i + 1][j]))
				{
					board->a[i][j] += board->a[i + 1][j];
					board->a[i + 1][j] = 0;
					valid = 1;
				}
			}
		}
	}
	upFlush(board); upFlush(board);	upFlush(board); upFlush(board);
	return valid;
}
int playDown(game* board)
{
	int valid = 0;
	int n = board->n;
	valid=downFlush(board); downFlush(board); downFlush(board); downFlush(board);
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (board->a[i][j] != 0)
			{
				if (board->a[i][j] == getPrevFibo(board->a[i -1][j]) || board->a[i][j] == getNextFibo(board->a[i -1][j]))
				{
					board->a[i-1][j] += board->a[i][j];
					board->a[i][j] = 0;
					valid = 1;
				}
			}
		}
	}
	downFlush(board); downFlush(board); downFlush(board); downFlush(board);
	return valid;
}
int upFlush(game* board)
{
	int valid = 0;
	int n = board->n;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n;j++)
		if (board->a[i][j] == 0&&board->a[i+1][j]!=0)
		{
			board->a[i][j] = board->a[i+1][j];
			board->a[i+1][j] = 0;
			valid = 1;
		}
	}
	return valid;
}
int downFlush(game* board)
{
	int valid = 0;
	int n = board->n;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board->a[i + 1][j] == 0&&board->a[i][j]!=0)
			{
				board->a[i + 1][j] = board->a[i][j];
				board->a[i][j] = 0;
				valid = 1;
			}
		}
	}
	return valid;
}
int rightFlush(game* board)
{
	int valid = 0;
	int n = board->n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (board->a[i][j+1] == 0&&board->a[i][j]!=0)
			{
				board->a[i][j+1] = board->a[i][j];
				board->a[i][j] = 0;
				valid = 1;
			}
		}
	}
	return valid;
}
int leftFlush(game* board)
{
	int valid = 0;
	int n = board->n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (board->a[i][j] == 0&&board->a[i][j+1]!=0)
			{
				board->a[i][j] = board->a[i][j + 1];
				board->a[i][j + 1] = 0;
				valid = 1;
			}
		}
	}
	return valid;
}