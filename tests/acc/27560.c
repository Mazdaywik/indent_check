#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue_ {
    int head;
    int tail;
    int size;
    int capacity;
    int* buffer;
} Queue;

void initQueue(Queue* queue, int capacity) {
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
    queue->capacity = capacity;
    queue->buffer = (int*) malloc(queue->capacity * sizeof(int));
}

void deleteQueue(Queue* queue) {
    queue->head = queue->tail = 0;
    queue->size = queue->capacity = 0;
    free(queue->buffer);
}

void resizeQueue(Queue* queue) {
    Queue old_queue = *queue;
    initQueue(queue, old_queue.capacity * 2);
    for (int i = 0; i < old_queue.size; ++i) {
        queue->buffer[queue->tail++] = old_queue.buffer[(old_queue.head + i) % old_queue.capacity];
        ++queue->size;
    }
    deleteQueue(&old_queue);
}

void enqueQueue(Queue* queue, int item) {
    if (queue->size == queue->capacity) {
        resizeQueue(queue);
    }
    ++queue->size;
    queue->buffer[queue->tail] = item;
    queue->tail = (queue->tail + 1) % queue->capacity;
}

int dequeQueue(Queue* queue) {
    int value = queue->buffer[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    --queue->size;
    return value;
}

int isEmptyQueue(Queue* queue) {
    return queue->size == 0;
}

int main() {
    int value;
    char operation[10];
    Queue queue;

    initQueue(&queue, 128);
    do {
        scanf("%s", operation);
        if (!strcmp(operation, "ENQ")) {
            scanf("%d", &value);
            enqueQueue(&queue, value);
        } else if (!strcmp(operation, "DEQ")) {
            printf("%d\n", dequeQueue(&queue));
        } else if (!strcmp(operation, "EMPTY")) {
            printf("%s\n", (isEmptyQueue(&queue) ? "true" : "false"));
        }
    } while (strcmp(operation, "END"));
    deleteQueue(&queue);

    return 0;
}
