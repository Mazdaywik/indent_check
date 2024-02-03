#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

struct Task {
    int low, high;
};

struct Stack {
    struct Task tasks[STACK_SIZE];
    int top;
};

void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

int isFull(struct Stack *stack) {
    return stack->top == STACK_SIZE - 1;
}

void push(struct Stack *stack, struct Task task) {
    if (!isFull(stack)) {
        stack->tasks[++stack->top] = task;
    } else {
        exit(EXIT_FAILURE);
    }
}

struct Task pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->tasks[stack->top--];
    } else {
        exit(EXIT_FAILURE);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void iterativeQuickSort(int arr[], int low, int high) {
    struct Stack stack;
    initializeStack(&stack);

    struct Task initialTask = {low, high};
    push(&stack, initialTask);

    while (!isEmpty(&stack)) {
        struct Task currentTask = pop(&stack);
        low = currentTask.low;
        high = currentTask.high;

        while (low < high) {
            int pivotIndex = partition(arr, low, high);

            if (pivotIndex - low < high - pivotIndex) {
                push(&stack, (struct Task){pivotIndex + 1, high});
                high = pivotIndex - 1;
            } else {
                push(&stack, (struct Task){low, pivotIndex - 1});
                low = pivotIndex + 1;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    iterativeQuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
