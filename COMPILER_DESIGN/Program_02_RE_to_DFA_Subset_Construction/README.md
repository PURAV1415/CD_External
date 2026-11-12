# Program 02: RE to DFA Subset Construction

## Compilation & Execution

From the repository root in PowerShell:
```powershell
Set-Location .\COMPILER_DESIGN\Program_02_RE_to_DFA_Subset_Construction
gcc nfa_to_dfa.c -o nfa_to_dfa.exe
.\nfa_to_dfa.exe
```

The same commands can be run from this directory:
```powershell
gcc nfa_to_dfa.c -o nfa_to_dfa.exe
.\nfa_to_dfa.exe
```

## Expected Output
```
NFA to DFA Conversion for (a|b)*a
----------------------------------
DFA States:
  D0 
  D1 (ACCEPTING)
DFA Transitions:
  D0 --a--> D1
  D0 --b--> D0
  D1 --a--> D1
  D1 --b--> D0
```
