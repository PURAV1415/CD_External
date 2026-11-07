# Program 08: Three-Address Code (TAC) Generator

## Aim
Implement a program to generate Three-Address Code (TAC) from a given postfix expression using C.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **Stack Initialization**: Use a stack of strings to hold operands and temporary variables.
2. **Scan Postfix**: Process the postfix expression from left to right.
3. **Operand**: If the character is an operand, push it onto the stack.
4. **Operator**:
   - Pop the top two elements (`op2` then `op1`).
   - Generate a temporary variable `tN`.
   - Emit: `tN = op1 operator op2`.
   - Push `tN` back onto the stack.
5. **Validation**: If the stack contains fewer than two elements when an operator is encountered, report a syntax error.

## Source File Description
- `tac_gen.c`: C implementation of the TAC generator.

## Compilation and Execution Commands
```bash
gcc tac_gen.c -o tac_gen
./tac_gen
```

## Sample Input
- `abc*+`

## Expected Output
```
Postfix abc*+:
t1 = b * c
t2 = a + t1
```

## Important Concepts Demonstrated
- **Intermediate Representation (IR)**.
- **Three-Address Code structure**.
- **Stack-based expression processing**.
