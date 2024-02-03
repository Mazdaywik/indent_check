#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tag_obj {
    long data;
    struct tag_obj *next;
} OBJ;

OBJ *push(OBJ *top, int data) {
    OBJ *ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

OBJ *pop(OBJ *top) {
    if (top == NULL)
        return top;
    OBJ *ptr_next = top->next;
    free(top);
    return ptr_next;
}

void show(const OBJ *top) {
    const OBJ *current = top;
    while (current != NULL) {
        printf("%ld\n", current->data);
        current = current->next;
    }
}

long max(long a, long b){
    if (a>b)
        return a;
    return b;
}

long min(long a, long b){
    if (a<b)
        return a;
    return b;
}

int main() {
    OBJ *top = NULL;
    char operation[10] = "START";
    while (strcmp(operation, "END") != 0) {
        scanf("%s", operation);
        if (strcmp(operation, "CONST") == 0) {
            long x;
            scanf("%ld", &x);
            top = push(top, x);
        }
        if (strcmp(operation, "ADD") == 0) {
            long a = top->data;
            top = pop(top);
            long b = top->data;
            top = pop(top);
            top = push(top, a + b);
        }
        if (strcmp(operation, "SUB") == 0) {
            long a = top->data;
            top = pop(top);
            long b = top->data;
            top = pop(top);
            top = push(top, a - b);
        }
        if (strcmp(operation, "MUL") == 0) {
            long a = top->data;
            top = pop(top);
            long b = top->data;
            top = pop(top);
            top = push(top, a * b);
        }
        if (strcmp(operation, "DIV") == 0) {
            long a = top->data;
            top = pop(top);
            long b = top->data;
            top = pop(top);
            top = push(top, a / b);
        }
        if (strcmp(operation, "MAX") == 0) {
            long a = top->data;
            top = pop(top);
            long b = top->data;
            top = pop(top);
            top = push(top, max(a, b));
        }
        if (strcmp(operation, "MIN") == 0) {
            long a = top->data;
            top = pop(top);
            long b = top->data;
            top = pop(top);
            top = push(top, min(a, b));
        }
        if (strcmp(operation, "NEG") == 0) {
            long a = top->data;
            top = pop(top);
            top = push(top, (-1 * a));
        }
        if (strcmp(operation, "DUP") == 0) {
            long a = top->data;
            top = push(top, a);
        }
        if (strcmp(operation, "SWAP") == 0) {
            long a = top->data;
            top = pop(top);
            long b = top->data;
            top = pop(top);
            top = push(top, a);
            top = push(top, b);
        }
    }
    show(top);
    free(top);
    return 0;
}