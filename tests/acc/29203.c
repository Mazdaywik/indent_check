#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int capacity;
    int top;
    int *elements;
};

void InitStack(struct Stack *stack, int capacity) {
    stack->capacity = capacity;
    stack->top = -1;
    stack->elements = (int *)malloc(sizeof(int) * capacity);
}

int StackEmpty(struct Stack stack) {
    return stack.top == -1;
}

void Push(struct Stack *stack, int element) {
    stack->elements[++stack->top] = element;
}

int Pop(struct Stack *stack) {
    return stack->elements[stack->top--];
}

int main() {
    struct Stack stack;
    InitStack(&stack, 100000000);
    char command[10];
    int value, a, b;
    do {
        scanf("%s", command);
        if (strcmp(command, "CONST") == 0) {
            scanf("%d", &value);
            Push(&stack, value);
        }
        else if (strcmp(command, "ADD") == 0) {
            a = Pop(&stack);
            b = Pop(&stack);
            Push(&stack, a + b);
        }
        else if (strcmp(command, "SUB") == 0) {
            a = Pop(&stack);
            b = Pop(&stack);
            Push(&stack, a - b);
        }
        else if (strcmp(command, "MUL") == 0) {
            a = Pop(&stack);
            b = Pop(&stack);
            Push(&stack, a * b);
        }
        else if (strcmp(command, "DIV") == 0) {
            a = Pop(&stack);
            b = Pop(&stack);
            Push(&stack, a / b);
        }
        else if (strcmp(command, "MAX") == 0) {
            a = Pop(&stack);
            b = Pop(&stack);
            Push(&stack, (a > b) ? a : b);
        } 
        else if (strcmp(command, "MIN") == 0) {
            a = Pop(&stack);
            b = Pop(&stack);
            Push(&stack, (a < b) ? a : b);
        } 
        else if (strcmp(command, "NEG") == 0) {
            a = Pop(&stack);
            Push(&stack, -a);
        } 
        else if (strcmp(command, "DUP") == 0) {
            a = Pop(&stack);
            Push(&stack, a);
            Push(&stack, a);
        } 
        else if (strcmp(command, "SWAP") == 0) {
            a = Pop(&stack);
            b = Pop(&stack);
            Push(&stack, a);
            Push(&stack, b);
        }
    } while (strcmp(command, "END") != 0);

    if (!StackEmpty(stack)) printf("%d", Pop(&stack));
    free(stack.elements);
    return 0;
}