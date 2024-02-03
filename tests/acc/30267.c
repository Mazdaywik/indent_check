#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue{
    int *data;
    int cap;
    int count;
    int head;
    int tail;
};

void queue_init(struct Queue *q, int n){
    q->data = (int *)malloc(sizeof(int) * n);
    q->cap = n;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
}

void QueueEmpty(struct Queue *q){
    printf((q->count == 0) ? "true\n" : "false\n");
}

void Enqueue(struct Queue *q, int x){
    q->data[q->tail] = x;
    q->tail++;
    if(q->tail == q->cap){
        q->cap *= 2;
        q->data = (int *)realloc(q->data, sizeof(int) * q->cap);
    }
    q->count++;
}

void Dequeue(struct Queue *q){
    int x = q->data[q->head];
    q->head++;
    if(q->head == q->cap)
        q->head = 0;
    q->count--;
    printf("%d\n", x);
}



int main(){
    struct Queue q;
    queue_init(&q, 4);
    char operation[10] = "START";
    while (strcmp(operation, "END") != 0) {
        scanf("%s", operation);
        if (strcmp(operation, "ENQ") == 0) {
            int x;
            scanf("%d", &x);
            Enqueue(&q, x);
        }
        if (strcmp(operation, "DEQ") == 0)
            Dequeue(&q);
        if (strcmp(operation, "EMPTY") == 0)
            QueueEmpty(&q);
    }
    free(q.data);
    return 0;
}