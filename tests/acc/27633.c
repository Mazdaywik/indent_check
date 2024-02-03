#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack {
    int *data, cap, count, head, tail;
};
struct Stack InitStack(struct Stack q, int n) {
    q.data = (int*)malloc(n * sizeof(int));
    q.cap = n;
    q.count = 0;
    q.head = 0;
    q.tail = 0;
    return q;
}
void QueueEmpty(struct Stack q)
{
    if (q.count == 0) printf("true\n");
    else printf("false\n");
}
void Enqueue(struct Stack *q, int x)
{
    int i;
    if (q->count == q->cap) {
        q->data = realloc(q->data, 2 * q->cap * sizeof(int));
        for (i = 0; i < q->cap; i++) {
            q->data[q->cap + i] = q->data[i]; 
        }
        q->head += q->cap;
        q->cap *= 2;
    }
    q->data[q->tail] = x;
    q->tail++;
    if (q->tail == q->cap) q->tail = 0;
    q->count++;
}
int Dequeue(struct Stack *q)
{
    int x = q->data[q->head];
    q->head++;
    if (q->head == q->cap) q->head = 0;
    q->count--;
    return x;
}
int main()
{
    char operation[10];
    struct Stack q;
    int x;
    q = InitStack(q, 4);
    scanf("%s", operation);
    while (strcmp(operation, "END") != 0) {
        if (strcmp(operation, "ENQ") == 0) {
            scanf("%d", &x);
            Enqueue(&q, x);
        }
        else if (strcmp(operation, "DEQ") == 0) {
            x = Dequeue(&q);
            printf("%d\n", x);
        }
        else if (strcmp(operation, "EMPTY") == 0) QueueEmpty(q);
        scanf("%s", operation);
    }
    free(q.data);
    return 0;
}