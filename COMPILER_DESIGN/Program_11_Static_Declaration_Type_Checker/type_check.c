#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_declaration(char* decl, char symbols[100][20], int* sym_count) {
    char temp[50];
    strcpy(temp, decl);
    char* token = strtok(temp, " ;");
    if (!token) return -1;

    char dtype[10];
    strcpy(dtype, token);

    token = strtok(NULL, " ;");
    if (!token) return -1;

    char var_name[20];
    int is_array = 0;
    int dim = 0;

    if (strchr(token, '[')) {
        is_array = 1;
        char* bracket = strchr(token, '[');
        int len = bracket - token;
        strncpy(var_name, token, len);
        var_name[len] = '\0';
        sscanf(bracket + 1, "%d", &dim);
    } else {
        strcpy(var_name, token);
    }

    if (strcmp(dtype, "int") != 0 && strcmp(dtype, "float") != 0 && strcmp(dtype, "char") != 0) {
        printf("Unknown Type '%s'\n", dtype);
        return 0;
    }

    if (is_array && dim <= 0) {
        printf("Array Error: Dimension must be positive\n");
        return 0;
    }

    for (int i = 0; i < *sym_count; i++) {
        if (strcmp(symbols[i], var_name) == 0) {
            printf("Redeclaration Error: '%s' already declared\n", var_name);
            return 0;
        }
    }

    strcpy(symbols[(*sym_count)++], var_name);
    printf("Valid Declaration: '%s' as %s\n", var_name, dtype);
    return 1;
}

int main() {
    char symbols[100][20];
    int sym_count = 0;
    char* tests[] = {"int arr[10];", "float arr[-2];", "int arr;", "double d;"};

    for (int i = 0; i < 4; i++) {
        printf("Decl: %s -> ", tests[i]);
        check_declaration(tests[i], symbols, &sym_count);
        printf("\n");
    }
    return 0;
}
