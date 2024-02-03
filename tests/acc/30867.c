#include <stdio.h>
#include <stdlib.h>

struct Heap {
    int index;
    int k; //key
    int v; //value
};

struct Queue {
    struct Heap *heap;
    int count;
    int cap;
};

void InitPriorityQueue(struct Queue *q, int n)
{
    q->heap = (struct Heap*) calloc(n, sizeof(struct Heap));
    q->cap = n;
    q->count = 0;
}

void Insert(struct Queue *q, struct Heap ptr)
{
    int i = q->count;
    q->count = i + 1;
    
    q->heap[i] = ptr;
    while (i > 0 && q->heap[(i - 1) / 2].v < q->heap[i].v) {
        struct Heap s = q->heap[(i - 1)/2];
        q->heap[(i - 1)/2] = q->heap[i];
        q->heap[i] = s;
        
        q->heap[i].index = i;
        i = (i - 1) / 2;
    }
    q->heap[i].index = i;
}

void Heapify(int i, int n, struct Queue *q)
{
    int l = 2 * i + 1;
    int r = l + 1;
    int j = i;
    if (l < n && q->heap[i].v < q->heap[l].v)
        i = l;
    if (r < n && q->heap[i].v < q->heap[r].v)
        i = r;
    if (i != j) {
        struct Heap s = q->heap[i];
        q->heap[i] = q->heap[j];
        q->heap[j] = s;
        
        q->heap[i].index = i;
        q->heap[j].index = j;
        
        Heapify(i, q->count, q);
    }
}

struct Heap ExtractMax(struct Queue *q)
{
    struct Heap ptr;
    ptr = q->heap[0];
    q->count--;
    if (q->count > 0) {
        q->heap[0] = q->heap[q->count];
        q->heap[0].index = 0;
        Heapify(0, q->count, q);
    }
    return ptr;
}

int main()
{
    int k;
    scanf("%d", &k);
    
    int *sizes;
    sizes = (int*) calloc(k, sizeof(int));
    int counter = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d", &sizes[i]);
        counter += sizes[i];
    }
    
    struct Queue q;
    InitPriorityQueue(&q, counter);
    
    int **arrays;
    arrays = (int**) calloc(k, sizeof(int*));
    for (int i = 0; i < k; i++) {
        arrays[i] = (int*) calloc(sizes[i], sizeof(int));
        for (int j = 0; j < sizes[i]; j++)
            scanf("%d", &arrays[i][j]);
    }
    
    int ind[k];
    for (int i = 0; i < k; i++) {
        struct Heap ptr;
        ptr.v = -arrays[i][0];
        ptr.k = i;
        Insert(&q, ptr);
        ind[i] = 1;
    }
    
    for (int i = 0; i < counter; i++) {
        struct Heap v = ExtractMax(&q);
        printf("%d ", -v.v);
        int index = v.k;
        if (sizes[index] > ind[index]) {
            struct Heap ptr;
            ptr.v = -arrays[index][ind[index]];
            ptr.k = index;
            Insert(&q, ptr);
            ind[index]++;
        }
    }

    for (int i = 0; i < k; i++) free(arrays[i]);
    free(arrays);
    free(sizes);
    free(q.heap);
    return 0;
}
