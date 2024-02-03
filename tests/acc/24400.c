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

void InitStack(struct Stack *my_stack, int n)
{
    my_stack->data = (struct Task *)malloc(n * sizeof(struct Task));
    my_stack->cap = n;
    my_stack->top = 0;
}

int StackEmpty(struct Stack my_stack)
{
    return (my_stack.top == 0);
}

void Push(struct Stack *my_stack, struct Task t)
{
    if (my_stack->cap == my_stack->top)
        printf("переполнение\n");
    else
    {
        (my_stack->data)[my_stack->top] = t;
        my_stack->top++;
    }
}

struct Task Pop(struct Stack *my_stack)
{
    if (StackEmpty(*my_stack))
        printf("опустошение\n");
    else
    {
        my_stack->top--;
        return (my_stack->data)[my_stack->top];
    }
}

void swap(long *a, long *b)
{
    long t = *a;
    *a = *b;
    *b = t;
}

long partition(long *arr, struct Task t)
{
    long i = t.low, j = t.low;
    while (j < t.high)
    {
        if (*(arr + j) < *(arr + t.high))
        {
            swap(arr + i, arr + j);
            i++;
        }
        j++;
    }
    swap(arr + i, arr + t.high);
    return i;
}

void quick_sort(long *arr, struct Stack *my_stack, long low, long high)
{
    struct Task t;
    t.low = low;
    t.high = high;

    Push(my_stack, t);
    while (!StackEmpty(*my_stack))
    {
        struct Task t = Pop(my_stack);
        if (t.low < t.high)
        {
            long i = partition(arr, t);
            if (i - t.low > t.high - i)
            {
                Push(my_stack, (struct Task){t.low, i - 1});
                Push(my_stack, (struct Task){i + 1, t.high});
            }
            else
            {
                Push(my_stack, (struct Task){i + 1, t.high});
                Push(my_stack, (struct Task){t.low, i - 1});
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    long arr[n];
    for (int i = 0; i < n; i++)
        scanf("%ld", &arr[i]);

    struct Stack my_stack;
    InitStack(&my_stack, n);
    quick_sort(arr, &my_stack, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%ld ", arr[i]);

    free(my_stack.data);

    return 0;
}