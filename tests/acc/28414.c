#include <stdio.h>
#include <stdlib.h>

#define MAX_DEPTH 32

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int low, int high, int m, int depth) {
    if (depth >= MAX_DEPTH) {
        insertionSort(arr, low, high);
        return;
    }

    while (low < high) {
        int pi = partition(arr, low, high);

        if (pi - low < high - pi) {
            quickSort(arr, low, pi - 1, m, depth + 1);
            low = pi + 1;
        } else {
            quickSort(arr, pi + 1, high, m, depth + 1);
            high = pi - 1;
        }
    }

    if (high - low <= m)
        insertionSort(arr, low, high);
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1, m, 0);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
