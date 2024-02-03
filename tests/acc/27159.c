#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
    int *data;
    int capacity;
    int count;
    int head;
    int tail;
};

void InitQueue(struct Queue *q, int n) {
    q->data = (int *)malloc(n * sizeof(int));
    q->capacity = n;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
}

int QueueEmpty(struct Queue q) {
    return q.count == 0;
}

void DoubleQueue(struct Queue *q) {
    int newCapacity = 2 * q->capacity;
    int *newData = (int *)malloc(newCapacity * sizeof(int));
    for (int i = 0; i < q->count; i++) newData[i] = q->data[(q->head + i) % q->capacity];
    free(q->data);
    q->capacity=newCapacity;
    q->data=newData;
    q->head=0;
    q->tail=q->count;
}

void Enqueue(struct Queue *q, int x) {
    if (q->count == q->capacity) DoubleQueue(q);
    q->data[q->tail++] = x;
    q->tail %= q->capacity;
    q->count++;   
}

int Dequeue(struct Queue *q) {
    int x = q->data[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->count--;
    return x;
}

int main() {
    struct Queue q;
    InitQueue(&q, 4);
    char command[10];
    int value;

    while (1==1) {
        scanf("%s", command);
        if (strcmp(command, "ENQ") == 0) {
            scanf("%d", &value);
            Enqueue(&q, value);
        } 
        else if (strcmp(command, "DEQ") == 0) {
            printf("%d\n", Dequeue(&q));
        } 
        else if (strcmp(command, "EMPTY") == 0) {
            printf("%s\n", QueueEmpty(q) ? "true" : "false");
        } 
        else if (strcmp(command, "END") == 0) {
            break;
        }
    }
    free(q.data);
    return 0;
}