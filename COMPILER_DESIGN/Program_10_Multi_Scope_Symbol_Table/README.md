# Program 10: Multi-Scope Symbol Table Manager

## Aim
Implement a symbol table manager in C that supports nested scopes, allowing inner scopes to shadow outer ones and preventing duplicate declarations within the same scope.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **Scope Stack**: Implement a stack of scopes, where each scope is an array of variable structures (name, type).
2. **Enter Scope**: Increment the stack pointer to create a new local scope.
3. **Exit Scope**: Decrement the stack pointer to discard the current local scope.
4. **Insert**:
   - Search only the current (topmost) scope for the variable name.
   - If found, return a redeclaration error.
   - If not found, add the variable to the current scope.
5. **Lookup**:
   - Search the stack from the top (innermost) to the bottom (global scope).
   - Return the first match found (implements shadowing).

## Source File Description
- `symbol_table.c`: C implementation of the scope-based symbol table.

## Compilation and Execution Commands
```bash
gcc symbol_table.c -o symbol_table
./symbol_table
```

## Sample Input
- `insert("a", "int")` $\to$ `enter_scope()` $\to$ `insert("a", "float")` $\to$ `lookup("a")`

## Expected Output
```
Inner Scope 'a': float
Duplicate in same scope: FAILED
Global Scope 'a': int
```

## Important Concepts Demonstrated
- **Lexical Scoping**.
- **Variable Shadowing**.
- **Stack-based Environment Management**.
