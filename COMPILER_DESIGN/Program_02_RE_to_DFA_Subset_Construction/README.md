# Program 02: RE to DFA Subset Construction

## Compilation & Execution
```bash
gcc nfa_to_dfa.c -o nfa_to_dfa
./nfa_to_dfa
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
