#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Queue {
    long int* data;
    int cap;
    int count;
    int head;
    int tail;
};

void InitQueue(struct Queue* q) {
    q->cap = 4;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
    q->data = calloc(4, sizeof(long int));
}

void QueueEmpty(struct Queue* q) {
    if (q->count == 0) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}

void Enqueue(struct Queue* q) {
    long int x;
    scanf("%ld", &x);
    if (q->count == q->cap) {
        long int copy_data[q->cap];
        for (int i = 0; i < q->cap; ++i) {
            copy_data[i] = q->data[i];
        }
        q->cap *= 2;
        free(q->data);
        q->data = calloc(q->cap, sizeof(long int));
        int i = q->head;
        int k = 0;
        while (k < q->count) {
            if (i == q->count) i = 0;
            q->data[k] = copy_data[i];
            ++i; ++k;
        }
        q->head = 0;
        q->tail = q->count;
    }

    if (q->tail == q->cap) q->tail = 0;
    q->data[q->tail] = x;
    q->tail += 1;
    q->count += 1;
}

void Dequeue(struct Queue* q) {
    long int x = q->data[q->head];
    q->head += 1;
    if (q->head == q->cap) q->head = 0;
    q->count -= 1;
    printf("%ld\n", x);
}


int main() {
    struct Queue* q = malloc (sizeof(struct Queue));
    InitQueue(q);
    while (1) {
        char op[6];
        scanf("%s", op);
        if (strcmp(op, "ENQ") == 0) {
            Enqueue(q);
        } else if (strcmp(op, "DEQ") == 0) {
            Dequeue(q);
        } else if (strcmp(op, "EMPTY") == 0) {
            QueueEmpty(q);
        } else {
            break;
        }
    }
    free(q->data);
    free(q);
    return 0;
}