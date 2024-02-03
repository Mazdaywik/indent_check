#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    int low, high;
};

typedef struct Stack_ {
    struct Task* buffer;
    int size;
    int capacity;
} Stack;

void initStack(Stack* ptr_stack) {
    ptr_stack->size = 0;
    ptr_stack->capacity = 0;
    ptr_stack->buffer = NULL;
}

void clearStack(Stack* ptr_stack) {
    if (ptr_stack->buffer) {
        free(ptr_stack->buffer);
    }
    initStack(ptr_stack);
}

void pushStack(Stack* ptr_stack, int low, int high) {
    if (ptr_stack->size == ptr_stack->capacity) {
        Stack old_stack = *ptr_stack;
        ptr_stack->capacity = ptr_stack->capacity ? ptr_stack->capacity * 2 : 2;
        ptr_stack->buffer = (struct Task*)malloc(ptr_stack->capacity * sizeof(struct Task));
        memcpy(ptr_stack->buffer, old_stack.buffer, old_stack.size * sizeof(struct Task));
        clearStack(&old_stack);
    }
    ptr_stack->buffer[ptr_stack->size].low = low;
    ptr_stack->buffer[ptr_stack->size].high = high;
    ++ptr_stack->size;
}

struct Task popStack(Stack* ptr_stack) {
    return ptr_stack->buffer[--ptr_stack->size];
}

int sizeStack(Stack* ptr_stack) {
    return ptr_stack->size;
}

void qsstack(int* array, int size) {
    Stack stack;
    initStack(&stack);
    pushStack(&stack, 0, size - 1);
    while (sizeStack(&stack) > 0) {
        struct Task elem = popStack(&stack);
        int low = elem.low;
        int high = elem.high;
        int value = array[(low + high) / 2];
        while (low <= high) {
            for (; array[low] < value; ++low) ;
            for (; value < array[high]; --high) ;
            if (low <= high) {
                int c = array[low];
                array[low] = array[high];
                array[high] = c;
                ++low;
                --high;
            }
        }
        if (elem.low < high) {
            pushStack(&stack, elem.low, high);
        }
        if (low < elem.high) {
            pushStack(&stack, low, elem.high);
        }
    }
    clearStack(&stack);
}

void inputArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        scanf("%d", array + i);
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int* array, size;

    scanf("%d", &size);
    array = (int*) malloc(size * sizeof(int));

    inputArray(array, size);
    qsstack(array, size);
    printArray(array, size);

    free(array);
    return 0;
}