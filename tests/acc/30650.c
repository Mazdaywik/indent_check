#include <stdio.h>
#include <stdlib.h>

struct Task {
    int low, high;
};

struct Stack {
    struct Task *data;
    int cap;
    int top;
};

void InitStack(struct Stack *s, int n)
{
    s->data = (struct Task *) calloc(n, sizeof(struct Task));
    s->cap = n;
    s->top = 0;
}

int StackEmpty(struct Stack *s)
{
    return (s->top == 0);
}

void Push(struct Stack *s, struct Task x)
{
    if (s->top == s->cap) printf("error");
    else {
        s->data[s->top] = x;
        s->top++;
    }
}

struct Task Pop(struct Stack *s)
{
    s->top--;
    return s->data[s->top];
}


void swap(int *arr, size_t a, size_t b)
{
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}

int Partion(int *arr, int low, int high)
{
    int i = low;
    int j = low;
    while (j <= high) {
        if (arr[high] > arr[j]) {
            swap(arr, i, j);
            i++;
        }
        j++;
    }
    swap(arr, i, high);
    return i;
}

void QuickSortStack(int *arr, int low, int high)
{
    int n = high - low + 1;
    struct Stack stack;
    InitStack(&stack, n);
    
    struct Task first_task;
    
    first_task.low = low;
    first_task.high = high;
    
    Push(&stack, first_task);
    
    while (StackEmpty(&stack) == 0) {
        struct Task task = Pop(&stack);
        low = task.low;
        high = task.high;
        
        int i = Partion(arr, low, high);
        
        if (low < i) {
            struct Task left;
            left.low = low;
            left.high = i - 1;
            Push(&stack, left);
        }
        if (high > i) {
            struct Task right;
            right.low = i + 1;
            right.high = high;
            Push(&stack, right);
        }
    }
    free(stack.data);
}

void QuickSort(int *arr, int n)
{
    QuickSortStack(arr, 0, n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    QuickSort(arr, n);
    
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}

