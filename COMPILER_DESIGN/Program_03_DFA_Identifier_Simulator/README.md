# Program 03: C Program to Simulate a DFA (Valid Identifiers)

## Aim
Simulate a Deterministic Finite Automaton (DFA) that accepts strings matching the identifier pattern: `[a-zA-Z_][a-zA-Z0-9_]*`.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **State Definitions**:
   - **State 0**: Start state.
   - **State 1**: Valid identifier state (Accepting).
   - **State -1**: Dead state (Error).
2. **Transition Rules**:
   - In **State 0**: If the character is a letter (`isalpha`) or an underscore (`_`), move to **State 1**. Otherwise, move to **State -1**.
   - In **State 1**: If the character is a letter, digit (`isalnum`), or an underscore (`_`), remain in **State 1**. Otherwise, move to **State -1**.
   - In **State -1**: Any input keeps the machine in **State -1**.
3. **Acceptance Condition**:
   - Reject empty input immediately.
   - If the machine ends in **State 1** after processing the entire string, the input is **ACCEPTED**.
   - Otherwise, it is **REJECTED**.

## Source File Description
- `dfa_sim.c`: A C program that implements the state machine logic and tests it against a set of sample inputs.

## Compilation and Execution Commands
```bash
# 1. Compile the C program
gcc dfa_sim.c -o dfa_sim

# 2. Run the executable
./dfa_sim
```

## Sample Input
The program tests the following inputs:
- `"var1"`
- `"_count"`
- `"99num"`
- `"a+b"`
- `""` (empty string)

## Expected Output
```
Input: 'var1' -> ACCEPTED
Input: '_count' -> ACCEPTED
Input: '99num' -> REJECTED
Input: 'a+b' -> REJECTED
Input: '' -> REJECTED
```

## Explanation of Output
- `var1` and `_count` are valid identifiers as they start with a letter/underscore and contain only valid characters.
- `99num` is rejected because it starts with a digit.
- `a+b` is rejected because the `+` symbol is not allowed in identifiers.
- The empty string is rejected as identifiers must contain at least one character.

## Important Concepts Demonstrated
- **DFA Simulation**: Implementing a state transition table using a `switch` statement.
- **Lexical Rules**: Enforcing the standard rules for variable names in most programming languages.
- **Finite Automata**: Using states and transitions to recognize a regular language.

## Common Errors and Resolution
- **Error**: `isalpha` or `isalnum` undefined.
  - **Resolution**: Ensure `#include <ctype.h>` is included at the top of the file.
