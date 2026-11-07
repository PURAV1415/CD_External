#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    char type[10];
} Symbol;

Symbol sym_table[100];
int sym_count = 0;

void add_symbol(char* name, char* type) {
    strcpy(sym_table[sym_count].name, name);
    strcpy(sym_table[sym_count].type, type);
    sym_count++;
}

char* get_type(char* name) {
    for (int i = 0; i < sym_count; i++) {
        if (strcmp(sym_table[i].name, name) == 0) return sym_table[i].type;
    }
    return NULL;
}

void check_assignment(char* lhs, char* rhs_tokens[], int token_count) {
    char* target_type = get_type(lhs);
    if (!target_type) {
        printf("Type Error: Undeclared destination variable '%s'\n", lhs);
        return;
    }

    int is_float = 0;
    for (int i = 0; i < token_count; i++) {
        char* type = get_type(rhs_tokens[i]);
        if (type && strcmp(type, "float") == 0) is_float = 1;
        if (strchr(rhs_tokens[i], '.')) is_float = 1;
    }

    if (strcmp(target_type, "int") == 0 && is_float) {
        printf("Type Error: Cannot assign float expression to int variable '%s'\n", lhs);
    } else {
        printf("Type Check SUCCESS: Expression assigned to '%s' (%s)\n", lhs, target_type);
    }
}

int main() {
    add_symbol("x", "int");
    add_symbol("y", "float");
    add_symbol("z", "int");

    char* rhs1[] = {"y", "+", "z"};
    check_assignment("x", rhs1, 3);

    char* rhs2[] = {"x", "+", "z"};
    check_assignment("y", rhs2, 3);

    char* rhs3[] = {"x"};
    check_assignment("w", rhs3, 1);

    return 0;
}
