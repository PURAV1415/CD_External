%{
#include <stdio.h>
#include <stdlib.h>
int  yylex(void);
void yyerror(const char *s);
%}

%token NUMBER
%left '+' '-'          /* lower precedence, left-associative  */
%left '*' '/'          /* higher precedence, left-associative */

%%
stmt : expr '\n'       { printf("Parsing Successful! Result = %d\\n", $1); exit(0); }
     ;

expr : expr '+' expr   { $$ = $1 + $3; }
     | expr '-' expr   { $$ = $1 - $3; }
     | expr '*' expr   { $$ = $1 * $3; }
     | expr '/' expr   { if ($3 == 0) {
                           yyerror("Execution Error: Division by Zero!");
                           exit(1);
                       }
                       $$ = $1 / $3; }
     | '(' expr ')'    { $$ = $2; }
     | NUMBER          { $$ = $1; }
     ;
%%

void yyerror(const char *s)
{
    fprintf(stderr, "Syntax Error: %s\\n", s);
}

int main()
{
    printf("Enter Expression:\\n");
    return yyparse();
}
