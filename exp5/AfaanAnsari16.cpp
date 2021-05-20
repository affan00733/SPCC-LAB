/*
Afaan ansari
2019230064
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
using namespace std;
#define SIZE 40


bool doLR(string s,char non_terminal) {
	char prod[100] = "";
	char beta;
	string production = s;
	
	bool stop = false;
	bool flag = false;
	int li = 0;
	int index = 3;
	bool prev = false;
	char prevprod[100] = "";
	int pp = 0;
	while (true) {

		if (stop == true || index == s.length())
			break;
		if (non_terminal == production[index] && (production[index] >= 'A' && production[index] <= 'Z')) {


			index = index + 1;
			while (true) {
				if (production[index] == '\0' || production[index] == '|') {
					break;
				}
				
				beta = production[index];
				prod[li] = beta;
				li++;
				index += 1;
			}
			if (production[index] != '\0')
				index += 1;
			if (li != 0) {
				
				prod[li] = '\0';
				li = 0;
				if (flag == false) {
					
					
					printf("%c->%c\'", non_terminal, non_terminal);
				}
				
				printf("\n%c\'->%s%c\'|E\n", non_terminal, prod, non_terminal);
				if (prev == true) {
					
					printf("%c->%s%c\'", non_terminal, prevprod, non_terminal);
					pp = 0;
					
				}
			}
			flag = true;
			if (production[index] == '\0') {
				stop = true;
				break;
			}
			li = 0;
			continue;
		}
		else if (flag == true) {

			while (true) {
				if (production[index] == '\0' || production[index] == '|') {
					break;
				}

				beta = production[index];
				prod[li] = beta;
				li++;
				index += 1;
			}
			if (production[index] != '\0')
				index = index + 1;
			if (li != 0) {
				// printf("Grammar without left recursion:\n");
				prod[li] = '\0';
				li = 0;
				
				printf("\n%c->%s%c\'\n", non_terminal, prod, non_terminal);
			}
			if (production[index] == '\0') {
				stop = true;
				break;
			}
			li = 0;
			continue;
		}
		else {

			if (prev == true) {
				prevprod[pp] = non_terminal;
				pp++;
				prevprod[pp] = '`';
				pp++;
				prevprod[pp] = '|';
				pp++;
			}
			while (true) {
				if (production[index] == '\0' || production[index] == '|') {
					break;
				}
				prevprod[pp] = production[index];
				pp++;
				index = index + 1;
			}
		
			prev = true;
			if (index == s.length())
				break;
			index = index + 1;

		}

	}
	if (flag == false)
		return false;
	else return true;
	

}
int main() {
	char non_terminal;
	char beta;


	bool flags[SIZE];
	char st[SIZE][30];
	int n=0;
	printf("Enter the number of productions");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", st[i]);
	}
// 	n = 3;
// 	string st[10];
// 	st[0] = "E->E+T|T";
// 	st[1] = "T->T*F|F";
// 	st[2] = "F->id|(E)";
// 	for(int i=0;i<n;i++){
// 	    printf("\n%s\n",st[i][0]);
// 	}
	printf("\nBefore left reccursion\n");
for (int i = 0; i < n; i++) {
		printf("%s\n", st[i]);
	}
	printf("\nAfter left reccursion\n");
	int i = 0;
	for (; i < n; i++) {
	
		string s = st[i];
		flags[i]= doLR(s, s.at(0));
		
	}
	int k = 0;
	for(int j=0;j<n;j++){
		if (flags[j] == true)
			k++;
	}
	if (k==0)
	{
		printf("Grammar is not left recursive");
	}

}



// A->A'                                                                                                       
// A'->aA'|E                                                                                                   
// A->BaA'                                                                                                     
// A->cA'                                                                                                      
// B->B'                                                                                                       
// B'->bB'|E                                                                                                   
                                                                                                            
// B->AbB'                                                                                                     
                                                                                                            
// B->dB'