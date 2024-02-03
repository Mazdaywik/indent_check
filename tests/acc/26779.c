#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Queue
{
    int *data;
    int cap;
    int count;
    int head;
    int tail;
};

int Find(char **arr, char *s, int n) 
{
        for (int i=0; i<n; i++)
        {
            if (strcmp(arr[i], s)==0)
            return i;
        }
}

void InitQueue(struct Queue *queue, int n)
{
    queue->data = malloc(n*sizeof(int));
    queue->cap = n;
    queue->count = 0;
    queue->head = 0;
    queue->tail = 0;
}

int EMPTY(struct Queue queue)
{
    return queue.count == 0;
}

void ENQ(struct Queue *queue, int x)
{
    queue->data[queue->tail] = x;
    queue->tail++;
    if(queue->tail == queue->cap) 
    {
        queue->cap *= 2;
        queue->data = realloc(queue->data, queue->cap * sizeof(int));
    }
    queue->count++;
}

int DEQ(struct Queue *queue)
{
    int x = queue->data[queue->head];
    queue->head++;
    if (queue->head == queue->cap) queue->head = 0;
    queue->count--;
    return x;
}

 int main() 
 {
    struct Queue q;
    InitQueue(&q, 4);
    char command[100];
    scanf("%s",command);
    while(strcmp(command,"END") != 0)
    {
        if(strcmp(command,"ENQ") == 0)
        {
            int x;
            scanf("%d",&x);
            ENQ(&q, x);
        }
        if(strcmp(command,"DEQ") == 0)
        printf("%d\n",DEQ(&q));
        if(strcmp(command,"EMPTY") == 0)
        {
            if(EMPTY(q))
                printf("true\n");
            else
                printf("false\n");
        }
        scanf("%s",command);
    }
    free(q.data);
    return 0;
}