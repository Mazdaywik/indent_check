#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct DoubleStack
{
    int cap, top1, top2;
    long *data;
};

void InitStack(struct DoubleStack *my_stack, int n)
{
    my_stack->cap = n;
    my_stack->top1 = 0;
    my_stack->top2 = n - 1;
    my_stack->data = (long *)malloc(n * sizeof(long));
}

int StackEmpty1(struct DoubleStack *my_stack) // t - 1; f - 2
{
    return (my_stack->top1 == 0);
}

int StackEmpty2(struct DoubleStack *my_stack) // t - 1; f - 2
{
    return (my_stack->top2 == my_stack->cap - 1);
}

void Push1(struct DoubleStack *my_stack, struct DoubleStack *max_stack, long number)
{
    if (my_stack->top2 < my_stack->top1)
        printf("переполнение");
    else
    {
        if (my_stack->top1 == 0)
            (max_stack->data)[my_stack->top1] = number;
        else
            (max_stack->data)[my_stack->top1] = (long)fmax(number, (max_stack->data)[my_stack->top1 - 1]);
        
        (my_stack->data)[my_stack->top1] = number;
        my_stack->top1++;
    }
}

void Push2(struct DoubleStack *my_stack, struct DoubleStack *max_stack, long number)
{
    if (my_stack->top2 < my_stack->top1)
        printf("переполнение");
    else
    {
        if (my_stack->top2 == my_stack->cap - 1)
            (max_stack->data)[my_stack->top2] = number;
        else
            (max_stack->data)[my_stack->top2] = (long)fmax(number, (max_stack->data)[my_stack->top2 + 1]);
        
        (my_stack->data)[my_stack->top2] = number;
        my_stack->top2--;
    }
}

long Pop1(struct DoubleStack *my_stack)
{
    if (StackEmpty1(my_stack))
        printf("опустошение");
    else
    {
        my_stack->top1--;
        return (my_stack->data)[my_stack->top1];
    }
}

long Pop2(struct DoubleStack *my_stack)
{
    if (StackEmpty2(my_stack))
        printf("опустошение");
    else
    {
        my_stack->top2++;
        return (my_stack->data)[my_stack->top2];
    }
}

void InitQueueOnStack(struct DoubleStack *my_queue, int n)
{
    InitStack(my_queue, n);
}

int QueueEmpty(struct DoubleStack *my_queue) // t - 1; f - 2
{
    return (StackEmpty1(my_queue) && StackEmpty2(my_queue));
}

void Enqueue(struct DoubleStack *my_queue, struct DoubleStack *max_stack, long number)
{
    Push1(my_queue, max_stack, number);
}

long Dequeue(struct DoubleStack *my_queue, struct DoubleStack *max_stack)
{
    if (StackEmpty2(my_queue))
    {
        while (StackEmpty1(my_queue) == 0)
            Push2(my_queue, max_stack, Pop1(my_queue));
    }
    return Pop2(my_queue);
}

long Maximum(struct DoubleStack *max_stack, int i, int j)
{
    if (i == 0)
        return (max_stack->data)[j + 1];
    else if (j == max_stack->cap - 1)
        return (max_stack->data)[i - 1];
    else
        return (long)fmax((max_stack->data)[i - 1], (max_stack->data)[j + 1]);
}

int main()
{
    struct DoubleStack my_queue, max_stack;
    InitQueueOnStack(&my_queue, 1000000);
    InitStack(&max_stack, 1000000);

    char word[6];
    scanf("%s", word);

    while (strcmp(word, "END") != 0)
    {
        if (strcmp(word, "ENQ") == 0)
        {
            long number;
            scanf("%ld", &number);
            Enqueue(&my_queue, &max_stack, number);
        }

        else if (strcmp(word, "DEQ") == 0)
            printf("%ld\n", Dequeue(&my_queue, &max_stack));

        else if (strcmp(word, "MAX") == 0)
            printf("%ld\n", Maximum(&max_stack, my_queue.top1, my_queue.top2));        

        else if (strcmp(word, "EMPTY") == 0)
        {
            if (QueueEmpty(&my_queue))
                printf("true\n");
            else
                printf("false\n");
        }
/*
        for(int i = 0; i < 5; i++)
            printf("%ld ", max_stack.data[i]);
        printf("\n");
*/
        scanf("%s", word);
    }

    free(my_queue.data);
    free(max_stack.data);

    return 0;
}