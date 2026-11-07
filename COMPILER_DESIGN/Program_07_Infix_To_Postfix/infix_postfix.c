#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char op[10];
    int prec;
} Op;

Op ops[] = { {"^", 3}, {"*", 2}, {"/", 2}, {"+", 1}, {"-", 1} };

int get_prec(char c) {
    for (int i = 0; i < 5; i++) if (ops[i].op[0] == c) return ops[i].prec;
    return 0;
}

void infix_to_postfix(char* infix, char* postfix) {
    char stack[MAX];
    int top = -1, k = 0;

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isspace(c)) continue;
        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') postfix[k++] = stack[top--];
            top--;
        } else {
            while (top != -1 && stack[top] != '(' &&
                  (get_prec(stack[top]) > get_prec(c) ||
                  (get_prec(stack[top]) == get_prec(c) && c != '^'))) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top != -1) postfix[k++] = stack[top--];
    postfix[k] = '\0';
}

int main() {
    char infix[] = "a+b*c^d^e";
    char postfix[MAX];
    printf("Infix: %s\n", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    return 0;
}
