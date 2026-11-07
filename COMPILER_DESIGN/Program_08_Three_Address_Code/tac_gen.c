#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char op1[10];
    char op[2];
    char op2[10];
} TAC;

void generate_tac(char* postfix) {
    char stack[100][10];
    int top = -1;
    int temp_count = 1;
    TAC tac[100];
    int tac_count = 0;

    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            char temp[2] = {c, '\0'};
            strcpy(stack[++top], temp);
        } else {
            if (top < 1) {
                printf("Error: Invalid Postfix\n");
                return;
            }
            char op2[10], op1[10];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);

            char temp_var[10];
            sprintf(temp_var, "t%d", temp_count++);

            printf("%s = %s %c %s\n", temp_var, op1, c, op2);
            strcpy(stack[++top], temp_var);
        }
    }
}

int main() {
    char postfix[] = "abc*+";
    printf("Postfix %s:\n", postfix);
    generate_tac(postfix);
    return 0;
}
