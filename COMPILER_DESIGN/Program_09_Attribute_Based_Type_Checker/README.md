# Program 09: Attribute-Based Type Checker for Assignments

## Aim
Implement a type checker in C that uses attributes of identifiers to validate assignments and detect type mismatches.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **Symbol Table**: Implement a simple array of structures to map variable names to their types (`int`, `float`).
2. **LHS Check**: Verify if the left-hand side variable is declared in the symbol table.
3. **RHS Type Analysis**:
   - Iterate through RHS tokens.
   - If any token is a `float` variable or contains a decimal point, mark the entire RHS as `float`.
4. **Type Compatibility**:
   - If LHS is `int` and RHS is `float`, report a Type Error.
   - Otherwise, the assignment is valid.

## Source File Description
- `type_checker.c`: C implementation of the attribute-based type checker.

## Compilation and Execution Commands
```bash
gcc type_checker.c -o type_checker
./type_checker
```

## Sample Input
- `x = y + z` (x: int, y: float)
- `y = x + z` (y: float, x: int)
- `w = x` (w: undeclared)

## Expected Output
```
Type Error: Cannot assign float expression to int variable 'x'
Type Check SUCCESS: Expression assigned to 'y' (float)
Type Error: Undeclared destination variable 'w'
```

## Important Concepts Demonstrated
- **Static Type Checking**.
- **Type Coercion/Promotion**.
- **Symbol Table usage in C**.
