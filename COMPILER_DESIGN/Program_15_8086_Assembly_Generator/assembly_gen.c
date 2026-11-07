#include <stdio.h>
#include <string.h>

void generate_arithmetic(char tac[][20], int count) {
    printf(".model small\n.code\n");
    for (int i = 0; i < count; i++) {
        char lhs[10], rhs[20];
        sscanf(tac[i], "%s = %s %s %s", lhs, rhs, rhs, rhs); // dummy
        // Actual logic:
        char op1[10], op[2], op2[10];
        sscanf(tac[i], "%s = %s %s %s", lhs, op1, op, op2);

        printf("MOV AX, %s\n", op1);
        if (op[0] == '+') printf("ADD AX, %s\n", op2);
        else if (op[0] == '-') printf("SUB AX, %s\n", op2);
        else if (op[0] == '*') {
            printf("MOV BX, %s\nMUL BX\n", op2);
        }
        printf("MOV %s, AX\n", lhs);
    }
}

void generate_proc_call(char* proc_name, char* args[], int arg_count) {
    for (int i = arg_count - 1; i >= 0; i--) {
        printf("PUSH %s\n", args[i]);
    }
    printf("CALL %s\n", proc_name);
    printf("ADD SP, %d\n", arg_count * 2);
}

int main() {
    char tac[2][20] = {"t1 = a + b", "t2 = t1 * c"};
    generate_arithmetic(tac, 2);

    char* args[] = {"x", "y"};
    generate_proc_call("swap", args, 2);

    return 0;
}
