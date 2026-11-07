# Program 01: LEX Token Recognizer

## Compilation & Execution
```bash
flex scanner.l
gcc lex.yy.c -o scanner
./scanner
```

## Sample Input
```c
int x = 10;
float y = x + 2.5;
if (x >= 5) return y;
```

## Expected Output
```
Line 1: [KEYWORD   ] int
Line 1: [IDENTIFIER] x
Line 1: [OPERATOR  ] =
Line 1: [NUMBER    ] 10
Line 1: [UNKNOWN   ] ;
Line 3: [KEYWORD   ] float
Line 3: [IDENTIFIER] y
...
```
