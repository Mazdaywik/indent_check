#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int size;
    int index;
} ArrayInfo;

typedef struct {
    ArrayInfo* arrays;
    int size;
} MinHeap;

void swap(ArrayInfo* a, ArrayInfo* b) {
    ArrayInfo temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(MinHeap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arrays[left].array[heap->arrays[left].index] 
    < heap->arrays[smallest].array[heap->arrays[smallest].index]) {
        smallest = left;
    }

    if (right < heap->size && heap->arrays[right].array[heap->arrays[right].index] 
    < heap->arrays[smallest].array[heap->arrays[smallest].index]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&heap->arrays[i], &heap->arrays[smallest]);
        min_heapify(heap, smallest);
    }
}

void build_min_heap(MinHeap* heap) {
    for (int i = heap->size / 2 - 1; i >= 0; i--) {
        min_heapify(heap, i);
    }
}

void merge_sorted_arrays(int k, int* sizes, int** arrays) {
    MinHeap heap;
    heap.size = k;
    heap.arrays = (ArrayInfo*)malloc(k * sizeof(ArrayInfo));

    int total_size = 0;
    for (int i = 0; i < k; i++) {
        heap.arrays[i].array = arrays[i];
        heap.arrays[i].size = sizes[i];
        heap.arrays[i].index = 0;
        total_size += sizes[i];
    }

    build_min_heap(&heap);

    int* result = (int*)malloc(total_size * sizeof(int));
    int result_index = 0;

    while (result_index < total_size) {
        ArrayInfo min_array = heap.arrays[0];
        result[result_index++] = min_array.array[min_array.index];

        if (min_array.index < min_array.size - 1) {
            min_array.index++;
            heap.arrays[0] = min_array;
        } else {
            heap.arrays[0] = heap.arrays[heap.size - 1];
            heap.size--;
        }

        min_heapify(&heap, 0);
    }

    for (int i = 0; i < total_size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(heap.arrays);
}

int main() {
    int k;
    scanf("%d", &k);

    int sizes[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &sizes[i]);
    }

    int* arrays[k];
    for (int i = 0; i < k; i++) {
        arrays[i] = (int*)malloc(sizes[i] * sizeof(int));
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d", &arrays[i][j]);
        }
    }

    merge_sorted_arrays(k, sizes, arrays);

    for (int i = 0; i < k; i++) {
        free(arrays[i]);
    }

    return 0;
}