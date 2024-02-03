#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Max {
    int val, max; 
};
struct DoubleStack {
    int top1, top2, cap;
    struct Max *data;
};
struct DoubleStack InitQueue(struct DoubleStack s, int n)
{
    s.data = malloc(n * sizeof(struct Max));
    s.cap = n;
    s.top1 = 0;
    s.top2 = n - 1;
    return s;
}
void QueueEmpty(struct DoubleStack s)
{
    if ((s.top1 == 0) && (s.top2 == s.cap - 1)) printf("true\n");
    else printf("false\n");
}
void Push1(struct DoubleStack *s, int x)
{
    s->data[s->top1].val = x;
    if (s->top1 == 0) s->data[s->top1].max = x;
    else if (x > s->data[s->top1 - 1].max) s->data[s->top1].max = x;
    else s->data[s->top1].max = s->data[s->top1 - 1].max;
    s->top1++;
}
void Push2(struct DoubleStack *s, int x)
{
    s->data[s->top2].val = x;
    if (s->top2 == s->cap - 1) s->data[s->top2].max = x;
    else if (x > s->data[s->top2 + 1].max) s->data[s->top2].max = x;
    else s->data[s->top2].max = s->data[s->top2 + 1].max;
    s->top2--;
}
int Pop1(struct DoubleStack *s)
{
    s->top1--;
    return s->data[s->top1].val;
}
int Pop2(struct DoubleStack *s)
{
    s->top2++;
    return s->data[s->top2].val;
}
int Maximum(struct DoubleStack s)
{
    if (s.top1 == 0) return s.data[s.top2 + 1].max;
    else if (s.top2 == s.cap - 1) return s.data[s.top1 - 1].max;
    else if (s.data[s.top1 - 1].max > s.data[s.top2 + 1].max) return s.data[s.top1 - 1].max;
    else return s.data[s.top2 + 1].max;
}

void Enqueue(struct DoubleStack *s, int x)
{
    Push1(s, x);
}
int Dequeue(struct DoubleStack *s)
{
    if (s->top2 == s->cap - 1) {
        while (s->top1 != 0) {
            Push2(s, Pop1(s));
        }
    }
    return Pop2(s);
}
int main()
{
    char operation[10];
    struct DoubleStack s;
    int x;
    s = InitQueue(s, 2000000);
    scanf("%s", operation);
    while (strcmp(operation, "END") != 0) {
        if (strcmp(operation, "ENQ") == 0) {
            scanf("%d", &x);
            Enqueue(&s, x);
        }
        else if (strcmp(operation, "DEQ") == 0) {
            x = Dequeue(&s);
            printf("%d\n", x);
        }
        else if (strcmp(operation, "EMPTY") == 0) QueueEmpty(s);
        else if (strcmp(operation, "MAX") == 0) {
            x = Maximum(s);
            printf("%d\n", x);
        }
        scanf("%s", operation);
    }
    free(s.data);
    return 0;
}