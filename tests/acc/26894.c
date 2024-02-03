#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Max{
    int x,max;
};

struct DoubleStack{

struct Max *data;
int cap;
int top1;
int top2;
};

void InitDoubleStack(struct DoubleStack *doublestack, int n){
    doublestack->data = (struct Max *)malloc(sizeof(struct Max)*n);
    doublestack->cap = n;
    doublestack->top1 = 0;
    doublestack->top2 = n-1;
}

int StackEmpty1(struct DoubleStack *doublestack){
    return doublestack->top1 == 0;
}

int StackEmpty2(struct DoubleStack *doublestack){
    return doublestack->top2 == doublestack->cap-1;
}

void Push1(struct DoubleStack *doublestack, int x){
    doublestack->data[doublestack->top1].x = x;
    if (StackEmpty1(doublestack)){
        doublestack->data[doublestack->top1].max = x;
    }
    else
    {
        doublestack->data[doublestack->top1].max = doublestack->data[doublestack->top1-1].max<x?x:doublestack->data[doublestack->top1-1].max;
    }
    doublestack->top1++;
}
void Push2(struct DoubleStack *doublestack, int x){
    doublestack->data[doublestack->top2].x = x;
    if (StackEmpty2(doublestack)){
        doublestack->data[doublestack->top2].max = x;
    }
    else
    {
        doublestack->data[doublestack->top2].max = doublestack->data[doublestack->top2+1].max<x?x:doublestack->data[doublestack->top2+1].max;
    }
    doublestack->top2--;
}

int Pop1(struct DoubleStack *doublestack){
    doublestack->top1--;
    return doublestack->data[doublestack->top1].x;
}

int Pop2(struct DoubleStack *doublestack){
    doublestack->top2++;
    return doublestack->data[doublestack->top2].x;
}

void InitQueueonStack(struct DoubleStack *doublestack, int n){
    InitDoubleStack(doublestack,n);
}

int QueueEmpty(struct DoubleStack *doublestack){
    return StackEmpty1(doublestack) && StackEmpty2(doublestack);
}

void Enqueue(struct DoubleStack *doublestack, int x){
    Push1(doublestack,x);
}

int Dequeue(struct DoubleStack *doublestack){

    if(StackEmpty2(doublestack)){
        while(!StackEmpty1(doublestack)){
            Push2(doublestack, Pop1(doublestack));
        }
    }
    return Pop2(doublestack);;
}
int Maximum(struct DoubleStack *doublestack){
    if (StackEmpty2(doublestack)){
        return doublestack->data[doublestack->top1-1].max;
    }
    else{
        if (!StackEmpty2(doublestack) && !StackEmpty1(doublestack)){
            int max1 = doublestack->data[doublestack->top1-1].max;
            int max2 = doublestack->data[doublestack->top2+1].max;
            return max1>max2?max1:max2;
        }
        else
        {
            return doublestack->data[doublestack->top2+1].max;
        }
        
    }
}
int main()
{
    int n = 100000, x;
    char act[6];
    struct DoubleStack queue;
    InitQueueonStack(&queue,2*n);
    scanf("%s", act);
    while (strcmp(act, "END") != 0)
    {
        if (strcmp(act, "ENQ") == 0){
            scanf("%d",&x);
            Enqueue(&queue,x);
        }
        else if (strcmp(act, "DEQ") == 0)
        {
            printf("%d\n", Dequeue(&queue));
        }
        else if (strcmp(act, "MAX") == 0)
        {
            printf("%d\n", Maximum(&queue));
        }
        else if (strcmp(act, "EMPTY") == 0)
        {
            printf("%s\n", QueueEmpty(&queue)?"true":"false");
        }
        scanf("%s", act);
    }
    free(queue.data);
}