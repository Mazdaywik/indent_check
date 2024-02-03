#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

struct Task {
    int low, high;
};

struct Stack {
    int capacity;
    int top;
    struct Task *task;
};

void InitStack(struct Stack *s, int n) {
    s->top = 0;
    s->capacity = n;
    s->task = (struct Task *)malloc(sizeof(struct Task)*n);
}

int StackEmpty(struct Stack s) {
    return s.top == 0;
}

void Push(struct Stack *s, struct Task x) {
    s->task[s->top] = x;
    s->top++;
}

struct Task Pop(struct Stack *s) {
    s->top--;
    return s->task[s->top];
}

int Partition(int a[], int low, int high)
{
    int elem = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < elem) {
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i+1, high);
    return i+1;
}

void QuickSort(int *a, int n) {
    struct Stack s;
    InitStack(&s, n);
    struct Task task;
    task.low = 0;
    task.high = n - 1;
    Push(&s, task);

    while (!StackEmpty(s)) {
        task = Pop(&s);
        int low = task.low;
        int high = task.high;
        if (low < high) {
            int op = Partition(a, low, high);
            struct Task left_task, right_task;
            left_task.low = low;
            left_task.high = op - 1;
            right_task.low = op + 1;
            right_task.high = high;
            Push(&s, right_task);
            Push(&s, left_task);
        }
    }

    free(s.task);
}


int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    QuickSort(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}