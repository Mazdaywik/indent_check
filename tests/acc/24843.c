#include <stdio.h>
#include <stdlib.h>
#include<string.h>


struct q_construct
{
   long arr[200000], max_arr[200000];
   int top1, top2, len;
};

int main(int argc, char ** argv) 
{
    long max(long a, long b);
    void push1(struct q_construct *q, long x);
    void push2(struct q_construct *q, long x);
    long pop1(struct q_construct *q);
    long pop2(struct q_construct *q);
    int empty1(struct q_construct *q);
    int empty2(struct q_construct *q);
    long max_elem(struct q_construct *q);
    long dequeue(struct q_construct *q);

    long x;
    int len = 200000;
    struct q_construct q;
    q.top1 = 0;
    q.len = len;
    q.top2 = len - 1;

    char s[100];
    while (1)
    {
        scanf("%s", &s);
        if (strcmp("ENQ", s) == 0)
        {
            scanf("%ld", &x);
            push1(&q, x);
        }
        if (strcmp("DEQ", s) == 0)
        {
            printf("%ld\n", dequeue(&q));
        }
        if (strcmp("MAX", s) == 0)
        {
            printf("%ld\n", max_elem(&q));
        }
        if (strcmp("EMPTY", s) == 0)
        {
            if (empty1(&q) & empty2(&q))
                printf("true\n");
            else
                printf("false\n");
        }
        if (strcmp("END", s) == 0)
        {
            break;
        }
    }
    return 0;
}

long max(long a, long b)
{
    if (a > b)
        return a;
    return b;
}

void push1(struct q_construct *q, long x)
{
    if (q->top1 == 0)
        q->max_arr[q->top1] = x;
    else
        q->max_arr[q->top1] = max(q->max_arr[q->top1-1], x);
    q->arr[q->top1] = x;
    q->top1++;
}

void push2(struct q_construct *q, long x)
{
    if (q->top2 == q->len - 1)
        q->max_arr[q->top2] = x;
    else
        q->max_arr[q->top2] = max(q->max_arr[q->top2+1], x);
    q->arr[q->top2] = x;
    q->top2--;
}

long pop1(struct q_construct *q)
{
    q->top1--;
    return q->arr[q->top1];
}

long pop2(struct q_construct *q)
{
    q->top2++;
    return q->arr[q->top2];
}

int empty1(struct q_construct *q)
{
    return !q->top1;
}

int empty2(struct q_construct *q)
{
    return q->top2 == q->len - 1;
}

long max_elem(struct q_construct *q)
{
    if (empty2(q))
        return q->max_arr[q->top1-1];
    return max(q->max_arr[q->top1-1], q->max_arr[q->top2+1]);
}

long dequeue(struct q_construct *q)
{
    if (empty2(q))
        while (!empty1(q))
        {
            push2(q, pop1(q));
        }
    return pop2(q);
}