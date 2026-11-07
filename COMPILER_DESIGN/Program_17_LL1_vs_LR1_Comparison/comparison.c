#include <stdio.h>

void compare_parsers() {
    printf("=== LL(1) vs LR(1) Comparison ===\n");
    printf("1. LL(1): Top-Down, Predictive, uses FIRST/FOLLOW, simpler table.\n");
    printf("2. LR(1): Bottom-Up, Shift-Reduce, uses Item Sets, more powerful.\n");
    printf("\nExample Grammar: E -> T E', E' -> + T E' | epsilon, T -> id\n");
    printf("\nLL(1) Table Entry: M[E, id] = E -> T E'\n");
    printf("LR(1) State 0: [S' -> .E, $], [E -> .T E', $]\n");
}

int main() {
    compare_parsers();
    return 0;
}
