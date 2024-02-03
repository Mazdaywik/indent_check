#include <stdio.h>

void swap(int* arr, int i, int j) {
    int copy_arri = arr[i];
        arr[i] = arr[j];
        arr[j] = copy_arri;
}

void SelectSort (int* arr, int low, int high) {
    int j = high;
    while (j > low) {
        int k = j;
        int i = j - 1;
        while (i >= low) {
            if (arr[k] < arr[i]) {
                k = i;
            }
            --i;
        }
        swap(arr, k, j);
        --j;
    }
}

int Partition (int low, int high, int* arr) {
    int i = low, j = low;
    while (j < high) {
        if (arr[j] < arr[high]) {
            swap(arr, i, j);
            ++i;
        }
        ++j;
    }
    swap(arr, i, high);
    return i;
}

void QuickSort (int low, int high, int* arr, int m) {
    if (low < high) {
        if (low - high < m) {
            SelectSort(arr, low, high);
        } else {
            int q = Partition(low, high, arr);
            QuickSort(low, q-1, arr, m);
            QuickSort(q+1, high, arr, m);
        }
    }
}

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    QuickSort(0, n-1, arr, m);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}