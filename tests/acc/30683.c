#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DoubleStack {
    int *data;
    int cap;
    int top1;
    int top2;
    int *maxs;
};

void InitDoubleStack(struct DoubleStack *s, int n)
{
    s->data = (int*) calloc(n, sizeof(int));
    s->cap = n;
    s->top1 = 0;
    s->top2 = n - 1;
    s->maxs = (int*) calloc(n, sizeof(int));
}

int StackEmpty1(struct DoubleStack *s)
{
    return (s->top1 == 0);
}

int StackEmpty2(struct DoubleStack *s)
{
    return (s->top2 == s->cap - 1);
}

void Push1(struct DoubleStack *s, int x)
{
    if (s->top1 == 0)
        s->maxs[s->top1] = x;
    else if (s->maxs[s->top1 - 1] < x)
        s->maxs[s->top1] = x;
    else
        s->maxs[s->top1] = s->maxs[s->top1 - 1];
    s->data[s->top1] = x;
    s->top1++;
}

void Push2(struct DoubleStack *s, int x)
{
    if (s->top2 == (s->cap - 1))
        s->maxs[s->top2] = x;
    else if (s->maxs[s->top2 + 1] < x)
        s->maxs[s->top2] = x;
    else
        s->maxs[s->top2] = s->maxs[s->top2 + 1];
    s->data[s->top2] = x;
    s->top2--;
}
 

int Pop1(struct DoubleStack *s)
{
    s->top1--;
    return s->data[s->top1];
}

int Pop2(struct DoubleStack *s)
{
    s->top2++;
    return s->data[s->top2];
}

void InitQueueOnStack(struct DoubleStack *s, int n)
{
    InitDoubleStack(s, n);
}

int QueueEmpty(struct DoubleStack *s)
{
    return (StackEmpty1(s) && StackEmpty2(s));
}

void Enqueue(struct DoubleStack *s, int x)
{
    Push1(s, x);
}

int Dequeue(struct DoubleStack *s)
{
    if (StackEmpty2(s))
        while (!StackEmpty1(s))
            Push2(s, Pop1(s));
    return Pop2(s);
}

int Maximum(struct DoubleStack *s)
{
    if (!StackEmpty1(s) && StackEmpty2(s))
        return s->maxs[s->top1 - 1];
    else if (!StackEmpty1(s) && !StackEmpty2(s)
             && (s->maxs[s->top2 + 1] < s->maxs[s->top1 - 1]))
        return s->maxs[s->top1 - 1];
    else
        return s->maxs[s->top2 + 1];
}

 
int main()
{
    struct DoubleStack stack;
    InitQueueOnStack(&stack, 1000000);
    
    char action[6];
    scanf("%s", action);
    
    while (strcmp("END", action) != 0) {
        if (strcmp("ENQ", action) == 0) {
            int x;
            scanf("%d", &x);
            Enqueue(&stack, x);
        }
        else if (strcmp("DEQ", action) == 0) {
            printf("%d\n", Dequeue(&stack));
        }
        else if (strcmp("EMPTY", action) == 0) {
            if (QueueEmpty(&stack)) printf("true\n");
            else printf("false\n");
        }
        else if (strcmp("MAX", action) == 0) {
            printf("%d\n", Maximum(&stack));
        }
        scanf("%s", action);
    }
    free(stack.data);
    free(stack.maxs);
    return 0;
}
