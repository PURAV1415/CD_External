# Program 14: Code Optimizer: Common Subexpression Elimination and Dead Code Removal

## Aim
Implement a code optimizer in C that performs Common Subexpression Elimination (CSE) and Dead Code Elimination (DCE) on Three-Address Code.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **Common Subexpression Elimination (Forward Pass)**:
   - Scan instructions. If the same right-hand side (RHS) is encountered again, mark it as redundant.
2. **Dead Code Elimination (Backward Pass)**:
   - Start from the required output variable.
   - Walk backward; keep only instructions whose results are used by subsequent live instructions.
3. **Output**: Print the final reduced set of instructions.

## Source File Description
- `optimizer.c`: C implementation of CSE and DCE.

## Compilation and Execution Commands
```bash
gcc optimizer.c -o optimizer
./optimizer
```

## Sample Input
TAC: `t1 = a+b`, `t2 = c*d`, `t3 = a+b`, `t4 = t1+t3`, `unused = x+1`.

## Expected Output
Optimized TAC:
`t1 = a+b`
`t4 = t1+t1` (simulated)

## Important Concepts Demonstrated
- **Data Flow Analysis**.
- **Redundancy Removal**.
- **Liveness Analysis**.
