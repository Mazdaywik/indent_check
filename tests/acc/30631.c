#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
    int *data;
    int cap;
    int count;
    int head;
    int tail;
};

void InitQueue(struct Queue *q, int n)
{
    q->data = (int*) calloc(n, sizeof(int));
    q->cap = n;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
}

int QueueEmpty(struct Queue *q)
{
    return (q->count == 0);
}

void Enqueue(struct Queue *q, int x)
{
    if (q->count == q->cap) printf("error");
    q->data[q->tail] = x;
    q->tail++;
    if (q->tail == q->cap) {
        q->cap = 2 * q-> cap;
        q->data = (int*) realloc(q->data, q->cap * sizeof(int));
    }
    q->count++;
}

int Dequeque(struct Queue *q)
{
    int x = q->data[q->head];
    q->head++;
    if (q->head == q->cap) q->head = 0;
    q->count--;
    return x;
}

int main()
{
    struct Queue cbuf;
    InitQueue(&cbuf, 4);
    
    char action[6];
    scanf("%s", action);
    
    while (strcmp("END", action) != 0) {
        if (strcmp("ENQ", action) == 0) {
            int x;
            scanf("%d", &x);
            Enqueue(&cbuf, x);
        }
        else if (strcmp("DEQ", action) == 0) {
            printf("%d\n", Dequeque(&cbuf));
        }
        else if (strcmp("EMPTY", action) == 0) {
            if (QueueEmpty(&cbuf)) printf("true\n");
            else printf("false\n");
        }
        scanf("%s", action);
    }
    free(cbuf.data);
    return 0;
}
