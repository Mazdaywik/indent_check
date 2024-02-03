#include <stdio.h>
#include <stdlib.h>

struct Heap {
    int index;
    int v;
    int k;
    
};
struct Queue {
    struct Heap** heap;
    int cap;
    int count;
};

struct Queue* InitQueue(int len) {
    struct Queue* q = malloc (len * sizeof(struct Queue));
    q->cap = len;
    q->heap = calloc (q->cap, sizeof(struct Heap));
    q->count = 0;
    return q;
}

void Insert(struct Queue* q, struct Heap* ptr) {
    int i = q->count;
    q->count = i + 1;
    q->heap[i] = ptr;
    
    while (i > 0 && q->heap[(i - 1)/2]->k > q->heap[i]->k) {
        struct Heap* copy_ptr = q->heap[i];
        q->heap[i] = q->heap[(i - 1)/2];
        q->heap[(i - 1)/2] = copy_ptr;
        i = (i - 1)/2;
    }
    q->heap[i]->index = i;
}

void Heapify(int i, int n, struct Heap** heap) {
    while (1) {
        int l = 2 * i + 1;
        int r = l + 1;
        int j = i;
        if (l < n && heap[i]->k > heap[l]->k) i = l;
        if (r < n && heap[i]->k > heap[r]->k) i = r;
        if (i == j) break;

        struct Heap* copy_ptr = heap[i];
        heap[i] = heap[j];
        heap[j] = copy_ptr;
        heap[i]->index = i;
        heap[j]->index = j;
    }
}

struct Heap* ExtractMax(struct Queue* q) {
    struct Heap* ptr = q->heap[0];
    -- q->count;
    if (q->count > 0) {
        q->heap[0] = q->heap[q->count];
        q->heap[0]->index = 0;
        Heapify (0, q->count, q->heap);
    }
    return ptr;
}


int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    struct Queue* q = InitQueue(m);
    for (int i = 0; i < m; i++) {
        int t1, t2;
        scanf("%d %d", &t1, &t2);

        struct Heap* ptr = malloc(sizeof(struct Heap));
        ptr->index = i;
        ptr->k = (i < n) ? t1 + t2 : t2;
        ptr->v = t1;

        if (i >= n) {
            struct Heap* max_ptr = ExtractMax(q);
            ptr->k += (ptr->v <= max_ptr->k) ? max_ptr->k : ptr->v;
            free(max_ptr);
        }

        Insert(q, ptr);
    }
    int max = 0;
    while (q->count > 0) {
        struct Heap* max_ptr = ExtractMax(q);
        max = (max < max_ptr->k) ? max_ptr->k : max;
        free(max_ptr);
    }
    printf("%d", max);
    free(q->heap);
    free(q);
    return 0;
}