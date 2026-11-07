# Program 07: Infix to Postfix Conversion (Operator Stack)

## Aim
Translate an infix expression to a postfix expression using an operator stack in C.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **Precedence**: Assign priorities to operators: `^` (3), `*`, `/` (2), `+`, `-` (1).
2. **Scan**: Read infix expression from left to right.
3. **Operand**: Add directly to postfix output.
4. **'('**: Push to stack.
5. **')'**: Pop stack to output until '(' is found.
6. **Operator**: Pop operators with higher or equal precedence (unless right-associative `^`) to output, then push current operator.
7. **Finalize**: Pop remaining operators from stack.

## Source File Description
- `infix_postfix.c`: C implementation of the Shunting-yard algorithm.

## Compilation and Execution Commands
```bash
gcc infix_postfix.c -o infix_postfix
./infix_postfix
```

## Sample Input
- `a+b*c^d^e`

## Expected Output
```
Infix: a+b*c^d^e
Postfix: abcde^^*+
```

## Important Concepts Demonstrated
- **Stack-based parsing**.
- **Operator Precedence and Associativity**.
