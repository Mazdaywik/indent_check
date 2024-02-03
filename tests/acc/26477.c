#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int* buffer; 
    int size;    
    int head;    
    int tail;    
} Queue;

void InitQueue(Queue* q){
    q->buffer = (int*)malloc(sizeof(int) * 4);
    q->size = 4;
    q->head = 0;
    q->tail = 0;
}

bool QueueEmpty(Queue* q){
    return q->head == q->tail;
}

void Enqueue(Queue* q, int x){
    if ((q->tail + 1) % q->size == q->head) {
        int newSize = q->size * 2;
        int* newBuffer = (int*)malloc(sizeof(int) * newSize);

        int i = q->head;
        int j = 0;
        while (i != q->tail){
            newBuffer[j++] = q->buffer[i];
            i = (i + 1) % q->size;
        }

        free(q->buffer);
        q->buffer = newBuffer;
        q->size = newSize;
        q->head = 0;
        q->tail = j;
    }

    q->buffer[q->tail] = x;
    q->tail = (q->tail + 1) % q->size;
}

int Dequeue(Queue* q){
    int x = q->buffer[q->head];
    q->head = (q->head + 1) % q->size;
    return x;
}

int main(){
    Queue q;
    InitQueue(&q);

    char command[10];
    int x;

    while (true)
    {
        scanf("%s", command);

        if (strcmp(command, "ENQ") == 0){
            scanf("%d", &x);
            Enqueue(&q, x);
        }
        else if (strcmp(command, "DEQ") == 0){
            printf("%d\n", Dequeue(&q));
        }
        else if (strcmp(command, "EMPTY") == 0){
            printf(QueueEmpty(&q) ? "true\n" : "false\n");
        }
        else if (strcmp(command, "END") == 0){
            break;
        }
    }

    free(q.buffer);

    return 0;
}
