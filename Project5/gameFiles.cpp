#include<stdio.h>
#include<stdlib.h>
#include "making.h"
#pragma warning(disable:4996)
struct players
{
	char* name;
	char* size;
	int moves;
};
void save(game* user)
{
	FILE* fp = fopen("savedGame.txt", "w+");
	int n = user->n;
	fprintf(fp,"%d\n", user->n);
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			fprintf(fp,"%d ", user->a[i][j]);
		fprintf(fp,"\n");
	}
	fprintf(fp,"%s %d\n", user->name, user->counter);
	fclose(fp);
}
void writeIntoFile(game* user)
{
	FILE* fp = fopen("LeaderBoard.txt", "a+");
	fprintf(fp,"\n%s %dX%d %d", user->name, user->n, user->n, user->counter);
	fclose(fp);
}
void swapCounter(int* counter1,int* counter2)
{
	int temp = *counter1;
	*counter1 = *counter2;
	*counter2 = temp;
}
void swapStrings(char* size1,char* size2)
{
	char temp[100];
	int i;
	for (i = 0; size1[i]; i++)
	{
		temp[i] = size1[i];
	}
	temp[i] = '\0';
	for (i = 0; size2[i]; i++)
	{
		size1[i] = size2[i];
	}
	size1[i] = '\0';
	for (i = 0; temp[i]; i++)
	{
		size2[i] = temp[i];
	}
	size2[i] = '\0';
}
void showLeaderBoard()
{
	printf("here it is\n");
	FILE* fp = fopen("LeaderBoard.txt", "r");
	char name[100][100], boardSize[100][30];
	int counter[100];
	int i = 0;
	while (fscanf(fp, "%s%s%d", name[i], boardSize[i], &counter[i])==3)
	{
		//printf("%s %s %d\n", name[i], boardSize[i], counter[i]);
		i++;
	}
	printf("Here is your leaderboard\n");
	int n = i;
	for (i = 0; i < n; i++)
	{
		for (int j =i+1; j < n; j++)
		{
			if (counter[i]>counter[j])
			{
				swapCounter(&counter[i], &counter[j]);
				swapStrings(boardSize[i], boardSize[j]);
				swapStrings(name[i],name[j]);
			}
		}
		printf("%s %s %d\n", name[i], boardSize[i], counter[i]);
	}
	fclose(fp);
}