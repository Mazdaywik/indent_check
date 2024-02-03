#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct queue
{
    int count, head, tail, cap;
    int *data;
};
void initqueue(struct queue *q)
{
    q->data = (int*)calloc(4, sizeof(int));
    q->cap = 4;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
}
void queuextension(struct queue *q)
{
    q->cap *= 2;
    q->data = (int*)realloc(q->data, q->cap * sizeof(int)); 
    if(q->head >= q->tail){
        int newhead = (q->head) + (q->cap)/2;
        for(int i=newhead, sdv=0; i < q->cap; i++, sdv++) q->data[i] = q->data[(q->head)+sdv];
        q->head = newhead;
    }
}
int queuempty(struct queue *q)
{
    if(q->count == 0) return 1;
    return 0;
}
void enqueue(struct queue *q, int x)
{
    if(q->count == q->cap) queuextension(q);
    q->data[q->tail++] = x;
    if(q->tail == q->cap) q->tail = 0;
    q->count++;
}

int dequeue(struct queue *q)
{
    if(queuempty(q) == 1) printf("queueunderflow");
    int x = q->data[q->head++];
    if(q->head == q->cap) q->head = 0;
    q->count--;
    printf("%d\n", x);
    return x;
}

int main(int argc, char** argv)
{
    struct queue queue;
    struct queue *q = &queue;
    initqueue(q);
    char word[6];
    scanf("%s", word);
    while(strcmp(word, "END") != 0){
        if(strcmp(word, "ENQ") == 0){
            int x;
            scanf("%d", &x);
            enqueue(q, x);
        }
        else if(strcmp(word, "DEQ") == 0) dequeue(q);
        else if(strcmp(word, "EMPTY") == 0){
            if (queuempty(q) == 1) printf("true\n");
            else printf("false\n");
        }
        scanf("%s", word);
    }
    free(q->data);
    return 0;
}