#include <stdio.h>

struct Task {
    int low, high;
};

struct Stack {
    struct Task data[100];
    int cap;
    int top;
};

void stackInit(struct Stack* s, int n) {
    s->cap = n;
    s->top = 0;
}

int stackIsEmpty(struct Stack s) {
    return s.top == 0;
}

void stackPush(struct Stack* s, struct Task x) {
    if (s->top == s->cap) {
        printf("Переполнение стека");
        return;
    }
    s->data[s->top] = x;
    s->top++;
}

struct Task stackPop(struct Stack* s) {
    if (stackIsEmpty(*s)) {
        printf("Опустошение стека");
        struct Task emptyTask;
        emptyTask.low = -1;
        emptyTask.high = -1;
        return emptyTask;
    }
    s->top--;
    return s->data[s->top];
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

void quickSortIterative(int arr[], int low, int high) {
    struct Task initialTask;
    initialTask.low = low;
    initialTask.high = high;

    struct Stack taskStack;
    stackInit(&taskStack, 100);
    stackPush(&taskStack, initialTask);

    while (!stackIsEmpty(taskStack)) {
        struct Task currentTask = stackPop(&taskStack);
        low = currentTask.low;
        high = currentTask.high;

        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - 1 > low) {
            struct Task newTask;
            newTask.low = low;
            newTask.high = pivotIndex - 1;
            stackPush(&taskStack, newTask);
        }

        if (pivotIndex + 1 < high) {
            struct Task newTask;
            newTask.low = pivotIndex + 1;
            newTask.high = high;
            stackPush(&taskStack, newTask);
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

    quickSortIterative(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
  
    return 0;
}
