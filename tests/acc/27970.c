#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Queue{
        int cap;
        int count;
        int head;
        int tail;
        int* data;
};

struct Queue* InitQueue(int size){
        struct Queue* queue = malloc(sizeof(struct Queue));
        queue->data = malloc(sizeof(int) * size);
        queue->cap = size;
        queue->count = 0;
        queue->head = 0;
        queue->tail = 0;
        return queue;
}

int Dequeue(struct Queue* queue);


void Enqueue(struct Queue* queue, int a){
        if(queue->count == queue->cap){
                int* newdata = malloc(sizeof(int) * queue->cap * 2);
//              printf("%d %d\n", queue->head, queue->tail);
                for(int i = 0; i < queue->cap;i++){
                        newdata[i] = Dequeue(queue);
                }

                free(queue->data);
                queue->count = queue->cap;
                queue->data = newdata;
                queue->tail = queue->cap;
                queue->cap *= 2;
                queue->head = 0;
        }

        queue->data[queue->tail] = a;
        queue->tail++;
        if(queue->tail == queue->cap) queue->tail = 0;
        queue->count++;
}

int Dequeue(struct Queue* queue){
        int a = queue->data[queue->head];
        queue->head ++;
        if(queue->head == queue->cap) queue->head = 0;
        queue->count--;
        return a;
}

int QueueEmpty(struct Queue* queue){
        if (queue->count == 0) return 1;
        else return 0;
}
int main(){
        struct Queue* queue = InitQueue(4);
        char input[10000] = { 'a' };
        int operand;
        while(strcmp(input, "END") != 0){
                scanf("%s", input);
                if (strcmp(input, "ENQ") == 0){
                        scanf("%d", &operand);
                        Enqueue(queue, operand);
                }
                if (strcmp(input, "DEQ") == 0){
                        printf("%d\n", Dequeue(queue));
                }
                if (strcmp(input, "EMPTY") == 0){
                        if(QueueEmpty(queue) == 1) printf("true\n");
                        else printf("false\n");
                }
        }
        free(queue->data);
        free(queue);
}