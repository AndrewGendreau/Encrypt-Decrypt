#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 500


void allocateArray(char *plaintext, char *key)
{
	int numOfColumns;
	int numOfRows;
	int plainKeyModulus;
	int i;
	int j;
	int k;
	int keyDigit;
	int keyLoopControl;
	int arrayCol;

	arrayCol = 0;
	k = 0;
	keyLoopControl = 0;

	plainKeyModulus = strlen(plaintext) % strlen(key);

	numOfColumns = strlen(key)-1;

	numOfRows = strlen(plaintext) / strlen(key);

	if(plainKeyModulus != 0)
	{
		numOfRows += plainKeyModulus;
	}

	char array[numOfRows][numOfColumns];

	for(i = 0; i < numOfRows; i++)
	{
		for(j = 0; j < numOfColumns; j++)
		{
			if(k > strlen(plaintext))
			{
				array[i][j] = ' ';
			}
			else
			{
				array[i][j] = plaintext[k];
			}
			k++;
		}
	}

	for(i = 0; i < numOfRows; i++)
	{
		for(j = 0; j < numOfColumns; j++)
		{
			printf("%c", array[i][j]);
		}
		printf("\n");
	}

	for(keyDigit = 1; keyDigit < strlen(key); keyDigit++)
	{
		keyLoopControl = 0;
		while((key[keyLoopControl] - '0') !=  keyDigit)
		{
			keyLoopControl++;
			arrayCol++;
		}

		for(i = 0; i < numOfRows; i++)
		{
			printf("%c", array[i][arrayCol]);
		}
		arrayCol = 0;
		printf(" ");
	}
	printf("\n");
}
