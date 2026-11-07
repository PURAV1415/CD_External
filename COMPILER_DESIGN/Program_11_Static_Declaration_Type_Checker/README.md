# Program 11: Static Declaration Type Checker

## Aim
Implement a static type checker in C to validate variable and array declarations.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **Parsing**: Split the declaration into type and variable parts using `strtok`.
2. **Type Check**: Ensure the type is one of `int`, `float`, or `char`.
3. **Array Check**: If `[` is present, extract the dimension and ensure it is a positive integer.
4. **Redeclaration Check**: Compare the variable name against a global symbol array.
5. **Registry**: If all checks pass, add the variable name to the symbol array.

## Source File Description
- `type_check.c`: C implementation of the declaration checker.

## Compilation and Execution Commands
```bash
gcc type_check.c -o type_check
./type_check
```

## Sample Input
- `int arr[10];`
- `float arr[-2];`
- `int arr;`
- `double d;`

## Expected Output
```
Decl: int arr[10]; -> Valid Declaration: 'arr' as int
Decl: float arr[-2]; -> Array Error: Dimension must be positive
Decl: int arr; -> Redeclaration Error: 'arr' already declared
Decl: double d; -> Unknown Type 'double'
```

## Important Concepts Demonstrated
- **Static Analysis**.
- **Symbol Table management**.
- **String manipulation in C**.
