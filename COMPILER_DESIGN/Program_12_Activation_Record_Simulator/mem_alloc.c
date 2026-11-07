#include <stdio.h>
#include <string.h>

typedef struct {
    char func_name[20];
    int return_address;
    int local_var_count;
} Frame;

Frame call_stack[10];
int top = -1;

void push_frame(char* name, int ret_addr, int locals) {
    if (top >= 9) { printf("Stack Overflow!\n"); return; }
    top++;
    strcpy(call_stack[top].func_name, name);
    call_stack[top].return_address = ret_addr;
    call_stack[top].local_var_count = locals;
    printf("[PUSH] Frame '%s' | RetAddr: %d | Locals: %d\n", name, ret_addr, locals);
}

void pop_frame() {
    if (top < 0) { printf("Stack Underflow!\n"); return; }
    printf("[POP ] Exiting Frame '%s' -> Returning to Addr: %d\n", call_stack[top].func_name, call_stack[top].return_address);
    top--;
}

int main() {
    push_frame("main", 1000, 2);
    push_frame("compute", 1045, 4);
    pop_frame();
    pop_frame();
    pop_frame();
    return 0;
}
