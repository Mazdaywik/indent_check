#include <stdio.h>
#include <stdlib.h>

struct Task
{
    int low, high;
};

struct Stack
{
    int cap, top;
    struct Task *data;
};

void InitStack(struct Stack *stack, int n)
{
    stack->data = (struct Task *)malloc(sizeof(struct Task) * n);
    stack->cap = n;
    stack->top = 0;
}

int StackEmpty(struct Stack *stack)
{
    return stack->top == 0;
}

void Push(struct Stack *stack, struct Task x)
{
    stack->data[stack->top] = x;
    stack->top++;
}

struct Task Pop(struct Stack *stack)
{
    stack->top--;
    return stack->data[stack->top];
}

int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; ++j) {
        if (arr[j] < pivot) {
            int intermediate = arr[i];
            arr[i] = arr[j];
            arr[j] = intermediate;
            i++;
        }
    }
    int intermediate = arr[i];
    arr[i] = pivot;
    arr[right] = intermediate;
    return i;
}

void quicksort(int *arr, int n) {
    struct Stack stack;
    InitStack(&stack, n);
    struct Task task;
    task.high = n - 1;
    task.low = 0;
    Push(&stack, task);
    
    while (!StackEmpty(&stack)) {
        struct Task currentTask = Pop(&stack);
        int l = currentTask.low;
        int r = currentTask.high;
        while (l < r) {
            int part = partition(arr, l, r);
            if (part - l < r - part) {
               struct Task newTask;
               newTask.low = l;
               newTask.high = part - 1;
               Push(&stack, newTask);
               l = part + 1;
            } else {
               struct Task newTask;
               newTask.low = part + 1;
               newTask.high = r;
               Push(&stack, newTask);
               r = part - 1;
            }
        }
    }
    free(stack.data);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
}