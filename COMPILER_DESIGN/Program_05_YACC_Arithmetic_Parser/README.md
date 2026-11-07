# Program 05: YACC Arithmetic Parser

## Compilation & Execution
```bash
bison -dy parser.y
flex lexer.l
gcc y.tab.c lex.yy.c -o parser
./parser
```

## Sample Input
`2+3*4`

## Expected Output
```
Parsing Successful! Result = 14
```
