#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct 
{
    int *data;
    int cap;
    int count;
    int head;
    int tail;
} CircularQueue;

void InitQueue(CircularQueue *q, int n) 
{
    q->data = (int *)malloc(sizeof(int) * n);
    q->cap = n;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
}

bool QueueEmpty(CircularQueue *q) 
{
    return q->count == 0;
}

void ResizeQueue(CircularQueue *q) 
{
    int *newData = (int *)malloc(sizeof(int) * q->cap * 2);

    if (q->head + q->count <= q->cap) {
        memcpy(newData, q->data + q->head, q->count * sizeof(int));
    } else {
        int segment1Size = q->cap - q->head;
        int segment2Size = q->count - segment1Size;
        
        memcpy(newData, q->data + q->head, segment1Size * sizeof(int));
        memcpy(newData + segment1Size, q->data, segment2Size * sizeof(int));
    }

    free(q->data);
    q->data = newData;
    q->head = 0;
    q->tail = q->count;
    q->cap *= 2;
}


void Enqueue(CircularQueue *q, int x) 
{
    if (q->count == q->cap) 
    {
        ResizeQueue(q);
    }
    q->data[q->tail] = x;
    q->tail = (q->tail + 1) % q->cap;
    q->count++;
}

int Dequeue(CircularQueue *q) 
{
    int result = q->data[q->head];
    q->head = (q->head + 1) % q->cap;
    q->count--;
    return result;
}

char *operations[4] = {"ENQ", "DEQ", "EMPTY", "END"};

int ind_operation(char *operation)
{
    for (int i = 0; i < 4; ++i)
    {
        if (strcmp(operations[i], operation) == 0)
            return i;
    }
}

int main() {
    CircularQueue q;
    InitQueue(&q, 4);

    char operation[10];
    int x;

    for (;;)
    {
        scanf("%s", operation);
        switch (ind_operation(operation))
        {
        case 0:
            scanf("%d", &x);
            Enqueue(&q, x);
            break;
        case 1:
            printf("%d\n", Dequeue(&q));
            break;
        case 2:
            printf("%s\n", QueueEmpty(&q) ? "true" : "false");
            break;
        case 3:
            goto end;
            break;            
        }
    }

end:
    free(q.data);
    return 0;
}
