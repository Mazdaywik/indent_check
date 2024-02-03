
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long int* arr;
    long long int cap;
    long long int size;
} stack_t;

stack_t* make_stack() {
    stack_t *new;
    new = (stack_t*)malloc(sizeof(stack_t));
    (*new).cap = 10;
    (*new).size = 0;
    (*new).arr = malloc(sizeof(long long int) * 10);
    return new;
}

void push(stack_t* st, long long int val) {
    if ((*st).size == (*st).cap) {
        (*st).arr = realloc((*st).arr, (*st).cap * 2 * sizeof(long long int));
        (*st).cap *= 2;
    }
    (*st).arr[(*st).size] = val;
    (*st).size++;
}

long long int top(stack_t* st) {
    return (*st).arr[(*st).size - 1];
}

long long int pop(stack_t* st) {
    long long int val = top(st);
    (*st).size--;
    return val;
}

void cleanup(stack_t* st) {
    free((*st).arr);
    free(st);
}

void max_handler(stack_t* st) {
    long long int a = pop(st);
    long long int b = pop(st);
    if (a > b) push(st, a);
    else push(st, b);
}

void min_handler(stack_t* st) {
    long long int a = pop(st);
    long long int b = pop(st);
    if (a < b) push(st, a);
    else push(st, b);
}



int main() {
    stack_t* st = make_stack();
    while (1 == 1) {
        char* command;
        scanf("%ms", &command);
        if (strcmp(command, "END") == 0){
            free(command);
            break;
        }
        if (strcmp(command, "CONST") == 0) {
            long long int x;
            scanf("%lld", &x);
            push(st, x);
        } 
        else if (strcmp(command, "ADD") == 0) {
            long long int a = pop(st);
            long long int b = pop(st);
            push(st, a + b);
        } 
        else if (strcmp(command, "SUB") == 0) {
            long long int a = pop(st);
            long long int b = pop(st);
            push(st, a - b);
        } 
        else if (strcmp(command, "MUL") == 0) {
            long long int a = pop(st);
            long long int b = pop(st);
            push(st, a * b);
        } 
        else if (strcmp(command, "DIV") == 0) {
            long long int a = pop(st);
            long long int b = pop(st);
            push(st, a / b);
        } 
        else if (strcmp(command, "MAX") == 0) {
            max_handler(st);
        } 
        else if (strcmp(command, "MIN") == 0) {
            min_handler(st);
        } 
        else if (strcmp(command, "NEG") == 0) {
            long long int a = pop(st);
            push(st, -a);
        } 
        else if (strcmp(command, "DUP") == 0) {
            push(st, top(st));
        } 
        else if (strcmp(command, "SWAP") == 0) {
                long long int a = pop(st);
                long long int b = pop(st);
                push(st, a);
                push(st, b);
        }
        free(command);
    }
    printf("%lld\n", top(st));
    cleanup(st);
    return 0;
}