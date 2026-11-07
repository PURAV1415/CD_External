# Program 13: Control Flow TAC

## Compilation & Execution
```bash
gcc control_flow.c -o control_flow
./control_flow
```

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
...
```
