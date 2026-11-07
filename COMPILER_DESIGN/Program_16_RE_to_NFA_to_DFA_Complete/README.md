# Program 16: Complete Regular Expression to NFA to DFA Conversion

## Aim
Implement a program in C that simulates the conversion of a regular expression to an NFA and then to a DFA.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **Thompson's Construction**: Convert regex to NFA using $\epsilon$-transitions for union and loops.
2. **Subset Construction**:
   - Compute $\epsilon$-closure of the start state.
   - For each symbol, find the set of reachable states.
   - Create new DFA states for each unique set.
3. **Output**: Display the transition table.

## Source File Description
- `regex_converter.c`: C implementation simulating the regex-to-DFA process.

## Compilation and Execution Commands
```bash
gcc regex_converter.c -o regex_converter
./regex_converter
```

## Expected Output
Shows the conversion of `(a|b)*a` into a DFA with states D0 and D1.

## Important Concepts Demonstrated
- **Automata Theory**.
- **NFA to DFA conversion**.
