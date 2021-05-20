/*
Afaan ansari
2019230064
SPCC
6A
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void LLparser(char *);

int top = 0;
//len of terminal and non-terminal
int t = 6, nt = 3;
//Stack initialization
char STACK[100];
//Non terminals
char NT[100] = {'D', 'L', 'T'};
// terminals
char T[100] = {'i', ';', ',', ':', 'n', 'r'};
//Productions
char G[100][100] = {
	{'D', '-', '>', 'i', 'L', ';'},
	{'L', '-', '>', ',', 'i', 'L'},
	{'L', '-', '>', ':', 'T'},
	{'T', '-', '>', 'n'},
	{'T', '-', '>', 'r'}};
//Parsing table
int LL1[100][100] = {
	{1, 0, 0, 0, 0, 0, 0},
	{0, 0, 2, 3, 0, 0, 0},
	{0, 0, 0, 0, 4, 5, 0}};

void main()
{
	int i, j;
	char STR[100];
	//printing grammar , non-terminal , terminal , productions
	printf("\nGrammar");
	printf("\nStarting symbol is: %c", G[0][0]);
	printf("\nNon-terminal symbol is: ");
	for (i = 0; i < 3; i++)
		printf("%c  ", NT[i]);
	printf("\nTerminal symbol is: ");
	for (i = 0; i < 6; i++)
		printf("%c  ", T[i]);
	printf("\nProduction rules: ");
	for (i = 0; i < 5; i++)
		printf("%s  ", G[i]);
	printf("\n");

	T[t++] = '$';
	T[t] = '\0';
	//printing parsing table
	for (int j = 0; j < t; j++)
	{
		printf("\t\t%c", T[j]);
	}
	printf("\n");
	for (int i = 0; i < nt; i++)
	{
		printf("%c\t|\t", NT[i]);
		for (int j = 0; j < t; j++)
		{
			if (LL1[i][j] != 0)
				printf("%s\t\t", G[LL1[i][j] - 1]);
			else
				printf("%c\t\t", '_');
		}
		printf("\n\n");
	}
	printf("\n");
	//taking input string
	printf("Enter string for parsing: ");
	scanf("%s", STR);
	LLparser(STR);
}

void LLparser(char *STR)
{
	int i = 0, j, pos, pos1, n, k;

	STR[strlen(STR)] = '$';
	STACK[top++] = '$';
	STACK[top] = G[0][0];

	//printing stack , string , action that is taken shifted or reduced
	printf("STACK\t\t\tINPUT\t\t\tACTION\n\n");

	i = 0;
	while (STACK[top] != '$')
	{
		//printing stack 
		for (j = 0; STACK[j] != '\0'; j++)
			printf("%c", STACK[j]);
		printf("\t\t");
		//printing string
		for (j = i; STR[j] != '\0'; j++)
			printf("%c", STR[j]);

		if (STR[i] == STACK[top])
		{
			//we have find the operator same on string and stack -- Reduction is performed i.e is pop operation from stack
			printf("\t\tReduced: %c", STACK[top]);
			STACK[top] = '\0';
			top = top - 1;
			i = i + 1;
		}
		else
		{
			//checking stack to non-terminal
			for (j = 0; j < nt; j++)
			{
				if (STACK[top] == NT[j])
				{
					pos = j;
					break;
				}
			}
			//checking string to terminal
			for (j = 0; j < t; j++)
			{
				if (STR[i] == T[j])
				{
					pos1 = j;
					break;
				}
			}
			//from LL1 array i.e is the indexing of the parsing table getting the position of the element that is to be shifted by taking the stack's element position and input string position
			n = LL1[pos][pos1];

			for (j = 3; G[n - 1][j] != '\0'; j++)
				k = j;
			// printf("%d ",k);
			for (j = k; j > 2; j--)
				// Action replacing symbol with it's production but production from right to left
				STACK[top++] = G[n - 1][j];
			top--;

			printf("\t\tShift: %s", G[n - 1]);
		}
		printf("\n");
	}
	//printing stack 
	for (j = 0; STACK[j] != '\0'; j++)
		printf("%c", STACK[j]);
	printf("\t\t");
	//printing string 
	for (j = i; STR[j] != '\0'; j++)
		printf("%c", STR[j]);

	printf("\n");
	//string accepted succesfully
	if (STACK[top] == '$' && STR[i] == '$')
		printf("\nParsing successfully\n");
	else 
		printf("\n Unsuccessful\n");
}


// i,i,i,i,i,i,i,i:r;