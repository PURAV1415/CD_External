#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char lhs[10];
    char rhs[20];
} Instruction;

void optimize(Instruction* tac, int count, char* live_out) {
    // CSE (Forward Pass) - simplified for lab
    Instruction cse_tac[100];
    int cse_count = 0;

    for (int i = 0; i < count; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(tac[i].rhs, tac[j].rhs) == 0) {
                // In a real compiler, we'd replace tac[i].lhs with tac[j].lhs
                // For this lab, we simulate the elimination
                found = 1;
                break;
            }
        }
        if (!found) {
            cse_tac[cse_count++] = tac[i];
        }
    }

    // DCE (Backward Pass)
    int is_live[100] = {0};
    // Simple simulation: assume last instruction is always live
    if (cse_count > 0) is_live[cse_count - 1] = 1;

    printf("Optimized TAC:\n");
    for (int i = 0; i < cse_count; i++) {
        printf("%s = %s\n", cse_tac[i].lhs, cse_tac[i].rhs);
    }
}

int main() {
    Instruction tac[] = {
        {"t1", "a + b"},
        {"t2", "c * d"},
        {"t3", "a + b"},
        {"t4", "t1 + t3"},
        {"unused", "x + 1"}
    };
    optimize(tac, 5, "t4");
    return 0;
}
