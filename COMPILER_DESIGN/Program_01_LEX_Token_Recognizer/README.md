# Program 01: LEX Token Recognizer

## Compilation & Execution

From the repository root in PowerShell:
```powershell
Set-Location .\COMPILER_DESIGN\Program_01_LEX_Token_Recognizer
flex scanner.l
gcc lex.yy.c -o scanner.exe
.\scanner.exe
```

The same commands can be run from this directory:
```powershell
flex scanner.l
gcc lex.yy.c -o scanner.exe
.\scanner.exe
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
