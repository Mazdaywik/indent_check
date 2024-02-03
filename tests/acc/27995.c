#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxInt(int a, int b) {
    return a > b ? a : b;
}

int minInt(int a, int b) {
    return a < b ? a : b;
}

typedef struct Stack_ {
    int* buffer;
    int size;
    int capacity;
} Stack;

void initStack(Stack* stck) {
    stck->size = 0;
    stck->capacity = 128;
    stck->buffer = (int*)malloc(stck->capacity * sizeof(int));
}

void deleteStack(Stack* stck) {
    stck->size = 0;
    stck->capacity = 0;
    free(stck->buffer);
}

void resizeStack(Stack* stck) {
    int* old_buffer = stck->buffer;
    stck->capacity *= 2;
    stck->buffer = (int*)malloc(stck->capacity * sizeof(int));
    for (int i = 0; i < stck->size; ++i) {
        stck->buffer[i] = old_buffer[i];
    }
    free(old_buffer);
}

void pushStack(Stack* stck, int value) {
    if (stck->size == stck->capacity) {
        resizeStack(stck);
    }
    stck->buffer[stck->size] = value;
    ++stck->size;
}

int popStack(Stack* stck) {
    int value = 0;
    if (stck->size) {
        value = stck->buffer[--stck->size];
    }
    return value;
}

int topStack(Stack* stck) {
    return stck->buffer[stck->size - 1];
}


void addOperation(Stack* ptr_stack) {
    pushStack(ptr_stack, popStack(ptr_stack) + popStack(ptr_stack));
}

void subOperation(Stack* ptr_stack) {
    pushStack(ptr_stack, popStack(ptr_stack) - popStack(ptr_stack));
}

void mulOperation(Stack* ptr_stack) {
    pushStack(ptr_stack, popStack(ptr_stack) * popStack(ptr_stack));
}

void divOperation(Stack* ptr_stack) {
    pushStack(ptr_stack, popStack(ptr_stack) / popStack(ptr_stack));
}

void maxOperation(Stack* ptr_stack) {
    pushStack(ptr_stack, maxInt(popStack(ptr_stack), popStack(ptr_stack)));
}

void minOperation(Stack* ptr_stack) {
    pushStack(ptr_stack, minInt(popStack(ptr_stack), popStack(ptr_stack)));
}

void negOperation(Stack* ptr_stack) {
    pushStack(ptr_stack, -popStack(ptr_stack));
}

void dupOperation(Stack* ptr_stack) {
    pushStack(ptr_stack, topStack(ptr_stack));
}

void swapOperation(Stack* ptr_stack) {
    int a = popStack(ptr_stack);
    int b = popStack(ptr_stack);
    pushStack(ptr_stack, a);
    pushStack(ptr_stack, b);
}

void runStackMachine(Stack* ptr_stack) {
    char operation[10];
    int value;
    do {
        scanf("%s", operation);
        if (!strcmp(operation, "CONST")) {
            scanf("%d", &value);
            pushStack(ptr_stack, value);
        } else if (!strcmp(operation, "ADD")) {
            addOperation(ptr_stack);
        } else if (!strcmp(operation, "SUB")) {
            subOperation(ptr_stack);
        } else if (!strcmp(operation, "MUL")) {
            mulOperation(ptr_stack);
        } else if (!strcmp(operation, "DIV")) {
            divOperation(ptr_stack);
        } else if (!strcmp(operation, "MAX")) {
            maxOperation(ptr_stack);
        } else if (!strcmp(operation, "MIN")) {
            minOperation(ptr_stack);
        } else if (!strcmp(operation, "NEG")) {
            negOperation(ptr_stack);
        } else if (!strcmp(operation, "DUP")) {
            dupOperation(ptr_stack);
        } else if (!strcmp(operation, "SWAP")) {
            swapOperation(ptr_stack);
        }
    } while (strcmp(operation, "END"));
}

int main() {
    Stack stack;
    initStack(&stack);
    runStackMachine(&stack);
    printf("%d\n", popStack(&stack));
    deleteStack(&stack);
    return 0;
}
