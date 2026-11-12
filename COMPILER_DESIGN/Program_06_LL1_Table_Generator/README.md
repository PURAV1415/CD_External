# Program 06: LL(1) Table Generator

## Compilation & Execution

From the repository root in PowerShell:
```powershell
Set-Location .\COMPILER_DESIGN\Program_06_LL1_Table_Generator
gcc ll1_table.c -o ll1_table.exe
.\ll1_table.exe
```

The program analyzes the expression grammar:
`E -> T E'`, `E' -> + T E' | epsilon`, `T -> F T'`,
`T' -> * F T' | epsilon`, and `F -> ( E ) | id`.
```

## Expected Output
```
FIRST sets: ...
FOLLOW sets: ...
=== LL(1) PARSING TABLE ===
M[E, (] = E -> T E'
...
Grammar is LL(1)
```
