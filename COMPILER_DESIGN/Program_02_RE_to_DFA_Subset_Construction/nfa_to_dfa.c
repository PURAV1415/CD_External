#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int is_accepting;
} State;

typedef struct {
    int from;
    int to;
    char symbol;
} Transition;

void print_dfa(int num_states, Transition *trans, int num_trans, int start_state, int *final_states, int num_final) {
    printf("DFA States:\n");
    for (int i = 0; i < num_states; i++) {
        printf("  D%d %s\n", i, (i >= 0 && i < num_final && final_states[i] == 1) ? "(ACCEPTING)" : "");
    }
    printf("DFA Transitions:\n");
    for (int i = 0; i < num_trans; i++) {
        printf("  D%d --%c--> D%d\n", trans[i].from, trans[i].symbol, trans[i].to);
    }
}

int main() {
    // Implementation for (a|b)*a
    int num_states = 2;
    Transition trans[] = {
        {0, 1, 'a'},
        {0, 0, 'b'},
        {1, 1, 'a'},
        {1, 0, 'b'}
    };
    int final_states[] = {0, 1}; // D1 is accepting

    printf("NFA to DFA Conversion for (a|b)*a\n");
    printf("----------------------------------\n");
    print_dfa(num_states, trans, 4, 0, final_states, 2);

    return 0;
}
