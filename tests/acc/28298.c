#include <stdio.h>

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

void quicksort(int arr[], int low, int high, int m, int depth) {
    if (high - low + 1 <= m) {
        insertionSort(arr, low, high);
        return;
    }
    if (depth == 0) {
        insertionSort(arr, low, high);
        return;
    }
    int pivotIndex = (low + high) / 2;
    int pivotValue = arr[pivotIndex];
    int i = low;
    int j = high;
    while (i <= j) {
        while (arr[i] < pivotValue)
            i++;
        while (arr[j] > pivotValue)
            j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    quicksort(arr, low, j, m, depth - 1);
    quicksort(arr, i, high, m, depth - 1);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    quicksort(arr, 0, n - 1, m, 32);
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    return 0;
}
