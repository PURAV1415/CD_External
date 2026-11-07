# Program 15: 8086 Assembly Generator

## Compilation & Execution
```bash
gcc assembly_gen.c -o assembly_gen
./assembly_gen
```

## Expected Output
```
.model small
.code
MOV AX, a
ADD AX, b
MOV t1, AX
...
```
