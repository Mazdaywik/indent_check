#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swapI(int* a, int* b) {
    int swaper = *a;
    *a = *b;
    *b = swaper;
}

void selectionSort(int* arr, int size) {
    int i, j, maxindex;
    for (i = 0; i < size; ++i) {
        maxindex = i;
        for (j = i + 1; j < size; ++j) {
            if (arr[j] < arr[maxindex]) {
                maxindex = j;
            }
        }
        if (i != maxindex) {
            swapI(arr + i, arr + maxindex);
        }
    }
}

void heapify(int* array, int size, int index) {
    int left, right, next;
    while (1) {
        left = index * 2 + 1;
        right = index * 2 + 2;
        next = index;
        if (left < size && array[left] > array[next]) {
            next = left;
        }
        if (right < size && array[right] > array[next]) {
            next = right;
        }
        if (next == index) {
            break;
        }
        swapI(array + index, array + next);
        index = next;
    }
}

void heapSort(int* array, int size) {
    int i;
    if (size <= 1) {
        return;
    }
    for (i = size / 2 - 1; i >= 0; --i) {
        heapify(array, size, i);
    }
    heapify(array, size, 0);
    for (i = size - 1; i > 0; --i) {
        swapI(array, array + i);
        heapify(array, i, 0);
    }
}

void quickSortRec(int* array, int low, int high, int m, int depth, int max_depth) {
    int mid_value, left, right;

    if (high + 1 < low + m) {
        selectionSort(array + low, high - low + 1);
        return;
    }

    if (depth >= max_depth) {
        heapSort(array + low, high - low + 1);
    }

    left = low;
    right = high;
    mid_value = array[(high + low) / 2];

    while (left <= right) {
        while (array[left] < mid_value) {
            ++left;
        }
        while (array[right] > mid_value) {
            --right;
        }
        if (left <= right) {
            swapI(array + left, array + right);
            ++left;
            --right;
        }
    }
    if (low < right) {
        quickSortRec(array, low, right, m, depth + 1, max_depth);
    }
    if (high > left) {
        quickSortRec(array, left, high, m, depth + 1, max_depth);
    }
}

void quickSort(int* array, int size, int m) {
    if (size < m) {
        selectionSort(array, size);
        return;
    }
    quickSortRec(array, 0, size - 1, m, 0, log(size) + 1);
}

int main() {
    int* array, size, i, m;

    scanf("%d%d", &size, &m);
    array = (int*) malloc(size * sizeof(int));
    for (i = 0; i < size; ++i) {
        scanf("%d", &array[i]);
    }

    quickSort(array, size, m);

    for (i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}