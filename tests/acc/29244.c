#include <stdio.h>
#include <stdlib.h>

struct Heap {
    int index;
    int* arr;
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
    
    while (i > 0 && q->heap[(i - 1)/2]->arr[q->heap[(i - 1)/2]->index] > q->heap[i]->arr[q->heap[i]->index]) {
        struct Heap* copy_ptr = q->heap[i];
        q->heap[i] = q->heap[(i - 1)/2];
        q->heap[(i - 1)/2] = copy_ptr;
        i = (i - 1)/2;
    }
}

void Heapify(int i, int n, struct Heap** heap) {
    while (1) {
        int l = 2 * i + 1;
        int r = l + 1;
        int j = i;
        if (l < n && heap[i]->arr[heap[i]->index] > heap[l]->arr[heap[l]->index]) i = l;
        if (r < n && heap[i]->arr[heap[i]->index] > heap[r]->arr[heap[r]->index]) i = r;
        if (i == j) break;

        struct Heap* copy_ptr = heap[i];
        heap[i] = heap[j];
        heap[j] = copy_ptr;
    }
}

struct Heap* ExtractMax(struct Queue* q) {
    struct Heap* ptr = q->heap[0];
    -- q->count;
    if (q->count > 0) {
        q->heap[0] = q->heap[q->count];
        Heapify (0, q->count, q->heap);
    }
    return ptr;
}

int main() {
    int n;
    scanf("%d", &n);
    struct Queue* q = InitQueue(n);
    int lens[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lens[i]);
    }
    for (int i = 0; i < n; i++) {
        int *arr = (int*) calloc(lens[i], sizeof(int));
        for (int j = 0; j < lens[i]; j++) {
            scanf("%d", &arr[j]);
        }
        struct Heap* ptr = malloc(sizeof(struct Heap));
        ptr->arr = arr; ptr->index = 0; ptr->k = lens[i];
        Insert(q, ptr);
    }
    while(q->count > 0) {
        struct Heap* curr = ExtractMax(q);
        printf("%d ", curr->arr[curr->index]);
        int ind = ++curr->index;
        if(ind < curr->k) {
            curr->arr[curr->index] = curr->arr[ind];
            Insert(q, curr);
        } else {
            free(curr->arr);
            free(curr);
        }
    }
    printf("\n");
    free(q->heap);
    free(q);
    return 0;
}