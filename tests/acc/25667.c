#include <stdio.h>
#include <stdlib.h>

struct stack{
    long val;
    struct stack *prev;
};

struct stack *newStack(long val, struct stack *prev){
    struct stack *new = malloc(sizeof(struct stack));
    new->prev = prev;
    new->val = val;
    return new;
}

int compare(char *a, char *b){
    return (a[0] == b[0]) && (a[1] == b[1]);
}

int main() {
    struct stack *s = NULL;
    char *instruction = calloc(6, sizeof(char));
    long x;
    scanf("%s", instruction);
    while (!compare(instruction, "END")) {
        if (compare(instruction, "CONST")) {
            scanf("%ld", &x);
            s = newStack(x, s);
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "ADD")) {
            struct stack *first = s;
            struct stack *second = s->prev;
            long res = first->val + second->val;
            free(first);
            s = second->prev;
            free(second);
            s = newStack(res, s);
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "SUB")) {
            struct stack *first = s;
            struct stack *second = s->prev;
            long res = first->val - second->val;
            free(first);
            s = second->prev;
            free(second);
            s = newStack(res, s);
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "MUL")) {
            struct stack *first = s;
            struct stack *second = s->prev;
            long res = first->val * second->val;
            free(first);
            s = second->prev;
            free(second);
            s = newStack(res, s);
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "DIV")) {
            struct stack *first = s;
            struct stack *second = s->prev;
            long res = first->val / second->val;
            free(first);
            s = second->prev;
            free(second);
            s = newStack(res, s);
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "MAX")) {
            struct stack *first = s;
            struct stack *second = s->prev;
            long res = first->val > second->val ? first->val : second->val;
            free(first);
            s = second->prev;
            free(second);
            s = newStack(res, s);
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "MIN")) {
            struct stack *first = s;
            struct stack *second = s->prev;
            long res = first->val < second->val ? first->val : second->val;
            free(first);
            s = second->prev;
            free(second);
            s = newStack(res, s);
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "NEG")) {
            s->val = -s->val;
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "DUP")) {
            s = newStack(s->val, s);
            scanf("%s", instruction);
            continue;
        }
        if (compare(instruction, "SWAP")) {
            struct stack *first = s;
            struct stack *second = s->prev;
            first->prev = second->prev;
            second->prev = first;
            s = second;
            scanf("%s", instruction);
            continue;
        }
    }
    printf("%ld", s->val);
    while (s != NULL){
        struct stack *prev;
        prev = s->prev;
        free(s);
        s = prev;
    }
    free(instruction);
    return 0;
}