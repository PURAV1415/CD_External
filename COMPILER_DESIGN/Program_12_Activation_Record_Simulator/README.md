# Program 12: Stack-Based Memory Allocation Simulator (Activation Records)

## Aim
Simulate the management of activation records (stack frames) during function calls to demonstrate LIFO (Last-In, First-Out) memory allocation.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **Activation Record Definition**: Create a `struct` (Frame) to hold the function name, the return address, and the number of local variables.
2. **Stack Setup**: Define a fixed-size array of `Frame` structures to act as the call stack and a `top` integer to track the current stack pointer.
3. **Push Operation (`push_frame`)**:
   - Check if the stack is full (Overflow).
   - If not, increment `top` and populate the frame with the function's details.
4. **Pop Operation (`pop_frame`)**:
   - Check if the stack is empty (Underflow).
   - If not, access the frame at `top`, print the return address to simulate returning from the function, and decrement `top`.
5. **Execution**: Simulate a sequence of function calls (Push) and returns (Pop).

## Source File Description
- `mem_alloc.c`: C implementation of the activation record stack simulator.

## Compilation and Execution Commands
```bash
# 1. Compile the C program
gcc mem_alloc.c -o mem_alloc

# 2. Run the executable
./mem_alloc
```

## Sample Input
The `main()` function simulates the following sequence:
1. Call `main` (RetAddr: 1000, Locals: 2)
2. Call `compute` (RetAddr: 1045, Locals: 4)
3. Return from `compute`
4. Return from `main`
5. Attempt another return (Underflow)

## Expected Output
```
[PUSH] Frame 'main' | RetAddr: 1000 | Locals: 2
[PUSH] Frame 'compute' | RetAddr: 1045 | Locals: 4
[POP ] Exiting Frame 'compute' -> Returning to Addr: 1045
[POP ] Exiting Frame 'main' -> Returning to Addr: 1000
Stack Underflow!
```

## Explanation of Output
- The `main` function is pushed first, then `compute`.
- Because it's a stack, `compute` must be popped before `main` can be popped.
- The final pop attempt occurs when the stack is already empty, triggering the underflow protection.

## Important Concepts Demonstrated
- **LIFO (Last-In, First-Out)**: The fundamental principle of the call stack.
- **Activation Record**: The data structure used by the OS/Runtime to manage function local variables and return paths.
- **Stack Overflow/Underflow**: Managing the boundaries of a fixed-size memory region.

## Common Errors and Resolution
- **Error**: `strcpy` is unsafe.
  - **Resolution**: For a simple lab practical, `strcpy` is acceptable; for production, `strncpy` would be used to prevent buffer overflows.
