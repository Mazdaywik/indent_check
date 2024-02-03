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
    int k;
    scanf("%d", &k);
    int lens[k];
    for(int i=0; i<k; i++) {
        scanf("%d", &lens[i]);
    }
    struct pqueue pqueue;
    struct pqueue *pq = &pqueue;
    initpqueue(pq, k);
    int *matr[k];
    for(int i=0; i<k; i++) matr[i] = (int*)calloc(lens[i], sizeof(int));
    for(int i=0; i<k; i++){
        for(int j=0; j<lens[i]; j++) {
            scanf("%d", &matr[i][j]);
            if (j==0){
                struct pair ptr;
                ptr.k = matr[i][j];
                ptr.v = i;
                insert(pq, ptr);
            }

        }
    }
    int sdvs[k];
    for(int i=0; i<k;i++) sdvs[i] = 1;
    while(queuempty(pq) == 0){
        struct pair e = extractmax(pq);
        printf("%d ", e.k);
        if(sdvs[e.v] < lens[e.v]){
            struct pair ptr;
            ptr.k = matr[e.v][sdvs[e.v]++];
            ptr.v = e.v;
            insert(pq, ptr);
        }
    }
    free(pq->heap);
    for(int i=0; i<k; i++) free(matr[i]);
    return 0;
}