#include <stdio.h>
#include <stdlib.h>
struct pair
{
    int k, v;
};
struct pqueue
{
    struct pair *heap;
    int cap, count;
};

void initpqueue(struct pqueue *pq, int n)
{
    pq->heap = (struct pair*)calloc(n, sizeof(struct pair));
    pq->cap = n;
    pq->count = 0;
};
int maximum(struct pqueue *pq)
{
    if(pq->count == 0) printf("stackunderflow");
    return pq->heap[0].v;
}
int queuempty(struct pqueue *pq)
{
    if(pq->count == 0) return 1;
    return 0;
}
void insert(struct pqueue *pq, struct pair ptr)
{
    int i = pq->count;
    if(i==pq->cap) printf("queueoverflow");
    pq->count = i+1;
    pq->heap[i] = ptr;
    while (i>0 && pq->heap[(i-1)/2].k > pq->heap[i].k){
        struct pair t = pq->heap[(i-1)/2];
        pq->heap[(i-1)/2] = pq->heap[i];
        pq->heap[i] = t;
        i = (i-1)/2;
    }
}
void heapify(int i, int n, struct pqueue *pq)
{
    while(1>0)
    {
        int l = 2*i+1, r = l+1, j=i;
        if (l<n && pq->heap[i].k > pq->heap[l].k) i = l;
        if (r<n && pq->heap[i].k > pq->heap[r].k) i = r;
        if (i == j) break;
        struct pair t = pq->heap[i];
        pq->heap[i] = pq->heap[j];
        pq->heap[j] = t;
    }
}
struct pair extractmax(struct pqueue *pq)
{
    if(pq->count == 0) printf("queueunderflow");
    struct pair ptr = pq->heap[0];
    (pq->count)--;
    if(pq->count > 0){
        pq->heap[0] = pq->heap[pq->count];
        heapify(0, pq->count, pq);
    }
    return ptr;
}

int main(int argc, char** argv)
{
    int n,m;
    scanf("%d%d", &n, &m);
    struct pqueue pqueue;
    struct pqueue *pq = &pqueue;
    initpqueue(pq, n);
    for(int i=0; i<n; i++){
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        struct pair ptr;
        ptr.k = (t1+t2);
        ptr.v = t1+t2;
        insert(pq, ptr);
    }
    for(int i=0; i<m-n; i++){
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        struct pair ended = extractmax(pq), ntask;
        if (t1 >= ended.v){
            ntask.k = (t1 + t2);
            ntask.v = t1+t2;
            insert(pq, ntask);
        }
        else if(t1 < ended.v){
            ntask.k = (ended.v + t2);
            ntask.v = ended.v + t2;
            insert(pq, ntask);
        }

        /*printf("\n");
        for(int j=0; j<n; j++) printf("%d ", pq->heap[j].v);    
        printf("\n");*/


    }
    while(pq->count > 1) extractmax(pq);
    printf("%d", extractmax(pq).v);
    free(pq->heap);
    return 0;
}