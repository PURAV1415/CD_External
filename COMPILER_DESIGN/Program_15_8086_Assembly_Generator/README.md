# Program 15: Assembly Code Generator (8086) for Arithmetic and Procedure Calls

## Aim
Implement a program in C that translates three-address intermediate code into 8086 assembly language.

## Language and Tools Required
- **Language**: C
- **Tools**: `gcc` (GNU Compiler Collection)

## Algorithm
1. **Direct Mapping**: Map TAC instructions (e.g., `t1 = a + b`) to 8086 instructions (`MOV AX, a`, `ADD AX, b`, `MOV t1, AX`).
2. **Arithmetic**:
   - Addition $\to$ `ADD`.
   - Subtraction $\to$ `SUB`.
   - Multiplication $\to$ `MOV BX, op2` followed by `MUL BX`.
3. **Procedure Calls**:
   - Push arguments in reverse order.
   - Emit `CALL`.
   - Clean the stack using `ADD SP, bytes`.

## Source File Description
- `assembly_gen.c`: C implementation of the 8086 code generator.

## Compilation and Execution Commands
```bash
gcc assembly_gen.c -o assembly_gen
./assembly_gen
```

## Sample Input
- `t1 = a + b`, `t2 = t1 * c`
- `CALL swap(x, y)`

## Expected Output
```
.model small
.code
MOV AX, a
ADD AX, b
MOV t1, AX
...
PUSH y
PUSH x
CALL swap
ADD SP, 4
```

## Important Concepts Demonstrated
- **Target Code Generation**.
- **CPU Register usage (AX, BX, SP)**.
- **Calling Conventions**.
