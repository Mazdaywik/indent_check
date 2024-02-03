#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue{
    int start;
    int end;
    int len;
    int size;
    long long *buf;
};

struct queue *InitQueue(){
    struct queue *new = malloc(sizeof(struct queue));
    new->buf = calloc(4, sizeof(long long));
    new->start = 0;
    new->end = 0;
    new->len = 4;
    new->size = 0;
    return new;
}

void Enqueue(struct queue *Queue, long long x){
    if(Queue->size == Queue->len){
        long long *new = calloc(Queue->len * 2, sizeof(long long));
        for(int i = 0, ind = Queue->start; i < Queue->size; i++, ind = (ind + 1) % Queue->len){
            new[i] = Queue->buf[ind];
        }
        free(Queue->buf);
        Queue->buf = new;
        Queue->start = 0;
        Queue->end = Queue->size;
        Queue->len *= 2;
    }
    Queue->buf[Queue->end] = x;
    Queue->end = (Queue->end + 1)%Queue->len;
    Queue->size++;
}

long long Dequeue(struct queue *Queue){
    long long res = Queue->buf[Queue->start];
    Queue->start = (Queue->start + 1) % Queue->len;
    Queue->size--;
    return res;
}

int QueueEmpty(struct queue *Queue){
    return Queue->size == 0;
}

int main(int argc, char** argv) {
    char command[10];
    scanf("%s", command);
    struct queue *Queue = InitQueue();
    while (strcmp(command, "END") != 0){
        if (!strcmp(command, "ENQ")){
            long long x;
            scanf("%lld", &x);
            Enqueue(Queue, x);
        }
        if (!strcmp(command, "DEQ")){
            printf("%lld\n", Dequeue(Queue));
        }
        if (!strcmp(command, "EMPTY")){
            if(QueueEmpty(Queue)){
                printf("true\n");
            }else{
                printf("false\n");
            }
        }
        scanf("%s", command);
    }
    free(Queue->buf);
    free(Queue);
    return 0;
}