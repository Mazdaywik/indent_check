#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CircularBuffer {
    int* arr;
    int capacity;
    int size;
    int head;
    int tail;
};

void InitQueue(struct CircularBuffer* q,int n) {
    q->arr = (int*)malloc(4 * sizeof(int)); // initial capacity is 4
    q->capacity = n;
    q->size = 0;
    q->head = 0;
    q->tail = -1;
}

int QueueEmpty(struct CircularBuffer* q) {
    return (q->size == 0);
}

void ResizeQueue(struct CircularBuffer* q) {
    int new_capacity = 2 * q->capacity;
    int* new_arr = (int*)malloc(new_capacity * sizeof(int));
    int j = 0;
    for (int i = q->head; i != q->tail; i = (i + 1) % q->capacity) {
        new_arr[j++] = q->arr[i];
    }
    new_arr[j++] = q->arr[q->tail];
    free(q->arr);
    q->arr = new_arr;
    q->capacity = new_capacity;
    q->head = 0;
    q->tail = j - 1;
}

void Enqueue(struct CircularBuffer* q, int val) {
    if (q->size == q->capacity) {
        ResizeQueue(q);
    }
    q->tail = (q->tail + 1) % q->capacity;
    q->arr[q->tail] = val;
    q->size++;
}

int Dequeue(struct CircularBuffer* q) {
    int val = q->arr[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    return val;
}

int main(){
    int n = 4,x;
    char act[6];
    struct CircularBuffer queue;
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
    free(queue.arr);
}
