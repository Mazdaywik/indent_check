#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1000000

typedef struct 
{
    int data[STACK_SIZE];
    int top;
} Stack;

void push(Stack *stack, int value) 
{
    if (stack->top == STACK_SIZE) 
    {
        exit(1);
    }
    stack->data[stack->top++] = value;
}

int pop(Stack *stack) 
{
    if (stack->top == 0) 
    {
        exit(1);
    }
    return stack->data[--stack->top];
}

int main() {
    Stack stack;
    stack.top = 0;

    char operation[5];
    int value;

    while (scanf("%s", operation) == 1) 
    {
        if (strcmp(operation, "CONST") == 0) 
        {
            scanf("%d", &value);
            push(&stack, value);
        } 
        else if (strcmp(operation, "ADD") == 0) 
        {
            int a = pop(&stack);
            int b = pop(&stack);
            push(&stack, a + b);
        } 
        else if (strcmp(operation, "SUB") == 0) 
        {
            int a = pop(&stack);
            int b = pop(&stack);
            push(&stack, a - b);
        } 
        else if (strcmp(operation, "MUL") == 0) 
        {
            int a = pop(&stack);
            int b = pop(&stack);
            push(&stack, a * b);
        } 
        else if (strcmp(operation, "DIV") == 0)
        {
        int a = pop(&stack);
        int b = pop(&stack);
        if (b == 0)
        {   
            exit(EXIT_FAILURE);
        }
        push(&stack, a / b);
        }
        else if (strcmp(operation, "MAX") == 0) 
        {
            int a = pop(&stack);
            int b = pop(&stack);
            push(&stack, a > b ? a : b);
        } 
        else if (strcmp(operation, "MIN") == 0) 
        {
            int a = pop(&stack);
            int b = pop(&stack);
            push(&stack, a < b ? a : b);
        } 
        else if (strcmp(operation, "NEG") == 0) 
        {
            int a = pop(&stack);
            push(&stack, -a);
        } 
        else if (strcmp(operation, "DUP") == 0) 
        {
            int a = pop(&stack);
            push(&stack, a);
            push(&stack, a);
        } 
        else if (strcmp(operation, "SWAP") == 0) 
        {
            int a = pop(&stack);
            int b = pop(&stack);
            push(&stack, a);
            push(&stack, b);
        } 
        else if (strcmp(operation, "END") == 0) 
        {
            break;
        }
    }

    printf("%d", pop(&stack));

    return 0;
}
