#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task
{
    int low, high;
};

struct Stack
{
    int cap;
    int top;
    struct Task *data;
};

void stack_init(struct Stack *s, int n)
{
    s->data = (struct Task*)malloc(sizeof(struct Task) * n);
    s->cap = n;
    s->top = 0;
}


int stack_empty(struct Stack s)
{
    return s.top == 0;
}

void stack_push(struct Stack *s, struct Task x)
{
    if (s->top == s->cap)
    {
        exit(1);
    }
    s->data[s->top] = x;
    s->top++;
}

struct Task stack_pop(struct Stack *s)
{
    s->top--;
    return s->data[s->top];
}


int partition(int *arr, int low, int high)
{
    int r = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < r)
        {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}


void quickSort(int *arr, int n) {
    struct Stack s;
    stack_init(&s, n);
    struct Task begin_task;
    begin_task.low = 0;
    begin_task.high = n - 1;
    stack_push(&s, begin_task);
    while (!stack_empty(s)) {
        struct Task cur_task = stack_pop(&s);
        int lo = cur_task.low, hi = cur_task.high;
        while (lo < hi) {
            int q = partition(arr, lo, hi);
            if (q - lo > hi - q) {
                struct Task new_task;
                new_task.low = lo;
                new_task.high = q - 1;
                stack_push(&s, new_task);
                lo = q + 1;
            } else {
                struct Task new_task;
                new_task.low = q + 1;
                new_task.high = hi;
                stack_push(&s, new_task);
                hi = q - 1;
            }
        }
    }
    free(s.data);
}


int main()
{
    int n;
    scanf("%d", &n);
    int *a;
    a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quickSort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}
