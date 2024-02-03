#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct KeyValue_ {
    int key;
    int value;
} KeyValue;

typedef struct Heap_ {
    int size;
    int capacity;
    KeyValue* buffer;
} Heap;

void initHeap(Heap* ptr_heap) {
    ptr_heap->size = 0;
    ptr_heap->capacity = 0;
    ptr_heap->buffer = NULL;
}

void clearHeap(Heap* ptr_heap) {
    ptr_heap->size = 0;
    ptr_heap->capacity = 0;
    if (ptr_heap->buffer != NULL) {
        free(ptr_heap->buffer);
        ptr_heap->buffer = NULL;
    }
}

void swapHeap(Heap* ptr_heap, int i, int j) {
    KeyValue a = ptr_heap->buffer[i];
    ptr_heap->buffer[i] = ptr_heap->buffer[j];
    ptr_heap->buffer[j] = a;
}

void addHeap(Heap* ptr_heap, int key, int value) {
    if (ptr_heap->size == ptr_heap->capacity) {
        Heap old_heap = *ptr_heap;
        ptr_heap->capacity = (ptr_heap->capacity) ? ptr_heap->capacity * 2 : 2;
        ptr_heap->buffer = (KeyValue*)malloc(ptr_heap->capacity * sizeof(KeyValue));
        memcpy(ptr_heap->buffer, old_heap.buffer, old_heap.size * sizeof(KeyValue));
        clearHeap(&old_heap);
    }
    ptr_heap->buffer[ptr_heap->size].key = key;
    ptr_heap->buffer[ptr_heap->size].value = value;
    ++ptr_heap->size;

    int index = ptr_heap->size - 1;
    int parent = (index - 1) / 2;
    while (index > 0 && ptr_heap->buffer[index].key < ptr_heap->buffer[parent].key) {
        swapHeap(ptr_heap, parent, index);
        index = parent;
        parent = (index - 1) / 2;
    }
}

KeyValue extractHeap(Heap* ptr_heap) {
    KeyValue kv = ptr_heap->buffer[0];
    swapHeap(ptr_heap, 0, ptr_heap->size - 1);
    --ptr_heap->size;

    int index = 0;
    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int next = index;
        if (left < ptr_heap->size && ptr_heap->buffer[left].key < ptr_heap->buffer[next].key) {
            next = left;
        }
        if (right < ptr_heap->size && ptr_heap->buffer[right].key < ptr_heap->buffer[next].key) {
            next = right;
        }
        if (next == index) {
            break;
        }
        swapHeap(ptr_heap, index, next);
        index = next;
    }

    return kv;
}

int heapSize(Heap* ptr_heap) {
    return ptr_heap->size;
}


void inputArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        scanf("%d", array + i);
    }
}

void printArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int sumArray(int* array, int size) {
    int sum = 0, i;
    for (i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum;
}


int** allocDynamicMatrix(int* row_sizes, int nrows) {
    int** table = (int**)malloc(nrows * sizeof(int*));
    for (int i = 0; i < nrows; ++i) {
        table[i] = (int*)malloc((row_sizes[i] + 1) * sizeof(int));
        table[i][0] = row_sizes[i];
    }
    return table;
}

void freeDynamicMatrix(int** table, int nrows) {
    for (int i = 0; i < nrows; ++i) {
        free(table[i]);
    }
    if (table != NULL) {
        free(table);
    }
}

void inputDynamicMatrix(int** table, int nrows) {
    for (int i = 0; i < nrows; ++i) {
        inputArray(table[i] + 1, table[i][0]);
    }
}


void mergeArrays(int** dynamic_matrix, int nrows, int* result_array) {
    Heap heap;
    initHeap(&heap);

    int* indexes = (int*) malloc(nrows * sizeof(int));
    for (int i = 0; i < nrows; ++i) {
        if (dynamic_matrix[i][0] > 0) {
            addHeap(&heap, dynamic_matrix[i][1], i);
            indexes[i] = 2;
        } else {
            indexes[i] = 1;
        }
    }

    int res_index = 0;
    while (heapSize(&heap) > 0) {
        KeyValue kv = extractHeap(&heap);
        result_array[res_index++] = kv.key;
        int nrow = kv.value;
        int ncol = indexes[nrow];
        if (ncol <= dynamic_matrix[nrow][0]) {
            addHeap(&heap, dynamic_matrix[nrow][ncol], nrow);
            ++indexes[nrow];
        }
    }

    clearHeap(&heap);
    free(indexes);
}


int main() {
    int amount_arrays;
    scanf("%d", &amount_arrays);

    int* array_sizes = (int*)malloc(amount_arrays * sizeof(int));
    inputArray(array_sizes, amount_arrays);
    int total_size = sumArray(array_sizes, amount_arrays);

    int** dynamic_matrix = allocDynamicMatrix(array_sizes, amount_arrays);
    inputDynamicMatrix(dynamic_matrix, amount_arrays);

    int *result_array = (int*)malloc(total_size * sizeof(int));
    mergeArrays(dynamic_matrix, amount_arrays, result_array);
    printArray(result_array, total_size);

    freeDynamicMatrix(dynamic_matrix, amount_arrays);
    free(array_sizes);
    free(result_array);
    return 0;
}