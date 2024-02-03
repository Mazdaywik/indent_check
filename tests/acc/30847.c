#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
    return x < y ? x : y;
}

struct key {
    int t1;
    int t2;
};

struct PriorityQueue {
    struct key *heap;
    int cap;
    int count;
};

void InitPriorityQueue(struct PriorityQueue *q, int n)
{
    q->heap = (struct key*) calloc(n, sizeof(struct key));
    q->cap = n;
    q->count = 0;
}

void Insert(struct PriorityQueue *q, struct key ptr)
{
    int i = q->count;
    q->count = i + 1;
    q->heap[i] = ptr;
    while (i > 0) {
        int time1 = q->heap[(i - 1)/2].t1 + q->heap[(i - 1)/2].t2;
        int time2 = q->heap[i].t1 + q->heap[i].t2;
        if (time1 > time2) {
            struct key s = q->heap[(i - 1) / 2];
            q->heap[(i - 1) / 2] = q->heap[i];
            q->heap[i] = s;
        }
        i  = (i - 1)/2;
    }
}

void Heapify(int i, int n, struct PriorityQueue *q)
{
    int l = 2 * i + 1;
    int r = l + 1;
    int j = i;
    if ((l < n) && ((q->heap[i].t1 + q->heap[i].t2) > (q->heap[l].t1 + q->heap[l].t2)))
        i = l;
    if ((r < n) && ((q->heap[i].t1 + q->heap[i].t2) > (q->heap[r].t1 + q->heap[r].t2)))
        i = r;
    if (i != j) {
        struct key s = q->heap[i];
        q->heap[i] = q->heap[j];
        q->heap[j] = s;
        Heapify(i, q->count, q);
    }
}

struct key ExtractMax(struct PriorityQueue *q)
{
    struct key ptr = q->heap[0];
    q->count--;
    if (q->count > 0) {
        q->heap[0] = q->heap[q->count];
        Heapify(0, q->count, q);
    }
    return ptr;
}

struct key Min(int t1, int t2, struct PriorityQueue *q,
               int i, int M, int N)
{
    struct key ptr;
    if (i < N) {
        ptr.t1 = t1;
        ptr.t2 = t2;
    } else {
        ptr = q->heap[0];
        ExtractMax(q);
        if ((ptr.t1 + ptr.t2) < t1)
            ptr.t1 = t1;
        else ptr.t1 += ptr.t2;
        ptr.t2 = t2;
    }
    return ptr;
}

int main()
{
    int N;
    scanf("%d", &N);
    
    int M;
    scanf("%d", &M);
    
    struct PriorityQueue q;
    InitPriorityQueue(&q, N);
 
    for (int i = 0; i < M; i++) {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        struct key k = Min(t1, t2, &q, i, M, N);
        Insert(&q, k);
    }
    
    int res = q.heap[0].t1 + q.heap[0].t2;
    
    for (int i = 0; i < min(M, N); i++)
        if (res < (q.heap[i].t1 + q.heap[i].t2))
            res = q.heap[i].t1 + q.heap[i].t2;
    
    printf("%d\n", res);
    free(q.heap);
    return 0;
}
 
