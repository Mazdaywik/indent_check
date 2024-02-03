#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100000

typedef struct {
    int stack[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack* s, int value) {
    s->stack[++s->top] = value;
}

int pop(Stack* s) {
    return s->stack[s->top--];
}

void add(Stack* s) {
    int a = pop(s);
    int b = pop(s);
    push(s, a + b);
}

void subtract(Stack* s) {
    int a = pop(s);
    int b = pop(s);
    push(s, a - b);
}

void multiply(Stack* s) {
    int a = pop(s);
    int b = pop(s);
    push(s, a * b);
}

void divide(Stack* s) {
    int a = pop(s);
    int b = pop(s);
    push(s, a / b);
}

void maximum(Stack* s) {
    int a = pop(s);
    int b = pop(s);
    push(s, a > b ? a : b);
}

void minimum(Stack* s) {
    int a = pop(s);
    int b = pop(s);
    push(s, a < b ? a : b);
}

void negative(Stack* s) {
    int a = pop(s);
    push(s, -a);
}

void duplicate(Stack* s)
{
    int val = s->stack[s->top];
    s->stack[++s->top] = val;
}

void swap(Stack* s)
{
    int temp = s->stack[s->top];
    s->stack[s->top] = s->stack[s->top - 1];
    s->stack[s->top - 1] = temp;
}

void constant(Stack* s, int value)
{
    push(s, value);
}

int performOperation(Stack* s, char* operation) {
    if (strcmp(operation, "ADD") == 0) {
        add(s);
    }
    else if (strcmp(operation, "SUB") == 0) {
        subtract(s);
    }
    else if (strcmp(operation, "MUL") == 0) {
        multiply(s);
    }
    else if (strcmp(operation, "DIV") == 0) {
        divide(s);
    }
    else if (strcmp(operation, "MAX") == 0) {
        maximum(s);
    }
    else if (strcmp(operation, "MIN") == 0) {
        minimum(s);
    }
    else if (strcmp(operation, "NEG") == 0) {
        negative(s);
    }
    else if (strcmp(operation, "DUP") == 0) {
        duplicate(s);
    }
    else if (strcmp(operation, "SWAP") == 0) {
        swap(s);
    }
    else if (strcmp(operation, "CONST") == 0) {
        int value;
        scanf("%d", &value);
        constant(s, value);
    }
    else if (strcmp(operation, "END") == 0) {
        return 0;
    }
    else {
        printf("Несуществующая операция\n");
        return 0;
    }
    return 1;
}

int main() {
    Stack stack;
    stack.top = -1;

    while (1) {
        char operation[MAX_STACK_SIZE];
        scanf("%s", operation);

        if (!performOperation(&stack, operation)) {
            break;
        }
    }

    printf("%d\n", pop(&stack));

    return 0;
}