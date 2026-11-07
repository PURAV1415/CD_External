# Program 13: Intermediate Code for Control Flow (if-else, while)

## Aim
Generate Three-Address Code (TAC) for high-level control flow structures such as `if-else` and `while` loops using labels and conditional/unconditional jumps.

## Language and Tools Required
- **Language**: Python 3
- **Tools**: Python 3 Interpreter

## Algorithm
1. **Label Management**: Use a counter to generate unique labels (e.g., `L1`, `L2`, `L3`) to mark jump targets in the code.
2. **If-Else Generation**:
   - Generate a label for the `else` block and a label for the `end` of the structure.
   - Emit: `ifFalse (condition) goto L_else`.
   - Emit the TAC for the `then` block.
   - Emit: `goto L_end` (to skip the else block).
   - Emit `L_else:`.
   - Emit the TAC for the `else` block.
   - Emit `L_end:`.
3. **While Loop Generation**:
   - Generate a label for the `begin` of the loop and a label for the `end`.
   - Emit `L_begin:`.
   - Emit: `ifFalse (condition) goto L_end` (exit loop if condition is false).
   - Emit the TAC for the loop body.
   - Emit: `goto L_begin` (loop back to the test).
   - Emit `L_end:`.

## Source File Description
- `control_flow.py`: Python implementation of the TAC generator for control flow.

## Compilation and Execution Commands
```bash
python control_flow.py
```

## Sample Input
- `if (a < b) { x = 1; y = 2; } else { x = 0; }`
- `while (i < 10) { i = i + 1; }`

## Expected Output
```
if (a < b) { x = 1; y = 2; } else { x = 0; }
ifFalse (a < b) goto L1
    x = 1
    y = 2
goto L2
L1:
    x = 0
L2:

------------------------------
while (i < 10) { i = i + 1; }
L3:
ifFalse (i < 10) goto L4
    i = i + 1
goto L3
L4:
```

## Explanation of Output
- For the `if-else` structure, the code jumps to `L1` if the condition is false, and jumps to `L2` after the `then` block to avoid executing the `else` block.
- For the `while` loop, the `L3` label marks the start of the condition check. If the condition is false, it jumps to `L4` to exit. Otherwise, it executes the body and jumps back to `L3`.

## Important Concepts Demonstrated
- **Control Flow Graphs (CFG)**: Translating structured programming constructs into a graph of basic blocks and jumps.
- **Boolean Expressions**: Using `ifFalse` as a primitive for conditional branching.
- **Labels**: Using symbolic markers to identify targets for jump instructions.

## Common Errors and Resolution
- **Error**: Incorrect jump targets.
  - **Resolution**: Ensure that the `goto L_end` is placed *after* the `then` block but *before* the `L_else` label.
