#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct queue{
    int *data, cap, count, head, tail;
};
void InitQueue(struct queue *q, int n){
    q->data = calloc(n, sizeof(int));
    q->cap = n;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
}
int QueueEmpty(struct queue *q){
    return q->count;
}
void Enqueue(struct queue *q, int x){
    if (q->count == q->cap){
        q->data = realloc(q->data, q->cap * 2 * sizeof(int));
        for (int i = q->head; i < q->cap; i++){
            q->data[i + q->cap] = q->data[i];
        }
        q->data[q->tail] = x;
        q->head += q->cap;
        q->cap *= 2;
        q->tail += 1;
        q->tail = q->tail % q->cap;
    }
    else{
      q->data[q->tail] = x;
      q->tail += 1;
      q->tail = q->tail % q->cap;
    }
    q->count += 1;
}
void Dequeue(struct queue *q){
    int x = q->data[q->head];
    printf("%d\n", x);
    q->head += 1;
    q->head = q->head % q->cap;
    q->count -= 1;
}
int main(){
    struct queue q;
    char command[6] = "HELL";
    int x;
    InitQueue(&q, 4);
    while (strcmp(command, "END")){
        scanf("%s", command);
        if (strcmp(command, "ENQ") == 0){
            scanf("%d", &x);
            Enqueue(&q, x);
        }
        if (strcmp(command, "DEQ") == 0){
            Dequeue(&q);
        }
        if (strcmp(command, "EMPTY") == 0){
            if (QueueEmpty(&q)){
                printf("%s\n", "false");
            }
            else{
                printf("%s\n", "true");
            }
        }
        
        
    }
    free(q.data);
}