#include <stdio.h>
#include <stdlib.h>

void InsertSort (int low, int high, int* arr) {
    int i = low+1;
    while (i <= high) {
        int elem = arr[i];
        int loc = i - 1;
        while (loc >= low && abs(arr[loc]) > abs(elem)) {
            arr[loc+1] = arr[loc];
            --loc;
        }
        arr[loc+1] = elem;
        ++i;
    }
}

void Merge(int k, int l, int m, int* arr) {
    int T[m-k+1];
    int i = k;
    int j = l+1;
    int h = 0;
    while (h < m-k+1) {
        if (j <= m && (i == l+1 || abs(arr[j]) < abs(arr[i]))) {
            T[h] = arr[j];
            ++j;
        } else {
            T[h] = arr[i];
            ++i;
        }
        ++h;
    }
    for (int ind = k; ind <= m; ++ind) {
        arr[ind] = T[ind-k];
    }
}

void MergeSort(int low, int high, int* arr) {
    if (low < high) {
        if (high-low+1 > 5) {
            int med = (low + high)/2;
            MergeSort(low, med, arr);
            MergeSort(med+1, high, arr);
            Merge(low, med, high, arr);
        } else {
            InsertSort (low, high, arr);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    MergeSort(0, n-1, arr);

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}