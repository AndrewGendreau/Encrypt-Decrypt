#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define ASCIIBEGIN 65
#define ASCIIEND 90
#define ASCIILEFTWRAP 26 //constant to wrap around if we have to wrap around the ASCII going left

//node struct
struct listNode 
{
	char currentChar;
	char shiftedChar;
	struct listNode *next;
};

struct listNode *head; //head of the list


void initalize(void);
void insert(char);
struct listNode *getHead(void);
char encryptChar(char charToEncrypt, int key);
struct listNode *removeFromHead(void);
struct listNode *findTail(void);

//initalize list to null
void initalize(void)
{
	head = NULL;
}

//function to insert a character in a node, either we're inserting in the head or the tail
void insert(char charToInsert)
{
	struct listNode *newNode;
	struct listNode *tail;
	
	newNode = malloc(sizeof(struct listNode));
	newNode->currentChar = charToInsert;
	
	if(head == NULL)
	{
		head = newNode;
		tail = NULL;
	}
	else
	{
		tail = findTail();
		tail->next = newNode;
	}
}

//function to return the head of the list
struct listNode *getHead(void)
{
	return head;
}

//function to do the shift
char encryptChar(char charToEncrypt, int key)
{
	int upperCase;
	int result;
	char output;

	upperCase = toupper(charToEncrypt);

	result = upperCase + key;

	if(result > ASCIIEND)
	{
		result = result - ASCIIEND;
		result = ASCIIBEGIN + result;
	}
	else if(result < ASCIIBEGIN)
	{
		result += ASCIILEFTWRAP;
	}

	return result;
}

struct listNode *removeFromHead(void)
{
	struct listNode *oldHead;

	oldHead = head;
	head = head->next;

	return oldHead;
}

struct listNode *findTail(void)
{
	struct listNode *currentNode;

	currentNode = head;

	while(currentNode->next != NULL)
	{
		currentNode = currentNode->next;
	}
	return currentNode;		
}

//function to encrypt the string
void encryptString(int key)
{
	struct listNode *currentNode;

	currentNode = head;

	while(currentNode->next != NULL)
	{
		currentNode->shiftedChar = encryptChar(currentNode->currentChar, key);
		currentNode = currentNode->next;
	}

	currentNode = head;

	while(currentNode->next != NULL)
	{
		printf("%c", currentNode->shiftedChar);
		currentNode = currentNode->next;
	}
	printf("\n");
}
int main()
{
	char testString[] = "Hellz";
	int i = 0;
	int len = 5;

	initalize();

	while(i <= len)
	{
		insert(testString[i]);
		i++;
	}

	findTail();

	encryptString(1);
}