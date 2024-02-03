#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct PriorityQueueUnit {
    int index;
    int k;
    int v;
};

struct PriorityQueue {
    struct PriorityQueueUnit *heap;
    int cap;
    int count;
};

void InitPriorityQueue(struct PriorityQueue *q, int n) {
    q->heap = (struct PriorityQueueUnit*) malloc(sizeof(struct PriorityQueueUnit) * n);
    q->cap = n;
    q->count = 0;
}

struct PriorityQueueUnit Maximum(struct PriorityQueue *q) {
    return q->heap[0];
}

void SwapPriorityQueue(struct PriorityQueueUnit *q1, struct PriorityQueueUnit *q2) {
    struct PriorityQueueUnit h = *q1;
    *q1 = *q2;
    *q2 = h;
}

void Insert(struct PriorityQueue *q, struct PriorityQueueUnit ptr) {
    int i = q->count;
    q->count = i + 1;
    q->heap[i] = ptr;
    while (i > 0 && q->heap[(i - 1) / 2].k < q->heap[i].k) {
        SwapPriorityQueue(&q->heap[(i - 1) / 2], &q->heap[i]);
        q->heap[i].index = i;
        i = (i - 1) / 2;
    }
    q->heap[i].index = i;
}

void Heapify(int i, int n, struct PriorityQueueUnit *heap) {
    int l = 2 * i + 1;
    int r = l + 1;
    int j = i;

    if (l < n && heap[i].k < heap[l].k)
        i = l;
    if (r < n && heap[i].k < heap[r].k) 
        i = r;
    if (i != j) {
        SwapPriorityQueue(&heap[i], &heap[j]);
        heap[i].index = i;
        heap[j].index = j;
        Heapify(i, n, heap);
    }
}

struct PriorityQueueUnit ExtractMax(struct PriorityQueue *q) {
    struct PriorityQueueUnit ptr = Maximum(q);
    q->count--;
    if (q->count > 0) {
        q->heap[0] = q->heap [q->count];
        q->heap[0].index = 0;
        Heapify(0, q->count, q->heap);
    }
    return ptr;
}

int main() {
    int n;
    scanf("%d", &n);
    int total_size = 0;
    int size;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &size);
        total_size += size;
    }

    struct PriorityQueue q;
    InitPriorityQueue(&q, total_size);

    for (int i = 0; i < total_size; i++) {
        int value;
        scanf("%d", &value);
        struct PriorityQueueUnit unit;
        unit.v = value;
        unit.k = value;
        Insert(&q, unit);
    }
    int *result = (int*) malloc(sizeof(int) * total_size);
    for (int i = total_size - 1; i >= 0; i--)
        result[i] = ExtractMax(&q).v;
    for (int i = 0; i < total_size; i++)
        printf("%d ", result[i]);
    free(result);
    free(q.heap);
    return 0;
}