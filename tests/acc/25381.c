#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int* data;
    int capacity;
    int size;
    int front;
    int rear;
} CircularBuffer;

void InitQueue(CircularBuffer* q) {
    q->capacity = 4;
    q->data = (int*)malloc(sizeof(int) * q->capacity);
    q->size = 0;
    q->front = 0;
    q->rear = -1;
}

bool QueueEmpty(CircularBuffer* q) {
    return (q->size == 0);
}

void resizeQueue(CircularBuffer* q) {
    int newCapacity = q->capacity * 2;
    int* newData = (int*)malloc(sizeof(int) * newCapacity);
    int j = 0;
    for (int i = q->front; i < q->capacity; i++) {
        newData[j++] = q->data[i];
    }
    for (int i = 0; i < q->front; i++) {
        newData[j++] = q->data[i];
    }
    q->front = 0;
    q->rear = q->size - 1;
    q->capacity = newCapacity;
    free(q->data);
    q->data = newData;
}

void Enqueue(CircularBuffer* q, int x) {
    if (q->size == q->capacity) {
        resizeQueue(q);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = x;
    q->size++;
}

int Dequeue(CircularBuffer* q) {
    int value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return value;
}

int main() {
    CircularBuffer queue;
    InitQueue(&queue);

    int n, val;
    char operation[100];
    scanf("%d", &n);

    while (1) {
        scanf("%s", operation);
        if (strcmp(operation, "ENQ") == 0) {
            scanf("%d", &val);
            Enqueue(&queue, val);
        }
        else if (strcmp(operation, "DEQ") == 0) {
            printf("%d\n", Dequeue(&queue));
        }
        else if (strcmp(operation, "EMPTY") == 0) {
            printf("%s\n", QueueEmpty(&queue) ? "true" : "false");
        }
        else if (strcmp(operation, "END") == 0) {
            break;
        }
    }

    free(queue.data);
    return 0;
}
