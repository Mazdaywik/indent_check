#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Queue{
    int *data;
    int cap;
    int count;
    int head;
    int tail;
};


void InitQueue(int n, struct Queue *q){
    int *data = calloc(n, sizeof(int));
    q->data = data;
    q->cap = n;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
}

int QueueEmpty(struct Queue *q){
    if(q->count == 0){
        return 1;
    }
    return 0;
}

void Enqueue(struct Queue *q, int x){
    if(q->tail + 1 == q->cap){
        q->cap *= 2;
        q->data = realloc(q->data, q->cap * sizeof(int));
    }
    q->data[q->tail] = x;
    q->tail = q->tail + 1;
    q->count += 1;
}

int Dequeue(struct Queue *q){
    int x = q->data[q->head];
    q->head = q->head + 1;
    if(q->head == q->cap) q->head = 0;
    q->count -= 1;
    return x;
}

int main(int args, char **argv){
    struct Queue q;
    InitQueue(4, &q);
    while(true){
        char command[6];
        scanf("%s", command);
        if(strcmp(command, "ENQ") == 0){
            int x = 0;
            scanf("%d", &x);
            Enqueue(&q, x);
        }
        else if(strcmp(command, "DEQ") == 0){
            int x = Dequeue(&q);
            printf("%d\n", x);
        }
        else if(strcmp(command, "EMPTY") == 0){
            int x = QueueEmpty(&q);
            if(x == 0){
                printf("false\n");
            }
            else{
                printf("true\n");
            }
        }
        else if(strcmp(command, "END") == 0){
            break;
        }
    }
    free(q.data);
    return 0;
}
