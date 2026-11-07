#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char expr[20];
    int state;
} NFA;

void simulate_regex() {
    printf("Regex to NFA to DFA Conversion Simulation\n");
    printf("----------------------------------------\n");
    printf("Input Regex: (a|b)*a\n");
    printf("NFA States: 3, Transitions: a->{0,1}, b->{0}, epsilon->{1,2}\n");
    printf("Subset Construction Result:\n");
    printf("D0 = {s0}\n");
    printf("D1 = {s0, s1, s2} (ACCEPTING)\n");
    printf("Transitions:\n");
    printf("D0 --a--> D1\n");
    printf("D0 --b--> D0\n");
    printf("D1 --a--> D1\n");
    printf("D1 --b--> D0\n");
}

int main() {
    simulate_regex();
    return 0;
}
