# Program 11: Static Declaration Type Checker

## Compilation & Execution
```bash
gcc type_check.c -o type_check
./type_check
```

## Expected Output
```
Decl: int arr[10]; -> Valid Declaration: 'arr' as int
Decl: float arr[-2]; -> Array Error: Dimension must be positive
...
```
