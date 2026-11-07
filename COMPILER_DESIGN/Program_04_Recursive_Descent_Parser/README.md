# Program 04: Recursive Descent Parser for Arithmetic Expressions

## Aim
Implement a recursive descent parser to verify if a given arithmetic expression is valid according to a specific context-free grammar.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **Grammar Definition**:
   - $E \to T E'$
   - $E' \to + T E' \mid \epsilon$
   - $T \to F T'$
   - $T' \to * F T' \mid \epsilon$
   - $F \to ( E ) \mid \text{id}$
2. **Function Implementation**: Create a function for each non-terminal ($E, E', T, T', F$). Each function returns 1 if the derivation is successful and 0 otherwise.
3. **Lookahead**: Use a global position pointer `pos` to keep track of the current character being scanned.
4. **Terminal Matching**: When a terminal (like `+` or `*`) is expected, check if the current character matches; if so, increment `pos`.
5. **Epsilon ($\epsilon$) Handling**: For rules that can derive $\epsilon$ (like $E'$ and $T'$), return 1 if the lookahead does not match the expected operator, allowing the parser to proceed.
6. **Final Validation**: The input is valid if the start symbol $E()$ returns 1 and the entire input string has been consumed (`input[pos] == '\0'`).

## Source File Description
- `rdp.c`: Implementation of the parser functions and a test suite in `main()`.

## Compilation and Execution Commands
```bash
# 1. Compile the C program
gcc rdp.c -o rdp

# 2. Run the executable
./rdp
```

## Sample Input
The program tests the following strings:
- `"a+b*c"`
- `"(a+b)*c"`
- `"a+*b"`
- `"(a+b"`

## Expected Output
```
Expression 'a+b*c' is VALID
Expression '(a+b)*c' is VALID
Expression 'a+*b' is INVALID
Expression '(a+b' is INVALID
```

## Explanation of Output
- `a+b*c` and `(a+b)*c` follow the grammar rules of precedence and grouping.
- `a+*b` is invalid because an operator cannot immediately follow another operator without an operand.
- `(a+b` is invalid due to a missing closing parenthesis.

## Important Concepts Demonstrated
- **Top-Down Parsing**: Building the parse tree from the root down to the leaves.
- **Left Recursion Removal**: The grammar used is transformed to remove left recursion, which would otherwise cause infinite recursion in a recursive descent parser.
- **Context-Free Grammars (CFG)**: Using a set of production rules to define a language.

## Common Errors and Resolution
- **Error**: Stack Overflow.
  - **Resolution**: This typically happens if the grammar has left recursion. Ensure the grammar is rewritten as shown in the algorithm.
