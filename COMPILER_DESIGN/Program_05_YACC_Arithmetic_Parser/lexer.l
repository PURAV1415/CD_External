%{
#include "y.tab.h"
#include <stdlib.h>
extern int yylval;
%}

%%
[0-9]+    { yylval = atoi(yytext); return NUMBER; }
[ \t]     ;                        /* ignore spaces */
\n        { return '\n'; }
.         { return yytext[0]; }    /* + - * / ( ) and anything else */
%%

int yywrap() { return 1; }
