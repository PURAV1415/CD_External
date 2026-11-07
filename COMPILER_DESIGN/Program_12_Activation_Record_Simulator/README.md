# Program 12: Activation Record Simulator

## Compilation & Execution
```bash
gcc mem_alloc.c -o mem_alloc
./mem_alloc
```

## Expected Output
```
[PUSH] Frame 'main' | RetAddr: 1000 | Locals: 2
[PUSH] Frame 'compute' | RetAddr: 1045 | Locals: 4
[POP ] Exiting Frame 'compute' -> Returning to Addr: 1045
[POP ] Exiting Frame 'main' -> Returning to Addr: 1000
Stack Underflow!
```
