# Program 17: LL(1) vs Canonical LR(1) Parsing Table Comparison

## Aim
Compare the structure and behavior of LL(1) (Top-Down) and LR(1) (Bottom-Up) parsing tables in C.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **LL(1) Analysis**: Simulate the table-based prediction using FIRST and FOLLOW sets.
2. **LR(1) Analysis**: Simulate the state-based shift-reduce approach using LR(1) items.
3. **Comparison**: Print the differences in parsing capability and table structure.

## Source File Description
- `comparison.c`: C program demonstrating the conceptual difference between LL(1) and LR(1).

## Compilation and Execution Commands
```bash
gcc comparison.c -o comparison
./comparison
```

## Expected Output
A text-based comparison of LL(1) and LR(1) for a small grammar.

## Important Concepts Demonstrated
- **Top-Down vs Bottom-Up Parsing**.
- **LR(1) Item Sets**.
- **Predictive vs Shift-Reduce parsing**.
