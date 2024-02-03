#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int arrayIndex;
    int elementIndex;
} HeapNode;

void minHeapify(HeapNode *heap, int heapSize, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].value < heap[smallest].value)
        smallest = left;

    if (right < heapSize && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        HeapNode temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        minHeapify(heap, heapSize, smallest);
    }
}

void buildMinHeap(HeapNode *heap, int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--)
        minHeapify(heap, heapSize, i);
}

void mergeArrays(int *arrays[], int sizes[], int k) {
    HeapNode *heap = (HeapNode *)malloc(k * sizeof(HeapNode));

    int totalElements = 0;
    for (int i = 0; i < k; i++)
        totalElements += sizes[i];

    for (int i = 0; i < k; i++) {
        heap[i].value = arrays[i][0];
        heap[i].arrayIndex = i;
        heap[i].elementIndex = 0;
    }

    buildMinHeap(heap, k);

    for (int i = 0; i < totalElements; i++) {
        printf("%d ", heap[0].value);

        int arrayIndex = heap[0].arrayIndex;
        int elementIndex = heap[0].elementIndex + 1;

        if (elementIndex < sizes[arrayIndex]) {
            heap[0].value = arrays[arrayIndex][elementIndex];
            heap[0].elementIndex = elementIndex;
        } else {
            heap[0].value = 2000000000;
        }

        minHeapify(heap, k, 0);
    }

    free(heap);
}

int main() {
    int k;
    scanf("%d", &k);

    int sizes[k];
    int *arrays[k];

    for (int i = 0; i < k; i++)
        scanf("%d", &sizes[i]);

    for (int i = 0; i < k; i++) {
        arrays[i] = (int *)malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; j++)
            scanf("%d", &arrays[i][j]);
    }

    mergeArrays(arrays, sizes, k);

    for (int i = 0; i < k; i++)
        free(arrays[i]);

    return 0;
}