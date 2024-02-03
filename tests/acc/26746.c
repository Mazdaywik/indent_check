#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue
{
    int *data;
    int count;
    int head;
    int cap;
    int tail;
};

void InitQueue(struct Queue *queue,int n){
    queue->data = (int *)malloc(sizeof(int)*n);
    queue->cap = n;
    queue->tail = 0;
    queue->head = 0;
    queue->count = 0;
    
}
int QueueEmpty(struct Queue *queue){
    return queue->count==0;
}

void Enqueue(struct Queue *queue, int x){
    queue->data[queue->tail] = x;
    queue->tail++;
    if (queue->tail==queue->cap){
        queue->cap*=2;
        queue->data = (int *)realloc(queue->data, sizeof(int)*queue->cap);
    }
    queue->count++;
}

int Dequeue(struct Queue *queue){
    int x = queue->data[queue->head];
    queue->head++;
    if (queue->head==queue->cap){
        queue->head = 0;
    }
    queue->count--;
    return x;
}

int main(){
    int n = 100000,x;
    char act[6];
    struct Queue queue;
    InitQueue(&queue, n);
    scanf("%s",act);
     while(strcmp(act,"END")!=0){
        if (strcmp(act,"ENQ")==0){
            scanf("%d",&x);
            Enqueue(&queue,x);
        }
        else if (strcmp(act,"DEQ")==0)
        {
           printf("%d\n",Dequeue(&queue));
        }
        else if (strcmp(act,"EMPTY")==0)
        {
            printf("%s\n", QueueEmpty(&queue)?"true":"false");
        }
        scanf("%s",act);
     }
    free(queue.data);
}