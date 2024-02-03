#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) a>b? a : b
#define min(a, b) a<b? a : b
#define p1p2()\
struct pairPop p1 = pop(stack);\
struct pairPop p2 = pop(p1.stack);
#define CONST()\
long long x;\
scanf("%lld", &x);\
stack = push(stack, x);
#define ADD() p1p2()\
stack = push(p2.stack, p1.val + p2.val);
#define SUB() p1p2()\
stack = push(p2.stack, p1.val - p2.val);
#define MUL() p1p2()\
stack = push(p2.stack, p1.val * p2.val);
#define DIV() p1p2()\
stack = push(p2.stack, p1.val / p2.val);
#define MAX() p1p2()\
stack = push(p2.stack, max(p1.val, p2.val));
#define MIN() p1p2()\
stack = push(p2.stack, min(p1.val, p2.val));
#define NEG()\
struct pairPop p1 = pop(stack);\
stack = push(p1.stack, -p1.val);
#define DUP() stack = push(stack, stack->val);
#define SWAP() p1p2()\
stack = push(p2.stack, p1.val);\
stack = push(stack, p2.val);
struct Stack{
    struct Stack *pred;
    struct Stack *next;
    long long val;
};

struct pairPop{
    struct Stack *stack;
    long long val;
};

struct Stack *push(struct Stack *stack, long long val){
    stack->next = malloc(sizeof(struct Stack));
    stack->next->val = val;
    stack->next->next = NULL;
    stack->next->pred = stack;
    return stack->next;
}

struct pairPop pop(struct Stack *stack){
    struct pairPop pair;
    pair.val = stack->val;
    pair.stack = stack->pred;
    pair.stack->next = NULL;
    free(stack);
    return pair;
}


int main() {
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->next=NULL;
    stack->pred=NULL;
    char command[10] = "1234567";
    while (strcmp(command, "END")){
        scanf("%s", command);
        if (!strcmp(command, "CONST")){CONST()}
        if (!strcmp(command, "ADD")) {ADD()}
        if (!strcmp(command, "SUB")) {SUB()}
        if (!strcmp(command, "MUL")) {MUL()}
        if (!strcmp(command, "DIV")) {DIV()}
        if (!strcmp(command, "NEG")) {NEG()}
        if (!strcmp(command, "MAX")) {MAX()}
        if (!strcmp(command, "MIN")) {MIN()}
        if (!strcmp(command, "DUP")) {DUP()}
        if (!strcmp(command, "SWAP")) {SWAP()}
    }
    printf("%lld", stack->val);
    while (stack!=NULL){
        struct Stack *st = stack;
        stack = stack->pred;
        free(st);
    }
    return 0;
}
