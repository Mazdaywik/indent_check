#include <stdio.h>
#include <stdlib.h>

struct Task {
    int low, high;
};

struct Stack {
    struct Task tasks[1000];
    int top;
};

void initStack(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, struct Task task) {
    stack->tasks[++stack->top] = task;
}

struct Task pop(struct Stack *stack) {
    return stack->tasks[stack->top--];
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Нерекурсивная быстрая сортировка с использованием стека заданий
void quickSort(int arr[], int low, int high) {
    struct Stack stack;
    initStack(&stack);
    struct Task initialTask = {low, high};
    push(&stack, initialTask);
    while (stack.top >= 0) {
        struct Task currentTask = pop(&stack);
        low = currentTask.low;
        high = currentTask.high;
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex - 1 > low) {
            struct Task leftTask = {low, pivotIndex - 1};
            push(&stack, leftTask);
        }
        if (pivotIndex + 1 < high) {
            struct Task rightTask = {pivotIndex + 1, high};
            push(&stack, rightTask);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    free(arr);
    return 0;
}
