%{
#include <stdio.h>
int yywrap(void) { return 1; }
%}

%%


[ \t\n]   {  /* Ignore spaces, tabs, and newlines */ }
int     { printf("Keyword: int\n"); }
if|for|while|return { printf("Keyword: %s\n", yytext);}
[0-9]+  { printf("Number: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier: %s\n", yytext); }
[+\-*/=] { printf("Operator: %s\n", yytext); }
";"     { printf("Semicolon: ;\n"); }
.       { printf("Unknown character: %s\n", yytext); }



%%

int main() {
    yylex();
    return 0;
}



