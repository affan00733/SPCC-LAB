
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int lc = 0;
int tc = 0;
int tokenLex = 0;

int i;
int st1 = 0;
int st2 = 0;

char c;
FILE *f;
char lexeme[100];
int count = 0;
struct tokenLex
{
    int id;
    char lexeme[100];
    char tn[100];
    struct tokenLex *n;
};

struct tokenLex *symbolTable[100];
// struct tokenLex symbolTable[100];

struct tokenLex *ct(int ID, char l[100], char name[100])
{
    struct tokenLex *newT = (struct tokenLex *)malloc(sizeof(struct tokenLex));
    newT->id = ID;
    strcpy(newT->lexeme, l);
    strcpy(newT->tn, name);
    return newT;
}

int searchtokenLex(char lexeme[100])
{
    for (int i = 0; i < tc; i++)
    {
        if (strcmp(symbolTable[i]->lexeme, lexeme) == 0)
        {
            return i;
        }
    }
    return -1;
}

int notfound()
{
    switch (st2)
    {
    case 0:
        st2 = 30;
        break;
    case 30:
        st2 = 12;
        break;
    case 12:
        st2 = 22;
        break;
    case 22:
        st2 = 25;
        break;
    case 25:
        st2 = 28;
        break;
    case 28:
        st2 = 29;
        break;

    default:
        break;
    }
    return st2;
}

int checkDelim(char a)
{
    if (a == '}' || a == '[' || a == ']' || a == '.' || a == ' ' || a == '\t' || a == '\n' || a == ';' || a == ',' || a == '(' || a == ')' || a == '{')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int checkOper(char a)
{
    if (a == '%' || a == '&' || a == '=' || a == '|' || a == '+' || a == '-' || a == '*' || a == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    f = fopen("ex.c", "r");
    c = (char)fgetc(f);
    while (c != EOF)
    {
        switch (st1)
        {
        case 0:
            if (c == '<')
            {
                st1 = 1;
                lexeme[count++] = c;
            }
            else if (c == '=')
            {
                st1 = 5;
                lexeme[count++] = c;
            }
            else if (c == '>')
            {
                st1 = 6;
                lexeme[count++] = c;
            }
            else
            {
                st1 = notfound();
            }
            break;

        case 1:
            c = (char)fgetc(f);
            if (c == '=')
            {
                st1 = 2;
                lexeme[count++] = c;
            }

            else if (c == '>')
            {
                st1 = 3;
                lexeme[count++] = c;
            }

            else
            {
                st1 = 4;
                lexeme[count++] = c;
            }

            break;

        case 2:
            lexeme[count++] = '\0';
            i = searchtokenLex(lexeme);
            if (i == -1)
            {
                struct tokenLex *newT = ct(tokenLex++, lexeme, "relop");
                symbolTable[tc++] = newT;
                printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
            }
            else
            {
                printf("\n%d. < %s, %d>\n", lc++, "relop", i);
            }
            c = (char)fgetc(f);
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;

            break;

        case 3:
            lexeme[count++] = '\0';
            i = searchtokenLex(lexeme);
            if (i == -1)
            {
                struct tokenLex *newT = ct(tokenLex++, lexeme, "relop");
                symbolTable[tc++] = newT;
                printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
            }
            else
            {
                printf("\n%d. < %s, %d>\n", lc++, "relop", i);
            }
            c = (char)fgetc(f);
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;

            break;

        case 4:
            lexeme[count++] = '\0';
            i = searchtokenLex(lexeme);
            if (i == -1)
            {
                struct tokenLex *newT = ct(tokenLex++, lexeme, "relop");
                symbolTable[tc++] = newT;
                printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
            }
            else
            {
                printf("\n%d. < %s, %d>\n", lc++, "relop", i);
            }
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;

            break;

        case 5:
            c = (char)fgetc(f);
            if (c == '=')
            {
                st1 = 63;
                lexeme[count++] = c;
            }
            else
            {
                lexeme[count++] = '\0';
                i = searchtokenLex(lexeme);
                if (i == -1)
                {
                    struct tokenLex *newT = ct(tokenLex++, lexeme, "relop");
                    symbolTable[tc++] = newT;
                    printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
                }
                else
                {
                    printf("\n%d. < %s, %d>\n", lc++, "relop", i);
                }
                c = (char)fgetc(f);
                strcpy(lexeme, "");
                count = 0;
                st2 = 0;
                st1 = 0;

                break;
            }
        case 63:
            lexeme[count++] = '\0';
            i = searchtokenLex(lexeme);
            if (i == -1)
            {
                struct tokenLex *newT = ct(tokenLex++, lexeme, "opeartor");
                symbolTable[tc++] = newT;
                printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
            }
            else
            {
                printf("\n%d. < %s, %d>\n", lc++, "operator", i);
            }
            c = (char)fgetc(f);
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;

            break;

        case 6:
            c = (char)fgetc(f);
            if (c == '=')
            {
                st1 = 7;
                lexeme[count++] = c;
            }
            else
            {
                st1 = 8;
                lexeme[count++] = c;
            }
            break;

        case 7:
            lexeme[count++] = '\0';
            i = searchtokenLex(lexeme);
            if (i == -1)
            {
                struct tokenLex *newT = ct(tokenLex++, lexeme, "relop");
                symbolTable[tc++] = newT;
                printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
            }
            else
            {
                printf("\n%d. < %s, %d>\n", lc++, "relop", i);
            }
            c = (char)fgetc(f);
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;

            break;

        case 8:
            lexeme[count++] = '\0';
            i = searchtokenLex(lexeme);
            if (i == -1)
            {
                struct tokenLex *newT = ct(tokenLex++, lexeme, "relop");
                symbolTable[tc++] = newT;
                printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
            }
            else
            {
                printf("\n%d. < %s, %d>\n", lc++, "relop", i);
            }
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;

            break;

        case 30:
            if (c == 'i')
            {
                lexeme[count++] = c;
                st1 = 31;
            }
            else if (c == 'w')
            {
                lexeme[count++] = c;
                st1 = 35;
            }
            else if (c == 'f')
            {
                lexeme[count++] = c;
                st1 = 40;
            }
            else if (c == 'c')
            {
                lexeme[count++] = c;
                st1 = 43;
            }
            else if (c == 'b')
            {
                lexeme[count++] = c;
                st1 = 51;
            }
            else if (c == 'r')
            {
                lexeme[count++] = c;
                st1 = 56;
            }
            else
                st1 = 9;
            break;

        case 31:
            c = (char)fgetc(f);
            if (c == 'f')
            {
                lexeme[count++] = c;
                st1 = 32;
            }
            else if (c == 'n')
            {
                lexeme[count++] = c;
                st1 = 33;
            }
            else
                st1 = 9;
            break;

        case 32:
            c = (char)fgetc(f);
            if (isalpha(c))
                st1 = 9;
            else if (isdigit(c))
                st1 = 62;
            else
            {
                lexeme[count++] = '\0';
                i = searchtokenLex(lexeme);
                if (i == -1)
                {
                    struct tokenLex *newT = ct(tokenLex++, lexeme, "keyword");
                    symbolTable[tc++] = newT;
                    printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
                }
                else
                {
                    printf("\n%d. < %s, %d>\n", lc++, "keyword", i);
                }
                strcpy(lexeme, "");
                count = 0;
                st2 = 0;
                st1 = 0;
            }
            break;

        case 33:
            c = (char)fgetc(f);
            if (c == 't')
            {
                lexeme[count++] = c;
                st1 = 32;
            }
            else
                st1 = 9;
            break;

        case 35:
            c = (char)fgetc(f);
            if (c == 'h')
            {
                lexeme[count++] = c;
                st1 = 36;
            }
            else
                st1 = 9;
            break;

        case 36:
            c = (char)fgetc(f);
            if (c == 'i')
            {
                lexeme[count++] = c;
                st1 = 37;
            }
            else
                st1 = 9;
            break;

        case 37:
            c = (char)fgetc(f);
            if (c == 'l')
            {
                lexeme[count++] = c;
                st1 = 38;
            }
            else
                st1 = 9;
            break;

        case 38:
            c = (char)fgetc(f);
            if (c == 'e')
            {
                lexeme[count++] = c;
                st1 = 32;
            }
            else
                st1 = 9;
            break;

        case 40:
            c = (char)fgetc(f);
            if (c == 'o')
            {
                lexeme[count++] = c;
                st1 = 41;
            }
            else
                st1 = 9;
            break;

        case 41:
            c = (char)fgetc(f);
            if (c == 'r')
            {
                lexeme[count++] = c;
                st1 = 32;
            }
            else
                st1 = 9;
            break;

        case 43:
            c = (char)fgetc(f);
            if (c == 'o')
            {
                lexeme[count++] = c;
                st1 = 44;
            }
            else
                st1 = 9;
            break;

        case 44:
            c = (char)fgetc(f);
            if (c == 'n')
            {
                lexeme[count++] = c;
                st1 = 45;
            }
            else
                st1 = 9;
            break;

        case 45:
            c = (char)fgetc(f);
            if (c == 't')
            {
                lexeme[count++] = c;
                st1 = 46;
            }
            else
                st1 = 9;
            break;

        case 46:
            c = (char)fgetc(f);
            if (c == 'i')
            {
                lexeme[count++] = c;
                st1 = 47;
            }
            else
                st1 = 9;
            break;

        case 47:
            c = (char)fgetc(f);
            if (c == 'n')
            {
                lexeme[count++] = c;
                st1 = 48;
            }
            else
                st1 = 9;
            break;

        case 48:
            c = (char)fgetc(f);
            if (c == 'u')
            {
                lexeme[count++] = c;
                st1 = 49;
            }
            else
                st1 = 9;
            break;

        case 49:
            c = (char)fgetc(f);
            if (c == 'e')
            {
                lexeme[count++] = c;
                st1 = 32;
            }
            else
                st1 = 9;
            break;

        case 51:
            c = (char)fgetc(f);
            if (c == 'r')
            {
                lexeme[count++] = c;
                st1 = 52;
            }
            else
                st1 = 9;
            break;

        case 52:
            c = (char)fgetc(f);
            if (c == 'e')
            {
                lexeme[count++] = c;
                st1 = 53;
            }
            else
                st1 = 9;
            break;

        case 53:
            c = (char)fgetc(f);
            if (c == 'a')
            {
                lexeme[count++] = c;
                st1 = 54;
            }
            else
                st1 = 9;
            break;

        case 54:
            c = (char)fgetc(f);
            if (c == 'k')
            {
                lexeme[count++] = c;
                st1 = 32;
            }
            else
                st1 = 9;
            break;

        case 56:
            c = (char)fgetc(f);
            if (c == 'e')
            {
                lexeme[count++] = c;
                st1 = 57;
            }
            else
                st1 = 9;
            break;

        case 57:
            c = (char)fgetc(f);
            if (c == 't')
            {
                lexeme[count++] = c;
                st1 = 58;
            }
            else
                st1 = 9;
            break;

        case 58:
            c = (char)fgetc(f);
            if (c == 'u')
            {
                lexeme[count++] = c;
                st1 = 59;
            }
            else
                st1 = 9;
            break;

        case 59:
            c = (char)fgetc(f);
            if (c == 'r')
            {
                lexeme[count++] = c;
                st1 = 60;
            }
            else
                st1 = 9;
            break;

        case 60:
            c = (char)fgetc(f);
            if (c == 'n')
            {
                lexeme[count++] = c;
                st1 = 32;
            }
            else
                st1 = 9;
            break;

        case 62:
            st1 = 10;
            lexeme[count++] = c;
            break;

        case 9:
            if (isalpha(c))
            {
                st1 = 10;
                lexeme[count++] = c;
            }
            else
            {
                st1 = notfound();
            }
            break;

        case 10:
            c = (char)fgetc(f);
            if (isalpha(c))
            {
                st1 = 10;
                lexeme[count++] = c;
            }
            else if (isdigit(c))
            {
                st1 = 10;
                lexeme[count++] = c;
            }
            else
                st1 = 11;
            break;

        case 11:
            lexeme[count++] = '\0';
            i = searchtokenLex(lexeme);
            if (i == -1)
            {
                struct tokenLex *newT = ct(tokenLex++, lexeme, "identifier");
                symbolTable[tc++] = newT;
                printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
            }
            else
            {
                printf("\n%d. < %s, %d>\n", lc++, "identifier", i);
            }
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;

            break;

        case 12:
            if (isdigit(c))
            {
                st1 = 13;
                lexeme[count++] = c;
            }
            else
            {
                st1 = notfound();
            }
            break;

        case 13:
            c = (char)fgetc(f);
            if (isdigit(c))
            {
                st1 = 13;
                lexeme[count++] = c;
            }
            else if (c == '.')
            {
                st1 = 14;
                lexeme[count++] = c;
            }
            else if (c == 'E')
            {
                st1 = 16;
                lexeme[count++] = c;
            }
            else
                st1 = 20;
            break;

        case 14:
            c = (char)fgetc(f);
            if (isdigit(c))
            {
                st1 = 15;
                lexeme[count++] = c;
            }

            break;

        case 15:
            c = (char)fgetc(f);
            if (isdigit(c))
            {
                st1 = 15;
                lexeme[count++] = c;
            }
            else if (c == 'E')
            {
                st1 = 16;
                lexeme[count++] = c;
            }
            else
                st1 = 21;
            break;

        case 16:
            c = (char)fgetc(f);
            if (isdigit(c))
            {
                st1 = 18;
                lexeme[count++] = c;
            }
            else if (c == '+' || c == '-')
            {
                st1 = 17;
                lexeme[count++] = c;
            }

            break;

        case 17:
            c = (char)fgetc(f);
            if (isdigit(c))
            {
                st1 = 18;
                lexeme[count++] = c;
            }
            break;

        case 18:
            c = (char)fgetc(f);
            if (isdigit(c))
            {
                st1 = 18;
                lexeme[count++] = c;
            }
            else
                st1 = 19;
            break;

        case 19:
            lexeme[count++] = '\0';
            i = searchtokenLex(lexeme);
            if (i == -1)
            {
                struct tokenLex *newT = ct(tokenLex++, lexeme, "number");
                symbolTable[tc++] = newT;
                printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
            }
            else
            {
                printf("\n%d. < %s, %d>\n", lc++, "number", i);
            }
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;
            break;

        case 20:
            lexeme[count++] = '\0';
            i = searchtokenLex(lexeme);
            if (i == -1)
            {
                struct tokenLex *newT = ct(tokenLex++, lexeme, "number");
                symbolTable[tc++] = newT;
                printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
            }
            else
            {
                printf("\n%d. < %s, %d>\n", lc++, "number", i);
            }
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;
            break;

        case 21:
            lexeme[count++] = '\0';
            i = searchtokenLex(lexeme);
            if (i == -1)
            {
                struct tokenLex *newT = ct(tokenLex++, lexeme, "number");
                symbolTable[tc++] = newT;
                printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
            }
            else
            {
                printf("\n%d. < %s, %d>\n", lc++, "number", i);
            }
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;
            break;

        case 22:
            if (checkDelim(c))
            {
                st1 = 24;
                lexeme[count++] = c;
            }
            else
            {
                st1 = notfound();
            }
            break;

        case 24:
            lexeme[count++] = '\0';
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;
            c = (char)fgetc(f);
            break;

        case 25:
            if (c == '\"')
            {
                st1 = 26;
                lexeme[count++] = c;
            }
            else
            {
                st1 = notfound();
            }
            break;
        case 26:
            c = (char)fgetc(f);
            if (c == '\"')
            {
                st1 = 27;
                lexeme[count++] = c;
            }
            else
            {
                st1 = 26;
                lexeme[count++] = c;
            }
            break;

        case 27:
            lexeme[count++] = '\0';
            i = searchtokenLex(lexeme);
            if (i == -1)
            {
                struct tokenLex *newT = ct(tokenLex++, lexeme, "string");
                symbolTable[tc++] = newT;
                printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
            }
            else
            {
                printf("\n%d. < %s, %d>\n", lc++, "string", i);
            }
            c = (char)fgetc(f);
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;
            break;

        case 28:
            if (checkOper(c))
            {
                lexeme[count++] = c;
                st1 = 29;
            }
            else
                st1 = notfound();
            break;

        case 29:
            lexeme[count++] = '\0';
            i = searchtokenLex(lexeme);
            if (i == -1)
            {
                struct tokenLex *newT = ct(tokenLex++, lexeme, "opeartor");
                symbolTable[tc++] = newT;
                printf("\n%d. < %s, %d>\n", lc++, newT->tn, newT->id);
            }
            else
            {
                printf("\n%d. < %s, %d>\n", lc++, "operator", i);
            }
            c = (char)fgetc(f);
            strcpy(lexeme, "");
            count = 0;
            st2 = 0;
            st1 = 0;
            break;

        default:
            break;
        }
    }
    printf("\n\nSymbol Table\n");
    printf("\n\nId\t\ttoken\t\tLexeme\n");
    for (int i = 0; i < tc; i++)
    {
        printf("\n%d\t\t%s\t\t%s\n", symbolTable[i]->id, symbolTable[i]->tn, symbolTable[i]->lexeme);
    }
}
