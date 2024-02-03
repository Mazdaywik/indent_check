#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_STACK_SIZE 100

int* stack;
int top = -1;
int count = 0;
int stack_size = INITIAL_STACK_SIZE;

void push(int value) {
    if (top < stack_size - 1) {
        top++;
        stack[top] = value;
    }
    else {
        stack_size *= 2;
        stack = realloc(stack, stack_size * sizeof(int));
        if (stack == NULL) {
            fprintf(stderr, "Error: Unable to resize the stack\n");
            exit(EXIT_FAILURE);
        }
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top >= 0) {
        int value = stack[top];
        top--;
        return value;
    }
    else {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char operation[10];
    int operand;

    stack = (int*)malloc(stack_size * sizeof(int));
    if (stack == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for the stack\n");
        exit(EXIT_FAILURE);
    }

    while (scanf("%s", operation) == 1) {
        count++;
        if (strcmp(operation, "CONST") == 0) {
            scanf("%d", &operand);
            push(operand);
        }
        else if (strcmp(operation, "ADD") == 0) {
            push(pop() + pop());
        }
        else if (strcmp(operation, "SUB") == 0) {
            int a = pop();
            int b = pop();
            push(a - b);
        }
        else if (strcmp(operation, "MUL") == 0) {
            push(pop() * pop());
        }
        else if (strcmp(operation, "DIV") == 0) {
            int a = pop();
            int b = pop();
            if (b != 0) {
                push(a / b);
            }
            else {
                fprintf(stderr, "Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
        }
        else if (strcmp(operation, "NEG") == 0) {
            push(-pop());
        }
        else if (strcmp(operation, "MAX") == 0) {
            int a = pop();
            int b = pop();
            push(a > b ? a : b);
        }
        else if (strcmp(operation, "MIN") == 0) {
            int a = pop();
            int b = pop();
            push(a < b ? a : b);
        }
        else if (strcmp(operation, "DUP") == 0) {
            push(stack[top]);
        }
        else if (strcmp(operation, "SWAP") == 0) {
            int a = pop();
            int b = pop();
            push(a);
            push(b);
        }
        else if (strcmp(operation, "END") == 0) {
            break;
        }
        else printf("\nWrong input!\n");
    }

    printf("%d\n", stack[top]);

    free(stack);

    return 0;
}