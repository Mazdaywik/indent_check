
#include <stdio.h>
#include <stdlib.h>

struct Task {
    int low, high;
};

struct Stack {
    int top;
    unsigned capacity;
    struct Task* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Task*)malloc(stack->capacity * sizeof(struct Task));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(struct Stack* stack, struct Task item) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}

struct Task pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        struct Task emptyTask = {-1, -1}; 
        return emptyTask;
    }
    return stack->array[stack->top--];
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortIterative(int arr[], int l, int h) {
    struct Stack* stack = createStack(h - l + 1);

    struct Task task = { l, h };
    push(stack, task);

    while (!isEmpty(stack)) {
        task = pop(stack);
        l = task.low;
        h = task.high;

        int p = partition(arr, l, h);
        if (p - 1 > l) {
            struct Task leftSubtask = { l, p - 1 };
            push(stack, leftSubtask);
        }

        if (p + 1 < h) {
            struct Task rightSubtask = { p + 1, h };
            push(stack, rightSubtask);
        }
    }
    free(stack->array);
    free(stack);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSortIterative(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}