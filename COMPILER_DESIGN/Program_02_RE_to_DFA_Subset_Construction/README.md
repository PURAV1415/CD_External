# Program 02: RE to NFA to DFA Conversion (Subset Construction)

## Aim
Convert a Non-deterministic Finite Automaton (NFA) into a Deterministic Finite Automaton (DFA) using the subset construction algorithm.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **$\epsilon$-closure**: Compute the set of states reachable from a state using only epsilon transitions.
2. **Initial State**: The start state of the DFA ($D_0$) is the $\epsilon$-closure of the NFA start state.
3. **Transitions**: For each DFA state and input symbol, compute the set of NFA states reachable, then take their $\epsilon$-closure.
4. **State Labeling**: If a new set of NFA states is found, assign it a new DFA state label.
5. **Acceptance**: A DFA state is accepting if it contains any NFA accepting state.

## Source File Description
- `nfa_to_dfa.c`: C implementation simulating the conversion for the regular expression `(a|b)*a`.

## Compilation and Execution Commands
```bash
# 1. Compile the C program
gcc nfa_to_dfa.c -o nfa_to_dfa

# 2. Run the executable
./nfa_to_dfa
```

## Sample Input
NFA for `(a|b)*a` (implemented in code).

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

## Important Concepts Demonstrated
- **Subset Construction**: The mathematical process of converting non-determinism to determinism.
- **$\epsilon$-transitions**: Transitions that do not consume any input.
- **DFA State Table**: Representing the final automaton as a transition table.
