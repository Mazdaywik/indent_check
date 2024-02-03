#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int value;
    int arrayIndex;
    int elementIndex;
} HeapNode;

void swap(HeapNode* arr, int i, int j) {
    HeapNode temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void minHeapify(HeapNode* arr, int heapSize, int i) {
    int smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < heapSize && arr[leftChild].value < arr[smallest].value)
        smallest = leftChild;

    if (rightChild < heapSize && arr[rightChild].value < arr[smallest].value)
        smallest = rightChild;

    if (smallest != i) {
        swap(arr, i, smallest);
        minHeapify(arr, heapSize, smallest);
    }
}

void buildMinHeap(HeapNode* arr, int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        minHeapify(arr, heapSize, i);
    }
}

void mergeArrays(int** arrays, int* sizes, int k) {
    HeapNode* heap = (HeapNode*)malloc(k * sizeof(HeapNode));

    for (int i = 0; i < k; i++) {
        heap[i].value = arrays[i][0];
        heap[i].arrayIndex = i;
        heap[i].elementIndex = 0;
    }

    buildMinHeap(heap, k);

    while (heap[0].value != INT_MAX) {
        printf("%d ", heap[0].value);

        int nextElementIndex = heap[0].elementIndex + 1;
        if (nextElementIndex < sizes[heap[0].arrayIndex]) {
            heap[0].value = arrays[heap[0].arrayIndex][nextElementIndex];
            heap[0].elementIndex = nextElementIndex;
        }
        else {
            heap[0].value = INT_MAX;
        }

        minHeapify(heap, k, 0);
    }

    free(heap);
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

    mergeArrays(arrays, sizes, k);

    for (int i = 0; i < k; i++) {
        free(arrays[i]);
    }
    free(arrays);
    free(sizes);

    return 0;
}