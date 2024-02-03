#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int left, int right) {
    for (int i = left; i <= right; i++) {
        int minIndex = i;
        for (int j = i + 1; j <= right; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

void quickSort(int arr[], int left, int right, int m) {
    while (right - left + 1 > m) {
        int pivot = arr[(left + right) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(&arr[i], &arr[j]);
                i++;
                j--;
            }
        }
        if (j - left < right - i) {
            if (left < j) {
                quickSort(arr, left, j, m);
            }
            left = i;
        } else {
            if (i < right) {
                quickSort(arr, i, right, m);
            }
            right = j;
        }
    }
    
    selectionSort(arr, left, right);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int* arr = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1, m);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
  
    return 0;
}
