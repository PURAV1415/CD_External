%{
#include <stdio.h>
int line_num = 1;
%}

%%
"int"|"float"|"char"|"if"|"else"|"while"|"return" { printf("Line %d: [KEYWORD   ] %s\n", line_num, yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("Line %d: [IDENTIFIER] %s\n", line_num, yytext); }
[0-9]+(\.[0-9]+)? { printf("Line %d: [NUMBER    ] %s\n", line_num, yytext); }
"=="|"!="|">="|"<="|"+"|"-"|"*"|"/"|"=" { printf("Line %d: [OPERATOR  ] %s\n", line_num, yytext); }
\/\/.* { /* skip single-line comment */ }
\n { line_num++; }
[ \t]+ { /* skip whitespace */ }
. { printf("Line %d: [UNKNOWN   ] %s\n", line_num, yytext); }
%%

int main(int argc, char **argv)
{
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            perror("File opening failed");
            return 1;
        }
        yyin = f;
    }
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
