#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxInt(int a, int b) {
    return a > b ? a : b;
}

typedef struct Stack_ {
    int size;
    int capacity;
    int* buffer;
    int* maximums;
} Stack;

void initStack(Stack* stck, int capacity) {
    stck->size = 0;
    stck->capacity = capacity;
    stck->buffer = (int* )malloc(stck->capacity * sizeof(int));
    stck->maximums = (int*) malloc(stck->capacity * sizeof(int));
}

void deleteStack(Stack* stck) {
    stck->size = 0;
    stck->capacity = 0;
    free(stck->buffer);
    free(stck->maximums);
}

void resizeStack(Stack* stck) {
    int* old_buffer = stck->buffer;
    int* old_maximums = stck->maximums;
    stck->capacity *= 2;
    stck->buffer = (int*) malloc(stck->capacity * sizeof(int));
    stck->maximums = (int*) malloc(stck->capacity * sizeof(int));
    for (int i = 0; i < stck->size; ++i) {
        stck->buffer[i] = old_buffer[i];
        stck->maximums[i] = old_maximums[i];
    }
    free(old_buffer);
    free(old_maximums);
}

void pushStack(Stack* stck, int value) {
    if (stck->size == stck->capacity) {
        resizeStack(stck);
    }
    stck->buffer[stck->size] = value;
    stck->maximums[stck->size] = (stck->size != 0) ? maxInt(value, stck->maximums[stck->size - 1]) : value;
    ++stck->size;
}

int popStack(Stack* stack) {
    return stack->buffer[--stack->size];
}

int topStack(Stack* stack) {
    return stack->buffer[stack->size - 1];
}

int maxStack(Stack* stack) {
    return stack->maximums[stack->size - 1];
}

int isEmptyStack(Stack* stack) {
    return stack->size == 0;
}

int isFullStack(Stack* stack) {
    return stack->size == stack->capacity;
}


typedef struct Queue_ {
    Stack lstack;
    Stack rstack;
} Queue;

void initQueue(Queue* queue, int capacity) {
    initStack(&queue->lstack, capacity);
    initStack(&queue->rstack, capacity);
}

void deleteQueue(Queue* queue) {
    deleteStack(&queue->lstack);
    deleteStack(&queue->rstack);
}

void enqueQueue(Queue* queue, int value) {
    pushStack(&queue->lstack, value);
}

int dequeQueue(Queue* queue) {
    if (isEmptyStack(&queue->rstack)) {
        while (!isEmptyStack(&queue->lstack)) {
            pushStack(&queue->rstack, popStack(&queue->lstack));
        }
    }
    return popStack(&queue->rstack);
}

int isQueueEmpty(Queue* queue) {
    return isEmptyStack(&queue->lstack) && isEmptyStack(&queue->rstack);
}

int maxQueue(Queue* queue) {
    if (!isEmptyStack(&queue->lstack) && !isEmptyStack(&queue->rstack)) {
        return maxInt(maxStack(&queue->lstack), maxStack(&queue->rstack));
    } else {
        return isEmptyStack(&queue->rstack) ? maxStack(&queue->lstack) : maxStack(&queue->rstack);
    }
}


int main() {
    int value;
    char operation[10];
    Queue queue;

    initQueue(&queue, 4);

    do {
        scanf("%s", operation);
        if (!strcmp(operation, "ENQ")) {
            scanf("%d", &value);
            enqueQueue(&queue, value);
        } else if (!strcmp(operation, "DEQ")) {
            printf("%d\n", dequeQueue(&queue));
        } else if (!strcmp(operation, "MAX")) {
            printf("%d\n", maxQueue(&queue));
        } else if (!strcmp(operation, "EMPTY")) {
            printf("%s\n", (isQueueEmpty(&queue) ? "true" : "false"));
        }
    } while (strcmp(operation, "END"));

    deleteQueue(&queue);
    return 0;
}
