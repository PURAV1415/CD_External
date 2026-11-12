# Program 05: YACC Arithmetic Parser

## Compilation & Execution

From the repository root in PowerShell:
```powershell
Set-Location .\COMPILER_DESIGN\Program_05_YACC_Arithmetic_Parser
$env:Path += ";$env:LOCALAPPDATA\Microsoft\WinGet\Packages\WinFlexBison.win_flex_bison_Microsoft.Winget.Source_8wekyb3d8bbwe"
win_bison -dy parser.y
win_flex lexer.l
gcc y.tab.c lex.yy.c -o parser.exe
.\parser.exe
```

Enter an expression such as `2+3*4`, then press Enter. The PATH line is
needed once in an already-open PowerShell window. Alternatively, close and
reopen PowerShell after installation. If `win_bison` and `win_flex` are not
installed, install **Flex and Bison for Microsoft Windows**:
```powershell
winget install --id WinFlexBison.win_flex_bison -e
```

## Sample Input
`2+3*4`

## Expected Output
```
Parsing Successful! Result = 14
```
