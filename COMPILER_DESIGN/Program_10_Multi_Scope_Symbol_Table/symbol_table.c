#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    char type[10];
} Symbol;

typedef struct {
    Symbol symbols[100];
    int count;
} Scope;

Scope scope_stack[10];
int top = 0;

void enter_scope() {
    top++;
    scope_stack[top].count = 0;
}

void exit_scope() {
    if (top > 0) top--;
}

int insert(char* name, char* type) {
    for (int i = 0; i < scope_stack[top].count; i++) {
        if (strcmp(scope_stack[top].symbols[i].name, name) == 0) return 0;
    }
    strcpy(scope_stack[top].symbols[scope_stack[top].count].name, name);
    strcpy(scope_stack[top].symbols[scope_stack[top].count].type, type);
    scope_stack[top].count++;
    return 1;
}

char* lookup(char* name) {
    for (int i = top; i >= 0; i--) {
        for (int j = 0; j < scope_stack[i].count; j++) {
            if (strcmp(scope_stack[i].symbols[j].name, name) == 0)
                return scope_stack[i].symbols[j].type;
        }
    }
    return NULL;
}

int main() {
    scope_stack[0].count = 0;
    insert("a", "int");

    enter_scope();
    insert("a", "float");
    printf("Inner Scope 'a': %s\n", lookup("a"));
    printf("Duplicate in same scope: %s\n", insert("a", "char") ? "SUCCESS" : "FAILED");
    exit_scope();

    printf("Global Scope 'a': %s\n", lookup("a"));
    return 0;
}
