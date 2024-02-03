#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int value;  // Значение элемента
    int arrayIndex;  // Индекс массива, из которого взят элемент
    int elementIndex;  // Индекс элемента в массиве
};

struct PriorityQueue {
    int capacity;
    int size;
    struct Pair* heap;
};

void swap(struct Pair* a, struct Pair* b) {
    struct Pair temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct PriorityQueue* pq, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < pq->size && pq->heap[left].value < pq->heap[smallest].value) {
        smallest = left;
    }

    if (right < pq->size && pq->heap[right].value < pq->heap[smallest].value) {
        smallest = right;
    }

    if (smallest != idx) {
        swap(&pq->heap[idx], &pq->heap[smallest]);
        minHeapify(pq, smallest);
    }
}

struct PriorityQueue* createPriorityQueue(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->heap = (struct Pair*)malloc(capacity * sizeof(struct Pair));
    return pq;
}

void insert(struct PriorityQueue* pq, int value, int arrayIndex, int elementIndex) {
    if (pq->size == pq->capacity) {
        return;
    }

    pq->size++;
    int i = pq->size - 1;
    pq->heap[i].value = value;
    pq->heap[i].arrayIndex = arrayIndex;
    pq->heap[i].elementIndex = elementIndex;

    while (i != 0 && pq->heap[(i - 1) / 2].value > pq->heap[i].value) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

struct Pair extractMin(struct PriorityQueue* pq) {
    if (pq->size <= 0) {
        struct Pair nullPair = {0, 0, 0};
        return nullPair;
    }

    if (pq->size == 1) {
        pq->size--;
        return pq->heap[0];
    }

    struct Pair root = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);

    return root;
}

void mergeArrays(int k, int* sizes, int** arrays) {
    struct PriorityQueue* pq = createPriorityQueue(k);

    int totalSize = 0;
    for (int i = 0; i < k; i++) {
        totalSize += sizes[i];
    }

    int* result = (int*)malloc(totalSize * sizeof(int));

    for (int i = 0; i < k; i++) {
        insert(pq, arrays[i][0], i, 0);
    }

    int resultIndex = 0;
    while (pq->size > 0) {
        struct Pair min = extractMin(pq);
        result[resultIndex++] = min.value;

        if (min.elementIndex + 1 < sizes[min.arrayIndex]) {
            insert(pq, arrays[min.arrayIndex][min.elementIndex + 1], min.arrayIndex, min.elementIndex + 1);
        }
    }

    for (int i = 0; i < totalSize; i++) {
        printf("%d ", result[i]);
    }

    free(pq->heap);
    free(pq);
    free(result);
}

int main() {
    int k;
    scanf("%d", &k);

    int* sizes = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        scanf("%d", &sizes[i]);
    }

    int** arrays = (int**)malloc(k * sizeof(int*));
    for (int i = 0; i < k; i++) {
        arrays[i] = (int*)malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    mergeArrays(k, sizes, arrays);

    for (int i = 0; i < k; i++) {
        free(arrays[i]);
    }
    free(arrays);
    free(sizes);

    return 0;
}
