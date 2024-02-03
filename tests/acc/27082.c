#include <stdio.h>
#include <stdlib.h>

struct Queue
{

    int *heap;
    int count, cap;
};

int InitPrioryQueue(struct Queue *queue, int n)
{
    queue->heap = (int *)malloc(sizeof(int) * n);
    queue->cap = n;
    queue->count = 0;
}

void Heapify(struct Queue *queue, int i, int n)
{

    int l, r, j;
    for (;;)
    {
        l = i * 2 + 1;
        r = i * 2 + 2;
        j = i;
        if (l < n && queue->heap[i] > queue->heap[l])
        {
            i = l;
        }
        if (r < n && queue->heap[i] > queue->heap[r])
        {
            i = r;
        }
        if (i == j)
        {
            break;
        }
        int temp = queue->heap[i];
        queue->heap[i] = queue->heap[j];
        queue->heap[j] = temp;
    }
}

void Insert(struct Queue *queue, int ptr)
{
    int i = queue->count;
    queue->count = i + 1;
    queue->heap[i] = ptr;
    while (i > 0 && queue->heap[(i - 1) / 2] > queue->heap[i])
    {
        int temp = queue->heap[(i - 1) / 2];
        queue->heap[(i - 1) / 2] = queue->heap[i];
        queue->heap[i] = temp;

        i = (i - 1) / 2;
    }
}

int ExtractMax(struct Queue *queue)
{
    int ptr = queue->heap[0];
    queue->count--;
    if (queue->count > 0)
    {
        queue->heap[0] = queue->heap[queue->count];
        Heapify(queue, 0, queue->count);
    }
    return ptr;
}

int main(){
    int n,m,max_time=0,cur_time=0;
    scanf("%d%d", &n,&m);
    struct Queue queue;
    InitPrioryQueue(&queue,n);
    for(int i =0;i<n;++i){
        int t1,t2;
        scanf("%d%d", &t1,&t2);
        cur_time=t1+t2;
        max_time=max_time>cur_time?max_time:cur_time;
        Insert(&queue,cur_time);
    }
    for(int i = n;i<m;++i){
        int t1,t2;
        scanf("%d%d", &t1,&t2);
        cur_time = ExtractMax(&queue);
        cur_time = cur_time>t1?cur_time+t2:t1+t2;
        max_time=max_time>cur_time?max_time:cur_time;
        Insert(&queue,cur_time);
    }
    printf("%d", max_time);
    free(queue.heap);
}