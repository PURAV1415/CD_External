#include <stdio.h>
#include <string.h>

void gen_if_else(char* cond, char* then_code[], int then_len, char* else_code[], int else_len, int* label_id) {
    int l_else = ++(*label_id);
    int l_end = ++(*label_id);
    printf("ifFalse (%s) goto L%d\n", cond, l_else);
    for(int i=0; i<then_len; i++) printf("    %s\n", then_code[i]);
    printf("goto L%d\n", l_end);
    printf("L%d:\n", l_else);
    for(int i=0; i<else_len; i++) printf("    %s\n", else_code[i]);
    printf("L%d:\n", l_end);
}

void gen_while(char* cond, char* body_code[], int body_len, int* label_id) {
    int l_begin = ++(*label_id);
    int l_end = ++(*label_id);
    printf("L%d:\n", l_begin);
    printf("ifFalse (%s) goto L%d\n", cond, l_end);
    for(int i=0; i<body_len; i++) printf("    %s\n", body_code[i]);
    printf("goto L%d\n", l_begin);
    printf("L%d:\n", l_end);
}

int main() {
    int lid = 0;
    char* then_c[] = {"x = 1", "y = 2"};
    char* else_c[] = {"x = 0"};
    printf("if (a < b) { x = 1; y = 2; } else { x = 0; }\n");
    gen_if_else("a < b", then_c, 2, else_c, 1, &lid);

    printf("\nwhile (i < 10) { i = i + 1; }\n");
    char* body[] = {"i = i + 1"};
    gen_while("i < 10", body, 1, &lid);

    return 0;
}
