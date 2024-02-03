#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue{
    long *buf;
    int start;
    int count;
    int size;
};

struct Queue *InitQueue(){
    struct Queue *queue = calloc(1, sizeof(struct Queue));
    queue->size = 4;
    queue->buf = calloc(queue->size, sizeof(long ));
    return queue;
}

void Enqueue(struct Queue *queue, long x){
    queue->buf[(queue->start + queue->count++) % queue->size] = x;
}

void Dequeue(struct Queue *queue){
    printf("%ld\n", queue->buf[queue->start]);
    queue->start = (queue->start + 1) % (queue->size);
    queue->count--;
}

int main() {
    struct Queue*queue = InitQueue();
    char action[6];

    while (1) {
        scanf("%s", action);
        if(queue->size == queue->count){
            queue->size<<=1;
            long *advanced_buf = calloc(queue->size, sizeof(long));
            for(int i = 0; i < queue->count; i++){
                advanced_buf[i] = queue->buf[queue->start];
                queue->start = (queue->start + 1) % (queue->size >> 1);
            }
            queue->start = 0;
            free(queue->buf);
            queue->buf = advanced_buf;
        }
        if (strcmp(action, "ENQ") == 0) {
            long x;
            scanf("%ld", &x);
            Enqueue(queue, x);
        }
        else if (strcmp(action, "DEQ") == 0) {
            Dequeue(queue);
        }
        else if (strcmp(action, "EMPTY") == 0) {
            if (queue->count != 0) printf("false\n");
            else printf("true\n");
        }
        else if (strcmp(action, "END") == 0) break;
    }
    free(queue->buf);
    free(queue);
    return 0;
}