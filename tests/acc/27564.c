#include <stdio.h>
#include <stdlib.h>

int maxInt(int a, int b) {
    return a > b ? a : b;
}

void swapInt(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}


typedef struct Heap_ {
    int size;
    int capacity;
    int* keys;
} Heap;

void initHeap(Heap* heap, int capacity) {
    heap->size = 0;
    heap->capacity = capacity;
    heap->keys = (int*) malloc(heap->capacity * sizeof(int));
}

void deleteHeap(Heap* heap) {
    heap->size = 0;
    heap->capacity = 0;
    if (heap->keys != NULL) {
        free(heap->keys);
    }
    heap->keys = NULL;
}

void swapHeap(Heap* heap, int i, int j) {
    swapInt(heap->keys + i, heap->keys + j);
}

void siftUpHeap(Heap* heap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap->keys[index] < heap->keys[parent]) {
        swapHeap(heap, parent, index);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void siftDownHeap(Heap* heap, int index) {
    int left, right, next;
    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        next = index;
        if (left < heap->size && heap->keys[left] < heap->keys[next]) {
            next = left;
        }
        if (right < heap->size && heap->keys[right] < heap->keys[next]) {
            next = right;
        }
        if (next == index) {
            break;
        }
        swapHeap(heap, index, next);
        index = next;
    }
}

void pushHeap(Heap* heap, int key) {
    heap->keys[heap->size] = key;
    ++heap->size;
    siftUpHeap(heap, heap->size - 1);
}

int popHeap(Heap* heap) {
    int key = heap->keys[0];
    swapHeap(heap, 0, heap->size - 1);
    --heap->size;
    siftDownHeap(heap, 0);
    return key;
}

int isEmptyHeap(Heap* heap) {
    return heap->size == 0;
}


typedef struct Timer_ {
    int start;
    int end;
} Timer;


void emptySolve(Timer* timers, int nproblems) {
    int max_time = 0, i;
    for (i = 0; i < nproblems; ++i) {
        max_time = maxInt(max_time, timers[i].end);
    }
    printf("%d\n", max_time);
}

void heapSolve(Timer* timers, int nproblems, int ncells) {
    int i, min_end_time, delay, max_time;
    Heap heap;

    initHeap(&heap, ncells);
    for (i = 0; i < ncells; ++i) {
        pushHeap(&heap, timers[i].end);
    }

    for (i = ncells; i < nproblems; ++i) {
        min_end_time = popHeap(&heap);
        delay = 0;
        if (min_end_time > timers[i].start) {
            delay = min_end_time - timers[i].start;
        }
        pushHeap(&heap, timers[i].end + delay);
    }

    max_time = 0;
    for (i = 0; i < ncells; ++i) {
        min_end_time = popHeap(&heap);
        max_time = maxInt(max_time, min_end_time);
    }
    printf("%d\n", max_time);
    deleteHeap(&heap);
}

int main() {
    int ncells, nproblems, i;

    scanf("%d%d", &ncells, &nproblems);

    Timer* timers = (Timer*) malloc(nproblems * sizeof(Timer));
    for (i = 0; i < nproblems; ++i) {
        scanf("%d%d", &timers[i].start, &timers[i].end);
        timers[i].end += timers[i].start;
    }

    if (nproblems <= ncells) {
        emptySolve(timers, nproblems);
    } else {
        heapSolve(timers, nproblems, ncells);
    }

    free(timers);
    return 0;
}
