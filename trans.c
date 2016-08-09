#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 500

void encrypt(char *key, char *words)
{
    int kLen = strlen(key);
    int wLen = strlen(words);
	int row, col, value=1;
	int i, j, k=0;
	col = kLen;
	if((wLen%kLen)!=0)
	{
		row = wLen/kLen;
		row++;
	}
	else
	{
		row = wLen/kLen;
	}
	
    char encr[row][col], cipher[row][col];
    for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			encr[i][j] = words[k];
			k++;
		//	printf("%c", encr[i][j]);
		}
	}
	k=1;
	i = 0;
	int currentColumn;
	currentColumn = 0;
	while(key[i] != k)
	{
		i++;
		currentColumn++;
	}

	for(i = 0; i< row; i++)
	{
		printf("%c", encr[i][currentColumn]);
	}

	printf("\n");
	/*for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
		if((key[i]==value) && (value<=kLen))
		{
			cipher[i][j] = encr[i][k];
			printf("%c", cipher[i][j]);
			
		}
		k++;
		value++;
		
	}
	}
*/	
}

void main()
{
	char ciphertext[SIZE], key[10], str[SIZE];
	char *input;
	FILE *fp = fopen("plaintext.txt", "r");
//	FILE *fp1 = fopen("ciphertext.txt", "w");
	if(fp == NULL)
	{
		printf("File doesnt exist");
	}
	while(fgets(str, sizeof(str), fp)!=NULL)
	{
		input = strtok(str, "\0");
	}
	printf("%s", input);
	printf("Enter the key:");
	fgets(key, SIZE, stdin);
	encrypt(key, input);
	//fprintf(fp1, "%s", ciphertext);
	fclose(fp);
//	fclose(fp1);
}	
