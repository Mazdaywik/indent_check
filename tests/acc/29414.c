#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int* buffer;
    int size;
    int head;
    int tail;
    int empty;
};

void InitQueue(struct Queue* queue) {
    queue->buffer = (int*) malloc(sizeof(int) * 4);
    queue->size = 4;
    queue->head = 0;
    queue->tail = 0;
    queue->empty = 1;
}

int QueueEmpty(struct Queue* queue) {
    return queue->empty;
}

void Enqueue(struct Queue* queue, int x) {
    if ((queue->tail + 1) % queue->size == queue->head) {
        int* new_buffer = (int*) malloc(sizeof(int) * queue->size * 2);
        int i = 0;
        int j = queue->head;
        while (j != queue->tail) {
            new_buffer[i] = queue->buffer[j];
            i++;
            j++;
            j %= queue->size;
        }
        new_buffer[i] = queue->buffer[j];
        free(queue->buffer);
        queue->buffer = new_buffer;
        queue->size *= 2;
        queue->head = 0;
        queue->tail = i;
    }
    queue->buffer[queue->tail] = x;
    queue->tail++;
    queue->tail %= queue->size;
    queue->empty = 0;
}

int Dequeue(struct Queue* queue) {
    int x = queue->buffer[queue->head];
    queue->head++;
    queue->head %= queue->size;
    if (queue->head == queue->tail)
        queue->empty = 1;
    return x;
}

int main() {
    struct Queue queue;
    InitQueue(&queue);

    char op[6];
    int x;

    while (1) {
        scanf("%s", op);
        if (op[0] == 'E') {
            if (op[1] == 'N') {
                if (op[2] == 'Q') {
                    scanf("%d", &x);
                    Enqueue(&queue, x);
                } else
                    break;
            } else {
                if (QueueEmpty(&queue))
                    printf("%s\n", "true");
                else
                    printf("%s\n", "false");
            }
        } else
            printf("%d\n", Dequeue(&queue));    
    }
    free(queue.buffer);
    return 0;
}