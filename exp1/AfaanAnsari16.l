%{

%}
%option noyywrap
%%
#.* {printf("\n\t%s is a Header",yytext);}
int |
float |
char |
double |
while |
for |
do |
if |
break |
continue |
void |
switch |
case |
long |
struct |
const |
typedef |
return |
else |
goto  {printf("\n\t%s is a Keyword",yytext);}
\{ {printf("\n\tBlock Starts");}
\} {printf("\n\tBlock Ends");}
[a-zA-Z]* {printf("\n\t%s is a Identifier",yytext);}
\".*\" {printf("\n\t%s is a String",yytext);}
[0-9]+ {printf("\n\t%s is a Number",yytext);}
= {printf("\n\t%s is a Assignment Operator",yytext);}
\<= |
\>= |
\< |
== |
\> {printf("\n\t%s is a Relational Operator",yytext);}
\%s |
\%d |
\%x {printf("\n\t%s is a Placeholder",yytext);}
\; |
\. |
\, {printf("\n\t%s is a Delimiter",yytext);}
\n | 
\t {ECHO ;}
\( | 
\) |
\[ |
\] {printf("\n\t%s is a Bracket",yytext);}

\>\>\>\>.*\<\<\<\< {printf("\n\t Greater and less");}

%%

int main(void){
    yyin = fopen("ex.c","r");
    yylex();
    return 0;
}
